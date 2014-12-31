#include "Sequence24.h"

using namespace cocosTween24;
USING_NS_CC;

Sequence24Ptr Sequence24::create(Node *target)
{
    auto s24 = new Sequence24(target);
    auto sp = std::shared_ptr<Sequence24>(s24);
    
    return std::move(sp);
}

Sequence24::Sequence24(Node *target) : _target(target)
{
}

Sequence24::~Sequence24()
{
}

FiniteTimeAction *Sequence24::getAction()
{
    Vector<FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->getAction());
    }

    return Sequence::create(actions);
}

void Sequence24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);
}

void Sequence24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

Sequence24Ptr Sequence24::addTween(ITween24Ptr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

Sequence24Ptr Sequence24::addTweens(const std::vector<ITween24Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTween(tween);
    }

    return shared_from_this();
}

