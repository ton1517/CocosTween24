#ifndef __TweenCC__Tween__
#define __TweenCC__Tween__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"
#include "Ease.hpp"

namespace tweencc
{
class Tween;
typedef std::shared_ptr<Tween> TweenPtr;

class Tween : public IInterval, public Player, public std::enable_shared_from_this<Tween>
{
public:
    static TweenPtr create(cocos2d::Node *target, float duration, Ease easing);
    static TweenPtr create(const std::vector<cocos2d::Node *> &targets, float duration, Ease easing);

    #pragma mark constructor & destructor
    Tween(cocos2d::Node *target, float duration, Ease easing);
    Tween(const std::vector<cocos2d::Node *> &targets, float duration, Ease easing);
    virtual ~Tween() = default;

    #pragma mark IInterval interface
    cocos2d::ActionInterval *generateAction() override;

    #pragma mark position
    //    TweenPtr x(float x);
    //    TweenPtr $x(float $x);
    //    TweenPtr y(float y);
    //    TweenPtr $y(float $y);
    TweenPtr xy(float x, float y);
    TweenPtr $xy(float $x, float $y);
    TweenPtr xy(const cocos2d::Vec2 &pos);
    TweenPtr $xy(const cocos2d::Vec2 &pos);

    #pragma mark scale
    //    TweenPtr scaleX(float sx);
    //    TweenPtr $scaleX(float $sx);
    //    TweenPtr scaleY(float sy);
    //    TweenPtr $scaleY(float $sy);
    //    TweenPtr scaleZ(float sz);
    //    TweenPtr $scaleZ(float $sz);
    TweenPtr scale(float s);
    TweenPtr $scale(float $s);
    TweenPtr scale(float sx, float sy);
    TweenPtr $scale(float $sx, float $sy);
    TweenPtr scale(float sx, float sy, float sz);
    TweenPtr $scale(float $sx, float $sy, float $sz);

    #pragma mark rorate
    //    TweenPtr rotateX(float angleX);
    //    TweenPtr $rotateX(float $angleX);
    //    TweenPtr rotateY(float angleY);
    //    TweenPtr $rotateY(float $angleX);
    TweenPtr rotate(float angle);
    TweenPtr $rotate(float angle);
    TweenPtr rotate(float angleX, float angleY);
    TweenPtr $rotate(float $angleX, float $angleY);
    TweenPtr rotate(const cocos2d::Vec3 &angle3D);
    TweenPtr $rotate(const cocos2d::Vec3 &$angle3D);

    #pragma mark fade
    TweenPtr fadeIn();
    TweenPtr fadeOut();
    TweenPtr fadeTo(GLubyte opacity);

    #pragma mark jump
    TweenPtr jump(const cocos2d::Vec2 &position, float height, int jumps);
    TweenPtr $jump(const cocos2d::Vec2 &position, float height, int jumps);
    TweenPtr jumpUp(float height, int jumps);

    #pragma mark bezier
    TweenPtr bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint);
    TweenPtr $bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint);
    TweenPtr bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2);
    TweenPtr $bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2);
    TweenPtr bezier(const cocos2d::ccBezierConfig &bezierConfig);
    TweenPtr $bezier(const cocos2d::ccBezierConfig &bezierConfig);

    #pragma mark blink
    TweenPtr blink(int times);

    #pragma mark tint
    TweenPtr tint(GLubyte red, GLubyte green, GLubyte blue);
    TweenPtr $tint(GLubyte red, GLubyte green, GLubyte blue);
    TweenPtr tint(const cocos2d::Color3B &color);
    TweenPtr $tint(const cocos2d::Color3B &color);

    #pragma mark delay
    TweenPtr delay(float delayTime);

    #pragma mark update
    TweenPtr onUpdate(const std::function<void(float)> &func);

    #pragma mark property
    CC_SYNTHESIZE_READONLY(float, _duration, Duration);
    CC_SYNTHESIZE_READONLY(Ease, _easing, Easing);

private:
    cocos2d::Vector<cocos2d::FiniteTimeAction *> _actions;
    void addAction(cocos2d::FiniteTimeAction *action);

    cocos2d::ActionInterval *addEasing(cocos2d::ActionInterval *action);

    float _delayTime {0};
    cocos2d::ActionInterval *addDelay(cocos2d::ActionInterval *action);

    Tween(const Tween&)           = delete;
    Tween(Tween&&)                = delete;
    Tween&operator=(const Tween&) = delete;
    Tween&operator=(Tween&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Tween__) */
