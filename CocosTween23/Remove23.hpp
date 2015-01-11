#ifndef __CocosTween23__Remove23__
#define __CocosTween23__Remove23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class Remove23;
typedef std::shared_ptr<Remove23> Remove23Ptr;

class Remove23 : public IInterval23, public Player23
{
public:
    static Remove23Ptr create(cocos2d::Node *target);

    Remove23(cocos2d::Node *target);
    virtual ~Remove23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Remove23(const Remove23&)           = delete;
    Remove23(Remove23&&)                = delete;
    Remove23&operator=(const Remove23&) = delete;
    Remove23&operator=(Remove23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Remove23__) */
