#include "FlipX23.hpp"

namespace cocosTween23
{
FlipX23Ptr FlipX23::create(cocos2d::Node *target, bool x)
{
    return std::move(std::make_shared<FlipX23>(target, x));
}

FlipX23::FlipX23(cocos2d::Node *target, bool x) : Player23(this, target), _flipX(x) {}

cocos2d::ActionInterval *FlipX23::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::FlipX::create(_flipX));
}
} // namespace
