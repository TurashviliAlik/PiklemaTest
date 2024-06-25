#ifndef MODEL_MODELPLUGIN_H
#define MODEL_MODELPLUGIN_H

#include <QQmlEngineExtensionPlugin>
#include <QQmlEngine>
#include <QDebug>
#include <QFileInfo>

namespace ModelPlugin {

class ModelPlugin : public QQmlEngineExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
    ModelPlugin(QObject* parent = Q_NULLPTR) : QQmlEngineExtensionPlugin(parent)
    {}

public:
    void initializeEngine(QQmlEngine* engine Q_DECL_UNUSED, const char* uri Q_DECL_UNUSED) override
    {
        qDebug() << "ModelPlugin initialized";
    }
};

}

#endif // MODEL_MODELPLUGIN_H
