#ifndef MQTTMODULELIBRARY_MQTTMODULE_H
#define MQTTMODULELIBRARY_MQTTMODULE_H

#include <QObject>

#include "IMqttModule.h"

#include <QtMqtt/QtMqtt>

namespace MqttModuleLibrary
{

class MqttModule : public IMqttModule
{
    Q_OBJECT

    friend IMqttModule* IMqttModule::create();

private:
    MqttModule();
    ~MqttModule();

public slots:
    void activate() override;
    void publish() override;
};

}

#endif // MQTTMODULELIBRARY_MQTTMODULE_H
