#include "Wait24.h"

using namespace cocosTween24;
USING_NS_CC;

Wait24Ptr Wait24::create(float waitTime)
{
    auto w24 = std::make_shared<Wait24>(waitTime);

    return std::move(w24);
}

Wait24::Wait24(float waitTime) : _waitTime(waitTime) {}
Wait24::~Wait24() {}

ActionInterval *Wait24::getAction()
{
    return DelayTime::create(_waitTime);
}

void Wait24::play() {}
void Wait24::stop() {}

