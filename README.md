# ColorProgressBar
Smooth ProgressBar Colored to C++Builder

Usage :
This is an extension of <a href='https://github.com/RRUZ/vcl-styles-utils'>vcl-styles-utils</a>

1) Add file in folder in path used by C++Builder
2) Add include in .h
```sh
#include <ColorProgressBarStyleHook.h>
#include "ColorProgressBar.h"
```

3) Add in .cpp
```sh
TColorProgressBarStyleHook::RegisterStyleHook();
TColorProgressBarStyleHook::UnRegisterStyleHook();
```

Color work only when style are running.

With TProgressBar :
if BarColor is clDefault, then theme color are used.
if not, this is color used to draw bar.

With TColorProgressBar :
BarColor work like to TProgressBar.
BarGray enable to show disable bar.

Lot of parameters are present to personalize car color like gradient.

[![Watch the video](http://www.flyonsoft.com/ColorProgressBar.gif)](https://youtu.be/Rm4DQo_ahPw)
