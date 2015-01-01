#include "Repeat24.hpp"

namespace cocosTween24
{
Repeat24Ptr Repeat24::create(cocos2d::Node *target, unsigned int times, ITween24Ptr tween)
{
    auto r24 = std::make_shared<Repeat24>(target, times, tween);

    return std::move(r24);
}

Repeat24::Repeat24(cocos2d::Node *target, unsigned int times, ITween24Ptr tween) : _target(target), _times(times), _tween(tween)
{
}

Repeat24::~Repeat24() {}

cocos2d::ActionInterval *Repeat24::getAction()
{
    auto action = _tween->getAction();
    if (_times == 0) {
        return cocos2d::RepeatForever::create(action);
    }

    return cocos2d::Repeat::create(action, _times);
}

void Repeat24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);
}

void Repeat24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}
} // namespace
