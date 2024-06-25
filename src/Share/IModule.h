#ifndef IMODULE_H
#define IMODULE_H

/****************************************************************************
**
** Базовый класс для всех интерфейсов модулей
**
****************************************************************************/

#include <QObject>

class IModule : public QObject
{
    Q_OBJECT

public:
    virtual ~IModule() = default;

protected:
    IModule() = default;

private:
    Q_DISABLE_COPY_MOVE(IModule)

public slots:
    virtual void activate() = 0;
};

#endif // IMODULE_H
