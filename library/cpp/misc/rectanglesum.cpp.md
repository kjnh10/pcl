---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/misc/rectanglesum.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//%snippet.set('RectangleSum')%\n\ntemplate <typename\
    \ T>\nstruct RectangleSum {\n    vector<vector<T>> sum;\n    T GetSum(int top,\
    \ int bottom, int left, int right){ // {{{\n        // [left, right), [top, bottom)\n\
    \        assert(top<bottom);\n        assert(left<right);\n\n        T res = sum[bottom-1][right-1];\n\
    \        if (left > 0) res -= sum[bottom-1][left - 1];\n        if (top > 0) res\
    \ -= sum[top - 1][right-1];\n        if (left > 0 && top > 0) res += sum[top -\
    \ 1][left - 1];\n        return res;\n    } /*}}}*/\n\n    RectangleSum(const\
    \ vector<vector<T>> &s) { /*{{{*/\n        int h = s.size();\n        int w =\
    \ s[0].size();\n        sum.resize(h);\n        for (int i = 0; i < h; i++) sum[i].resize(w,\
    \ 0);\n        for (int y = 0; y < h; y++) {\n            for (int x = 0; x <\
    \ w; x++) {\n                sum[y][x] = s[y][x];\n                if (y > 0)\
    \ sum[y][x] += sum[y - 1][x];\n                if (x > 0) sum[y][x] += sum[y][x\
    \ - 1];\n                if (y > 0 && x > 0) sum[y][x] -= sum[y - 1][x - 1];\n\
    \            }\n        }\n    } /*}}}*/\n};\n\n//%snippet.end()%\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//%snippet.set('RectangleSum')%\n\
    \ntemplate <typename T>\nstruct RectangleSum {\n    vector<vector<T>> sum;\n \
    \   T GetSum(int top, int bottom, int left, int right){ // {{{\n        // [left,\
    \ right), [top, bottom)\n        assert(top<bottom);\n        assert(left<right);\n\
    \n        T res = sum[bottom-1][right-1];\n        if (left > 0) res -= sum[bottom-1][left\
    \ - 1];\n        if (top > 0) res -= sum[top - 1][right-1];\n        if (left\
    \ > 0 && top > 0) res += sum[top - 1][left - 1];\n        return res;\n    } /*}}}*/\n\
    \n    RectangleSum(const vector<vector<T>> &s) { /*{{{*/\n        int h = s.size();\n\
    \        int w = s[0].size();\n        sum.resize(h);\n        for (int i = 0;\
    \ i < h; i++) sum[i].resize(w, 0);\n        for (int y = 0; y < h; y++) {\n  \
    \          for (int x = 0; x < w; x++) {\n                sum[y][x] = s[y][x];\n\
    \                if (y > 0) sum[y][x] += sum[y - 1][x];\n                if (x\
    \ > 0) sum[y][x] += sum[y][x - 1];\n                if (y > 0 && x > 0) sum[y][x]\
    \ -= sum[y - 1][x - 1];\n            }\n        }\n    } /*}}}*/\n};\n\n//%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/misc/rectanglesum.cpp
  requiredBy: []
  timestamp: '2021-07-16 13:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/misc/rectanglesum.cpp
layout: document
redirect_from:
- /library/library/cpp/misc/rectanglesum.cpp
- /library/library/cpp/misc/rectanglesum.cpp.html
title: library/cpp/misc/rectanglesum.cpp
---
