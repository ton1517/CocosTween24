#include "cocosTween24.hpp"

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

ITween24Ptr sequence(const std::vector<ITween24Ptr> &tweens)
{
    return std::move(sequence(nullptr, tweens));
}

#pragma mark spawn

Spawn24Ptr spawn(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = Spawn24::create(target);
    s24->addTweens(tweens);

    return std::move(s24);
}

ITween24Ptr spawn(const std::vector<ITween24Ptr> &tweens)
{
    return std::move(spawn(nullptr, tweens));
}

#pragma mark repeat

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, ITween24Ptr tween)
{
    auto r24 = Repeat24::create(target, times, tween);

    return std::move(r24);
}

ITween24Ptr repeat(unsigned int times, ITween24Ptr tween)
{
    return std::move(repeat(nullptr, times, tween));
}

Repeat24Ptr repeat(cocos2d::Node *target, unsigned int times, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = sequence(target, tweens);
    auto r24 = Repeat24::create(target, times, std::move(s24));

    return std::move(r24);
}

ITween24Ptr repeat(unsigned int times, const std::vector<ITween24Ptr> &tweens)
{
    return std::move(repeat(nullptr, times, tweens));
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

#pragma mark lag

Lag24Ptr lag(cocos2d::Node *target, float waitTime, const std::vector<ITween24Ptr> &tweens)
{
    auto l24 = Lag24::create(target, waitTime);
    l24->addTweens(tweens);

    return std::move(l24);
}

ITween24Ptr lag(float waitTime, const std::vector<ITween24Ptr> &tweens)
{
    return std::move(lag(nullptr, waitTime, tweens));
}

#pragma mark wait

Wait24Ptr wait(float waitTime)
{
    return std::move(Wait24::create(waitTime));
}
} // namespace
