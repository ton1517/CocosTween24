#include "Action.hpp"

namespace tweencc
{
ActionPtr Action::create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
{
    auto a = std::make_shared<Action>(target, action);

    return std::move(a);
}

Action::Action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action) : Player(this, target), _action(action) {}

cocos2d::ActionInterval *Action::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), _action->clone());
}
} // namespace
