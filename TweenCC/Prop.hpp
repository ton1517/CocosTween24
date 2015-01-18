#ifndef __TweenCC__Prop__
#define __TweenCC__Prop__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Prop;
typedef std::shared_ptr<Prop> PropPtr;

class Prop : public IInterval, public Player, public std::enable_shared_from_this<Prop>
{
public:
    static PropPtr create(cocos2d::Node *target);

    #pragma mark constructor & destructor
    Prop(cocos2d::Node *target);
    virtual ~Prop() = default;

    #pragma mark IInterval interface
    cocos2d::ActionInterval *generateAction() override;

    #pragma mark visible
    PropPtr visible(bool visible);
    PropPtr toggleVisibility();

    #pragma mark flip
    PropPtr flipX(bool x);

private:
    cocos2d::Vector<cocos2d::FiniteTimeAction *> _actions;
    void addAction(cocos2d::FiniteTimeAction *action);

    Prop(const Prop&)           = delete;
    Prop(Prop&&)                = delete;
    Prop&operator=(const Prop&) = delete;
    Prop&operator=(Prop&&)      = delete;
};
}   // namespace

#endif /* defined(__TweenCC__Prop__) */
