#include "Lag23.hpp"
#include "Wait23.hpp"

namespace cocosTween23
{
Lag23Ptr Lag23::create(cocos2d::Node *target, float waitTime)
{
    auto s23 = std::make_shared<Lag23>(target, waitTime);

    return std::move(s23);
}

Lag23::Lag23(cocos2d::Node *target, float waitTime) : Player23(this, target), _waitTime(waitTime) {}

cocos2d::ActionInterval *Lag23::generateAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->generateAction());
    }

    return cocos2d::Sequence::create(actions);
}

Lag23Ptr Lag23::addTweens(IFiniteTime23Ptr tween)
{
    if (_tweens.size() > 0) {
        _tweens.push_back(Wait23::create(_waitTime));
    }
    _tweens.push_back(tween);

    return shared_from_this();
}

Lag23Ptr Lag23::addTweens(const std::vector<IFiniteTime23Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace
