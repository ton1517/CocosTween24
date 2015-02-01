# TweenCC

TweenCC is tween library for Cocos2d-x.

It's simple Action wrapper library.


This library is inspired by [Tween24](https://github.com/a24/Tween24).

## Usage

### include

```
#include "tweencc.hpp"
```

### Basic Tween

```
tweencc::tween(sprite, 1.0)->xy(300, 500)->rotate(30)->play();
```

equals to

```cpp
sprite->runAction(
    Spawn::create(
        MoveTo::create(1.0, Vec2(300, 500)),
        RotateTo::create(1.0, 30),
        nullptr
    )
);
```

### Ease

```
tweencc::tween(sprite, 1.0, tweencc::Ease::ExpoIn)->xy(300, 500)->rotate(30)->play();
```

## License

This software is released under the MIT License, see [LICENSE](https://github.com/ton1517/TweenCC/blob/master/LICENSE).
