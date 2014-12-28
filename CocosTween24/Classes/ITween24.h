#ifndef __CocosTween24__ITween24__
#define __CocosTween24__ITween24__

#include <cocos2d.h>

namespace cocosTween24
{
class ITween24
{
public:
    virtual cocos2d::FiniteTimeAction *getAction() = 0;
};
}

#endif /* defined(__CocosTween24__ITween24__) */
