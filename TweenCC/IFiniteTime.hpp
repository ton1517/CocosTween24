#ifndef __TweenCC__IFiniteTime__
#define __TweenCC__IFiniteTime__

#include <cocos2d.h>

#include "IAction.hpp"

namespace tweencc
{
class IFiniteTime;
typedef std::shared_ptr<IFiniteTime> IFiniteTimePtr;

class IFiniteTime : public IAction
{
public:
    IFiniteTime()          = default;
    virtual ~IFiniteTime() = default;

    virtual cocos2d::FiniteTimeAction *generateAction() = 0;

private:
    IFiniteTime(const IFiniteTime&)           = delete;
    IFiniteTime(IFiniteTime&&)                = delete;
    IFiniteTime&operator=(const IFiniteTime&) = delete;
    IFiniteTime&operator=(IFiniteTime&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__IFiniteTime__) */
