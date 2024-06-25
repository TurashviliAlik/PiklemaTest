#ifndef TOOLS_MACROS_H
#define TOOLS_MACROS_H

#include <QObject>

namespace Tools {

template<typename Ob, typename Func, typename... Args>
static auto safeCall(Ob* const ob, Func func, Args&&... args)
{
    auto funcBind = std::bind(func, ob, std::forward<Args>(args)...);
    auto lambda = [funcBind]{ funcBind(); };
    QMetaObject::invokeMethod(ob, std::move(lambda));
}

template<typename Ob, typename Func>
static auto safeCall(Ob* const ob, Func func)
{
    auto funcBind = std::bind(func, ob);
    auto lambda = [funcBind]{ funcBind(); };
    QMetaObject::invokeMethod(ob, std::move(lambda));
}

}

#endif // TOOLS_MACROS_H
