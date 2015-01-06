#ifndef __CocosTween24__Place24__
#define __CocosTween24__Place24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Place24;
typedef std::shared_ptr<Place24> Place24Ptr;

class Place24 : public IInterval24, public Player24
{
public:
    static Place24Ptr create(cocos2d::Node *target, const cocos2d::Vec2 &pos);

    Place24(cocos2d::Node *target, const cocos2d::Vec2 &pos);
    virtual ~Place24() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Place24(const Place24&)           = delete;
    Place24(Place24&&)                = delete;
    Place24&operator=(const Place24&) = delete;
    Place24&operator=(Place24&&)      = delete;

    const cocos2d::Vec2 &_pos;
};
} // namespace

#endif /* defined(__CocosTween24__Place24__) */
