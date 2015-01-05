#ifndef __CocosTween24__Remove24__
#define __CocosTween24__Remove24__

#include <cocos2d.h>

#include "IInterval24.hpp"
#include "Player24.hpp"

namespace cocosTween24
{
class Remove24;
typedef std::shared_ptr<Remove24> Remove24Ptr;

class Remove24 : public IInterval24, public Player24
{
public:
    static Remove24Ptr create(cocos2d::Node *target);

    Remove24(cocos2d::Node *target);
    virtual ~Remove24() = default;

    cocos2d::ActionInterval *generateAction() override;

private:
    Remove24(const Remove24&)           = delete;
    Remove24(Remove24&&)                = delete;
    Remove24&operator=(const Remove24&) = delete;
    Remove24&operator=(Remove24&&)      = delete;
};
} // namespace

#endif /* defined(__CocosTween24__Remove24__) */
