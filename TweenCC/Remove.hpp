#ifndef __TweenCC__Remove__
#define __TweenCC__Remove__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Remove;
typedef std::shared_ptr<Remove> RemovePtr;

class Remove : public IInterval, public Player
{
public:
    static RemovePtr create(cocos2d::Node *target);

    Remove(cocos2d::Node *target);
    virtual ~Remove() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Remove(const Remove&)           = delete;
    Remove(Remove&&)                = delete;
    Remove&operator=(const Remove&) = delete;
    Remove&operator=(Remove&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__Remove__) */
