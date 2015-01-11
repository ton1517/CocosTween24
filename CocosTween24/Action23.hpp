#ifndef __CocosTween23__Action23__
#define __CocosTween23__Action23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class Action23;
typedef std::shared_ptr<Action23> Action23Ptr;

class Action23 : public IInterval23, public Player23
{
public:
    static Action23Ptr create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);

    explicit Action23(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);
    virtual ~Action23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Action23(const Action23&)           = delete;
    Action23(Action23&&)                = delete;
    Action23&operator=(const Action23&) = delete;
    Action23&operator=(Action23&&)      = delete;

    cocos2d::FiniteTimeAction *_action;
};
} // namespace

#endif /* defined(__CocosTween23__Action23__) */
