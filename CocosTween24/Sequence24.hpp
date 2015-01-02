#ifndef __CocosTween24__Sequence24__
#define __CocosTween24__Sequence24__

#include <cocos2d.h>

#include "Player24.hpp"

namespace cocosTween24
{
class Sequence24;
typedef std::shared_ptr<Sequence24> Sequence24Ptr;

class Sequence24 : public Player24, public std::enable_shared_from_this<Sequence24>
{
public:
    static Sequence24Ptr create(cocos2d::Node *target);

    Sequence24(cocos2d::Node *target);
    virtual ~Sequence24();

    cocos2d::ActionInterval *getAction() override;

    Sequence24Ptr addTween(ITween24Ptr tween);
    Sequence24Ptr addTweens(const std::vector<ITween24Ptr> &tweens);

    template <class Tween>
    void addTweens(Tween tween)
    {
        addTween(tween);
    }

    template <class Tween, class... Args>
    Sequence24Ptr addTweens(Tween tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<ITween24Ptr> _tweens;
};
} // namespace

#endif /* defined(__CocosTween24__Sequence24__) */
