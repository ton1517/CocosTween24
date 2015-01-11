#include "cocosTween23.hpp"

namespace cocosTween23
{
#pragma mark tween

Tween23Ptr tween(cocos2d::Node *target, float duration, Ease23 easing)
{
    auto t23 = Tween23::create(target, duration, easing);

    return std::move(t23);
}

#pragma mark sequence

Sequence23Ptr sequence(cocos2d::Node *target, const std::vector<IFiniteTime23Ptr> &tweens)
{
    auto s23 = Sequence23::create(target);
    s23->addTweens(tweens);

    return std::move(s23);
}

IInterval23Ptr sequence(const std::vector<IFiniteTime23Ptr> &tweens)
{
    return std::move(sequence(nullptr, tweens));
}

#pragma mark spawn

Spawn23Ptr spawn(cocos2d::Node *target, const std::vector<IFiniteTime23Ptr> &tweens)
{
    auto s23 = Spawn23::create(target);
    s23->addTweens(tweens);

    return std::move(s23);
}

IInterval23Ptr spawn(const std::vector<IFiniteTime23Ptr> &tweens)
{
    return std::move(spawn(nullptr, tweens));
}

#pragma mark repeat

Repeat23Ptr repeat(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween)
{
    auto r23 = Repeat23::create(target, times, tween);

    return std::move(r23);
}

IInterval23Ptr repeat(unsigned int times, IFiniteTime23Ptr tween)
{
    return std::move(repeat(nullptr, times, tween));
}

Repeat23Ptr repeat(cocos2d::Node *target, unsigned int times, const std::vector<IFiniteTime23Ptr> &tweens)
{
    auto s23 = sequence(target, tweens);
    auto r23 = Repeat23::create(target, times, std::move(s23));

    return std::move(r23);
}

IInterval23Ptr repeat(unsigned int times, const std::vector<IFiniteTime23Ptr> &tweens)
{
    return std::move(repeat(nullptr, times, tweens));
}

#pragma mark repeat forever

RepeatForever23Ptr repeatForever(cocos2d::Node *target, IInterval23Ptr tween)
{
    auto r23 = RepeatForever23::create(target, tween);

    return std::move(r23);
}

RepeatForever23Ptr repeatForever(cocos2d::Node *target, const std::vector<IFiniteTime23Ptr> &tweens)
{
    auto s23 = sequence(target, tweens);
    auto r23 = RepeatForever23::create(target, std::move(s23));

    return std::move(r23);
}

#pragma mark lag

Lag23Ptr lag(cocos2d::Node *target, float waitTime, const std::vector<IFiniteTime23Ptr> &tweens)
{
    auto l23 = Lag23::create(target, waitTime);
    l23->addTweens(tweens);

    return std::move(l23);
}

IInterval23Ptr lag(float waitTime, const std::vector<IFiniteTime23Ptr> &tweens)
{
    return std::move(lag(nullptr, waitTime, tweens));
}

#pragma mark wait

Wait23Ptr wait(float waitTime)
{
    return std::move(Wait23::create(waitTime));
}

#pragma mark func

Func23Ptr func(const std::function<void()> &func)
{
    return std::move(Func23::create(func));
}

#pragma mark action

Action23Ptr action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
{
    return std::move(Action23::create(target, action));
}

#pragma mark visible

Visible23Ptr visible(cocos2d::Node *target, bool visible)
{
    return std::move(Visible23::create(target, visible));
}

ToggleVisibility23Ptr toggleVisibility(cocos2d::Node *target)
{
    return std::move(ToggleVisibility23::create(target));
}

#pragma mark remove

Remove23Ptr remove(cocos2d::Node *target)
{
    return std::move(Remove23::create(target));
}

#pragma mark place

Place23Ptr place(cocos2d::Node *target, const cocos2d::Vec2 &pos)
{
    return std::move(Place23::create(target, pos));
}

#pragma mark flip

FlipX23Ptr flipX(cocos2d::Node *target, bool x)
{
    return std::move(FlipX23::create(target, x));
}
} // namespace
