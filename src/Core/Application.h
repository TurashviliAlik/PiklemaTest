#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>

namespace Core
{

class Application : public QGuiApplication
{
    Q_OBJECT

public:
    explicit Application(qint32 argc, char *argv[]);
    ~Application();

private:
    QQmlApplicationEngine m_engine;
    QThread m_controllerThread;
    QObject* m_model;
};

}

#endif // CORE_APPLICATION_H
