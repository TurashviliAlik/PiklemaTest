#include "Application.h"
#include "LogFormatter.h"
#include <QDebug>

int main(int _argc, char *_argv[])
{
    Tools::formatLogging();
    Core::Application app Q_DECL_UNUSED(_argc, _argv);

    return QCoreApplication::exec();
}
