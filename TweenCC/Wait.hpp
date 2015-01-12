#ifndef __TweenCC__Wait__
#define __TweenCC__Wait__

#include <cocos2d.h>

#include "IInterval.hpp"

namespace tweencc
{
class Wait;
typedef std::shared_ptr<Wait> WaitPtr;

class Wait : public IInterval
{
public:
    static WaitPtr create(float waitTime);

    explicit Wait(float waitTime);
    virtual ~Wait() = default;

    cocos2d::ActionInterval *generateAction() override;

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);

private:
    Wait(const Wait&)           = delete;
    Wait(Wait&&)                = delete;
    Wait&operator=(const Wait&) = delete;
    Wait&operator=(Wait&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Wait__) */
