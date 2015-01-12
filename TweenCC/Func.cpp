#include "Func.hpp"

namespace tweencc
{
FuncPtr Func::create(const std::function<void()> &func)
{
    auto f = std::make_shared<Func>(func);

    return std::move(f);
}

Func::Func(const std::function<void()> &func) : _func(func) {}

cocos2d::ActionInstant *Func::generateAction()
{
    return cocos2d::CallFunc::create(_func);
}
} // namespaces
