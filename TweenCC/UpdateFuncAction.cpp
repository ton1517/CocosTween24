#include "UpdateFuncAction.hpp"

namespace tweencc
{
UpdateFuncAction *UpdateFuncAction::create(float duration, const std::function<void(float)> &func)
{
    UpdateFuncAction *updateFuncAction = new (std::nothrow)UpdateFuncAction();
    updateFuncAction->initWithDuration(duration, func);
    updateFuncAction->autorelease();

    return updateFuncAction;
}

bool UpdateFuncAction::initWithDuration(float duration, const std::function<void(float)> &func)
{
    if (ActionInterval::initWithDuration(duration)) {
        _func = func;
        return true;
    }

    return false;
}

UpdateFuncAction *UpdateFuncAction::clone() const
{
    auto a = new (std::nothrow)UpdateFuncAction();
    a->initWithDuration(_duration, _func);
    a->autorelease();
    return a;
}

void UpdateFuncAction::update(float time)
{
    _func(time);
}
} // namespace
