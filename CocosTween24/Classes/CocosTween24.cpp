#include "CocosTween24.h"

using namespace cocosTween24;
USING_NS_CC;

#pragma mark ----- static -----

CocosTween24 * CocosTween24::tween(cocos2d::Node * target, float duration, CocosEase24::EASE easing)
{
    auto tween = new CocosTween24();
    tween->_target = target;
    tween->_duration = duration;
    tween->_easing = easing;

    return tween;
}

#pragma mark ----- public -----

CocosTween24::CocosTween24() {}

FiniteTimeAction * CocosTween24::getAction()
{
    auto spawn = Spawn::create(_actions);
    auto action = this->addEasing(spawn);
    auto targetedAction = TargetedAction::create(_target, action);

    return targetedAction;
}

void CocosTween24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);
}

void CocosTween24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }
}

#pragma mark position

CocosTween24 * CocosTween24::x(float x)
{
    auto pos = _target->getPosition();
    auto action = MoveTo::create(_duration, Point(x, pos.y));
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$x(float $x)
{
    auto action = MoveBy::create(_duration, Point($x, 0));
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::y(float y)
{
    auto pos = _target->getPosition();
    auto action = MoveTo::create(_duration, Point(pos.x, y));
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$y(float $y)
{
    auto action = MoveBy::create(_duration, Point(0, $y));
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::xy(float x, float y)
{
    auto action = MoveTo::create(_duration, Point(x, y));
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$xy(float $x, float $y)
{
    auto action = MoveBy::create(_duration, Point($x, $y));
    addAction(action);

    return this;
}

#pragma mark scale

CocosTween24 * CocosTween24::scaleX(float sx)
{
    auto action = ScaleTo::create(_duration, sx, _target->getScaleY());
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::$scaleX(float $sx)
{
    auto action = ScaleBy::create(_duration, $sx, 0);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::scaleY(float sy)
{
    auto action = ScaleTo::create(_duration, _target->getScaleX(), sy);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::$scaleY(float $sy)
{
    auto action = ScaleBy::create(_duration, 0, $sy);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::scaleZ(float sz)
{
    auto action = ScaleTo::create(_duration, _target->getScaleX(), _target->getScaleY(), sz);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::$scaleZ(float $sz)
{
    auto action = ScaleBy::create(_duration, 0, 0, $sz);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::scale(float s)
{
    auto action = ScaleTo::create(_duration, s);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::$scale(float $s)
{
    auto action = ScaleBy::create(_duration, $s);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::scale(float sx, float sy)
{
    auto action = ScaleTo::create(_duration, sx, sy);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::$scale(float $sx, float $sy)
{
    auto action = ScaleBy::create(_duration, $sx, $sy);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::scale(float sx, float sy, float sz)
{
    auto action = ScaleTo::create(_duration, sx, sy, sz);
    addAction(action);
    
    return this;
}

CocosTween24 * CocosTween24::$scale(float $sx, float $sy, float $sz)
{
    auto action = ScaleBy::create(_duration, $sx, $sy, $sz);
    addAction(action);
    
    return this;
}

#pragma mark rotate

CocosTween24 * CocosTween24::rotateX(float angleX)
{
    auto action = RotateTo::create(_duration, angleX, _target->getRotationSkewY());
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$rotateX(float $angleX)
{
    auto action = RotateBy::create(_duration, $angleX, 0);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::rotateY(float angleY)
{
    auto action = RotateTo::create(_duration, _target->getRotationSkewX(), angleY);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$rotateY(float $angleY)
{
    auto action = RotateBy::create(_duration, 0, $angleY);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::rotate(float angle)
{
    auto action = RotateTo::create(_duration, angle);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$rotate(float $angle)
{
    auto action = RotateBy::create(_duration, $angle);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::rotate(float angleX, float angleY)
{
    auto action = RotateTo::create(_duration, angleX, angleY);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$rotate(float $angleX, float $angleY)
{
    auto action = RotateBy::create(_duration, $angleX, $angleY);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::rotate(const Vec3 & angle3D)
{
    auto action = RotateTo::create(_duration, angle3D);
    addAction(action);

    return this;
}

CocosTween24 * CocosTween24::$rotate(const Vec3 & $angle3D)
{
    auto action = RotateBy::create(_duration, $angle3D);
    addAction(action);

    return this;
}

#pragma mark ----- protected -----

void CocosTween24::addAction(FiniteTimeAction * action)
{
    _actions.pushBack(action);
}

#pragma mark easing

ActionInterval * CocosTween24::addEasing(cocos2d::ActionInterval * action)
{
    switch (_easing) {
        case CocosEase24::Linear:
            return action;
        case CocosEase24::SineIn:
            return EaseSineIn::create(action);
        case CocosEase24::SineOut:
            return EaseSineOut::create(action);
        case CocosEase24::SineInOut:
            return EaseSineInOut::create(action);
        case CocosEase24::QuadIn:
            return EaseQuadraticActionIn::create(action);
        case CocosEase24::QuadOut:
            return EaseQuadraticActionOut::create(action);
        case CocosEase24::QuadInOut:
            return EaseQuadraticActionInOut::create(action);
        case CocosEase24::CubicIn:
            return EaseCubicActionIn::create(action);
        case CocosEase24::CubicOut:
            return EaseCubicActionOut::create(action);
        case CocosEase24::CubicInOut:
            return EaseCubicActionInOut::create(action);
        case CocosEase24::QuartIn:
            return EaseQuarticActionIn::create(action);
        case CocosEase24::QuartOut:
            return EaseQuarticActionOut::create(action);
        case CocosEase24::QuartInOut:
            return EaseQuarticActionInOut::create(action);
        case CocosEase24::QuintIn:
            return EaseQuinticActionIn::create(action);
        case CocosEase24::QuintOut:
            return EaseQuinticActionOut::create(action);
        case CocosEase24::QuintInOut:
            return EaseQuinticActionInOut::create(action);
        case CocosEase24::ExpoIn:
            return EaseExponentialIn::create(action);
        case CocosEase24::ExpoOut:
            return EaseExponentialOut::create(action);
        case CocosEase24::ExpoInOut:
            return EaseExponentialInOut::create(action);
        case CocosEase24::CircIn:
            return EaseCircleActionIn::create(action);
        case CocosEase24::CircOut:
            return EaseCircleActionOut::create(action);
        case CocosEase24::CircInOut:
            return EaseCircleActionInOut::create(action);
        case CocosEase24::ElasticIn:
            return EaseElasticIn::create(action);
        case CocosEase24::ElasticOut:
            return EaseElasticOut::create(action);
        case CocosEase24::ElasticInOut:
            return EaseElasticInOut::create(action);
        case CocosEase24::BackIn:
            return EaseBackIn::create(action);
        case CocosEase24::BackOut:
            return EaseBackOut::create(action);
        case CocosEase24::BackInOut:
            return EaseBackInOut::create(action);
        case CocosEase24::BounceIn:
            return EaseBounceIn::create(action);
        case CocosEase24::BounceOut:
            return EaseBounceOut::create(action);
        case CocosEase24::BounceInOut:
            return EaseBounceInOut::create(action);
    }
}