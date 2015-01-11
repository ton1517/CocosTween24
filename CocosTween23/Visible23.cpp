#include "Visible23.hpp"

namespace cocosTween23
{
Visible23Ptr Visible23::create(cocos2d::Node *target, bool visible)
{
    auto v23 = std::make_shared<Visible23>(target, visible);

    return std::move(v23);
}

Visible23::Visible23(cocos2d::Node *target, bool visible) : Player23(this, target), _visible(visible) {}

cocos2d::ActionInterval *Visible23::generateAction()
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
