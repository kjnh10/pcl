# competitive programing library

[![Actions Status](https://github.com/kjnh10/pcl/workflows/verify/badge.svg)](https://github.com/kjnh10/pcl/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://kjnh10.github.io/pcl/)

# 機能
* snippet 自動生成機能: 任意の言語でneosnippet形式とvscode(textmate)形式に対応。includeは複雑な依存関係も解決。
```
inv build
```

```cpp
// %snippet.set('gcd')%
// %snippet.config({'abbr':'great common divisor'})%
int gcd(int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}
// %snippet.end()%

// %snippet.set('lcm')%
// %snippet.include('gcd')%
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // overflowしにくいように最初に割り算をする。
}
// %snippet.end()%
```

* include path 修正機能: C++のみ対応。cpp, hppファイル内の#include "???.hpp"に対してレポジトリ内で移動されていた場合は自動で修正する。
```
inv modpath
```
