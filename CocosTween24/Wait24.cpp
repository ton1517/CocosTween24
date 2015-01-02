#include "Wait24.hpp"

namespace cocosTween24
{
Wait24Ptr Wait24::create(float waitTime)
{
    auto w24 = std::make_shared<Wait24>(waitTime);

    return std::move(w24);
}

Wait24::Wait24(float waitTime) : _waitTime(waitTime) {}

cocos2d::ActionInterval *Wait24::getAction()
{
    return cocos2d::DelayTime::create(_waitTime);
}
} // namespace