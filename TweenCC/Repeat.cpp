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
    cocos2d::ActionInterval *action = cocos2d::Repeat::create(_tween->generateAction(), _times);

    auto target = getTarget();
    if (target) {
        action = cocos2d::TargetedAction::create(target, action);
    }

    return action;
}
} // namespace
