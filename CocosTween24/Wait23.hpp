#ifndef __CocosTween23__Wait23__
#define __CocosTween23__Wait23__

#include <cocos2d.h>

#include "IInterval23.hpp"

namespace cocosTween23
{
class Wait23;
typedef std::shared_ptr<Wait23> Wait23Ptr;

class Wait23 : public IInterval23
{
public:
    static Wait23Ptr create(float waitTime);

    explicit Wait23(float waitTime);
    virtual ~Wait23() = default;

    cocos2d::ActionInterval *generateAction() override;

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);

private:
    Wait23(const Wait23&)           = delete;
    Wait23(Wait23&&)                = delete;
    Wait23&operator=(const Wait23&) = delete;
    Wait23&operator=(Wait23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Wait23__) */
