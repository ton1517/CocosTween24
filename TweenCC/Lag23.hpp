#ifndef __CocosTween23__Lag23__
#define __CocosTween23__Lag23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace tween23
{
class Lag23;
typedef std::shared_ptr<Lag23> Lag23Ptr;

class Lag23 : public IInterval23, public Player23, public std::enable_shared_from_this<Lag23>
{
public:
    static Lag23Ptr create(cocos2d::Node *target, float waitTime);

    Lag23(cocos2d::Node *target, float waitTime);
    virtual ~Lag23() = default;

    cocos2d::ActionInterval *generateAction() override;

    Lag23Ptr addTweens(IFiniteTime23Ptr tween);
    Lag23Ptr addTweens(const std::vector<IFiniteTime23Ptr> &tweens);

    template <class... Args>
    Lag23Ptr addTweens(IFiniteTime23Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);

private:
    std::vector<IFiniteTime23Ptr> _tweens;

    Lag23(const Lag23&)           = delete;
    Lag23(Lag23&&)                = delete;
    Lag23&operator=(const Lag23&) = delete;
    Lag23&operator=(Lag23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Lag23__) */
