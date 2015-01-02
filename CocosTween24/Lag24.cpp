#include "Lag24.hpp"
#include "Wait24.hpp"

namespace cocosTween24
{
Lag24Ptr Lag24::create(cocos2d::Node *target, float waitTime)
{
    auto s24 = std::make_shared<Lag24>(target, waitTime);

    return std::move(s24);
}

Lag24::Lag24(cocos2d::Node *target, float waitTime) : Player24(this, target), _waitTime(waitTime) {}

cocos2d::ActionInterval *Lag24::getAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->getAction());
    }

    return cocos2d::Sequence::create(actions);
}

Lag24Ptr Lag24::addTweens(IInterval24Ptr tween)
{
    if (_tweens.size() > 0) {
        _tweens.push_back(Wait24::create(_waitTime));
    }
    _tweens.push_back(tween);

    return shared_from_this();
}

Lag24Ptr Lag24::addTweens(const std::vector<IInterval24Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace
