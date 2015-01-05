#ifndef __CocosTween24__ToggleVisibility24__
#define __CocosTween24__ToggleVisibility24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class ToggleVisibility24;
typedef std::shared_ptr<ToggleVisibility24> ToggleVisibility24Ptr;

class ToggleVisibility24 : public IInterval24, public Player24
{
public:
    static ToggleVisibility24Ptr create(cocos2d::Node *target);

    ToggleVisibility24(cocos2d::Node *target);
    virtual ~ToggleVisibility24() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    ToggleVisibility24(const ToggleVisibility24&)           = delete;
    ToggleVisibility24(ToggleVisibility24&&)                = delete;
    ToggleVisibility24&operator=(const ToggleVisibility24&) = delete;
    ToggleVisibility24&operator=(ToggleVisibility24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__ToggleVisibility24__) */