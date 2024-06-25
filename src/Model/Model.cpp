#include <QGuiApplication>

#include "Model.h"
#include "Macros.h"

using namespace ModelPlugin;

Model* Model::instance()
{
    static Model* model = new Model();
    return model;
}

Model* Model::create(QQmlEngine*, QJSEngine*)
{
    return instance();
}

Model::Model(QObject* parent):QObject(parent)
{
    if(qApp->thread() != thread())
    {
        moveToThread(qApp->thread());
    }
    _unsetHost();
    _unsetPort();
    _unsetUsername();
    _unsetPassword();
    _unsetTopic();
    _unsetFilepath();
    m_messagesSentCount = 0;

    QObject::connect(this, &Model::messageSent, this, &Model::_onMessageSent);

    qDebug() << "Model создан";
}

Model::~Model()
{
    qDebug() << "Model удален";
}

QString Model::host() const
{
    return m_host;
}

void Model::_setHost(const QString& newHost)
{
    if (m_host == newHost)
        return;
    m_host = newHost;
    emit hostChanged();
}

void Model::_unsetHost()
{
    _setHost("test.mosquitto.org");
}

qint32 Model::port() const
{
    return m_port;
}

void Model::_setPort(qint32 newPort)
{
    if (m_port == newPort)
        return;
    m_port = newPort;
    emit portChanged();
}

void Model::_unsetPort()
{
    _setPort(1884);
}

QString Model::username() const
{
    return m_username;
}

void Model::_setUsername(const QString& newUsername)
{
    if (m_username == newUsername)
        return;
    m_username = newUsername;
    emit usernameChanged();
}

void Model::_unsetUsername()
{
    _setUsername("rw");
}

QString Model::password() const
{
    return m_password;
}

void Model::_setPassword(const QString& newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}

void Model::_unsetPassword()
{
    _setPassword("readwrite");
}

QString Model::topic() const
{
    return m_topic;
}

void Model::_setTopic(const QString& newTopic)
{
    if (m_topic == newTopic)
        return;
    m_topic = newTopic;
    emit topicChanged();
}

void Model::_unsetTopic()
{
    _setTopic("piklema/test");
}

QUrl Model::filepath() const
{
    return m_filepath;
}

void Model::_setFilepath(const QUrl& newFilepath)
{
    if (m_filepath == newFilepath)
        return;
    m_filepath = newFilepath;
    emit filepathChanged();
}

void Model::_unsetFilepath()
{
    _setFilepath(QUrl());
}

QString Model::status() const
{
    return m_status;
}

void Model::_setStatus(const QString& newStatus)
{
    if (m_status == newStatus)
        return;
    m_status = newStatus;
    emit statusChanged();
}

void Model::_setErrorMessage(const QString& newErrorMessage)
{
    if (m_errorMessage == newErrorMessage)
        return;
    m_errorMessage = newErrorMessage;
    emit errorMessageChanged();
}

QString Model::errorMessage() const
{
    return m_errorMessage;
}

qint32 Model::messagesSentCount() const
{
    return m_messagesSentCount;
}

void Model::setStatus(const QString& newStatus)
{
    Tools::safeCall(this, &Model::_setStatus, newStatus);
}

void Model::setErrorMessage(const QString& newErrorMessage)
{
    Tools::safeCall(this, &Model::_setErrorMessage, newErrorMessage);
}

void Model::_onMessageSent()
{
    m_messagesSentCount += 1;
    emit messagesSentCountChanged();
}
