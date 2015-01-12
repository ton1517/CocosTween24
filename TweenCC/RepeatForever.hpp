#ifndef __CocosTween23__RepeatForever23__
#define __CocosTween23__RepeatForever23__

#include <cocos2d.h>

#include "IInterval23.hpp"
#include "Player23.hpp"

namespace tween23
{
class RepeatForever23;
typedef std::shared_ptr<RepeatForever23> RepeatForever23Ptr;

class RepeatForever23 : public IInterval23, public Player23, public std::enable_shared_from_this<RepeatForever23>
{
public:
    static RepeatForever23Ptr create(cocos2d::Node *target, IInterval23Ptr tween);

    RepeatForever23(cocos2d::Node *target, IInterval23Ptr tween);
    virtual ~RepeatForever23() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    IInterval23Ptr _tween;

    RepeatForever23(const RepeatForever23&)           = delete;
    RepeatForever23(RepeatForever23&&)                = delete;
    RepeatForever23&operator=(const RepeatForever23&) = delete;
    RepeatForever23&operator=(RepeatForever23&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween23__RepeatForever23__) */
