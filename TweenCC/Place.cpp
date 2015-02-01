#include "Place.hpp"

namespace tweencc
{
PlacePtr Place::create(cocos2d::Node *target, const cocos2d::Vec2 &pos)
{
    return std::move(std::make_shared<Place>(target, pos));
}

Place::Place(cocos2d::Node *target, const cocos2d::Vec2 &pos) : Player(this, target), _pos(pos) {}

cocos2d::FiniteTimeAction *Place::generateAction()
{
    cocos2d::FiniteTimeAction *action = generateActionWithoutTarget();

    auto target = getTarget();
    if (target) {
        action = cocos2d::TargetedAction::create(target, action);
    }

    return action;
}

cocos2d::FiniteTimeAction *Place::generateActionWithoutTarget()
{
    return cocos2d::Place::create(_pos);
}
} // namespace
