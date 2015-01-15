#ifndef __TweenCC__UpdateFuncAction__
#define __TweenCC__UpdateFuncAction__

#include <cocos2d.h>

namespace tweencc
{
class UpdateFuncAction : public cocos2d::ActionInterval
{
public:
    static UpdateFuncAction *create(float duration, const std::function<void(float)> &func);

    virtual UpdateFuncAction *clone() const override;
    virtual void update(float time) override;

protected:
    UpdateFuncAction()          = default;
    virtual ~UpdateFuncAction() = default;

    bool initWithDuration(float duration, const std::function<void(float)> &func);

    std::function<void(float)> _func;

private:
    UpdateFuncAction(const UpdateFuncAction&)           = delete;
    UpdateFuncAction(UpdateFuncAction&&)                = delete;
    UpdateFuncAction&operator=(const UpdateFuncAction&) = delete;
    UpdateFuncAction&operator=(UpdateFuncAction&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__UpdateFuncAction__) */
