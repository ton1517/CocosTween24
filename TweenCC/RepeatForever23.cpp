#include "RepeatForever23.hpp"

namespace tween23
{
RepeatForever23Ptr RepeatForever23::create(cocos2d::Node *target, IInterval23Ptr tween)
{
    auto r23 = std::make_shared<RepeatForever23>(target, tween);

    return std::move(r23);
}

RepeatForever23::RepeatForever23(cocos2d::Node *target, IInterval23Ptr tween) : Player23(this, target), _tween(tween) {}

cocos2d::ActionInterval *RepeatForever23::generateAction()
{
    auto action = _tween->generateAction();

    return cocos2d::RepeatForever::create(action);
}
} // namespace
