#ifndef __CocosTween24__Action24__
#define __CocosTween24__Action24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Action24;
typedef std::shared_ptr<Action24> Action24Ptr;

class Action24 : public IInterval24, public Player24
{
public:
    static Action24Ptr create(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);

    explicit Action24(cocos2d::Node *target, cocos2d::FiniteTimeAction *action);
    virtual ~Action24() = default;

    cocos2d::ActionInterval *getAction() override;

private:
    Action24(const Action24&)           = delete;
    Action24(Action24&&)                = delete;
    Action24&operator=(const Action24&) = delete;
    Action24&operator=(Action24&&)      = delete;

    cocos2d::FiniteTimeAction *_action;
};
} // namespace

#endif /* defined(__CocosTween24__Action24__) */
