#ifndef __TweenCC__RepeatForever__
#define __TweenCC__RepeatForever__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class RepeatForever;
typedef std::shared_ptr<RepeatForever> RepeatForeverPtr;

class RepeatForever : public IInterval, public Player, public std::enable_shared_from_this<RepeatForever>
{
public:
    static RepeatForeverPtr create(cocos2d::Node *target, IIntervalPtr tween);

    RepeatForever(cocos2d::Node *target, IIntervalPtr tween);
    virtual ~RepeatForever() = default;

    cocos2d::ActionInterval *generateAction() override;
    cocos2d::ActionInterval *generateActionWithoutTarget() override;

private:
    IIntervalPtr _tween;

    RepeatForever(const RepeatForever&)           = delete;
    RepeatForever(RepeatForever&&)                = delete;
    RepeatForever&operator=(const RepeatForever&) = delete;
    RepeatForever&operator=(RepeatForever&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__RepeatForever__) */
