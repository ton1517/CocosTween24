#include "Sequence23.hpp"

namespace tween23
{
Sequence23Ptr Sequence23::create(cocos2d::Node *target)
{
    auto s23 = std::make_shared<Sequence23>(target);

    return std::move(s23);
}

Sequence23::Sequence23(cocos2d::Node *target) : Player23(this, target) {}

cocos2d::ActionInterval *Sequence23::generateAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->generateAction());
    }

    return cocos2d::Sequence::create(actions);
}

Sequence23Ptr Sequence23::addTweens(IFiniteTime23Ptr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

Sequence23Ptr Sequence23::addTweens(const std::vector<IFiniteTime23Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace
