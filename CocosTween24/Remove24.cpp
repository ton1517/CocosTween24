#include "Remove24.hpp"

namespace cocosTween24
{
Remove24Ptr Remove24::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<Remove24>(target));
}

Remove24::Remove24(cocos2d::Node *target) : Player24(this, target) {}

cocos2d::ActionInterval *Remove24::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::RemoveSelf::create());
}
} // namespace
