#include "Place23.hpp"

namespace cocosTween23
{
Place23Ptr Place23::create(cocos2d::Node *target, const cocos2d::Vec2 &pos)
{
    return std::move(std::make_shared<Place23>(target, pos));
}

Place23::Place23(cocos2d::Node *target, const cocos2d::Vec2 &pos) : Player23(this, target), _pos(pos) {}

cocos2d::ActionInterval *Place23::generateAction()
{
    return cocos2d::TargetedAction::create(getTarget(), cocos2d::Place::create(_pos));
}
} // namespace
