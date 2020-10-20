---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n// varibable settings\n\
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
    \ long double ld;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing pll\
    \ = pair<ll, ll>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/array/syakutori.cpp\"\
    \n\nvector<int> x;\nint k;\nint n;\n\nsigned main(){\n//%snippet.set('syakutori')%\n\
    //%snippet.config({'abbr':'syakutori-hou-[l,r)', 'indent':True})%\n    ll sum\
    \ = 0;\n\n    auto isok = [&](ll next_r) {  // check [l, next_r) is ok?\n    \
    \    if (sum + x[next_r - 1] <= k)\n            return true;\n        else\n \
    \           return false;\n    };\n\n    ll res = 0;\n    ll r = 0;\n    for (ll\
    \ l = 0; l < n; ++l) {\n        // [l, r)\u3092\u9650\u754C\u307E\u3067\u5E83\u3052\
    \u308B\u3002\n        while (r < n && isok(r + 1)) {\n            sum += x[r];\n\
    \            ++r;\n        }\n        chmax(res, (r - l));\n\n        // left\u3092\
    increment\u3059\u308B\u6E96\u5099\n        if (r == l){\n            ++r;  //\
    \ \u7A7A\u533A\u9593\u304B\u3089\u7A7A\u533A\u9593\u3078\u306E\u5909\u52D5\u306A\
    \u306E\u3067\u4F55\u3082\u3057\u306A\u3044\u3002\n        }\n        else{\n \
    \           sum -= x[l];\n        }\n    }\n//%snippet.end()%\n}\n"
  code: "#include \"../header.hpp\"\n\nvector<int> x;\nint k;\nint n;\n\nsigned main(){\n\
    //%snippet.set('syakutori')%\n//%snippet.config({'abbr':'syakutori-hou-[l,r)',\
    \ 'indent':True})%\n    ll sum = 0;\n\n    auto isok = [&](ll next_r) {  // check\
    \ [l, next_r) is ok?\n        if (sum + x[next_r - 1] <= k)\n            return\
    \ true;\n        else\n            return false;\n    };\n\n    ll res = 0;\n\
    \    ll r = 0;\n    for (ll l = 0; l < n; ++l) {\n        // [l, r)\u3092\u9650\
    \u754C\u307E\u3067\u5E83\u3052\u308B\u3002\n        while (r < n && isok(r + 1))\
    \ {\n            sum += x[r];\n            ++r;\n        }\n        chmax(res,\
    \ (r - l));\n\n        // left\u3092increment\u3059\u308B\u6E96\u5099\n      \
    \  if (r == l){\n            ++r;  // \u7A7A\u533A\u9593\u304B\u3089\u7A7A\u533A\
    \u9593\u3078\u306E\u5909\u52D5\u306A\u306E\u3067\u4F55\u3082\u3057\u306A\u3044\
    \u3002\n        }\n        else{\n            sum -= x[l];\n        }\n    }\n\
    //%snippet.end()%\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/array/syakutori.cpp
  requiredBy: []
  timestamp: '2020-10-17 17:32:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/syakutori.cpp
layout: document
redirect_from:
- /library/library/cpp/array/syakutori.cpp
- /library/library/cpp/array/syakutori.cpp.html
title: library/cpp/array/syakutori.cpp
---
