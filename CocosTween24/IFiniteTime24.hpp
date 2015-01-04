#ifndef __CocosTween24__IFiniteTime24__
#define __CocosTween24__IFiniteTime24__

#include <cocos2d.h>

#include "IAction24.hpp"

namespace cocosTween24
{
class IFiniteTime24;
typedef std::shared_ptr<IFiniteTime24> IFiniteTime24Ptr;

class IFiniteTime24 : public IAction24
{
public:
    IFiniteTime24()          = default;
    virtual ~IFiniteTime24() = default;

    virtual cocos2d::FiniteTimeAction *generateAction() = 0;

private:
    IFiniteTime24(const IFiniteTime24&)           = delete;
    IFiniteTime24(IFiniteTime24&&)                = delete;
    IFiniteTime24&operator=(const IFiniteTime24&) = delete;
    IFiniteTime24&operator=(IFiniteTime24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__IFiniteTime24__) */
