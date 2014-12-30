#ifndef __CocosTween24__Sequence24__
#define __CocosTween24__Sequence24__

#include <cocos2d.h>
#include "ITween24.h"

namespace cocosTween24
{
class Sequence24;
typedef std::shared_ptr<Sequence24> Sequence24Ptr;

class Sequence24 : public ITween24, public std::enable_shared_from_this<Sequence24>
{
private:
    // dummy
    void addTweens() {}

public:
    Sequence24(cocos2d::Node *target);
    virtual ~Sequence24();

    cocos2d::FiniteTimeAction *getAction() override;
    void play() override;
    void stop() override;

    Sequence24Ptr addTween(ITween24Ptr tween);
    Sequence24Ptr addTweens(const std::vector<ITween24Ptr> &tweens);

    template <class Tween, class... Args>
    Sequence24Ptr addTweens(Tween tween, Args... args)
    {
        addTween(tween);
        addTweens(args...);

        return shared_from_this();
    }

    CC_SYNTHESIZE_READONLY(cocos2d::Node *, _target, Target);

private:
    cocos2d::FiniteTimeAction *_playingAction;

    std::vector<ITween24Ptr> _tweens;
};
}

#endif /* defined(__CocosTween24__Sequence24__) */
