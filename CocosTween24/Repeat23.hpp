#ifndef __CocosTween23__Repeat23__
#define __CocosTween23__Repeat23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class Repeat23;
typedef std::shared_ptr<Repeat23> Repeat23Ptr;

class Repeat23 : public IInterval23, public Player23, public std::enable_shared_from_this<Repeat23>
{
public:
    static Repeat23Ptr create(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween);

    Repeat23(cocos2d::Node *target, unsigned int times, IFiniteTime23Ptr tween);
    virtual ~Repeat23() = default;

    cocos2d::ActionInterval *generateAction() override;

    CC_SYNTHESIZE(unsigned int, _times, Times);

private:
    IFiniteTime23Ptr _tween;

    Repeat23(const Repeat23&)           = delete;
    Repeat23(Repeat23&&)                = delete;
    Repeat23&operator=(const Repeat23&) = delete;
    Repeat23&operator=(Repeat23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__Repeat23__) */
