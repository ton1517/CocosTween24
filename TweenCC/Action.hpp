#ifndef __TweenCC__Action__
#define __TweenCC__Action__

#include <cocos2d.h>

#include "IFiniteTime.hpp"
#include "Player.hpp"

namespace tweencc
{
class Action;
typedef std::shared_ptr<Action> ActionPtr;

class Action : public IFiniteTime, public Player
{
public:
    static ActionPtr create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);

    explicit Action(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);
    virtual ~Action() = default;

    cocos2d::FiniteTimeAction *generateAction() override;
    cocos2d::FiniteTimeAction *generateActionWithoutTarget() override;

private:
    Action(const Action&)           = delete;
    Action(Action&&)                = delete;
    Action&operator=(const Action&) = delete;
    Action&operator=(Action&&)      = delete;

    cocos2d::FiniteTimeAction *_action;
};
} // namespace

#endif /* defined(__TweenCC__Action__) */
