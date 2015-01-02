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
    virtual ~ITween24() {}
    virtual cocos2d::ActionInterval *getAction() = 0;
};
} // namespace

#endif /* defined(__CocosTween24__ITween24__) */
