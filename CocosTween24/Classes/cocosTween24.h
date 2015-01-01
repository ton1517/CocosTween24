#ifndef __CocosTween24__cocosTween24__
#define __CocosTween24__cocosTween24__

#include "Tween24.h"
#include "Ease24.h"
#include "Sequence24.h"
#include "Spawn24.h"
#include "Repeat24.h"
#include "Wait24.h"

namespace cocosTween24
{
#pragma mark tween

Tween24Ptr tween(cocos2d::Node *target, float duration, Ease24 easing=Ease24::Linear);

#pragma mark sequence

Sequence24Ptr sequence(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);

template <class Tween, class... Args>
Sequence24Ptr sequence(cocos2d::Node *target, Tween tween, Args... args)
{
    auto s24 = Sequence24::create(target);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

#pragma mark spawn

Spawn24Ptr spawn(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);

template <class Tween, class... Args>
Spawn24Ptr spawn(cocos2d::Node *target, Tween tween, Args... args)
{
    auto s24 = Spawn24::create(target);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

#pragma mark repeat

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, ITween24Ptr tween);
Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, const std::vector<ITween24Ptr> &tweens);

template <class Tween1, class Tween2, class... Args>
Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, Tween1 tween1, Tween2 tween2, Args... args)
{
    auto s24 = sequence(target, tween1, tween2, args...);
    auto r24 = Repeat24::create(target, times, std::move(s24));

    return std::move(r24);
}

#pragma mark wait

Wait24Ptr wait(float waitTime);
}

#endif /* defined(__CocosTween24__cocosTween24__) */
