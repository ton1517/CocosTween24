#ifndef __CocosTween23__cocosTween23__
#define __CocosTween23__cocosTween23__

#include <cocos2d.h>

#include "Tween23.hpp"
#include "Ease23.hpp"
#include "Sequence23.hpp"
#include "Spawn23.hpp"
#include "Repeat23.hpp"
#include "RepeatForever23.hpp"
#include "Lag23.hpp"
#include "Wait23.hpp"
#include "Func23.hpp"
#include "Action23.hpp"
#include "Visible23.hpp"
#include "ToggleVisibility23.hpp"
#include "Remove23.hpp"
#include "Place23.hpp"
#include "FlipX23.hpp"

namespace tween23
{
#pragma mark tween

Tween23Ptr tween(cocos2d::Node *target, float duration, Ease23 easing=Ease23::Linear);

#pragma mark sequence

Sequence23Ptr sequence(cocos2d::Node *target, const std::vector<IFiniteTime23Ptr> &tweens);
IInterval23Ptr sequence(const std::vector<IFiniteTime23Ptr> &tweens);

template <class... Args>
Sequence23Ptr sequence(cocos2d::Node *target, IFiniteTime23Ptr tween, Args... args)
{
    auto s23 = Sequence23::create(target);
    s23->addTweens(tween, args...);

    return std::move(s23);
}

template <class... Args>
IInterval23Ptr sequence(IFiniteTime23Ptr tween, Args... args)
{
    auto s23 = Sequence23::create(nullptr);
    s23->addTweens(tween, args...);

    return std::move(s23);
}

#pragma mark spawn

Spawn23Ptr spawn(cocos2d::Node *target, const std::vector<IFiniteTime23Ptr> &tweens);
IInterval23Ptr spawn(const std::vector<IFiniteTime23Ptr> &tweens);

template <class... Args>
Spawn23Ptr spawn(cocos2d::Node *target, IFiniteTime23Ptr tween, Args... args)
{
    auto s23 = Spawn23::create(target);
    s23->addTweens(tween, args...);

    return std::move(s23);
}

template <class... Args>
IInterval23Ptr spawn(IFiniteTime23Ptr tween, Args... args)
{
    auto s23 = Spawn23::create(nullptr);
    s23->addTweens(tween, args...);

    return std::move(s23);
}

#pragma mark repeat

Repeat23Ptr repeat(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween);
IInterval23Ptr repeat(unsigned int times, IFiniteTime23Ptr tween);

Repeat23Ptr repeat(cocos2d::Node *target, unsigned int times, const std::vector<IFiniteTime23Ptr> &tweens);
IInterval23Ptr repeat(unsigned int times, const std::vector<IFiniteTime23Ptr> &tweens);

template <class... Args>
Repeat23Ptr repeat(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween1, IFiniteTime23Ptr tween2, Args... args)
{
    auto s23 = sequence(target, tween1, tween2, args...);
    auto r23 = Repeat23::create(target, times, std::move(s23));

    return std::move(r23);
}

template <class... Args>
IInterval23Ptr repeat(unsigned int times, IFiniteTime23Ptr tween1, IFiniteTime23Ptr tween2, Args... args)
{
    auto s23 = sequence(tween1, tween2, args...);
    auto r23 = Repeat23::create(nullptr, times, std::move(s23));

    return std::move(r23);
}

#pragma mark repeat forever

RepeatForever23Ptr repeatForever(cocos2d::Node *target, IInterval23Ptr tween);
RepeatForever23Ptr repeatForever(cocos2d::Node *target, const std::vector<IFiniteTime23Ptr> &tweens);

template <class... Args>
RepeatForever23Ptr repeatForever(cocos2d::Node *target, IFiniteTime23Ptr tween1, IFiniteTime23Ptr tween2, Args... args)
{
    auto s23 = sequence(target, tween1, tween2, args...);
    auto r23 = RepeatForever23::create(target, std::move(s23));

    return std::move(r23);
}

#pragma mark lag

Lag23Ptr lag(cocos2d::Node *target, float waitTime, const std::vector<IFiniteTime23Ptr> &tweens);
IInterval23Ptr lag(float waitTime, const std::vector<IFiniteTime23Ptr> &tweens);

template <class... Args>
Lag23Ptr lag(cocos2d::Node *target, float waitTime, IFiniteTime23Ptr tween, Args... args)
{
    auto l23 = Lag23::create(target, waitTime);
    l23->addTweens(tween, args...);

    return std::move(l23);
}

template <class... Args>
IInterval23Ptr lag(float waitTime, IFiniteTime23Ptr tween, Args... args)
{
    auto l23 = Lag23::create(nullptr, waitTime);
    l23->addTweens(tween, args...);

    return std::move(l23);
}

#pragma mark wait

Wait23Ptr wait(float waitTime);

#pragma mark func

Func23Ptr func(const std::function<void()> &func);

#pragma mark action

Action23Ptr action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);

#pragma mark visible

Visible23Ptr visible(cocos2d::Node *target, bool visible);

ToggleVisibility23Ptr toggleVisibility(cocos2d::Node *target);

#pragma mark remove

Remove23Ptr remove(cocos2d::Node *target);

#pragma mark place

Place23Ptr place(cocos2d::Node *target, const cocos2d::Vec2 &pos);

#pragma mark flip

FlipX23Ptr flipX(cocos2d::Node *target, bool x);
} // namespace

#endif /* defined(__CocosTween23__cocosTween23__) */
