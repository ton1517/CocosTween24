#include "ToggleVisibility23.hpp"

namespace cocosTween23
{
ToggleVisibility23Ptr ToggleVisibility23::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<ToggleVisibility23>(target));
}

ToggleVisibility23::ToggleVisibility23(cocos2d::Node *target) : Player23(this, target) {}

cocos2d::ActionInterval *ToggleVisibility23::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::ToggleVisibility::create());
}
} // namespace
