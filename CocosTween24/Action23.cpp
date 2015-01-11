#include "Action23.hpp"

namespace cocosTween23
{
Action23Ptr Action23::create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
{
    auto a23 = std::make_shared<Action23>(target, action);

    return std::move(a23);
}

Action23::Action23(cocos2d::Node *target, cocos2d::FiniteTimeAction *action) : Player23(this, target), _action(action) {}

cocos2d::ActionInterval *Action23::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), _action->clone());
}
} // namespace
