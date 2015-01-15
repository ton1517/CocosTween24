#include "FlipY.hpp"

namespace tweencc
{
FlipYPtr FlipY::create(cocos2d::Node *target, bool y)
{
    return std::move(std::make_shared<FlipY>(target, y));
}

FlipY::FlipY(cocos2d::Node *target, bool y) : Player(this, target), _flipY(y) {}

cocos2d::ActionInterval *FlipY::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::FlipY::create(_flipY));
}
} // namespace
