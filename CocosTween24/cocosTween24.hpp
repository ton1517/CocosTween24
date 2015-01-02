#ifndef __CocosTween24__cocosTween24__
#define __CocosTween24__cocosTween24__

#include <cocos2d.h>

#include "Tween24.hpp"
#include "Ease24.hpp"
#include "Sequence24.hpp"
#include "Spawn24.hpp"
#include "Repeat24.hpp"
#include "Wait24.hpp"

namespace cocosTween24
{
#pragma mark tween

Tween24Ptr tween(cocos2d::Node *target, float duration, Ease24 easing=Ease24::Linear);

#pragma mark sequence

Sequence24Ptr sequence(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);
ITween24Ptr sequence(const std::vector<ITween24Ptr> &tweens);

template <class... Args>
Sequence24Ptr sequence(cocos2d::Node *target, ITween24Ptr tween, Args... args)
{
    auto s24 = Sequence24::create(target);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

template <class... Args>
ITween24Ptr sequence(ITween24Ptr tween, Args... args)
{
    auto s24 = Sequence24::create(nullptr);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

#pragma mark spawn

Spawn24Ptr spawn(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);
ITween24Ptr spawn(const std::vector<ITween24Ptr> &tweens);

template <class... Args>
Spawn24Ptr spawn(cocos2d::Node *target, ITween24Ptr tween, Args... args)
{
    auto s24 = Spawn24::create(target);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

template <class... Args>
ITween24Ptr spawn(ITween24Ptr tween, Args... args)
{
    auto s24 = Spawn24::create(nullptr);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

#pragma mark repeat

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, ITween24Ptr tween);
ITween24Ptr repeat(unsigned int times, ITween24Ptr tween);

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, const std::vector<ITween24Ptr> &tweens);
ITween24Ptr repeat(unsigned int times, const std::vector<ITween24Ptr> &tweens);

template <class... Args>
Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, ITween24Ptr tween1, ITween24Ptr tween2, Args... args)
{
    auto s24 = sequence(target, tween1, tween2, args...);
    auto r24 = Repeat24::create(target, times, std::move(s24));

    return std::move(r24);
}

template <class... Args>
ITween24Ptr repeat(unsigned int times, ITween24Ptr tween1, ITween24Ptr tween2, Args... args)
{
    auto s24 = sequence(tween1, tween2, args...);
    auto r24 = Repeat24::create(nullptr, times, std::move(s24));

    return std::move(r24);
}

#pragma mark repeat forever

Repeat24Ptr repeatForever(cocos2d::Node *target, ITween24Ptr tween);
Repeat24Ptr repeatForever(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);

template <class... Args>
Repeat24Ptr repeatForever(cocos2d::Node *target, ITween24Ptr tween1, ITween24Ptr tween2, Args... args)
{
    auto s24 = sequence(target, tween1, tween2, args...);
    auto r24 = Repeat24::create(target, 0, std::move(s24));

    return std::move(r24);
}

#pragma mark wait

Wait24Ptr wait(float waitTime);
} // namespace

#endif /* defined(__CocosTween24__cocosTween24__) */
