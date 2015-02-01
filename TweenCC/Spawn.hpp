#ifndef __TweenCC__Spawn__
#define __TweenCC__Spawn__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Spawn;
typedef std::shared_ptr<Spawn> SpawnPtr;

class Spawn : public IInterval, public Player, public std::enable_shared_from_this<Spawn>
{
public:
    static SpawnPtr create(cocos2d::Node *target);

    explicit Spawn(cocos2d::Node *target);
    virtual ~Spawn() = default;

    cocos2d::ActionInterval *generateAction() override;
    cocos2d::ActionInterval *generateActionWithoutTarget() override;

    SpawnPtr addTweens(IFiniteTimePtr tween);
    SpawnPtr addTweens(const std::vector<IFiniteTimePtr> &tweens);

    template <class... Args>
    SpawnPtr addTweens(IFiniteTimePtr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<IFiniteTimePtr> _tweens;

    Spawn(const Spawn&)           = delete;
    Spawn(Spawn&&)                = delete;
    Spawn&operator=(const Spawn&) = delete;
    Spawn&operator=(Spawn&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Spawn__) */
