#ifndef __CocosTween24__IInstant24__
#define __CocosTween24__IInstant24__

#include <cocos2d.h>

#include "IFiniteTime24.hpp"

namespace cocosTween24
{
class IInstant24;
typedef std::shared_ptr<IInstant24> IInstant24Ptr;

class IInstant24 : public IFiniteTime24
{
public:
    IInstant24()          = default;
    virtual ~IInstant24() = default;

    virtual cocos2d::ActionInstant *generateAction() = 0;

private:
    IInstant24(const IInstant24&)           = delete;
    IInstant24(IInstant24&&)                = delete;
    IInstant24&operator=(const IInstant24&) = delete;
    IInstant24&operator=(IInstant24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__IInstant24__) */
