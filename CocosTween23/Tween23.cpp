#include "Tween23.hpp"

namespace tween23
{
#pragma mark----- static -----

Tween23Ptr Tween23::create(cocos2d::Node *target, float duration, Ease23 easing)
{
    auto t23 = std::make_shared<Tween23>(target, duration, easing);

    return std::move(t23);
}

#pragma mark----- public -----

Tween23::Tween23(cocos2d::Node *target, float duration, Ease23 easing) : Player23(this, target), _duration(duration), _easing(easing) {}

cocos2d::ActionInterval *Tween23::generateAction()
{
    cocos2d::ActionInterval *action = cocos2d::Spawn::create(_actions);
    action = this->addDelay(action);
    action = this->addEasing(action);
    auto targetedAction = cocos2d::TargetedAction::create(getTarget(), action);

    return targetedAction;
}

#pragma mark position

Tween23Ptr Tween23::x(float x)
{
    auto pos    = getTarget()->getPosition();
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(x, pos.y));
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$x(float $x)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point($x, 0));
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::y(float y)
{
    auto pos    = getTarget()->getPosition();
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(pos.x, y));
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$y(float $y)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point(0, $y));
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::xy(float x, float y)
{
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(x, y));
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$xy(float $x, float $y)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point($x, $y));
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::xy(const cocos2d::Vec2 &pos)
{
    auto action = cocos2d::MoveTo::create(_duration, pos);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$xy(const cocos2d::Vec2 &pos)
{
    auto action = cocos2d::MoveBy::create(_duration, pos);
    addAction(action);

    return shared_from_this();
}

#pragma mark scale

Tween23Ptr Tween23::scaleX(float sx)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, getTarget()->getScaleY());
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$scaleX(float $sx)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, 0);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::scaleY(float sy)
{
    auto action = cocos2d::ScaleTo::create(_duration, getTarget()->getScaleX(), sy);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$scaleY(float $sy)
{
    auto action = cocos2d::ScaleBy::create(_duration, 0, $sy);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::scaleZ(float sz)
{
    auto action = cocos2d::ScaleTo::create(_duration, getTarget()->getScaleX(), getTarget()->getScaleY(), sz);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$scaleZ(float $sz)
{
    auto action = cocos2d::ScaleBy::create(_duration, 0, 0, $sz);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::scale(float s)
{
    auto action = cocos2d::ScaleTo::create(_duration, s);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$scale(float $s)
{
    auto action = cocos2d::ScaleBy::create(_duration, $s);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::scale(float sx, float sy)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, sy);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$scale(float $sx, float $sy)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, $sy);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::scale(float sx, float sy, float sz)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, sy, sz);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$scale(float $sx, float $sy, float $sz)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, $sy, $sz);
    addAction(action);

    return shared_from_this();
}

#pragma mark rotate

Tween23Ptr Tween23::rotateX(float angleX)
{
    auto action = cocos2d::RotateTo::create(_duration, angleX, getTarget()->getRotationSkewY());
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$rotateX(float $angleX)
{
    auto action = cocos2d::RotateBy::create(_duration, $angleX, 0);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::rotateY(float angleY)
{
    auto action = cocos2d::RotateTo::create(_duration, getTarget()->getRotationSkewX(), angleY);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$rotateY(float $angleY)
{
    auto action = cocos2d::RotateBy::create(_duration, 0, $angleY);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::rotate(float angle)
{
    auto action = cocos2d::RotateTo::create(_duration, angle);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$rotate(float $angle)
{
    auto action = cocos2d::RotateBy::create(_duration, $angle);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::rotate(float angleX, float angleY)
{
    auto action = cocos2d::RotateTo::create(_duration, angleX, angleY);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$rotate(float $angleX, float $angleY)
{
    auto action = cocos2d::RotateBy::create(_duration, $angleX, $angleY);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::rotate(const cocos2d::Vec3 &angle3D)
{
    auto action = cocos2d::RotateTo::create(_duration, angle3D);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$rotate(const cocos2d::Vec3 &$angle3D)
{
    auto action = cocos2d::RotateBy::create(_duration, $angle3D);
    addAction(action);

    return shared_from_this();
}

#pragma mark fade
Tween23Ptr Tween23::fadeIn()
{
    auto action = cocos2d::FadeIn::create(_duration);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::fadeOut()
{
    auto action = cocos2d::FadeOut::create(_duration);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::fadeTo(GLubyte opacity)
{
    auto action = cocos2d::FadeTo::create(_duration, opacity);
    addAction(action);

    return shared_from_this();
}

#pragma mark jump
Tween23Ptr Tween23::jump(const cocos2d::Vec2 &position, float height, int jumps)
{
    auto action = cocos2d::JumpTo::create(_duration, position, height, jumps);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$jump(const cocos2d::Vec2 &position, float height, int jumps)
{
    auto action = cocos2d::JumpBy::create(_duration, position, height, jumps);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::jumpUp(float height, int jumps)
{
    $jump(cocos2d::Vec2(0, 0), height, jumps);

    return shared_from_this();
}

#pragma mark bezier
Tween23Ptr Tween23::bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint)
{
    auto action = cocos2d::BezierTo::create(_duration, {endPosition, controlPoint, controlPoint});
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint)
{
    auto action = cocos2d::BezierBy::create(_duration, {endPosition, controlPoint, controlPoint});
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2)
{
    auto action = cocos2d::BezierTo::create(_duration, {endPosition, controlPoint1, controlPoint2});
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2)
{
    auto action = cocos2d::BezierBy::create(_duration, {endPosition, controlPoint1, controlPoint2});
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::bezier(const cocos2d::ccBezierConfig &bezierConfig)
{
    auto action = cocos2d::BezierTo::create(_duration, bezierConfig);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$bezier(const cocos2d::ccBezierConfig &bezierConfig)
{
    auto action = cocos2d::BezierBy::create(_duration, bezierConfig);
    addAction(action);

    return shared_from_this();
}

#pragma mark blink
Tween23Ptr Tween23::blink(int times)
{
    auto action = cocos2d::Blink::create(_duration, times);
    addAction(action);

    return shared_from_this();
}

#pragma mark tint
Tween23Ptr Tween23::tint(GLubyte red, GLubyte green, GLubyte blue)
{
    auto action = cocos2d::TintTo::create(_duration, red, green, blue);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$tint(GLubyte red, GLubyte green, GLubyte blue)
{
    auto action = cocos2d::TintBy::create(_duration, red, green, blue);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::tint(const cocos2d::Color3B &color)
{
    auto action = cocos2d::TintTo::create(_duration, color.r, color.g, color.b);
    addAction(action);

    return shared_from_this();
}

Tween23Ptr Tween23::$tint(const cocos2d::Color3B &color)
{
    auto action = cocos2d::TintBy::create(_duration, color.r, color.g, color.b);
    addAction(action);

    return shared_from_this();
}

#pragma mark delay

Tween23Ptr Tween23::delay(float delayTime)
{
    _delayTime = delayTime;

    return shared_from_this();
}

#pragma mark----- private -----

void Tween23::addAction(cocos2d::FiniteTimeAction *action)
{
    _actions.pushBack(action);
}

cocos2d::ActionInterval *Tween23::addEasing(cocos2d::ActionInterval *action)
{
    switch (_easing) {
        case Ease23::Linear:
            return action;
        case Ease23::SineIn:
        case Ease23::_1_SineIn:
            return cocos2d::EaseSineIn::create(action);
        case Ease23::SineOut:
        case Ease23::_1_SineOut:
            return cocos2d::EaseSineOut::create(action);
        case Ease23::SineInOut:
        case Ease23::_1_SineInOut:
            return cocos2d::EaseSineInOut::create(action);
        case Ease23::QuadIn:
        case Ease23::_2_QuadIn:
            return cocos2d::EaseQuadraticActionIn::create(action);
        case Ease23::QuadOut:
        case Ease23::_2_QuadOut:
            return cocos2d::EaseQuadraticActionOut::create(action);
        case Ease23::QuadInOut:
        case Ease23::_2_QuadInOut:
            return cocos2d::EaseQuadraticActionInOut::create(action);
        case Ease23::CubicIn:
        case Ease23::_3_CubicIn:
            return cocos2d::EaseCubicActionIn::create(action);
        case Ease23::CubicOut:
        case Ease23::_3_CubicOut:
            return cocos2d::EaseCubicActionOut::create(action);
        case Ease23::CubicInOut:
        case Ease23::_3_CubicInOut:
            return cocos2d::EaseCubicActionInOut::create(action);
        case Ease23::QuartIn:
        case Ease23::_4_QuartIn:
            return cocos2d::EaseQuarticActionIn::create(action);
        case Ease23::QuartOut:
        case Ease23::_4_QuartOut:
            return cocos2d::EaseQuarticActionOut::create(action);
        case Ease23::QuartInOut:
        case Ease23::_4_QuartInOut:
            return cocos2d::EaseQuarticActionInOut::create(action);
        case Ease23::QuintIn:
        case Ease23::_5_QuintIn:
            return cocos2d::EaseQuinticActionIn::create(action);
        case Ease23::QuintOut:
        case Ease23::_5_QuintOut:
            return cocos2d::EaseQuinticActionOut::create(action);
        case Ease23::QuintInOut:
        case Ease23::_5_QuintInOut:
            return cocos2d::EaseQuinticActionInOut::create(action);
        case Ease23::ExpoIn:
        case Ease23::_6_ExpoIn:
            return cocos2d::EaseExponentialIn::create(action);
        case Ease23::ExpoOut:
        case Ease23::_6_ExpoOut:
            return cocos2d::EaseExponentialOut::create(action);
        case Ease23::ExpoInOut:
        case Ease23::_6_ExpoInOut:
            return cocos2d::EaseExponentialInOut::create(action);
        case Ease23::CircIn:
        case Ease23::_7_CircIn:
            return cocos2d::EaseCircleActionIn::create(action);
        case Ease23::CircOut:
        case Ease23::_7_CircOut:
            return cocos2d::EaseCircleActionOut::create(action);
        case Ease23::CircInOut:
        case Ease23::_7_CircInOut:
            return cocos2d::EaseCircleActionInOut::create(action);
        case Ease23::ElasticIn:
            return cocos2d::EaseElasticIn::create(action);
        case Ease23::ElasticOut:
            return cocos2d::EaseElasticOut::create(action);
        case Ease23::ElasticInOut:
            return cocos2d::EaseElasticInOut::create(action);
        case Ease23::BackIn:
            return cocos2d::EaseBackIn::create(action);
        case Ease23::BackOut:
            return cocos2d::EaseBackOut::create(action);
        case Ease23::BackInOut:
            return cocos2d::EaseBackInOut::create(action);
        case Ease23::BounceIn:
            return cocos2d::EaseBounceIn::create(action);
        case Ease23::BounceOut:
            return cocos2d::EaseBounceOut::create(action);
        case Ease23::BounceInOut:
            return cocos2d::EaseBounceInOut::create(action);
    }
}

cocos2d::ActionInterval *Tween23::addDelay(cocos2d::ActionInterval *action)
{
    if (_delayTime == 0) {
        return action;
    }

    return cocos2d::Sequence::create(cocos2d::DelayTime::create(_delayTime), action, nullptr);
}
} // namespace