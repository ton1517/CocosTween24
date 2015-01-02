#ifndef __CocosTween24__Repeat24__
#define __CocosTween24__Repeat24__

#include <cocos2d.h>

#include "Player24.hpp"

namespace cocosTween24
{
class Repeat24;
typedef std::shared_ptr<Repeat24> Repeat24Ptr;

class Repeat24 : public Player24, public std::enable_shared_from_this<Repeat24>
{
public:
    static Repeat24Ptr create(cocos2d::Node *target, unsigned int times, ITween24Ptr tween);

    Repeat24(cocos2d::Node *target, unsigned int times, ITween24Ptr tween);
    virtual ~Repeat24();

    cocos2d::ActionInterval *getAction() override;

    CC_SYNTHESIZE(unsigned int, _times, Times);

private:
    ITween24Ptr _tween;
};
} // namespace

#endif /* defined(__CocosTween24__Repeat24__) */
