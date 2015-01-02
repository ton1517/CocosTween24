#ifndef __CocosTween24__ITween24__
#define __CocosTween24__ITween24__

#include <cocos2d.h>

namespace cocosTween24
{
class ITween24;
typedef std::shared_ptr<ITween24> ITween24Ptr;

class ITween24
{
public:
    ITween24()          = default;
    virtual ~ITween24() = default;

    virtual cocos2d::ActionInterval *getAction() = 0;

private:
    ITween24(const ITween24&)           = delete;
    ITween24(ITween24&&)                = delete;
    ITween24&operator=(const ITween24&) = delete;
    ITween24&operator=(ITween24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__ITween24__) */
