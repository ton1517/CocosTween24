#ifndef __CocosTween23__Func23__
#define __CocosTween23__Func23__

#include <cocos2d.h>

#include "IInstant23.hpp"

namespace tween23
{
class Func23;
typedef std::shared_ptr<Func23> Func23Ptr;

class Func23 : public IInstant23
{
public:
    static Func23Ptr create(const std::function<void()> &func);

    explicit Func23(const std::function<void()> &func);
    virtual ~Func23() = default;

    cocos2d::ActionInstant *generateAction() override;

private:
    Func23(const Func23&)           = delete;
    Func23(Func23&&)                = delete;
    Func23&operator=(const Func23&) = delete;
    Func23&operator=(Func23&&)      = delete;

    const std::function<void()> &_func;
};
} // namespace

#endif /* defined(__CocosTween23__Func23__) */
