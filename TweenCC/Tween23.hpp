#ifndef __CocosTween23__Tween23__
#define __CocosTween23__Tween23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"
#include "Ease23.hpp"

namespace tween23
{
class Tween23;
typedef std::shared_ptr<Tween23> Tween23Ptr;

class Tween23 : public IInterval23, public Player23, public std::enable_shared_from_this<Tween23>
{
public:
    static Tween23Ptr create(cocos2d::Node *target, float duration, Ease23 easing);

    #pragma mark constructor & destructor
    Tween23(cocos2d::Node *target, float duration, Ease23 easing);
    virtual ~Tween23() = default;

    #pragma mark IInterval23 interface
    cocos2d::ActionInterval *generateAction() override;

    #pragma mark position
    Tween23Ptr x(float x);
    Tween23Ptr $x(float $x);
    Tween23Ptr y(float y);
    Tween23Ptr $y(float $y);
    Tween23Ptr xy(float x, float y);
    Tween23Ptr $xy(float $x, float $y);
    Tween23Ptr xy(const cocos2d::Vec2 &pos);
    Tween23Ptr $xy(const cocos2d::Vec2 &pos);

    #pragma mark scale
    Tween23Ptr scaleX(float sx);
    Tween23Ptr $scaleX(float $sx);
    Tween23Ptr scaleY(float sy);
    Tween23Ptr $scaleY(float $sy);
    Tween23Ptr scaleZ(float sz);
    Tween23Ptr $scaleZ(float $sz);
    Tween23Ptr scale(float s);
    Tween23Ptr $scale(float $s);
    Tween23Ptr scale(float sx, float sy);
    Tween23Ptr $scale(float $sx, float $sy);
    Tween23Ptr scale(float sx, float sy, float sz);
    Tween23Ptr $scale(float $sx, float $sy, float $sz);

    #pragma mark rorate
    Tween23Ptr rotateX(float angleX);
    Tween23Ptr $rotateX(float $angleX);
    Tween23Ptr rotateY(float angleY);
    Tween23Ptr $rotateY(float $angleX);
    Tween23Ptr rotate(float angle);
    Tween23Ptr $rotate(float angle);
    Tween23Ptr rotate(float angleX, float angleY);
    Tween23Ptr $rotate(float $angleX, float $angleY);
    Tween23Ptr rotate(const cocos2d::Vec3 &angle3D);
    Tween23Ptr $rotate(const cocos2d::Vec3 &$angle3D);

    #pragma mark fade
    Tween23Ptr fadeIn();
    Tween23Ptr fadeOut();
    Tween23Ptr fadeTo(GLubyte opacity);

    #pragma mark jump
    Tween23Ptr jump(const cocos2d::Vec2 &position, float height, int jumps);
    Tween23Ptr $jump(const cocos2d::Vec2 &position, float height, int jumps);
    Tween23Ptr jumpUp(float height, int jumps);

    #pragma mark bezier
    Tween23Ptr bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint);
    Tween23Ptr $bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint);
    Tween23Ptr bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2);
    Tween23Ptr $bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2);
    Tween23Ptr bezier(const cocos2d::ccBezierConfig &bezierConfig);
    Tween23Ptr $bezier(const cocos2d::ccBezierConfig &bezierConfig);

    #pragma mark blink
    Tween23Ptr blink(int times);

    #pragma mark tint
    Tween23Ptr tint(GLubyte red, GLubyte green, GLubyte blue);
    Tween23Ptr $tint(GLubyte red, GLubyte green, GLubyte blue);
    Tween23Ptr tint(const cocos2d::Color3B &color);
    Tween23Ptr $tint(const cocos2d::Color3B &color);

    #pragma mark delay
    Tween23Ptr delay(float delayTime);

    #pragma mark property
    CC_SYNTHESIZE_READONLY(float, _duration, Duration);
    CC_SYNTHESIZE_READONLY(Ease23, _easing, Easing);

private:
    cocos2d::Vector<cocos2d::FiniteTimeAction *> _actions;
    void addAction(cocos2d::FiniteTimeAction *action);

    cocos2d::ActionInterval *addEasing(cocos2d::ActionInterval *action);

    float _delayTime {0};
    cocos2d::ActionInterval *addDelay(cocos2d::ActionInterval *action);

    Tween23(const Tween23&)           = delete;
    Tween23(Tween23&&)                = delete;
    Tween23&operator=(const Tween23&) = delete;
    Tween23&operator=(Tween23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Tween23__) */
