#include "FlipX.hpp"

namespace tweencc
{
FlipXPtr FlipX::create(cocos2d::Node *target, bool x)
{
    return std::move(std::make_shared<FlipX>(target, x));
}

FlipX::FlipX(cocos2d::Node *target, bool x) : Player(this, target), _flipX(x) {}

cocos2d::ActionInterval *FlipX::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::FlipX::create(_flipX));
}
} // namespace
