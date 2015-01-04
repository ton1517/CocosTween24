#ifndef __CocosTween24__RepeatForever24__
#define __CocosTween24__RepeatForever24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class RepeatForever24;
typedef std::shared_ptr<RepeatForever24> RepeatForever24Ptr;

class RepeatForever24 : public IInterval24, public Player24, public std::enable_shared_from_this<RepeatForever24>
{
public:
    static RepeatForever24Ptr create(cocos2d::Node *target, IInterval24Ptr tween);

    RepeatForever24(cocos2d::Node *target, IInterval24Ptr tween);
    virtual ~RepeatForever24() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    IInterval24Ptr _tween;

    RepeatForever24(const RepeatForever24&)           = delete;
    RepeatForever24(RepeatForever24&&)                = delete;
    RepeatForever24&operator=(const RepeatForever24&) = delete;
    RepeatForever24&operator=(RepeatForever24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__RepeatForever24__) */
