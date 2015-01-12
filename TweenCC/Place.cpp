#include "Place.hpp"

namespace tweencc
{
PlacePtr Place::create(cocos2d::Node *target, const cocos2d::Vec2 &pos)
{
    return std::move(std::make_shared<Place>(target, pos));
}

Place::Place(cocos2d::Node *target, const cocos2d::Vec2 &pos) : Player(this, target), _pos(pos) {}

cocos2d::ActionInterval *Place::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::Place::create(_pos));
}
} // namespace
