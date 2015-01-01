#include "Spawn24.hpp"

namespace cocosTween24
{
Spawn24Ptr Spawn24::create(cocos2d::Node *target)
{
    auto s24 = std::make_shared<Spawn24>(target);

    return std::move(s24);
}

Spawn24::Spawn24(cocos2d::Node *target) : _target(target) {}
Spawn24::~Spawn24() {}

cocos2d::ActionInterval *Spawn24::getAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->getAction());
    }

    return cocos2d::TargetedAction::create(_target, cocos2d::Spawn::create(actions));
}

void Spawn24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);
}

void Spawn24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

Spawn24Ptr Spawn24::addTween(ITween24Ptr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

Spawn24Ptr Spawn24::addTweens(const std::vector<ITween24Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTween(tween);
    }

    return shared_from_this();
}
} // namespace