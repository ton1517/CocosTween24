#ifndef __CocosTween23__IInstant23__
#define __CocosTween23__IInstant23__

#include <cocos2d.h>

#include "IFiniteTime23.hpp"

namespace tween23
{
class IInstant23;
typedef std::shared_ptr<IInstant23> IInstant23Ptr;

class IInstant23 : public IFiniteTime23
{
public:
    IInstant23()          = default;
    virtual ~IInstant23() = default;

    virtual cocos2d::ActionInstant *generateAction() = 0;

private:
    IInstant23(const IInstant23&)           = delete;
    IInstant23(IInstant23&&)                = delete;
    IInstant23&operator=(const IInstant23&) = delete;
    IInstant23&operator=(IInstant23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__IInstant23__) */
