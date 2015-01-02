#ifndef __CocosTween24__IInterval24__
#define __CocosTween24__IInterval24__

#include <cocos2d.h>

#include "IFiniteTime24.hpp"

namespace cocosTween24
{
class IInterval24;
typedef std::shared_ptr<IInterval24> IInterval24Ptr;

class IInterval24 : public IFiniteTime24
{
public:
    IInterval24()          = default;
    virtual ~IInterval24() = default;

    virtual cocos2d::ActionInterval *getAction() = 0;

private:
    IInterval24(const IInterval24&)           = delete;
    IInterval24(IInterval24&&)                = delete;
    IInterval24&operator=(const IInterval24&) = delete;
    IInterval24&operator=(IInterval24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__IInterval24__) */
