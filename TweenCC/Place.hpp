#ifndef __TweenCC__Place__
#define __TweenCC__Place__

#include <cocos2d.h>

#include "IFiniteTime.hpp"
#include "Player.hpp"

namespace tweencc
{
class Place;
typedef std::shared_ptr<Place> PlacePtr;

class Place : public IFiniteTime, public Player
{
public:
    static PlacePtr create(cocos2d::Node *target, const cocos2d::Vec2 &pos);

    Place(cocos2d::Node *target, const cocos2d::Vec2 &pos);
    virtual ~Place() = default;

    cocos2d::FiniteTimeAction *generateAction() override;

private:
    Place(const Place&)           = delete;
    Place(Place&&)                = delete;
    Place&operator=(const Place&) = delete;
    Place&operator=(Place&&)      = delete;

    const cocos2d::Vec2 &_pos;
};
} // namespace

#endif /* defined(__TweenCC__Place__) */
