#include "FlipX24.hpp"

namespace cocosTween24
{
FlipX24Ptr FlipX24::create(cocos2d::Node *target, bool x){
    return std::move(std::make_shared<FlipX24>(target, x));
}

FlipX24::FlipX24(cocos2d::Node *target, bool x) : Player24(this, target), _flipX(x) {
}

cocos2d::ActionInterval *FlipX24::generateAction(){
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::FlipX::create(_flipX));
}

} // namespace
