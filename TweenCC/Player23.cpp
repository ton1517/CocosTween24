#include "Player23.hpp"

namespace tween23
{
Player23::Player23(IAction23 *tweener, cocos2d::Node *target) : _tweener(tweener), _target(target) {}

void Player23::play()
{
    _playingAction = _tweener->generateAction();
    _target->runAction(_playingAction);
}

void Player23::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

cocos2d::Node *Player23::getTarget()
{
    return _target;
}
} // namespace
