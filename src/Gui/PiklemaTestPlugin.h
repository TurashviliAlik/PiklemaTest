#ifndef GUI_PIKLEMATESTPLUGIN_H
#define GUI_PIKLEMATESTPLUGIN_H

#include <QQmlEngineExtensionPlugin>
#include <QQmlEngine>
#include <QDebug>
#include <QFileInfo>
#include <QQuickStyle>

namespace GuiPlugin {

class PiklemaTestPlugin : public QQmlEngineExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
    PiklemaTestPlugin(QObject* parent = Q_NULLPTR) : QQmlEngineExtensionPlugin(parent)
    {
    }

public:
    void initializeEngine(QQmlEngine* engine Q_DECL_UNUSED, const char* uri Q_DECL_UNUSED) override
    {
        engine->addImportPath(":/");
        engine->addImportPath(":/PiklemaTest/");
        qDebug() << "PiklemaTestPlugin initialized";
    }
};

}

#endif // GUI_PIKLEMATESTPLUGIN
