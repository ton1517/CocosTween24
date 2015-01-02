#ifndef __CocosTween24__Wait24__
#define __CocosTween24__Wait24__

#include <cocos2d.h>

#include "IInterval24.hpp"

namespace cocosTween24
{
class Wait24;
typedef std::shared_ptr<Wait24> Wait24Ptr;

class Wait24 : public IInterval24
{
public:
    static Wait24Ptr create(float waitTime);

    explicit Wait24(float waitTime);
    virtual ~Wait24() = default;

    cocos2d::ActionInterval *getAction() override;

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);

private:
    Wait24(const Wait24&)           = delete;
    Wait24(Wait24&&)                = delete;
    Wait24&operator=(const Wait24&) = delete;
    Wait24&operator=(Wait24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Wait24__) */
