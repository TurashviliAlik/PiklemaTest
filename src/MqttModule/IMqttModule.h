#ifndef MQTTMODULELIBRARY_IMQTTMODULE_H
#define MQTTMODULELIBRARY_IMQTTMODULE_H

#include "IModule.h"

namespace MqttModuleLibrary
{

class IMqttModule : public IModule
{
    Q_OBJECT

protected:
    ~IMqttModule() = default;

public:
    static IMqttModule* create();

public slots:
    virtual void publish() = 0;
};

}

#endif // MQTTMODULELIBRARY_IMQTTMODULE_H
