#include "Tween24.h"

using namespace cocosTween24;
USING_NS_CC;

#pragma mark----- static -----

Tween24Ptr Tween24::create(cocos2d::Node *target, float duration, Ease24 easing)
{
    auto t24 = std::make_shared<Tween24>(target, duration, easing);

    return std::move(t24);
}

#pragma mark----- public -----

Tween24::Tween24(cocos2d::Node *target, float duration, Ease24 easing) : _target(target), _duration(duration), _easing(easing) {}
Tween24::~Tween24() {}

FiniteTimeAction *Tween24::getAction()
{
    ActionInterval *action = Spawn::create(_actions);
    action = this->addDelay(action);
    action = this->addEasing(action);
    auto targetedAction = TargetedAction::create(_target, action);

    return targetedAction;
}

void Tween24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);
}

void Tween24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

#pragma mark position

Tween24Ptr Tween24::x(float x)
{
    auto pos    = _target->getPosition();
    auto action = MoveTo::create(_duration, Point(x, pos.y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$x(float $x)
{
    auto action = MoveBy::create(_duration, Point($x, 0));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::y(float y)
{
    auto pos    = _target->getPosition();
    auto action = MoveTo::create(_duration, Point(pos.x, y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$y(float $y)
{
    auto action = MoveBy::create(_duration, Point(0, $y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::xy(float x, float y)
{
    auto action = MoveTo::create(_duration, Point(x, y));
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$xy(float $x, float $y)
{
    auto action = MoveBy::create(_duration, Point($x, $y));
    addAction(action);

    return shared_from_this();
}

#pragma mark scale

Tween24Ptr Tween24::scaleX(float sx)
{
    auto action = ScaleTo::create(_duration, sx, _target->getScaleY());
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scaleX(float $sx)
{
    auto action = ScaleBy::create(_duration, $sx, 0);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scaleY(float sy)
{
    auto action = ScaleTo::create(_duration, _target->getScaleX(), sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scaleY(float $sy)
{
    auto action = ScaleBy::create(_duration, 0, $sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scaleZ(float sz)
{
    auto action = ScaleTo::create(_duration, _target->getScaleX(), _target->getScaleY(), sz);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scaleZ(float $sz)
{
    auto action = ScaleBy::create(_duration, 0, 0, $sz);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scale(float s)
{
    auto action = ScaleTo::create(_duration, s);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scale(float $s)
{
    auto action = ScaleBy::create(_duration, $s);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scale(float sx, float sy)
{
    auto action = ScaleTo::create(_duration, sx, sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scale(float $sx, float $sy)
{
    auto action = ScaleBy::create(_duration, $sx, $sy);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::scale(float sx, float sy, float sz)
{
    auto action = ScaleTo::create(_duration, sx, sy, sz);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$scale(float $sx, float $sy, float $sz)
{
    auto action = ScaleBy::create(_duration, $sx, $sy, $sz);
    addAction(action);

    return shared_from_this();
}

#pragma mark rotate

Tween24Ptr Tween24::rotateX(float angleX)
{
    auto action = RotateTo::create(_duration, angleX, _target->getRotationSkewY());
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotateX(float $angleX)
{
    auto action = RotateBy::create(_duration, $angleX, 0);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotateY(float angleY)
{
    auto action = RotateTo::create(_duration, _target->getRotationSkewX(), angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotateY(float $angleY)
{
    auto action = RotateBy::create(_duration, 0, $angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotate(float angle)
{
    auto action = RotateTo::create(_duration, angle);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotate(float $angle)
{
    auto action = RotateBy::create(_duration, $angle);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotate(float angleX, float angleY)
{
    auto action = RotateTo::create(_duration, angleX, angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotate(float $angleX, float $angleY)
{
    auto action = RotateBy::create(_duration, $angleX, $angleY);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::rotate(const Vec3 &angle3D)
{
    auto action = RotateTo::create(_duration, angle3D);
    addAction(action);

    return shared_from_this();
}

Tween24Ptr Tween24::$rotate(const Vec3 &$angle3D)
{
    auto action = RotateBy::create(_duration, $angle3D);
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

void Tween24::addAction(FiniteTimeAction *action)
{
    _actions.pushBack(action);
}

ActionInterval *Tween24::addEasing(cocos2d::ActionInterval *action)
{
    switch (_easing) {
        case Ease24::Linear:
            return action;
        case Ease24::SineIn:
        case Ease24::_1_SineIn:
            return EaseSineIn::create(action);
        case Ease24::SineOut:
        case Ease24::_1_SineOut:
            return EaseSineOut::create(action);
        case Ease24::SineInOut:
        case Ease24::_1_SineInOut:
            return EaseSineInOut::create(action);
        case Ease24::QuadIn:
        case Ease24::_2_QuadIn:
            return EaseQuadraticActionIn::create(action);
        case Ease24::QuadOut:
        case Ease24::_2_QuadOut:
            return EaseQuadraticActionOut::create(action);
        case Ease24::QuadInOut:
        case Ease24::_2_QuadInOut:
            return EaseQuadraticActionInOut::create(action);
        case Ease24::CubicIn:
        case Ease24::_3_CubicIn:
            return EaseCubicActionIn::create(action);
        case Ease24::CubicOut:
        case Ease24::_3_CubicOut:
            return EaseCubicActionOut::create(action);
        case Ease24::CubicInOut:
        case Ease24::_3_CubicInOut:
            return EaseCubicActionInOut::create(action);
        case Ease24::QuartIn:
        case Ease24::_4_QuartIn:
            return EaseQuarticActionIn::create(action);
        case Ease24::QuartOut:
        case Ease24::_4_QuartOut:
            return EaseQuarticActionOut::create(action);
        case Ease24::QuartInOut:
        case Ease24::_4_QuartInOut:
            return EaseQuarticActionInOut::create(action);
        case Ease24::QuintIn:
        case Ease24::_5_QuintIn:
            return EaseQuinticActionIn::create(action);
        case Ease24::QuintOut:
        case Ease24::_5_QuintOut:
            return EaseQuinticActionOut::create(action);
        case Ease24::QuintInOut:
        case Ease24::_5_QuintInOut:
            return EaseQuinticActionInOut::create(action);
        case Ease24::ExpoIn:
        case Ease24::_6_ExpoIn:
            return EaseExponentialIn::create(action);
        case Ease24::ExpoOut:
        case Ease24::_6_ExpoOut:
            return EaseExponentialOut::create(action);
        case Ease24::ExpoInOut:
        case Ease24::_6_ExpoInOut:
            return EaseExponentialInOut::create(action);
        case Ease24::CircIn:
        case Ease24::_7_CircIn:
            return EaseCircleActionIn::create(action);
        case Ease24::CircOut:
        case Ease24::_7_CircOut:
            return EaseCircleActionOut::create(action);
        case Ease24::CircInOut:
        case Ease24::_7_CircInOut:
            return EaseCircleActionInOut::create(action);
        case Ease24::ElasticIn:
            return EaseElasticIn::create(action);
        case Ease24::ElasticOut:
            return EaseElasticOut::create(action);
        case Ease24::ElasticInOut:
            return EaseElasticInOut::create(action);
        case Ease24::BackIn:
            return EaseBackIn::create(action);
        case Ease24::BackOut:
            return EaseBackOut::create(action);
        case Ease24::BackInOut:
            return EaseBackInOut::create(action);
        case Ease24::BounceIn:
            return EaseBounceIn::create(action);
        case Ease24::BounceOut:
            return EaseBounceOut::create(action);
        case Ease24::BounceInOut:
            return EaseBounceInOut::create(action);
    }
}

ActionInterval *Tween24::addDelay(ActionInterval *action)
{
    if (_delayTime == 0) {
        return action;
    }

    return Sequence::create(DelayTime::create(_delayTime), action, nullptr);
}

