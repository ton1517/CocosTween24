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
    cocos2d::FiniteTimeAction *action = generateActionWithoutTarget();

    auto target = getTarget();
    if (target) {
        action = cocos2d::TargetedAction::create(target, action);
    }

    return action;
}

cocos2d::FiniteTimeAction *Action::generateActionWithoutTarget()
{
    return _action->clone();
}
} // namespace
