#include "Prop.hpp"

namespace tweencc
{
#pragma mark----- static -----

PropPtr Prop::create(cocos2d::Node *target)
{
    auto t = std::make_shared<Prop>(target);

    return std::move(t);
}

#pragma mark----- public -----

Prop::Prop(cocos2d::Node *target) : Player(this, target) {}

cocos2d::ActionInterval *Prop::generateAction()
{
    cocos2d::ActionInterval *action         = cocos2d::Spawn::create(_actions);
    auto                     targetedAction = cocos2d::TargetedAction::create(getTarget(), action);

    return targetedAction;
}
} // namespace
