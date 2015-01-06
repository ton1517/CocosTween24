#include "Place24.hpp"

namespace cocosTween24
{
Place24Ptr Place24::create(cocos2d::Node *target, const cocos2d::Vec2 &pos)
{
    return std::move(std::make_shared<Place24>(target, pos));
}

Place24::Place24(cocos2d::Node *target, const cocos2d::Vec2 &pos) : Player24(this, target), _pos(pos) {}

cocos2d::ActionInterval *Place24::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::Place::create(_pos));
}
} // namespace
