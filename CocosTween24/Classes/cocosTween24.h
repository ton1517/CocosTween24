#ifndef __CocosTween24__cocosTween24__
#define __CocosTween24__cocosTween24__

#include "Tween24.h"
#include "Ease24.h"
#include "Sequence24.h"
#include "Spawn24.h"
#include "Wait24.h"

namespace cocosTween24
{
Tween24Ptr tween(cocos2d::Node *target, float duration, Ease24 easing=Ease24::Linear);

Sequence24Ptr sequence(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);

template <class Tween, class... Args>
Sequence24Ptr sequence(cocos2d::Node *target, Tween tween, Args... args)
{
    auto s24 = Sequence24::create(target);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

Spawn24Ptr spawn(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens);

template <class Tween, class... Args>
Spawn24Ptr spawn(cocos2d::Node *target, Tween tween, Args... args)
{
    auto s24 = Spawn24::create(target);
    s24->addTweens(tween, args...);

    return std::move(s24);
}

Wait24Ptr wait(float waitTime);
}

#endif /* defined(__CocosTween24__cocosTween24__) */
