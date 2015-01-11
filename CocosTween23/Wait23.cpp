#include "Wait23.hpp"

namespace tween23
{
Wait23Ptr Wait23::create(float waitTime)
{
    auto w23 = std::make_shared<Wait23>(waitTime);

    return std::move(w23);
}

Wait23::Wait23(float waitTime) : _waitTime(waitTime) {}

cocos2d::ActionInterval *Wait23::generateAction()
{
    return cocos2d::DelayTime::create(_waitTime);
}
} // namespace