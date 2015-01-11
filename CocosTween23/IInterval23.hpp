#ifndef __CocosTween23__IInterval23__
#define __CocosTween23__IInterval23__

#include <cocos2d.h>

#include "IFiniteTime23.hpp"

namespace cocosTween23
{
class IInterval23;
typedef std::shared_ptr<IInterval23> IInterval23Ptr;

class IInterval23 : public IFiniteTime23
{
public:
    IInterval23()          = default;
    virtual ~IInterval23() = default;

    virtual cocos2d::ActionInterval *generateAction() = 0;

private:
    IInterval23(const IInterval23&)           = delete;
    IInterval23(IInterval23&&)                = delete;
    IInterval23&operator=(const IInterval23&) = delete;
    IInterval23&operator=(IInterval23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__IInterval23__) */
