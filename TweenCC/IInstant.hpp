#ifndef __TweenCC__IInstant__
#define __TweenCC__IInstant__

#include <cocos2d.h>

#include "IFiniteTime.hpp"

namespace tweencc
{
class IInstant;
typedef std::shared_ptr<IInstant> IInstantPtr;

class IInstant : public IFiniteTime
{
public:
    IInstant()          = default;
    virtual ~IInstant() = default;

    virtual cocos2d::ActionInstant *generateAction() = 0;
    virtual cocos2d::ActionInstant *generateActionWithoutTarget() = 0;

private:
    IInstant(const IInstant&)           = delete;
    IInstant(IInstant&&)                = delete;
    IInstant&operator=(const IInstant&) = delete;
    IInstant&operator=(IInstant&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__IInstant__) */
