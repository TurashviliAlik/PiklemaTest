#include <QThread>
#include <QQmlContext>

#include "Application.h"
#include "Controller.h"

// #include "mrt_model.h"
// #include <QFileInfo>
// #include "DebuggerObject.h"
#include <QFileInfo>
#include <Model.h>
using namespace Core;

Application::Application(qint32 argc, char *argv[]) : QGuiApplication(argc, argv)
{
    m_engine.addImportPath("qml");

    Controller* controller = new Controller();
    controller->moveToThread(&m_controllerThread);
    QObject::connect(&m_controllerThread, &QThread::started, controller, &Controller::init);
    QObject::connect(&m_controllerThread, &QThread::finished, controller, &QObject::deleteLater);
    m_controllerThread.start();

    qmlRegisterSingletonInstance("PiklemaTest.ModelInstance", 1, 0, "Model", ModelPlugin::Model::instance());

    const QUrl url("qrc:/main.qml");
    QObject::connect(&m_engine, &QQmlApplicationEngine::objectCreated, this, [url](QObject *object, const QUrl &objUrl)
        { if(objUrl == url && !object) QCoreApplication::exit(EXIT_FAILURE); }, Qt::QueuedConnection);
    m_engine.rootContext()->setContextProperty("Controller", controller);
    m_engine.load(url);

    qDebug() << "Старт Application";
}

Application::~Application()
{
    qDebug() << "Завершение Application";
    m_controllerThread.quit();
    m_controllerThread.wait(1000);
}
