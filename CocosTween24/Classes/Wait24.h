#ifndef __CocosTween24__Wait24__
#define __CocosTween24__Wait24__

#include <cocos2d.h>
#include "ITween24.h"

namespace cocosTween24
{
class Wait24 : public ITween24
{
public:
    Wait24(float waitTime);

    cocos2d::FiniteTimeAction *getAction() override;

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);
};
}

#endif /* defined(__CocosTween24__Wait24__) */
