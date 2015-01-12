#ifndef __TweenCC__Visible__
#define __TweenCC__Visible__

#include <cocos2d.h>

#include "IInterval.hpp"
#include "Player.hpp"

namespace tweencc
{
class Visible;
typedef std::shared_ptr<Visible> VisiblePtr;

class Visible : public IInterval, public Player
{
public:
    static VisiblePtr create(cocos2d::Node *target, bool visible);

    Visible(cocos2d::Node *target, bool visible);
    virtual ~Visible() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Visible(const Visible&)           = delete;
    Visible(Visible&&)                = delete;
    Visible&operator=(const Visible&) = delete;
    Visible&operator=(Visible&&)      = delete;

    bool _visible;
};
} // namespace

#endif /* defined(__TweenCC__Visible__) */
