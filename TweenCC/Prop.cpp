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
    auto action         = cocos2d::Spawn::create(_actions);
    auto targetedAction = cocos2d::TargetedAction::create(getTarget(), action);

    return targetedAction;
}

#pragma mark visible

PropPtr Prop::visible(bool visible)
{
    cocos2d::ActionInstant *action;
    if (visible) {
        action = cocos2d::Show::create();
    } else {
        action = cocos2d::Hide::create();
    }
    addAction(action);

    return shared_from_this();
}

PropPtr Prop::toggleVisibility()
{
    auto action = cocos2d::ToggleVisibility::create();
    addAction(action);

    return shared_from_this();
}

#pragma mark flip

PropPtr Prop::flipX(bool x)
{
    auto action = cocos2d::FlipX::create(x);
    addAction(action);

    return shared_from_this();
}

#pragma mark----- private -----

void Prop::addAction(cocos2d::FiniteTimeAction *action)
{
    _actions.pushBack(action);
}
} // namespace
