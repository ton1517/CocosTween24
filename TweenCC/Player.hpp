#ifndef __TweenCC__Player__
#define __TweenCC__Player__

#include "IAction.hpp"

namespace tweencc
{
class Player
{
public:
    explicit Player(IAction *tweener, cocos2d::Node *target);
    virtual ~Player() = default;

    virtual void play();
    virtual void stop();

    cocos2d::Node *getTarget();

private:
    IAction       *_tweener;
    cocos2d::Node   *_target;
    cocos2d::Action *_playingAction;

    Player(const Player&)           = delete;
    Player(Player&&)                = delete;
    Player&operator=(const Player&) = delete;
    Player&operator=(Player&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Player__) */
