#include "TweenCC.hpp"

namespace tweencc
{
#pragma mark tween

TweenPtr tween(cocos2d::Node *target, float duration, Ease easing)
{
    auto t = Tween::create(target, duration, easing);

    return std::move(t);
}

#pragma mark prop

PropPtr prop(cocos2d::Node *target)
{
    auto p = Prop::create(target);

    return std::move(p);
}

#pragma mark sequence

SequencePtr sequence(cocos2d::Node *target, const std::vector<IFiniteTimePtr> &tweens)
{
    auto s = Sequence::create(target);
    s->addTweens(tweens);

    return std::move(s);
}

IIntervalPtr sequence(const std::vector<IFiniteTimePtr> &tweens)
{
    return std::move(sequence(nullptr, tweens));
}

#pragma mark spawn

SpawnPtr spawn(cocos2d::Node *target, const std::vector<IFiniteTimePtr> &tweens)
{
    auto s = Spawn::create(target);
    s->addTweens(tweens);

    return std::move(s);
}

IIntervalPtr spawn(const std::vector<IFiniteTimePtr> &tweens)
{
    return std::move(spawn(nullptr, tweens));
}

#pragma mark repeat

RepeatPtr repeat(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween)
{
    auto r = Repeat::create(target, times, tween);

    return std::move(r);
}

IIntervalPtr repeat(unsigned int times, IFiniteTimePtr tween)
{
    return std::move(repeat(nullptr, times, tween));
}

RepeatPtr repeat(cocos2d::Node *target, unsigned int times, const std::vector<IFiniteTimePtr> &tweens)
{
    auto s = sequence(target, tweens);
    auto r = Repeat::create(target, times, std::move(s));

    return std::move(r);
}

IIntervalPtr repeat(unsigned int times, const std::vector<IFiniteTimePtr> &tweens)
{
    return std::move(repeat(nullptr, times, tweens));
}

#pragma mark repeat forever

RepeatForeverPtr repeatForever(cocos2d::Node *target, IIntervalPtr tween)
{
    auto r = RepeatForever::create(target, tween);

    return std::move(r);
}

RepeatForeverPtr repeatForever(cocos2d::Node *target, const std::vector<IFiniteTimePtr> &tweens)
{
    auto s = sequence(target, tweens);
    auto r = RepeatForever::create(target, std::move(s));

    return std::move(r);
}

#pragma mark lag

LagPtr lag(cocos2d::Node *target, float waitTime, const std::vector<IFiniteTimePtr> &tweens)
{
    auto l = Lag::create(target, waitTime);
    l->addTweens(tweens);

    return std::move(l);
}

IIntervalPtr lag(float waitTime, const std::vector<IFiniteTimePtr> &tweens)
{
    return std::move(lag(nullptr, waitTime, tweens));
}

#pragma mark wait

WaitPtr wait(float waitTime)
{
    return std::move(Wait::create(waitTime));
}

#pragma mark func

FuncPtr func(const std::function<void()> &func)
{
    return std::move(Func::create(func));
}

#pragma mark action

ActionPtr action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
{
    return std::move(Action::create(target, action));
}

#pragma mark remove

RemovePtr remove(cocos2d::Node *target)
{
    return std::move(Remove::create(target));
}

#pragma mark place

PlacePtr place(cocos2d::Node *target, const cocos2d::Vec2 &pos)
{
    return std::move(Place::create(target, pos));
}

#pragma mark flip

FlipXPtr flipX(cocos2d::Node *target, bool x)
{
    return std::move(FlipX::create(target, x));
}

FlipYPtr flipY(cocos2d::Node *target, bool y)
{
    return std::move(FlipY::create(target, y));
}
} // namespace
