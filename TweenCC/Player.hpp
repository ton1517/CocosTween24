#ifndef __TweenCC__Player__
#define __TweenCC__Player__

#include "IAction.hpp"

namespace tweencc
{
class Player
{
public:
    explicit Player(IAction *tweener, cocos2d::Node *target);
    explicit Player(IAction *tweener, const std::vector<cocos2d::Node *> &targets);
    virtual ~Player() = default;

    virtual void play();
    virtual void stop();

    cocos2d::Node *getTarget();

    std::vector<cocos2d::Node *> getTargets();

private:
    IAction *_tweener;

    std::vector<cocos2d::Node *>   _targets;
    std::vector<cocos2d::Action *> _playingActions;

    Player(const Player&)           = delete;
    Player(Player&&)                = delete;
    Player&operator=(const Player&) = delete;
    Player&operator=(Player&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Player__) */
