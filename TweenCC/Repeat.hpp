#ifndef __TweenCC__Repeat__
#define __TweenCC__Repeat__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Repeat;
typedef std::shared_ptr<Repeat> RepeatPtr;

class Repeat : public IInterval, public Player, public std::enable_shared_from_this<Repeat>
{
public:
    static RepeatPtr create(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween);

    Repeat(cocos2d::Node *target, unsigned int times, IFiniteTimePtr tween);
    virtual ~Repeat() = default;

    cocos2d::ActionInterval *generateAction() override;
    cocos2d::ActionInterval *generateActionWithoutTarget() override;

    CC_SYNTHESIZE(unsigned int, _times, Times);

private:
    IFiniteTimePtr _tween;

    Repeat(const Repeat&)           = delete;
    Repeat(Repeat&&)                = delete;
    Repeat&operator=(const Repeat&) = delete;
    Repeat&operator=(Repeat&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Repeat__) */
