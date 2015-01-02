#ifndef __CocosTween24__Player24__
#define __CocosTween24__Player24__

#include "ITween24.hpp"

namespace cocosTween24
{
class Player24 : public ITween24
{
public:
    explicit Player24(cocos2d::Node *target);
    virtual ~Player24() = default;

    virtual void play();
    virtual void stop();

    cocos2d::Node *getTarget();

private:
    cocos2d::Node   *_target;
    cocos2d::Action *_playingAction;

    Player24(const Player24&)           = delete;
    Player24(Player24&&)                = delete;
    Player24&operator=(const Player24&) = delete;
    Player24&operator=(Player24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Player24__) */
