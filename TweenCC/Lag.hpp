#ifndef __TweenCC__Lag__
#define __TweenCC__Lag__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Lag;
typedef std::shared_ptr<Lag> LagPtr;

class Lag : public IInterval, public Player, public std::enable_shared_from_this<Lag>
{
public:
    static LagPtr create(cocos2d::Node *target, float waitTime);

    Lag(cocos2d::Node *target, float waitTime);
    virtual ~Lag() = default;

    cocos2d::ActionInterval *generateAction() override;
    cocos2d::ActionInterval *generateActionWithoutTarget() override;

    LagPtr addTweens(IFiniteTimePtr tween);
    LagPtr addTweens(const std::vector<IFiniteTimePtr> &tweens);

    template <class... Args>
    LagPtr addTweens(IFiniteTimePtr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);

private:
    std::vector<IFiniteTimePtr> _tweens;

    Lag(const Lag&)           = delete;
    Lag(Lag&&)                = delete;
    Lag&operator=(const Lag&) = delete;
    Lag&operator=(Lag&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Lag__) */
