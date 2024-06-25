#ifndef MODELPLUGIN_MODEL_H
#define MODELPLUGIN_MODEL_H

#include <QObject>
#include <QtQml/qqml.h>

namespace ModelPlugin {

class Model : public QObject
{
    Q_OBJECT
    // Это нужно вынести в отдельный класс
    Q_PROPERTY(QString host READ host WRITE _setHost NOTIFY hostChanged RESET _unsetHost FINAL)
    Q_PROPERTY(qint32 port READ port WRITE _setPort NOTIFY portChanged RESET _unsetPort FINAL)
    Q_PROPERTY(QString username READ username WRITE _setUsername NOTIFY usernameChanged RESET _unsetUsername FINAL)
    Q_PROPERTY(QString password READ password WRITE _setPassword NOTIFY passwordChanged RESET _unsetPassword FINAL)
    Q_PROPERTY(QString topic READ topic WRITE _setTopic NOTIFY topicChanged RESET _unsetTopic FINAL)
    Q_PROPERTY(QUrl filepath READ filepath WRITE _setFilepath NOTIFY filepathChanged RESET _unsetFilepath FINAL)
    // Это нужно вынести в отдельный класс
    Q_PROPERTY(QString status READ status NOTIFY statusChanged FINAL)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged FINAL)
    // Это нужно вынести в отдельный класс
    Q_PROPERTY(qint32 messagesSentCount READ messagesSentCount NOTIFY messagesSentCountChanged FINAL)

    //QML_NAMED_ELEMENT(Model)
    //QML_SINGLETON

    Q_DISABLE_COPY_MOVE(Model)

public:
    static Model* instance();
    static Model* create(QQmlEngine*, QJSEngine*);

private:
    explicit Model(QObject* parent = Q_NULLPTR);
    ~Model();

public:
    QString host() const;
    qint32 port() const;
    QString username() const;
    QString password() const;
    QString topic() const;
    QUrl filepath() const;
    QString status() const;
    QString errorMessage() const;
    qint32 messagesSentCount() const;

public:
    void setStatus(const QString& newStatus);
    void setErrorMessage(const QString& newErrorMessage);

private:
    void _setHost(const QString& newHost);
    void _unsetHost();

    void _setPort(qint32 newPort);
    void _unsetPort();

    void _setUsername(const QString& newUsername);
    void _unsetUsername();

    void _setPassword(const QString& newPassword);
    void _unsetPassword();

    void _setTopic(const QString& newTopic);
    void _unsetTopic();

    void _setFilepath(const QUrl& newFilepath);
    void _unsetFilepath();

    void _setStatus(const QString& newStatus);
    void _setErrorMessage(const QString& newStatus);

    void _onMessageSent();

signals:
    void hostChanged();
    void portChanged();
    void usernameChanged();
    void passwordChanged();
    void topicChanged();
    void filepathChanged();
    void statusChanged();
    void errorMessageChanged();
    void messagesSentCountChanged();

signals:
    void messageSent();

private:
    QString m_host;
    qint32 m_port;
    QString m_username;
    QString m_password;
    QString m_topic;
    QUrl m_filepath;
    QString m_status;
    QString m_errorMessage;
    qint32 m_messagesSentCount;
};

}

#endif // MODELPLUGIN_MODEL_H
