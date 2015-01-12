#ifndef __TweenCC__FlipX__
#define __TweenCC__FlipX__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class FlipX;
typedef std::shared_ptr<FlipX> FlipXPtr;

class FlipX : public IInterval, public Player
{
public:
    static FlipXPtr create(cocos2d::Node *target, bool x);

    FlipX(cocos2d::Node *target, bool x);
    virtual ~FlipX() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    FlipX(const FlipX&)           = delete;
    FlipX(FlipX&&)                = delete;
    FlipX&operator=(const FlipX&) = delete;
    FlipX&operator=(FlipX&&)      = delete;

    bool _flipX;
};
} // namespace

#endif /* defined(__TweenCC__FlipX__) */
