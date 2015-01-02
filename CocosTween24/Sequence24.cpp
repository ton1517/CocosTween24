#include "Sequence24.hpp"

namespace cocosTween24
{
Sequence24Ptr Sequence24::create(cocos2d::Node *target)
{
    auto s24 = std::make_shared<Sequence24>(target);

    return std::move(s24);
}

Sequence24::Sequence24(cocos2d::Node *target) : Player24(this, target) {}

cocos2d::ActionInterval *Sequence24::getAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->getAction());
    }

    return cocos2d::Sequence::create(actions);
}

Sequence24Ptr Sequence24::addTweens(IInterval24Ptr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

Sequence24Ptr Sequence24::addTweens(const std::vector<IInterval24Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace
