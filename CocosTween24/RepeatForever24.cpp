#include "RepeatForever24.hpp"

namespace cocosTween24
{
RepeatForever24Ptr RepeatForever24::create(cocos2d::Node *target, IInterval24Ptr tween)
{
    auto r24 = std::make_shared<RepeatForever24>(target, tween);

    return std::move(r24);
}

RepeatForever24::RepeatForever24(cocos2d::Node *target, IInterval24Ptr tween) : Player24(this, target), _tween(tween) {}

cocos2d::ActionInterval *RepeatForever24::generateAction()
{
    auto action = _tween->generateAction();

    return cocos2d::RepeatForever::create(action);
}
} // namespace
