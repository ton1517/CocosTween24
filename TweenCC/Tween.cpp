#include "Tween.hpp"

#include "UpdateFuncAction.hpp"

namespace tweencc
{
#pragma mark----- static -----

TweenPtr Tween::create(cocos2d::Node *target, float duration, Ease easing)
{
    auto t = std::make_shared<Tween>(target, duration, easing);

    return std::move(t);
}

#pragma mark----- public -----

Tween::Tween(cocos2d::Node *target, float duration, Ease easing) : Player(this, target), _duration(duration), _easing(easing) {}

cocos2d::ActionInterval *Tween::generateAction()
{
    cocos2d::ActionInterval *action = cocos2d::Spawn::create(_actions);
    action = this->addDelay(action);
    action = this->addEasing(action);
    auto targetedAction = cocos2d::TargetedAction::create(getTarget(), action);

    return targetedAction;
}

#pragma mark position

// TweenPtr Tween::x(float x)
// {
//    auto pos    = getTarget()->getPosition();
//    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(x, pos.y));
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$x(float $x)
// {
//    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point($x, 0));
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::y(float y)
// {
//    auto pos    = getTarget()->getPosition();
//    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(pos.x, y));
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$y(float $y)
// {
//    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point(0, $y));
//    addAction(action);
//
//    return shared_from_this();
// }

TweenPtr Tween::xy(float x, float y)
{
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(x, y));
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$xy(float $x, float $y)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point($x, $y));
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::xy(const cocos2d::Vec2 &pos)
{
    auto action = cocos2d::MoveTo::create(_duration, pos);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$xy(const cocos2d::Vec2 &pos)
{
    auto action = cocos2d::MoveBy::create(_duration, pos);
    addAction(action);

    return shared_from_this();
}

#pragma mark scale

// TweenPtr Tween::scaleX(float sx)
// {
//    auto action = cocos2d::ScaleTo::create(_duration, sx, getTarget()->getScaleY());
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$scaleX(float $sx)
// {
//    auto action = cocos2d::ScaleBy::create(_duration, $sx, 0);
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::scaleY(float sy)
// {
//    auto action = cocos2d::ScaleTo::create(_duration, getTarget()->getScaleX(), sy);
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$scaleY(float $sy)
// {
//    auto action = cocos2d::ScaleBy::create(_duration, 0, $sy);
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::scaleZ(float sz)
// {
//    auto action = cocos2d::ScaleTo::create(_duration, getTarget()->getScaleX(), getTarget()->getScaleY(), sz);
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$scaleZ(float $sz)
// {
//    auto action = cocos2d::ScaleBy::create(_duration, 0, 0, $sz);
//    addAction(action);
//
//    return shared_from_this();
// }

TweenPtr Tween::scale(float s)
{
    auto action = cocos2d::ScaleTo::create(_duration, s);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$scale(float $s)
{
    auto action = cocos2d::ScaleBy::create(_duration, $s);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::scale(float sx, float sy)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, sy);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$scale(float $sx, float $sy)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, $sy);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::scale(float sx, float sy, float sz)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, sy, sz);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$scale(float $sx, float $sy, float $sz)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, $sy, $sz);
    addAction(action);

    return shared_from_this();
}

#pragma mark rotate

// TweenPtr Tween::rotateX(float angleX)
// {
//    auto action = cocos2d::RotateTo::create(_duration, angleX, getTarget()->getRotationSkewY());
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$rotateX(float $angleX)
// {
//    auto action = cocos2d::RotateBy::create(_duration, $angleX, 0);
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::rotateY(float angleY)
// {
//    auto action = cocos2d::RotateTo::create(_duration, getTarget()->getRotationSkewX(), angleY);
//    addAction(action);
//
//    return shared_from_this();
// }
//
// TweenPtr Tween::$rotateY(float $angleY)
// {
//    auto action = cocos2d::RotateBy::create(_duration, 0, $angleY);
//    addAction(action);
//
//    return shared_from_this();
// }

TweenPtr Tween::rotate(float angle)
{
    auto action = cocos2d::RotateTo::create(_duration, angle);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$rotate(float $angle)
{
    auto action = cocos2d::RotateBy::create(_duration, $angle);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::rotate(float angleX, float angleY)
{
    auto action = cocos2d::RotateTo::create(_duration, angleX, angleY);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$rotate(float $angleX, float $angleY)
{
    auto action = cocos2d::RotateBy::create(_duration, $angleX, $angleY);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::rotate(const cocos2d::Vec3 &angle3D)
{
    auto action = cocos2d::RotateTo::create(_duration, angle3D);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$rotate(const cocos2d::Vec3 &$angle3D)
{
    auto action = cocos2d::RotateBy::create(_duration, $angle3D);
    addAction(action);

    return shared_from_this();
}

#pragma mark fade
TweenPtr Tween::fadeIn()
{
    auto action = cocos2d::FadeIn::create(_duration);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::fadeOut()
{
    auto action = cocos2d::FadeOut::create(_duration);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::fadeTo(GLubyte opacity)
{
    auto action = cocos2d::FadeTo::create(_duration, opacity);
    addAction(action);

    return shared_from_this();
}

#pragma mark jump
TweenPtr Tween::jump(const cocos2d::Vec2 &position, float height, int jumps)
{
    auto action = cocos2d::JumpTo::create(_duration, position, height, jumps);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$jump(const cocos2d::Vec2 &position, float height, int jumps)
{
    auto action = cocos2d::JumpBy::create(_duration, position, height, jumps);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::jumpUp(float height, int jumps)
{
    $jump(cocos2d::Vec2(0, 0), height, jumps);

    return shared_from_this();
}

#pragma mark bezier
TweenPtr Tween::bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint)
{
    auto action = cocos2d::BezierTo::create(_duration, {endPosition, controlPoint, controlPoint});
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint)
{
    auto action = cocos2d::BezierBy::create(_duration, {endPosition, controlPoint, controlPoint});
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2)
{
    auto action = cocos2d::BezierTo::create(_duration, {endPosition, controlPoint1, controlPoint2});
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$bezier(const cocos2d::Vec2 &endPosition, const cocos2d::Vec2 &controlPoint1, const cocos2d::Vec2 &controlPoint2)
{
    auto action = cocos2d::BezierBy::create(_duration, {endPosition, controlPoint1, controlPoint2});
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::bezier(const cocos2d::ccBezierConfig &bezierConfig)
{
    auto action = cocos2d::BezierTo::create(_duration, bezierConfig);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$bezier(const cocos2d::ccBezierConfig &bezierConfig)
{
    auto action = cocos2d::BezierBy::create(_duration, bezierConfig);
    addAction(action);

    return shared_from_this();
}

#pragma mark blink
TweenPtr Tween::blink(int times)
{
    auto action = cocos2d::Blink::create(_duration, times);
    addAction(action);

    return shared_from_this();
}

#pragma mark tint
TweenPtr Tween::tint(GLubyte red, GLubyte green, GLubyte blue)
{
    auto action = cocos2d::TintTo::create(_duration, red, green, blue);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$tint(GLubyte red, GLubyte green, GLubyte blue)
{
    auto action = cocos2d::TintBy::create(_duration, red, green, blue);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::tint(const cocos2d::Color3B &color)
{
    auto action = cocos2d::TintTo::create(_duration, color.r, color.g, color.b);
    addAction(action);

    return shared_from_this();
}

TweenPtr Tween::$tint(const cocos2d::Color3B &color)
{
    auto action = cocos2d::TintBy::create(_duration, color.r, color.g, color.b);
    addAction(action);

    return shared_from_this();
}

#pragma mark delay

TweenPtr Tween::delay(float delayTime)
{
    _delayTime = delayTime;

    return shared_from_this();
}

#pragma mark update

TweenPtr Tween::onUpdate(const std::function<void(float)> &func)
{
    auto action = UpdateFuncAction::create(_duration, func);
    addAction(action);

    return shared_from_this();
}

#pragma mark----- private -----

void Tween::addAction(cocos2d::FiniteTimeAction *action)
{
    _actions.pushBack(action);
}

cocos2d::ActionInterval *Tween::addEasing(cocos2d::ActionInterval *action)
{
    switch (_easing) {
        case Ease::Linear:
            return action;
        case Ease::SineIn:
        case Ease::_1_SineIn:
            return cocos2d::EaseSineIn::create(action);
        case Ease::SineOut:
        case Ease::_1_SineOut:
            return cocos2d::EaseSineOut::create(action);
        case Ease::SineInOut:
        case Ease::_1_SineInOut:
            return cocos2d::EaseSineInOut::create(action);
        case Ease::QuadIn:
        case Ease::_2_QuadIn:
            return cocos2d::EaseQuadraticActionIn::create(action);
        case Ease::QuadOut:
        case Ease::_2_QuadOut:
            return cocos2d::EaseQuadraticActionOut::create(action);
        case Ease::QuadInOut:
        case Ease::_2_QuadInOut:
            return cocos2d::EaseQuadraticActionInOut::create(action);
        case Ease::CubicIn:
        case Ease::_3_CubicIn:
            return cocos2d::EaseCubicActionIn::create(action);
        case Ease::CubicOut:
        case Ease::_3_CubicOut:
            return cocos2d::EaseCubicActionOut::create(action);
        case Ease::CubicInOut:
        case Ease::_3_CubicInOut:
            return cocos2d::EaseCubicActionInOut::create(action);
        case Ease::QuartIn:
        case Ease::_4_QuartIn:
            return cocos2d::EaseQuarticActionIn::create(action);
        case Ease::QuartOut:
        case Ease::_4_QuartOut:
            return cocos2d::EaseQuarticActionOut::create(action);
        case Ease::QuartInOut:
        case Ease::_4_QuartInOut:
            return cocos2d::EaseQuarticActionInOut::create(action);
        case Ease::QuintIn:
        case Ease::_5_QuintIn:
            return cocos2d::EaseQuinticActionIn::create(action);
        case Ease::QuintOut:
        case Ease::_5_QuintOut:
            return cocos2d::EaseQuinticActionOut::create(action);
        case Ease::QuintInOut:
        case Ease::_5_QuintInOut:
            return cocos2d::EaseQuinticActionInOut::create(action);
        case Ease::ExpoIn:
        case Ease::_6_ExpoIn:
            return cocos2d::EaseExponentialIn::create(action);
        case Ease::ExpoOut:
        case Ease::_6_ExpoOut:
            return cocos2d::EaseExponentialOut::create(action);
        case Ease::ExpoInOut:
        case Ease::_6_ExpoInOut:
            return cocos2d::EaseExponentialInOut::create(action);
        case Ease::CircIn:
        case Ease::_7_CircIn:
            return cocos2d::EaseCircleActionIn::create(action);
        case Ease::CircOut:
        case Ease::_7_CircOut:
            return cocos2d::EaseCircleActionOut::create(action);
        case Ease::CircInOut:
        case Ease::_7_CircInOut:
            return cocos2d::EaseCircleActionInOut::create(action);
        case Ease::ElasticIn:
            return cocos2d::EaseElasticIn::create(action);
        case Ease::ElasticOut:
            return cocos2d::EaseElasticOut::create(action);
        case Ease::ElasticInOut:
            return cocos2d::EaseElasticInOut::create(action);
        case Ease::BackIn:
            return cocos2d::EaseBackIn::create(action);
        case Ease::BackOut:
            return cocos2d::EaseBackOut::create(action);
        case Ease::BackInOut:
            return cocos2d::EaseBackInOut::create(action);
        case Ease::BounceIn:
            return cocos2d::EaseBounceIn::create(action);
        case Ease::BounceOut:
            return cocos2d::EaseBounceOut::create(action);
        case Ease::BounceInOut:
            return cocos2d::EaseBounceInOut::create(action);
    }
}

cocos2d::ActionInterval *Tween::addDelay(cocos2d::ActionInterval *action)
{
    if (_delayTime == 0) {
        return action;
    }

    return cocos2d::Sequence::create(cocos2d::DelayTime::create(_delayTime), action, nullptr);
}
} // namespace