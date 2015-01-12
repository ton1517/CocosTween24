#include "Func23.hpp"

namespace tween23
{
Func23Ptr Func23::create(const std::function<void()> &func)
{
    auto f23 = std::make_shared<Func23>(func);

    return std::move(f23);
}

Func23::Func23(const std::function<void()> &func) : _func(func) {}

cocos2d::ActionInstant *Func23::generateAction()
{
    return cocos2d::CallFunc::create(_func);
}
} // namespaces
