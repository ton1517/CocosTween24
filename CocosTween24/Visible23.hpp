#ifndef __CocosTween23__Visible23__
#define __CocosTween23__Visible23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class Visible23;
typedef std::shared_ptr<Visible23> Visible23Ptr;

class Visible23 : public IInterval23, public Player23
{
public:
    static Visible23Ptr create(cocos2d::Node *target, bool visible);

    Visible23(cocos2d::Node *target, bool visible);
    virtual ~Visible23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Visible23(const Visible23&)           = delete;
    Visible23(Visible23&&)                = delete;
    Visible23&operator=(const Visible23&) = delete;
    Visible23&operator=(Visible23&&)      = delete;

    bool _visible;
};
} // namespace

#endif /* defined(__CocosTween23__Visible23__) */
