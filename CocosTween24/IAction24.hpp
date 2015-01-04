#ifndef __CocosTween24__IAction24__
#define __CocosTween24__IAction24__

#include <cocos2d.h>

namespace cocosTween24
{
class IAction24;
typedef std::shared_ptr<IAction24> IAction24Ptr;

class IAction24
{
public:
    IAction24()          = default;
    virtual ~IAction24() = default;

    virtual cocos2d::Action *generateAction() = 0;

private:
    IAction24(const IAction24&)           = delete;
    IAction24(IAction24&&)                = delete;
    IAction24&operator=(const IAction24&) = delete;
    IAction24&operator=(IAction24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__IAction24__) */
