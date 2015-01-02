#ifndef __CocosTween24__Player24__
#define __CocosTween24__Player24__

#include "ITween24.hpp"

namespace cocosTween24
{
class Player24 : public ITween24
{
public:
    Player24(cocos2d::Node *target);
    virtual ~Player24();

    virtual void play();
    virtual void stop();

    cocos2d::Node *getTarget();

private:
    cocos2d::Node   *_target;
    cocos2d::Action *_playingAction;
};
} // namespace

#endif /* defined(__CocosTween24__Player24__) */
