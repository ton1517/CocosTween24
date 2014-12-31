#include "Spawn24.h"

using namespace cocosTween24;
USING_NS_CC;

Spawn24Ptr Spawn24::create(Node *target)
{
    auto s24 = std::make_shared<Spawn24>(target);

    return std::move(s24);
}

Spawn24::Spawn24(Node *target) : _target(target) {}
Spawn24::~Spawn24() {}

FiniteTimeAction *Spawn24::getAction()
{
    Vector<FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->getAction());
    }

    return TargetedAction::create(_target, Spawn::create(actions));
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

