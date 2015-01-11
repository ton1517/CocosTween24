#ifndef __CocosTween23__IAction23__
#define __CocosTween23__IAction23__

#include <cocos2d.h>

namespace cocosTween23
{
class IAction23;
typedef std::shared_ptr<IAction23> IAction23Ptr;

class IAction23
{
public:
    IAction23()          = default;
    virtual ~IAction23() = default;

    virtual cocos2d::Action *generateAction() = 0;

private:
    IAction23(const IAction23&)           = delete;
    IAction23(IAction23&&)                = delete;
    IAction23&operator=(const IAction23&) = delete;
    IAction23&operator=(IAction23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__IAction23__) */
