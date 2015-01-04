#ifndef __CocosTween24__Lag24__
#define __CocosTween24__Lag24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Lag24;
typedef std::shared_ptr<Lag24> Lag24Ptr;

class Lag24 : public IInterval24, public Player24, public std::enable_shared_from_this<Lag24>
{
public:
    static Lag24Ptr create(cocos2d::Node *target, float waitTime);

    Lag24(cocos2d::Node *target, float waitTime);
    virtual ~Lag24() = default;

    cocos2d::ActionInterval *generateAction() override;

    Lag24Ptr addTweens(IFiniteTime24Ptr tween);
    Lag24Ptr addTweens(const std::vector<IFiniteTime24Ptr> &tweens);

    template <class... Args>
    Lag24Ptr addTweens(IFiniteTime24Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

    CC_SYNTHESIZE_READONLY(float, _waitTime, WaitTime);

private:
    std::vector<IFiniteTime24Ptr> _tweens;

    Lag24(const Lag24&)           = delete;
    Lag24(Lag24&&)                = delete;
    Lag24&operator=(const Lag24&) = delete;
    Lag24&operator=(Lag24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Lag24__) */
