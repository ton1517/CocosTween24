#ifndef __CocosTween23__Place23__
#define __CocosTween23__Place23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace cocosTween23
{
class Place23;
typedef std::shared_ptr<Place23> Place23Ptr;

class Place23 : public IInterval23, public Player23
{
public:
    static Place23Ptr create(cocos2d::Node *target, const cocos2d::Vec2 &pos);

    Place23(cocos2d::Node *target, const cocos2d::Vec2 &pos);
    virtual ~Place23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Place23(const Place23&)           = delete;
    Place23(Place23&&)                = delete;
    Place23&operator=(const Place23&) = delete;
    Place23&operator=(Place23&&)      = delete;

    const cocos2d::Vec2 &_pos;
};
} // namespace

#endif /* defined(__CocosTween23__Place23__) */
