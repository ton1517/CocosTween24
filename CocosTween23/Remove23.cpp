#include "Remove23.hpp"

namespace cocosTween23
{
Remove23Ptr Remove23::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<Remove23>(target));
}

Remove23::Remove23(cocos2d::Node *target) : Player23(this, target) {}

cocos2d::ActionInterval *Remove23::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::RemoveSelf::create());
}
} // namespace
