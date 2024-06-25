#include <QDebug>

#include "Controller.h"
#include "Model.h"

using namespace Core;

Controller::Controller(QObject* parent) : QObject(parent)
{
    qDebug() << "Controller создан";
}

Controller::~Controller()
{
    m_mqttModuleThread.quit();
    m_mqttModuleThread.wait();

    qDebug() << "Controller удален";
}

void Controller::init()
{
    _createMqttModule();

    QObject::connect(this, &Controller::publish, m_mqttModule, &MqttModuleLibrary::IMqttModule::publish);
    qDebug() << "Controller инициализирован";
}

bool Controller::_createMqttModule()
{
    m_mqttModule = MqttModuleLibrary::IMqttModule::create();
    m_mqttModule->moveToThread(&m_mqttModuleThread);
    QObject::connect(&m_mqttModuleThread, &QThread::finished, m_mqttModule, &QObject::deleteLater);
    QObject::connect(&m_mqttModuleThread, &QThread::started, m_mqttModule, &MqttModuleLibrary::IMqttModule::activate);
    m_mqttModuleThread.start();
    return true;
}
