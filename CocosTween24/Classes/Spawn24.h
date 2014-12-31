#ifndef __CocosTween24__Spawn24__
#define __CocosTween24__Spawn24__

#include <cocos2d.h>
#include "ITween24.h"

namespace cocosTween24
{
class Spawn24;
typedef std::shared_ptr<Spawn24> Spawn24Ptr;

class Spawn24 : public ITween24, public std::enable_shared_from_this<Spawn24>
{
public:
    static Spawn24Ptr create(cocos2d::Node *target);

    Spawn24(cocos2d::Node *target);
    virtual ~Spawn24();

    cocos2d::ActionInterval *getAction() override;
    void play() override;
    void stop() override;

    Spawn24Ptr addTween(ITween24Ptr tween);
    Spawn24Ptr addTweens(const std::vector<ITween24Ptr> &tweens);

    template <class Tween, class... Args>
    Spawn24Ptr addTweens(Tween tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

    CC_SYNTHESIZE_READONLY(cocos2d::Node *, _target, Target);

private:
    cocos2d::FiniteTimeAction *_playingAction;
    std::vector<ITween24Ptr>   _tweens;

    template <class Tween>
    void addTweens(Tween tween)
    {
        addTween(tween);
    }
};
}

#endif /* defined(__CocosTween24__Spawn24__) */
