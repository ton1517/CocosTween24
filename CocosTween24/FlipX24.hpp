#ifndef __CocosTween24__FlipX24__
#define __CocosTween24__FlipX24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class FlipX24;
typedef std::shared_ptr<FlipX24> FlipX24Ptr;

class FlipX24 : public IInterval24, public Player24
{
public:
    static FlipX24Ptr create(cocos2d::Node *target, bool x);

    FlipX24(cocos2d::Node *target, bool x);
    virtual ~FlipX24() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    FlipX24(const FlipX24&)            = delete;
    FlipX24(FlipX24&&)                 = delete;
    FlipX24&operator =(const FlipX24&) = delete;
    FlipX24&operator =(FlipX24&&)      = delete;

    bool _flipX;
};
} // namespace

#endif /* defined(__CocosTween24__FlipX24__) */
