#ifndef __TweenCC__Func__
#define __TweenCC__Func__

#include <cocos2d.h>

#include "IInstant.hpp"

namespace tweencc
{
class Func;
typedef std::shared_ptr<Func> FuncPtr;

class Func : public IInstant
{
public:
    static FuncPtr create(const std::function<void()> &func);

    explicit Func(const std::function<void()> &func);
    virtual ~Func() = default;

    cocos2d::ActionInstant *generateAction() override;
    cocos2d::ActionInstant *generateActionWithoutTarget() override;

private:
    Func(const Func&)           = delete;
    Func(Func&&)                = delete;
    Func&operator=(const Func&) = delete;
    Func&operator=(Func&&)      = delete;

    const std::function<void()> &_func;
};
} // namespace

#endif /* defined(__TweenCC__Func__) */
