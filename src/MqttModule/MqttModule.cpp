#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include "MqttModule.h"
#include "Model.h"

using namespace MqttModuleLibrary;

IMqttModule* IMqttModule::create()
{
    return static_cast<IMqttModule*>(new MqttModule());
}

MqttModule::MqttModule()
{
    qDebug() << "MqttModule создан";
}

MqttModule::~MqttModule()
{
    qDebug() << "MqttModule удален";
}

void MqttModule::activate()
{
    ModelPlugin::Model* model = ModelPlugin::Model::instance();
    model->setStatus("Отключен");
    model->setErrorMessage("");
    qDebug() << "Модуль MqttModule активирован";
}

void MqttModule::publish()
{
    ModelPlugin::Model* model = ModelPlugin::Model::instance();
    model->setErrorMessage("");
    qInfo() << "Публикация в:" << model->host() + ":" + QString::number(model->port());
    qInfo() << "Пользователь:" << model->username() << model->password();
    qInfo() << "Из файла:" << model->filepath();

    QMqttClient* client = new QMqttClient(this);
    QObject::connect(client, &QMqttClient::stateChanged, client, [client, model](QMqttClient::ClientState state){
        if(state == QMqttClient::ClientState::Disconnected)
            model->setStatus("Disconnected");
        else if(state == QMqttClient::ClientState::Connected)
        {
            model->setStatus("Connected");
            QFile file(model->filepath().path());

            if(file.open(QIODevice::ReadOnly))
            {
                qDebug() << "Отправка в топик: " << model->topic();
                QTextStream stream(&file);
                stream.setCodec("UTF-8");
                while(!stream.atEnd())
                {
                    QString line = stream.readLine();
                    if(client->publish(QMqttTopicName(model->topic()), line.toUtf8()) != -1)
                    {
                        emit model->messageSent();
                        qInfo() << "Сообщение" << line << "отправлено в топик" << model->topic();
                    }
                    else
                        qWarning() << "Не удалось отправить сообщение:" << line;
                }
            }
            else
                model->setErrorMessage("Не удалось открыть файл");
        }
        else
            model->setStatus("Connecting");
    });
    QObject::connect(client, &QMqttClient::errorChanged, client, [client, model](QMqttClient::ClientError error){
        static const auto enumMeta = client->metaObject()->
                                 enumerator(client->metaObject()->indexOfEnumerator("ClientError"));
        model->setErrorMessage(enumMeta.valueToKey(error));
        client->disconnectFromHost();
    });
    QObject::connect(client, &QMqttClient::disconnected, client, &QObject::deleteLater);

    client->setHostname(model->host());
    client->setPort(1884);
    client->setUsername(model->username());
    client->setPassword(model->password());
    client->connectToHost();
}
