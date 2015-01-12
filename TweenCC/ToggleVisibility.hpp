#ifndef __TweenCC__ToggleVisibility__
#define __TweenCC__ToggleVisibility__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class ToggleVisibility;
typedef std::shared_ptr<ToggleVisibility> ToggleVisibilityPtr;

class ToggleVisibility : public IInterval, public Player
{
public:
    static ToggleVisibilityPtr create(cocos2d::Node *target);

    ToggleVisibility(cocos2d::Node *target);
    virtual ~ToggleVisibility() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    ToggleVisibility(const ToggleVisibility&)           = delete;
    ToggleVisibility(ToggleVisibility&&)                = delete;
    ToggleVisibility&operator=(const ToggleVisibility&) = delete;
    ToggleVisibility&operator=(ToggleVisibility&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__ToggleVisibility__) */