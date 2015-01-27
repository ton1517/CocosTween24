#include "Action.hpp"

namespace tweencc
{
ActionPtr Action::create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
{
    auto a = std::make_shared<Action>(target, action);

    return std::move(a);
}

Action::Action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action) : Player(this, target), _action(action) {}

cocos2d::FiniteTimeAction *Action::generateAction()
{
    auto                       target = getTarget();
    cocos2d::FiniteTimeAction *action = _action->clone();

    if (target) {
        action = cocos2d::TargetedAction::create(target, action);
    }

    return action;
}
} // namespace
