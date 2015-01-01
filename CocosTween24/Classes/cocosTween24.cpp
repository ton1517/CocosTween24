#include "cocosTween24.h"

namespace cocosTween24
{
#pragma mark tween

Tween24Ptr tween(cocos2d::Node *target, float duration, Ease24 easing)
{
    auto t24 = Tween24::create(target, duration, easing);

    return std::move(t24);
}

#pragma mark sequence

Sequence24Ptr sequence(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = Sequence24::create(target);
    s24->addTweens(tweens);

    return std::move(s24);
}

#pragma mark spawn

Spawn24Ptr spawn(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = Spawn24::create(target);
    s24->addTweens(tweens);

    return std::move(s24);
}

#pragma mark repeat

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, ITween24Ptr tween)
{
    auto r24 = Repeat24::create(target, times, tween);

    return std::move(r24);
}

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = sequence(target, tweens);
    auto r24 = Repeat24::create(target, times, std::move(s24));

    return std::move(r24);
}

#pragma mark repeat forever

Repeat24Ptr repeatForever(cocos2d::Node *target, ITween24Ptr tween)
{
    auto r24 = Repeat24::create(target, 0, tween);

    return std::move(r24);
}

Repeat24Ptr repeatForever(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = sequence(target, tweens);
    auto r24 = Repeat24::create(target, 0, std::move(s24));

    return std::move(r24);
}

#pragma mark wait

Wait24Ptr wait(float waitTime)
{
    return std::move(std::make_shared<Wait24>(waitTime));
}
}
