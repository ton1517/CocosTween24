#ifndef __CocosTween23__ToggleVisibility23__
#define __CocosTween23__ToggleVisibility23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class ToggleVisibility23;
typedef std::shared_ptr<ToggleVisibility23> ToggleVisibility23Ptr;

class ToggleVisibility23 : public IInterval23, public Player23
{
public:
    static ToggleVisibility23Ptr create(cocos2d::Node *target);

    ToggleVisibility23(cocos2d::Node *target);
    virtual ~ToggleVisibility23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    ToggleVisibility23(const ToggleVisibility23&)           = delete;
    ToggleVisibility23(ToggleVisibility23&&)                = delete;
    ToggleVisibility23&operator=(const ToggleVisibility23&) = delete;
    ToggleVisibility23&operator=(ToggleVisibility23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__ToggleVisibility23__) */