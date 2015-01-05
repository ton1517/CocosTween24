#include "Visible24.hpp"

namespace cocosTween24
{
Visible24Ptr Visible24::create(cocos2d::Node *target, bool visible)
{
    auto v24 = std::make_shared<Visible24>(target, visible);

    return std::move(v24);
}

Visible24::Visible24(cocos2d::Node *target, bool visible) : Player24(this, target), _visible(visible) {}

cocos2d::ActionInterval *Visible24::generateAction()
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
