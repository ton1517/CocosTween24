#include "ToggleVisibility24.hpp"

namespace cocosTween24
{
ToggleVisibility24Ptr ToggleVisibility24::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<ToggleVisibility24>(target));
}

ToggleVisibility24::ToggleVisibility24(cocos2d::Node *target) : Player24(this, target) {}

cocos2d::ActionInterval *ToggleVisibility24::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::ToggleVisibility::create());
}
} // namespace
