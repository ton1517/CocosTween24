#include "Tween24.hpp"

namespace cocosTween24
{
#pragma mark----- static -----

Tween24Ptr Tween24::create(cocos2d::Node *target, float duration, Ease24 easing)
{
    auto t24 = std::make_shared<Tween24>(target, duration, easing);

    return std::move(t24);
}

#pragma mark----- public -----

Tween24::Tween24(cocos2d::Node *target, float duration, Ease24 easing) : cocosTween24::Player24(target), _duration(duration), _easing(easing) {}

cocos2d::ActionInterval *Tween24::getAction()
{
    cocos2d::ActionInterval *action = cocos2d::Spawn::create(_actions);
    action = this->addDelay(action);
    action = this->addEasing(action);
    auto targetedAction = cocos2d::TargetedAction::create(getTarget(), action);

    return targetedAction;
}

#pragma mark position

Tween24Ptr Tween24::x(float x)
{
    auto pos    = getTarget()->getPosition();
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(x, pos.y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$x(float $x)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point($x, 0));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::y(float y)
{
    auto pos    = getTarget()->getPosition();
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(pos.x, y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$y(float $y)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point(0, $y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::xy(float x, float y)
{
    auto action = cocos2d::MoveTo::create(_duration, cocos2d::Point(x, y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$xy(float $x, float $y)
{
    auto action = cocos2d::MoveBy::create(_duration, cocos2d::Point($x, $y));
    addAction(action);

    return shared_from_this();
}

#pragma mark scale

Tween24Ptr Tween24::scaleX(float sx)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, getTarget()->getScaleY());
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scaleX(float $sx)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, 0);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scaleY(float sy)
{
    auto action = cocos2d::ScaleTo::create(_duration, getTarget()->getScaleX(), sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scaleY(float $sy)
{
    auto action = cocos2d::ScaleBy::create(_duration, 0, $sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scaleZ(float sz)
{
    auto action = cocos2d::ScaleTo::create(_duration, getTarget()->getScaleX(), getTarget()->getScaleY(), sz);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scaleZ(float $sz)
{
    auto action = cocos2d::ScaleBy::create(_duration, 0, 0, $sz);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scale(float s)
{
    auto action = cocos2d::ScaleTo::create(_duration, s);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scale(float $s)
{
    auto action = cocos2d::ScaleBy::create(_duration, $s);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scale(float sx, float sy)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scale(float $sx, float $sy)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, $sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scale(float sx, float sy, float sz)
{
    auto action = cocos2d::ScaleTo::create(_duration, sx, sy, sz);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scale(float $sx, float $sy, float $sz)
{
    auto action = cocos2d::ScaleBy::create(_duration, $sx, $sy, $sz);
    addAction(action);

    return shared_from_this();
}

#pragma mark rotate

Tween24Ptr Tween24::rotateX(float angleX)
{
    auto action = cocos2d::RotateTo::create(_duration, angleX, getTarget()->getRotationSkewY());
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotateX(float $angleX)
{
    auto action = cocos2d::RotateBy::create(_duration, $angleX, 0);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotateY(float angleY)
{
    auto action = cocos2d::RotateTo::create(_duration, getTarget()->getRotationSkewX(), angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotateY(float $angleY)
{
    auto action = cocos2d::RotateBy::create(_duration, 0, $angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotate(float angle)
{
    auto action = cocos2d::RotateTo::create(_duration, angle);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotate(float $angle)
{
    auto action = cocos2d::RotateBy::create(_duration, $angle);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotate(float angleX, float angleY)
{
    auto action = cocos2d::RotateTo::create(_duration, angleX, angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotate(float $angleX, float $angleY)
{
    auto action = cocos2d::RotateBy::create(_duration, $angleX, $angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotate(const cocos2d::Vec3 &angle3D)
{
    auto action = cocos2d::RotateTo::create(_duration, angle3D);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotate(const cocos2d::Vec3 &$angle3D)
{
    auto action = cocos2d::RotateBy::create(_duration, $angle3D);
    addAction(action);

    return shared_from_this();
}

#pragma mark delay

Tween24Ptr Tween24::delay(float delayTime)
{
    _delayTime = delayTime;

    return shared_from_this();
}

#pragma mark----- private -----

void Tween24::addAction(cocos2d::FiniteTimeAction *action)
{
    _actions.pushBack(action);
}

cocos2d::ActionInterval *Tween24::addEasing(cocos2d::ActionInterval *action)
{
    switch (_easing) {
        case Ease24::Linear:
            return action;
        case Ease24::SineIn:
        case Ease24::_1_SineIn:
            return cocos2d::EaseSineIn::create(action);
        case Ease24::SineOut:
        case Ease24::_1_SineOut:
            return cocos2d::EaseSineOut::create(action);
        case Ease24::SineInOut:
        case Ease24::_1_SineInOut:
            return cocos2d::EaseSineInOut::create(action);
        case Ease24::QuadIn:
        case Ease24::_2_QuadIn:
            return cocos2d::EaseQuadraticActionIn::create(action);
        case Ease24::QuadOut:
        case Ease24::_2_QuadOut:
            return cocos2d::EaseQuadraticActionOut::create(action);
        case Ease24::QuadInOut:
        case Ease24::_2_QuadInOut:
            return cocos2d::EaseQuadraticActionInOut::create(action);
        case Ease24::CubicIn:
        case Ease24::_3_CubicIn:
            return cocos2d::EaseCubicActionIn::create(action);
        case Ease24::CubicOut:
        case Ease24::_3_CubicOut:
            return cocos2d::EaseCubicActionOut::create(action);
        case Ease24::CubicInOut:
        case Ease24::_3_CubicInOut:
            return cocos2d::EaseCubicActionInOut::create(action);
        case Ease24::QuartIn:
        case Ease24::_4_QuartIn:
            return cocos2d::EaseQuarticActionIn::create(action);
        case Ease24::QuartOut:
        case Ease24::_4_QuartOut:
            return cocos2d::EaseQuarticActionOut::create(action);
        case Ease24::QuartInOut:
        case Ease24::_4_QuartInOut:
            return cocos2d::EaseQuarticActionInOut::create(action);
        case Ease24::QuintIn:
        case Ease24::_5_QuintIn:
            return cocos2d::EaseQuinticActionIn::create(action);
        case Ease24::QuintOut:
        case Ease24::_5_QuintOut:
            return cocos2d::EaseQuinticActionOut::create(action);
        case Ease24::QuintInOut:
        case Ease24::_5_QuintInOut:
            return cocos2d::EaseQuinticActionInOut::create(action);
        case Ease24::ExpoIn:
        case Ease24::_6_ExpoIn:
            return cocos2d::EaseExponentialIn::create(action);
        case Ease24::ExpoOut:
        case Ease24::_6_ExpoOut:
            return cocos2d::EaseExponentialOut::create(action);
        case Ease24::ExpoInOut:
        case Ease24::_6_ExpoInOut:
            return cocos2d::EaseExponentialInOut::create(action);
        case Ease24::CircIn:
        case Ease24::_7_CircIn:
            return cocos2d::EaseCircleActionIn::create(action);
        case Ease24::CircOut:
        case Ease24::_7_CircOut:
            return cocos2d::EaseCircleActionOut::create(action);
        case Ease24::CircInOut:
        case Ease24::_7_CircInOut:
            return cocos2d::EaseCircleActionInOut::create(action);
        case Ease24::ElasticIn:
            return cocos2d::EaseElasticIn::create(action);
        case Ease24::ElasticOut:
            return cocos2d::EaseElasticOut::create(action);
        case Ease24::ElasticInOut:
            return cocos2d::EaseElasticInOut::create(action);
        case Ease24::BackIn:
            return cocos2d::EaseBackIn::create(action);
        case Ease24::BackOut:
            return cocos2d::EaseBackOut::create(action);
        case Ease24::BackInOut:
            return cocos2d::EaseBackInOut::create(action);
        case Ease24::BounceIn:
            return cocos2d::EaseBounceIn::create(action);
        case Ease24::BounceOut:
            return cocos2d::EaseBounceOut::create(action);
        case Ease24::BounceInOut:
            return cocos2d::EaseBounceInOut::create(action);
    }
}

cocos2d::ActionInterval *Tween24::addDelay(cocos2d::ActionInterval *action)
{
    if (_delayTime == 0) {
        return action;
    }

    return cocos2d::Sequence::create(cocos2d::DelayTime::create(_delayTime), action, nullptr);
}
} // namespace