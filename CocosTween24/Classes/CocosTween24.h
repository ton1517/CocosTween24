#ifndef __CocosTween24__CocosTween24__
#define __CocosTween24__CocosTween24__

#include "cocos2d.h"
#include "ITween24.h"
#include "CocosEase24.h"
#include "Wait24.h"

namespace cocosTween24
{
class CocosTween24 : public ITween24
{
public:
    static CocosTween24 *tween(cocos2d::Node *target, float duration, CocosEase24::EASE easing = CocosEase24::Linear);
    static Wait24 *wait(float waitTime);

    CocosTween24();

    cocos2d::FiniteTimeAction *getAction() override;

    void play();
    void stop();

#pragma mark position
    CocosTween24 *x(float x);
    CocosTween24 *$x(float $x);
    CocosTween24 *y(float y);
    CocosTween24 *$y(float $y);
    CocosTween24 *xy(float x, float y);
    CocosTween24 *$xy(float $x, float $y);

#pragma mark scale
    CocosTween24 *scaleX(float sx);
    CocosTween24 *$scaleX(float $sx);
    CocosTween24 *scaleY(float sy);
    CocosTween24 *$scaleY(float $sy);
    CocosTween24 *scaleZ(float sz);
    CocosTween24 *$scaleZ(float $sz);
    CocosTween24 *scale(float s);
    CocosTween24 *$scale(float $s);
    CocosTween24 *scale(float sx, float sy);
    CocosTween24 *$scale(float $sx, float $sy);
    CocosTween24 *scale(float sx, float sy, float sz);
    CocosTween24 *$scale(float $sx, float $sy, float $sz);

#pragma mark rorate
    CocosTween24 *rotateX(float angleX);
    CocosTween24 *$rotateX(float $angleX);
    CocosTween24 *rotateY(float angleY);
    CocosTween24 *$rotateY(float $angleX);
    CocosTween24 *rotate(float angle);
    CocosTween24 *$rotate(float angle);
    CocosTween24 *rotate(float angleX, float angleY);
    CocosTween24 *$rotate(float $angleX, float $angleY);
    CocosTween24 *rotate(const cocos2d::Vec3 &angle3D);
    CocosTween24 *$rotate(const cocos2d::Vec3 &$angle3D);

#pragma mark delay
    CocosTween24 *delay(float delayTime);

#pragma mark property
    CC_SYNTHESIZE_READONLY(cocos2d::Node *, _target, Target);
    CC_SYNTHESIZE_READONLY(float, _duration, Duration);
    CC_SYNTHESIZE_READONLY(CocosEase24::EASE, _easing, Easing);

private:
    cocos2d::FiniteTimeAction *_playingAction;

    cocos2d::Vector<cocos2d::FiniteTimeAction *> _actions;
    void addAction(cocos2d::FiniteTimeAction *action);

    cocos2d::ActionInterval *addEasing(cocos2d::ActionInterval *action);

    float _delayTime{0};
    cocos2d::ActionInterval *addDelay(cocos2d::ActionInterval *action);
};
}

#endif /* defined(__CocosTween24__CocosTween24__) */
