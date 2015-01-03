#include "Action24.hpp"

namespace cocosTween24
{
Action24Ptr Action24::create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
{
    auto a24 = std::make_shared<Action24>(target, action);

    return std::move(a24);
}

Action24::Action24(cocos2d::Node *target, cocos2d::FiniteTimeAction *action) : Player24(this, target), _action(action) {}

cocos2d::ActionInterval *Action24::getAction()
{
    return cocos2d::TargetedAction::create(getTarget(), _action);
}
} // namespace
