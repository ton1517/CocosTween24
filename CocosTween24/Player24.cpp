#include "Player24.hpp"

namespace cocosTween24
{
Player24::Player24(cocos2d::Node *target) : _target(target) {}
Player24::~Player24() {}

void Player24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);
}

void Player24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

cocos2d::Node *Player24::getTarget()
{
    return _target;
}
} // namespace
