#ifndef __CocosTween23__Player23__
#define __CocosTween23__Player23__

#include "IAction23.hpp"

namespace tween23
{
class Player23
{
public:
    explicit Player23(IAction23 *tweener, cocos2d::Node *target);
    virtual ~Player23() = default;

    virtual void play();
    virtual void stop();

    cocos2d::Node *getTarget();

private:
    IAction23       *_tweener;
    cocos2d::Node   *_target;
    cocos2d::Action *_playingAction;

    Player23(const Player23&)           = delete;
    Player23(Player23&&)                = delete;
    Player23&operator=(const Player23&) = delete;
    Player23&operator=(Player23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Player23__) */
