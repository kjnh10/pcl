---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/cpp/array/fast_zeta.hpp
    title: library/cpp/array/fast_zeta.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\n#include <bits/stdc++.h>\nusing namespace std;\n\n// varibable settings\n\
    template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;\n\n#define\
    \ _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define\
    \ repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
    \ repi, _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i, 0, n)\n#define rrepi(i,\
    \ a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n#define r_rep(...) _overload3(__VA_ARGS__,\
    \ rrepi, _rrep, )(__VA_ARGS__)\n#define each(i, a) for (auto &&i : a)\n#define\
    \ all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n#define pb(a)\
    \ push_back(a)\n#define mp(a, b) make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n\
    #define ub upper_bound\n#define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A),\
    \ x) - A.begin())\n#define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate\
    \ <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a)\
    \ = (b); }\ntemplate <class T, class U> inline void chmin(T &a, const U &b) {\
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto make_table(X\
    \ x, T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y,\
    \ z, zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T\
    \ cdiv(T a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x,\
    \ a, b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/array/fast_zeta.hpp\"\
    \n\n//%snippet.set('zeta')%\n//%snippet.fold()%\n\ntemplate <class T> \nvec<T>\
    \ zeta(const vec<T>& a, int n){\n    vec<T> res(a);\n    // \u81EA\u7531\u5EA6\
    0\n    rep(j, 0, n){\n        // j\u6841\u76EE\u3092\u81EA\u7531\u306B\u3059\u308B\
    \u3002\n        rep(i, 1<<n) {\n            if (i >> j & 1) {\n              \
    \  res[i] += res[i ^ 1<<j];\n                // j\u6841\u76EE\u304C\u7ACB\u3063\
    \u3066\u306A\u3044\u3084\u3064\u304B\u3089j\u6841\u76EE\u304C\u7ACB\u3063\u3066\
    \u308B\u3084\u3064\u306B\u66F4\u65B0\u304C\u884C\u304F\u306E\u3067\u9806\u756A\
    \u306E\u5FC3\u914D\u306F\u4E0D\u8981\n            }\n        }\n    }\n    return\
    \ res;\n}\n\n//%snippet.end()%\n#line 2 \"library/cpp/include/fast_zeta.hpp\"\n"
  code: '#include "../array/fast_zeta.hpp"'
  dependsOn:
  - library/cpp/array/fast_zeta.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/fast_zeta.hpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/fast_zeta.hpp
layout: document
redirect_from:
- /library/library/cpp/include/fast_zeta.hpp
- /library/library/cpp/include/fast_zeta.hpp.html
title: library/cpp/include/fast_zeta.hpp
---
