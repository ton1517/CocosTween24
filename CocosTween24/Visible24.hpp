#ifndef __CocosTween24__Visible24__
#define __CocosTween24__Visible24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Visible24;
typedef std::shared_ptr<Visible24> Visible24Ptr;

class Visible24 : public IInterval24, public Player24
{
public:
    static Visible24Ptr create(cocos2d::Node *target, bool visible);

    Visible24(cocos2d::Node *target, bool visible);
    virtual ~Visible24() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Visible24(const Visible24&)           = delete;
    Visible24(Visible24&&)                = delete;
    Visible24&operator=(const Visible24&) = delete;
    Visible24&operator=(Visible24&&)      = delete;

    bool _visible;
};
} // namespace

#endif /* defined(__CocosTween24__Visible24__) */
