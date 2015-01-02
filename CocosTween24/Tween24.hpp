#ifndef __CocosTween24__Tween24__
#define __CocosTween24__Tween24__

#include <cocos2d.h>

#include "Player24.hpp"
#include "Ease24.hpp"
#include "Sequence24.hpp"
#include "Wait24.hpp"

namespace cocosTween24
{
class Tween24;
typedef std::shared_ptr<Tween24> Tween24Ptr;

class Tween24 : public Player24, public std::enable_shared_from_this<Tween24>
{
public:
    static Tween24Ptr create(cocos2d::Node *target, float duration, Ease24 easing);

    #pragma mark constructor & destructor
    Tween24(cocos2d::Node *target, float duration, Ease24 easing);
    virtual ~Tween24();

    #pragma mark ITween24 interface
    cocos2d::ActionInterval *getAction() override;

    #pragma mark position
    Tween24Ptr x(float x);
    Tween24Ptr $x(float $x);
    Tween24Ptr y(float y);
    Tween24Ptr $y(float $y);
    Tween24Ptr xy(float x, float y);
    Tween24Ptr $xy(float $x, float $y);

    #pragma mark scale
    Tween24Ptr scaleX(float sx);
    Tween24Ptr $scaleX(float $sx);
    Tween24Ptr scaleY(float sy);
    Tween24Ptr $scaleY(float $sy);
    Tween24Ptr scaleZ(float sz);
    Tween24Ptr $scaleZ(float $sz);
    Tween24Ptr scale(float s);
    Tween24Ptr $scale(float $s);
    Tween24Ptr scale(float sx, float sy);
    Tween24Ptr $scale(float $sx, float $sy);
    Tween24Ptr scale(float sx, float sy, float sz);
    Tween24Ptr $scale(float $sx, float $sy, float $sz);

    #pragma mark rorate
    Tween24Ptr rotateX(float angleX);
    Tween24Ptr $rotateX(float $angleX);
    Tween24Ptr rotateY(float angleY);
    Tween24Ptr $rotateY(float $angleX);
    Tween24Ptr rotate(float angle);
    Tween24Ptr $rotate(float angle);
    Tween24Ptr rotate(float angleX, float angleY);
    Tween24Ptr $rotate(float $angleX, float $angleY);
    Tween24Ptr rotate(const cocos2d::Vec3 &angle3D);
    Tween24Ptr $rotate(const cocos2d::Vec3 &$angle3D);

    #pragma mark delay
    Tween24Ptr delay(float delayTime);

    #pragma mark property
    CC_SYNTHESIZE_READONLY(float, _duration, Duration);
    CC_SYNTHESIZE_READONLY(Ease24, _easing, Easing);

private:
    cocos2d::Vector<cocos2d::FiniteTimeAction *> _actions;
    void addAction(cocos2d::FiniteTimeAction *action);

    cocos2d::ActionInterval *addEasing(cocos2d::ActionInterval *action);

    float _delayTime {0};
    cocos2d::ActionInterval *addDelay(cocos2d::ActionInterval *action);
};
} // namespace

#endif /* defined(__CocosTween24__Tween24__) */
