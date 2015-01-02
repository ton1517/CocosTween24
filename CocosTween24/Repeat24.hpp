#ifndef __CocosTween24__Repeat24__
#define __CocosTween24__Repeat24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Repeat24;
typedef std::shared_ptr<Repeat24> Repeat24Ptr;

class Repeat24 : public IInterval24, public Player24, public std::enable_shared_from_this<Repeat24>
{
public:
    static Repeat24Ptr create(cocos2d::Node *target, unsigned int times, IInterval24Ptr tween);

    Repeat24(cocos2d::Node *target, unsigned int times, IInterval24Ptr tween);
    virtual ~Repeat24() = default;

    cocos2d::ActionInterval *getAction() override;

    CC_SYNTHESIZE(unsigned int, _times, Times);

private:
    IInterval24Ptr _tween;

    Repeat24(const Repeat24&)           = delete;
    Repeat24(Repeat24&&)                = delete;
    Repeat24&operator=(const Repeat24&) = delete;
    Repeat24&operator=(Repeat24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Repeat24__) */
