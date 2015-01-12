#include "Repeat.hpp"

namespace tweencc
{
RepeatPtr Repeat::create(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween)
{
    auto r = std::make_shared<Repeat>(target, times, tween);

    return std::move(r);
}

Repeat::Repeat(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween) : Player(this, target), _times(times), _tween(tween)
{
}

cocos2d::ActionInterval *Repeat::generateAction()
{
    auto action = _tween->generateAction();

    return cocos2d::Repeat::create(action, _times);
}
} // namespace
