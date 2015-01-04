#ifndef __CocosTween24__Sequence24__
#define __CocosTween24__Sequence24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Sequence24;
typedef std::shared_ptr<Sequence24> Sequence24Ptr;

class Sequence24 : public IInterval24, public Player24, public std::enable_shared_from_this<Sequence24>
{
public:
    static Sequence24Ptr create(cocos2d::Node *target);

    explicit Sequence24(cocos2d::Node *target);
    virtual ~Sequence24() = default;

    cocos2d::ActionInterval *generateAction() override;

    Sequence24Ptr addTweens(IFiniteTime24Ptr tween);
    Sequence24Ptr addTweens(const std::vector<IFiniteTime24Ptr> &tweens);

    template <class... Args>
    Sequence24Ptr addTweens(IFiniteTime24Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<IFiniteTime24Ptr> _tweens;

    Sequence24(const Sequence24&)           = delete;
    Sequence24(Sequence24&&)                = delete;
    Sequence24&operator=(const Sequence24&) = delete;
    Sequence24&operator=(Sequence24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Sequence24__) */
