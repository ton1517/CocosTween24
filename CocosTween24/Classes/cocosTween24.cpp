#include "cocosTween24.h"

namespace cocosTween24
{
Tween24Ptr tween(cocos2d::Node *target, float duration, Ease24 easing)
{
    auto t24 = Tween24::create(target, duration, easing);

    return std::move(t24);
}

Sequence24Ptr sequence(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = Sequence24::create(target);
    s24->addTweens(tweens);

    return std::move(s24);
}

Spawn24Ptr spawn(cocos2d::Node *target, const std::vector<ITween24Ptr> &tweens)
{
    auto s24 = Spawn24::create(target);
    s24->addTweens(tweens);

    return std::move(s24);
}

Wait24Ptr wait(float waitTime)
{
    return std::move(std::make_shared<Wait24>(waitTime));
}
}
