#ifndef __CocosTween23__Spawn23__
#define __CocosTween23__Spawn23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace tween23
{
class Spawn23;
typedef std::shared_ptr<Spawn23> Spawn23Ptr;

class Spawn23 : public IInterval23, public Player23, public std::enable_shared_from_this<Spawn23>
{
public:
    static Spawn23Ptr create(cocos2d::Node *target);

    explicit Spawn23(cocos2d::Node *target);
    virtual ~Spawn23() = default;

    cocos2d::ActionInterval *generateAction() override;

    Spawn23Ptr addTweens(IFiniteTime23Ptr tween);
    Spawn23Ptr addTweens(const std::vector<IFiniteTime23Ptr> &tweens);

    template <class... Args>
    Spawn23Ptr addTweens(IFiniteTime23Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<IFiniteTime23Ptr> _tweens;

    Spawn23(const Spawn23&)           = delete;
    Spawn23(Spawn23&&)                = delete;
    Spawn23&operator=(const Spawn23&) = delete;
    Spawn23&operator=(Spawn23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Spawn23__) */
