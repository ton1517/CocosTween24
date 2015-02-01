#ifndef __TweenCC__IAction__
#define __TweenCC__IAction__

#include <cocos2d.h>

namespace tweencc
{
class IAction;
typedef std::shared_ptr<IAction> IActionPtr;

class IAction
{
public:
    IAction()          = default;
    virtual ~IAction() = default;

    virtual cocos2d::Action *generateAction() = 0;
    virtual cocos2d::Action *generateActionWithoutTarget() = 0;

private:
    IAction(const IAction&)           = delete;
    IAction(IAction&&)                = delete;
    IAction&operator=(const IAction&) = delete;
    IAction&operator=(IAction&&)      = delete;
};
} // namespace

#endif /* defined(__TweenCC__IAction__) */
