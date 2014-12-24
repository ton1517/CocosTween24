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

CocosTween24 * CocosTween24::play()
{
    _playingAction = this->getAction();
    _target->runAction(_playingAction);

    return this;
}

CocosTween24 * CocosTween24::stop()
{
    if (_playingAction && !_playingAction->isDone()) {
        _target->stopAction(_playingAction);
    }

    return this;
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
        case CocosEase24::Sine_EaseIn:
            return EaseSineIn::create(action);
        case CocosEase24::Sine_EaseOut:
            return EaseSineOut::create(action);
        case CocosEase24::Sine_EaseInOut:
            return EaseSineInOut::create(action);
        case CocosEase24::Quad_EaseIn:
            return EaseQuadraticActionIn::create(action);
        case CocosEase24::Quad_EaseOut:
            return EaseQuadraticActionOut::create(action);
        case CocosEase24::Quad_EaseInOut:
            return EaseQuadraticActionInOut::create(action);
        case CocosEase24::Cubic_EaseIn:
            return EaseCubicActionIn::create(action);
        case CocosEase24::Cubic_EaseOut:
            return EaseCubicActionOut::create(action);
        case CocosEase24::Cubic_EaseInOut:
            return EaseCubicActionInOut::create(action);
        case CocosEase24::Quart_EaseIn:
            return EaseQuarticActionIn::create(action);
        case CocosEase24::Quart_EaseOut:
            return EaseQuarticActionOut::create(action);
        case CocosEase24::Quart_EaseInOut:
            return EaseQuarticActionInOut::create(action);
        case CocosEase24::Quint_EaseIn:
            return EaseQuinticActionIn::create(action);
        case CocosEase24::Quint_EaseOut:
            return EaseQuinticActionOut::create(action);
        case CocosEase24::Quint_EaseInOut:
            return EaseQuinticActionInOut::create(action);
        case CocosEase24::Expo_EaseIn:
            return EaseExponentialIn::create(action);
        case CocosEase24::Expo_EaseOut:
            return EaseExponentialOut::create(action);
        case CocosEase24::Expo_EaseInOut:
            return EaseExponentialInOut::create(action);
        case CocosEase24::Circ_EaseIn:
            return EaseCircleActionIn::create(action);
        case CocosEase24::Circ_EaseOut:
            return EaseCircleActionOut::create(action);
        case CocosEase24::Circ_EaseInOut:
            return EaseCircleActionInOut::create(action);
        case CocosEase24::Elastic_EaseIn:
            return EaseElasticIn::create(action);
        case CocosEase24::Elastic_EaseOut:
            return EaseElasticOut::create(action);
        case CocosEase24::Elastic_EaseInOut:
            return EaseElasticInOut::create(action);
        case CocosEase24::Back_EaseIn:
            return EaseBackIn::create(action);
        case CocosEase24::Back_EaseOut:
            return EaseBackOut::create(action);
        case CocosEase24::Back_EaseInOut:
            return EaseBackInOut::create(action);
        case CocosEase24::Bounce_EaseIn:
            return EaseBounceIn::create(action);
        case CocosEase24::Bounce_EaseOut:
            return EaseBounceOut::create(action);
        case CocosEase24::Bounce_EaseInOut:
            return EaseBounceInOut::create(action);
    }
}