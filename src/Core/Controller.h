#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

#include <QObject>
#include <QThread>

#include "IMqttModule.h"

namespace Core
{

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject* parent = Q_NULLPTR);
    ~Controller();

public:
    void init();

signals:
    void publish();

private:
    bool _createMqttModule();

private:
    QThread m_mqttModuleThread;
    MqttModuleLibrary::IMqttModule* m_mqttModule = Q_NULLPTR;
};

}

#endif // CONTROLLER_H
