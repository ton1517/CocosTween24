#include "Func24.hpp"

namespace cocosTween24
{
Func24Ptr Func24::create(const std::function<void()> &func)
{
    auto f24 = std::make_shared<Func24>(func);

    return std::move(f24);
}

Func24::Func24(const std::function<void()> &func) : _func(func) {}

cocos2d::ActionInstant *Func24::generateAction()
{
    return cocos2d::CallFunc::create(_func);
}
} // namespaces
