#ifndef __CocosTween23__Sequence23__
#define __CocosTween23__Sequence23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class Sequence23;
typedef std::shared_ptr<Sequence23> Sequence23Ptr;

class Sequence23 : public IInterval23, public Player23, public std::enable_shared_from_this<Sequence23>
{
public:
    static Sequence23Ptr create(cocos2d::Node *target);

    explicit Sequence23(cocos2d::Node *target);
    virtual ~Sequence23() = default;

    cocos2d::ActionInterval *generateAction() override;

    Sequence23Ptr addTweens(IFiniteTime23Ptr tween);
    Sequence23Ptr addTweens(const std::vector<IFiniteTime23Ptr> &tweens);

    template <class... Args>
    Sequence23Ptr addTweens(IFiniteTime23Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<IFiniteTime23Ptr> _tweens;

    Sequence23(const Sequence23&)           = delete;
    Sequence23(Sequence23&&)                = delete;
    Sequence23&operator=(const Sequence23&) = delete;
    Sequence23&operator=(Sequence23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Sequence23__) */
