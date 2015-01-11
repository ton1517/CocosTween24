#ifndef __CocosTween23__FlipX23__
#define __CocosTween23__FlipX23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace tween23
{
class FlipX23;
typedef std::shared_ptr<FlipX23> FlipX23Ptr;

class FlipX23 : public IInterval23, public Player23
{
public:
    static FlipX23Ptr create(cocos2d::Node *target, bool x);

    FlipX23(cocos2d::Node *target, bool x);
    virtual ~FlipX23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    FlipX23(const FlipX23&)           = delete;
    FlipX23(FlipX23&&)                = delete;
    FlipX23&operator=(const FlipX23&) = delete;
    FlipX23&operator=(FlipX23&&)      = delete;

    bool _flipX;
};
} // namespace

#endif /* defined(__CocosTween23__FlipX23__) */
