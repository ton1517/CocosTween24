#ifndef __TweenCC__IInterval__
#define __TweenCC__IInterval__

#include <cocos2d.h>

#include "IFiniteTime.hpp"

namespace tweencc
{
class IInterval;
typedef std::shared_ptr<IInterval> IIntervalPtr;

class IInterval : public IFiniteTime
{
public:
    IInterval()          = default;
    virtual ~IInterval() = default;

    virtual cocos2d::ActionInterval *generateAction() = 0;
    virtual cocos2d::ActionInterval *generateActionWithoutTarget() = 0;

private:
    IInterval(const IInterval&)           = delete;
    IInterval(IInterval&&)                = delete;
    IInterval&operator=(const IInterval&) = delete;
    IInterval&operator=(IInterval&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__IInterval__) */
