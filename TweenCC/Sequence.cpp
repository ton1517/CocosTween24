#include "Sequence.hpp"

namespace tweencc
{
SequencePtr Sequence::create(cocos2d::Node *target)
{
    auto s = std::make_shared<Sequence>(target);

    return std::move(s);
}

Sequence::Sequence(cocos2d::Node *target) : Player(this, target) {}

cocos2d::ActionInterval *Sequence::generateAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->generateAction());
    }

    return cocos2d::Sequence::create(actions);
}

SequencePtr Sequence::addTweens(IFiniteTimePtr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

SequencePtr Sequence::addTweens(const std::vector<IFiniteTimePtr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace
