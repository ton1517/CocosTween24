#ifndef __TweenCC__Sequence__
#define __TweenCC__Sequence__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Sequence;
typedef std::shared_ptr<Sequence> SequencePtr;

class Sequence : public IInterval, public Player, public std::enable_shared_from_this<Sequence>
{
public:
    static SequencePtr create(cocos2d::Node *target);

    explicit Sequence(cocos2d::Node *target);
    virtual ~Sequence() = default;

    cocos2d::ActionInterval *generateAction() override;
    cocos2d::ActionInterval *generateActionWithoutTarget() override;

    SequencePtr addTweens(IFiniteTimePtr tween);
    SequencePtr addTweens(const std::vector<IFiniteTimePtr> &tweens);

    template <class... Args>
    SequencePtr addTweens(IFiniteTimePtr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<IFiniteTimePtr> _tweens;

    Sequence(const Sequence&)           = delete;
    Sequence(Sequence&&)                = delete;
    Sequence&operator=(const Sequence&) = delete;
    Sequence&operator=(Sequence&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Sequence__) */
