#include "Spawn23.hpp"

namespace cocosTween23
{
Spawn23Ptr Spawn23::create(cocos2d::Node *target)
{
    auto s23 = std::make_shared<Spawn23>(target);

    return std::move(s23);
}

Spawn23::Spawn23(cocos2d::Node *target) : Player23(this, target) {}

cocos2d::ActionInterval *Spawn23::generateAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->generateAction());
    }

    return cocos2d::Spawn::create(actions);
}

Spawn23Ptr Spawn23::addTweens(IFiniteTime23Ptr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

Spawn23Ptr Spawn23::addTweens(const std::vector<IFiniteTime23Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace