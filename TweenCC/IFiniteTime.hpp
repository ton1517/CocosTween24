#ifndef __CocosTween23__IFiniteTime23__
#define __CocosTween23__IFiniteTime23__

#include <cocos2d.h>

#include "IAction23.hpp"

namespace tween23
{
class IFiniteTime23;
typedef std::shared_ptr<IFiniteTime23> IFiniteTime23Ptr;

class IFiniteTime23 : public IAction23
{
public:
    IFiniteTime23()          = default;
    virtual ~IFiniteTime23() = default;

    virtual cocos2d::FiniteTimeAction *generateAction() = 0;

private:
    IFiniteTime23(const IFiniteTime23&)           = delete;
    IFiniteTime23(IFiniteTime23&&)                = delete;
    IFiniteTime23&operator=(const IFiniteTime23&) = delete;
    IFiniteTime23&operator=(IFiniteTime23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__IFiniteTime23__) */
