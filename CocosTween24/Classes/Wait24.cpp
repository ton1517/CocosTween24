#include "Wait24.h"

using namespace cocosTween24;
USING_NS_CC;

Wait24::Wait24(float waitTime) : _waitTime(waitTime)
{
}

Wait24::~Wait24()
{
}

FiniteTimeAction *Wait24::getAction()
{
    return DelayTime::create(_waitTime);
}

void Wait24::play()
{
}

void Wait24::stop()
{
}