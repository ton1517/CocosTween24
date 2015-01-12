#include "Wait.hpp"

namespace tweencc
{
WaitPtr Wait::create(float waitTime)
{
    auto w = std::make_shared<Wait>(waitTime);

    return std::move(w);
}

Wait::Wait(float waitTime) : _waitTime(waitTime) {}

cocos2d::ActionInterval *Wait::generateAction()
{
    return cocos2d::DelayTime::create(_waitTime);
}
} // namespace