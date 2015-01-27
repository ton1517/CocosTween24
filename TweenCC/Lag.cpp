#include "Lag.hpp"
#include "Wait.hpp"

namespace tweencc
{
LagPtr Lag::create(cocos2d::Node *target, float waitTime)
{
    auto s = std::make_shared<Lag>(target, waitTime);

    return std::move(s);
}

Lag::Lag(cocos2d::Node *target, float waitTime) : Player(this, target), _waitTime(waitTime) {}

cocos2d::ActionInterval *Lag::generateAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->generateAction());
    }

    cocos2d::ActionInterval *action = cocos2d::Sequence::create(actions);

    auto target = getTarget();
    if (target) {
        action = cocos2d::TargetedAction::create(target, action);
    }

    return action;
}

LagPtr Lag::addTweens(IFiniteTimePtr tween)
{
    if (_tweens.size() > 0) {
        _tweens.push_back(Wait::create(_waitTime));
    }
    _tweens.push_back(tween);

    return shared_from_this();
}

LagPtr Lag::addTweens(const std::vector<IFiniteTimePtr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace
