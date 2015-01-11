#include "Repeat23.hpp"

namespace cocosTween23
{
Repeat23Ptr Repeat23::create(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween)
{
    auto r23 = std::make_shared<Repeat23>(target, times, tween);

    return std::move(r23);
}

Repeat23::Repeat23(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween) : Player23(this, target), _times(times), _tween(tween)
{
}

cocos2d::ActionInterval *Repeat23::generateAction()
{
    auto action = _tween->generateAction();

    return cocos2d::Repeat::create(action, _times);
}
} // namespace
