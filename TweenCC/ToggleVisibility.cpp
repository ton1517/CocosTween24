#include "ToggleVisibility.hpp"

namespace tweencc
{
ToggleVisibilityPtr ToggleVisibility::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<ToggleVisibility>(target));
}

ToggleVisibility::ToggleVisibility(cocos2d::Node *target) : Player(this, target) {}

cocos2d::ActionInterval *ToggleVisibility::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::ToggleVisibility::create());
}
} // namespace
