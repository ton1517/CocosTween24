#ifndef __CocosTween24__Wait24__
#define __CocosTween24__Wait24__

#include <cocos2d.h>
#include "ITween24.hpp"

namespace cocosTween24
{
class Wait24;
typedef std::shared_ptr<Wait24> Wait24Ptr;

class Wait24 : public ITween24
{
public:
    static Wait24Ptr create(float waitTime);

    Wait24(float waitTime);
    virtual ~Wait24();

    cocos2d::ActionInterval *getAction() override;
    void play() override;
    void stop() override;

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);
};
}

#endif /* defined(__CocosTween24__Wait24__) */
