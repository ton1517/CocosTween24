#ifndef __TweenCC__TweenCC__
#define __TweenCC__TweenCC__

#include <cocos2d.h>

#include "Tween.hpp"
#include "Ease.hpp"
#include "Sequence.hpp"
#include "Spawn.hpp"
#include "Repeat.hpp"
#include "RepeatForever.hpp"
#include "Lag.hpp"
#include "Wait.hpp"
#include "Func.hpp"
#include "Action.hpp"
#include "Visible.hpp"
#include "ToggleVisibility.hpp"
#include "Remove.hpp"
#include "Place.hpp"
#include "FlipX.hpp"

namespace tweencc
{
#pragma mark tween

TweenPtr tween(cocos2d::Node *target, float duration, Ease easing=Ease::Linear);

#pragma mark sequence

SequencePtr sequence(cocos2d::Node *target, const std::vector<IFiniteTimePtr> &tweens);
IIntervalPtr sequence(const std::vector<IFiniteTimePtr> &tweens);

template <class... Args>
SequencePtr sequence(cocos2d::Node *target, IFiniteTimePtr tween, Args... args)
{
    auto s = Sequence::create(target);
    s->addTweens(tween, args...);

    return std::move(s);
}

template <class... Args>
IIntervalPtr sequence(IFiniteTimePtr tween, Args... args)
{
    auto s = Sequence::create(nullptr);
    s->addTweens(tween, args...);

    return std::move(s);
}

#pragma mark spawn

SpawnPtr spawn(cocos2d::Node *target, const std::vector<IFiniteTimePtr> &tweens);
IIntervalPtr spawn(const std::vector<IFiniteTimePtr> &tweens);

template <class... Args>
SpawnPtr spawn(cocos2d::Node *target, IFiniteTimePtr tween, Args... args)
{
    auto s = Spawn::create(target);
    s->addTweens(tween, args...);

    return std::move(s);
}

template <class... Args>
IIntervalPtr spawn(IFiniteTimePtr tween, Args... args)
{
    auto s = Spawn::create(nullptr);
    s->addTweens(tween, args...);

    return std::move(s);
}

#pragma mark repeat

RepeatPtr repeat(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween);
IIntervalPtr repeat(unsigned int times, IFiniteTimePtr tween);

RepeatPtr repeat(cocos2d::Node *target, unsigned int times, const std::vector<IFiniteTimePtr> &tweens);
IIntervalPtr repeat(unsigned int times, const std::vector<IFiniteTimePtr> &tweens);

template <class... Args>
RepeatPtr repeat(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween1, IFiniteTimePtr tween2, Args... args)
{
    auto s = sequence(target, tween1, tween2, args...);
    auto r = Repeat::create(target, times, std::move(s));

    return std::move(r);
}

template <class... Args>
IIntervalPtr repeat(unsigned int times, IFiniteTimePtr tween1, IFiniteTimePtr tween2, Args... args)
{
    auto s = sequence(tween1, tween2, args...);
    auto r = Repeat::create(nullptr, times, std::move(s));

    return std::move(r);
}

#pragma mark repeat forever

RepeatForeverPtr repeatForever(cocos2d::Node *target, IIntervalPtr tween);
RepeatForeverPtr repeatForever(cocos2d::Node *target, const std::vector<IFiniteTimePtr> &tweens);

template <class... Args>
RepeatForeverPtr repeatForever(cocos2d::Node *target, IFiniteTimePtr tween1, IFiniteTimePtr tween2, Args... args)
{
    auto s = sequence(target, tween1, tween2, args...);
    auto r = RepeatForever::create(target, std::move(s));

    return std::move(r);
}

#pragma mark lag

LagPtr lag(cocos2d::Node *target, float waitTime, const std::vector<IFiniteTimePtr> &tweens);
IIntervalPtr lag(float waitTime, const std::vector<IFiniteTimePtr> &tweens);

template <class... Args>
LagPtr lag(cocos2d::Node *target, float waitTime, IFiniteTimePtr tween, Args... args)
{
    auto l = Lag::create(target, waitTime);
    l->addTweens(tween, args...);

    return std::move(l);
}

template <class... Args>
IIntervalPtr lag(float waitTime, IFiniteTimePtr tween, Args... args)
{
    auto l = Lag::create(nullptr, waitTime);
    l->addTweens(tween, args...);

    return std::move(l);
}

#pragma mark wait

WaitPtr wait(float waitTime);

#pragma mark func

FuncPtr func(const std::function<void()> &func);

#pragma mark action

ActionPtr action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);

#pragma mark visible

VisiblePtr visible(cocos2d::Node *target, bool visible);

ToggleVisibilityPtr toggleVisibility(cocos2d::Node *target);

#pragma mark remove

RemovePtr remove(cocos2d::Node *target);

#pragma mark place

PlacePtr place(cocos2d::Node *target, const cocos2d::Vec2 &pos);

#pragma mark flip

FlipXPtr flipX(cocos2d::Node *target, bool x);
} // namespace

#endif /* defined(__TweenCC__TweenCC__) */
