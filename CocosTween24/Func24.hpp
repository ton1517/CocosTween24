#ifndef __CocosTween24__Func24__
#define __CocosTween24__Func24__

#include <cocos2d.h>

#include "IInstant24.hpp"

namespace cocosTween24
{
class Func24;
typedef std::shared_ptr<Func24> Func24Ptr;

class Func24 : public IInstant24
{
public:
    static Func24Ptr create(const std::function<void()> &func);

    explicit Func24(const std::function<void()> &func);
    virtual ~Func24() = default;

    cocos2d::ActionInstant *generateAction() override;

private:
    Func24(const Func24&)           = delete;
    Func24(Func24&&)                = delete;
    Func24&operator=(const Func24&) = delete;
    Func24&operator=(Func24&&)      = delete;

    const std::function<void()> &_func;
};
} // namespace

#endif /* defined(__CocosTween24__Func24__) */
