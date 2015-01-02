#ifndef __CocosTween24__Spawn24__
#define __CocosTween24__Spawn24__

#include <cocos2d.h>

#include "Player24.hpp"

namespace cocosTween24
{
class Spawn24;
typedef std::shared_ptr<Spawn24> Spawn24Ptr;

class Spawn24 : public Player24, public std::enable_shared_from_this<Spawn24>
{
public:
    static Spawn24Ptr create(cocos2d::Node *target);

    Spawn24(cocos2d::Node *target);
    virtual ~Spawn24();

    cocos2d::ActionInterval *getAction() override;

    Spawn24Ptr addTweens(ITween24Ptr tween);
    Spawn24Ptr addTweens(const std::vector<ITween24Ptr> &tweens);

    template <class... Args>
    Spawn24Ptr addTweens(ITween24Ptr tween, Args... args)
    {
        addTweens(tween);
        addTweens(args...);

        return shared_from_this();
    }

private:
    std::vector<ITween24Ptr> _tweens;
};
} // namespace

#endif /* defined(__CocosTween24__Spawn24__) */
