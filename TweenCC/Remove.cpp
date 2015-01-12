#include "Remove.hpp"

namespace tweencc
{
RemovePtr Remove::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<Remove>(target));
}

Remove::Remove(cocos2d::Node *target) : Player(this, target) {}

cocos2d::ActionInterval *Remove::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::RemoveSelf::create());
}
} // namespace
