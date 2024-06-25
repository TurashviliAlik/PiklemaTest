#include "LogFormatter.h"

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>

static QtMessageHandler sOriginalHandler = Q_NULLPTR;

enum Color
{
    Default     = 9,
    Black       = 0,
    DarkRed     = 1,
    DarkGreen   = 2,
    DarkYellow  = 3,
    DarkBlue    = 4,
    DarkMagenta = 5,
    DarkCyan    = 6,
    LightGray   = 7,
    DarkGray    = 60,
    Red         = 61,
    Green       = 62,
    Orange      = 63,
    Blue        = 64,
    Magenta     = 65,
    Cyan        = 66,
    White       = 67,
};

enum TextStyle
{
    Normal      = 0,
    Bold        = 1,
    DoubleBold  = 2,
    Underline   = 4,
    Blink       = 5,
    Inverse     = 7,
};

QString styleForeground(Color foreground, TextStyle textStyle = TextStyle::Normal)
{
    const qint32 textColorStart = 30;

    return "\033[" + QString::number(textStyle) + ";" + QString::number(textColorStart + foreground) + "m";
}

QString styleBackground(Color background)
{
    const qint32 backgroundColorStart = 40;

    return "\033[" + QString::number(backgroundColorStart + background) + "m";
}

static const char *patternTemplate =
    "["
    "%{time h:mm:ss.zzz} #%{threadid} "
    "%{if-debug}"    "COLOR_DEBUG"    "DBG%{endif}"
    "%{if-info}"     "COLOR_INFO"     "INF%{endif}"
    "%{if-warning}"  "COLOR_WARNING"  "WRN%{endif}"
    "%{if-critical}" "COLOR_CRITICAL" "CRT%{endif}"
    "%{if-fatal}"    "COLOR_FATAL"    "FTL%{endif}"
    "COLOR_NONE"
    "]"
    "["
    "%{if-category}" "COLOR_CATEGORY" "%{category}" "COLOR_NONE" " %{endif}"
    "COLOR_FUNCTION" "%{function}" "COLOR_NONE"
    "]  "
    "%{if-debug}"    "COLOR_DEBUG"    "%{endif}"
    "%{if-info}"     "COLOR_INFO"     "%{endif}"
    "%{if-warning}"  "COLOR_WARNING"  "%{endif}"
    "%{if-critical}" "COLOR_CRITICAL" "%{endif}"
    "%{if-fatal}"    "COLOR_FATAL"    "%{endif}"
    "%{message}"
    "COLOR_NONE";

static const QString functionStyle = styleForeground(Color::DarkGray);
static const QString debugStyle    = styleForeground(Color::LightGray);
static const QString infoStyle     = styleForeground(Color::Green);
static const QString warningStyle  = styleForeground(Color::DarkYellow);
static const QString criticalStyle = styleForeground(Color::DarkRed);
static const QString fatalStyle    = styleForeground(Color::DarkRed, TextStyle::Bold);
static const QString categoryStyle = styleForeground(Color::DarkBlue);
static const char noStyle[] = "\033[0m";

QString coloredPattern()
{
    return QString(patternTemplate)
                .replace("COLOR_DEBUG",    debugStyle)
                .replace("COLOR_INFO",     infoStyle)
                .replace("COLOR_WARNING",  warningStyle)
                .replace("COLOR_CRITICAL", criticalStyle)
                .replace("COLOR_FATAL",    fatalStyle)
                .replace("COLOR_CATEGORY", categoryStyle)
                .replace("COLOR_FUNCTION", functionStyle)
                .replace("COLOR_NONE",     noStyle);
}

QString noColorPattern()
{
    return QString(patternTemplate)
        .replace("COLOR_DEBUG",    "")
        .replace("COLOR_INFO",     "")
        .replace("COLOR_WARNING",  "")
        .replace("COLOR_CRITICAL", "")
        .replace("COLOR_FATAL",    "")
        .replace("COLOR_CATEGORY", "")
        .replace("COLOR_FUNCTION", "")
        .replace("COLOR_NONE",     "");
}

static const QString colored = coloredPattern();
static const QString noColor = noColorPattern();

void messageHook(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (!sOriginalHandler)
    {
        return;
    }

    QFile logFile("./output.log");
    if(logFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qSetMessagePattern(noColor);
        QString logString = qFormatLogMessage(type, context, msg);
        qSetMessagePattern(colored);
        QTextStream stream(&logFile);
        stream << logString << "\r\n";
        logFile.close();
    }

    // Отключаем колоризацию для ссылок, включаем для части сообщения,
    // которая идёт после ссылки.
    auto refPos = msg.lastIndexOf(":/");
    if (refPos != -1)
    {
        auto spaceAfterRef = msg.indexOf(' ', refPos);
        auto substrNotColored = msg.mid(0, spaceAfterRef);
        auto substrColored = msg.mid(spaceAfterRef);

        QString color;
        switch (type)
        {
        case QtDebugMsg:
            color = debugStyle;
            break;
        case QtWarningMsg:
            color = warningStyle;
            break;
        case QtCriticalMsg:
            color = criticalStyle;
            break;
        case QtFatalMsg:
            color = fatalStyle;
            break;
        case QtInfoMsg:
            color = infoStyle;
            break;
        }

        qSetMessagePattern(noColor);
        sOriginalHandler(type, context, substrNotColored + color + substrColored + noStyle);
        qSetMessagePattern(colored);
    }
    else
    {
        sOriginalHandler(type, context, msg);
    }
}

void Tools::formatLogging()
{
    qSetMessagePattern(coloredPattern());
    sOriginalHandler = qInstallMessageHandler(messageHook);
}
