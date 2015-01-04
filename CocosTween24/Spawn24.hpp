#ifndef __CocosTween24__Spawn24__
#define __CocosTween24__Spawn24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Spawn24;
typedef std::shared_ptr<Spawn24> Spawn24Ptr;

class Spawn24 : public IInterval24, public Player24, public std::enable_shared_from_this<Spawn24>
{
public:
    static Spawn24Ptr create(cocos2d::Node *target);

    explicit Spawn24(cocos2d::Node *target);
    virtual ~Spawn24() = default;

    cocos2d::ActionInterval *generateAction() override;

    Spawn24Ptr addTweens(IFiniteTime24Ptr tween);
    Spawn24Ptr addTweens(const std::vector<IFiniteTime24Ptr> &tweens);

    template <class... Args>
    Spawn24Ptr addTweens(IFiniteTime24Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<IFiniteTime24Ptr> _tweens;

    Spawn24(const Spawn24&)           = delete;
    Spawn24(Spawn24&&)                = delete;
    Spawn24&operator=(const Spawn24&) = delete;
    Spawn24&operator=(Spawn24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Spawn24__) */
