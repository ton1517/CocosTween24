#include "Player.hpp"

namespace tweencc
{
Player::Player(IAction *tweener, cocos2d::Node *target) : _tweener(tweener), _target(target) {}

void Player::play()
{
    _playingAction = _tweener->generateAction();
    _target->runAction(_playingAction);
}

void Player::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

cocos2d::Node *Player::getTarget()
{
    return _target;
}
} // namespace
