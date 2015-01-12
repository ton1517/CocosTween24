#include "Visible.hpp"

namespace tweencc
{
VisiblePtr Visible::create(cocos2d::Node *target, bool visible)
{
    auto v = std::make_shared<Visible>(target, visible);

    return std::move(v);
}

Visible::Visible(cocos2d::Node *target, bool visible) : Player(this, target), _visible(visible) {}

cocos2d::ActionInterval *Visible::generateAction()
{
    cocos2d::ActionInstant *action;
    if (_visible) {
        action = cocos2d::Show::create();
    } else {
        action = cocos2d::Hide::create();
    }

    return cocos2d::TargetedAction::create(getTarget(), action);
}
} // namespace
