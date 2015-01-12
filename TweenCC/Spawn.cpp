#include "Spawn.hpp"

namespace tweencc
{
SpawnPtr Spawn::create(cocos2d::Node *target)
{
    auto s = std::make_shared<Spawn>(target);

    return std::move(s);
}

Spawn::Spawn(cocos2d::Node *target) : Player(this, target) {}

cocos2d::ActionInterval *Spawn::generateAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->generateAction());
    }

    return cocos2d::Spawn::create(actions);
}

SpawnPtr Spawn::addTweens(IFiniteTimePtr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

SpawnPtr Spawn::addTweens(const std::vector<IFiniteTimePtr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace