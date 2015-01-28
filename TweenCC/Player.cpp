#include "Player.hpp"

namespace tweencc
{
Player::Player(IAction *tweener, cocos2d::Node *target) : _tweener(tweener), _targets({target}) {}
Player::Player(IAction *tweener, const std::vector<cocos2d::Node *> &targets) : _tweener(tweener), _targets(targets) {}

void Player::play()
{
    for (int i = 0; i < _targets.size(); i++) {
        auto target = _targets[i];
        auto action = _tweener->generateAction();
        target->runAction(action);

        _playingActions.push_back(action);
    }
}

void Player::stop()
{
    for (int i = 0; i < _playingActions.size(); i++) {
        auto target = _targets[i];
        auto action = _playingActions[i];
        if (action && !action->isDone()) {
            target->stopAction(action);
        }
    }
}

cocos2d::Node *Player::getTarget()
{
    return _targets[0];
}

std::vector<cocos2d::Node *> Player::getTargets()
{
    return _targets;
}
} // namespace
