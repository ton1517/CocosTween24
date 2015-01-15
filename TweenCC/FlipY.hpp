#ifndef __TweenCC__FlipY__
#define __TweenCC__FlipY__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class FlipY;
typedef std::shared_ptr<FlipY> FlipYPtr;

class FlipY : public IInterval, public Player
{
public:
    static FlipYPtr create(cocos2d::Node *target, bool y);

    FlipY(cocos2d::Node *target, bool y);
    virtual ~FlipY() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    FlipY(const FlipY&)           = delete;
    FlipY(FlipY&&)                = delete;
    FlipY&operator=(const FlipY&) = delete;
    FlipY&operator=(FlipY&&)      = delete;

    bool _flipY;
};
} // namespace

#endif /* defined(__TweenCC__FlipY__) */
