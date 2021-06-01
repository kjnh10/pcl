---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/geometry/area_rect.hpp
    title: library/cpp/math/geometry/area_rect.hpp
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
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto mv(X x,\
    \ T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto mv(X x, Y y, Z z, Zs... zs) { auto cont = mv(y, z, zs...);\
    \ return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T cdiv(T a,\
    \ T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x, a, b)\
    \ ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\n#include <cxxabi.h>\nstring\
    \ demangle(const char * name) {\n    size_t len = strlen(name) + 256;\n    char\
    \ output_buffer[len];\n    int status = 0;\n    return string(abi::__cxa_demangle(name,\
    \ output_buffer, &len, &status));\n}\ntemplate<class T> string type(T x){ return\
    \ demangle(typeid(x).name()); }\n\ntypedef long long ll;\ntypedef long double\
    \ ld;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>, greater<T>>;\n\
    void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof()\
    \ == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define dump(...) ;\n\
    #define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n\
    #endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/math/geometry/area_rect.hpp\"\
    \n\n//%snippet.set('AreaRect')%\n//%snippet.fold()%\n\nclass AreaRect { //(0,0)-(X,Y)\u306E\
    \u77E9\u5F62\u306E\u9762\u7A4D\u306E\u7DCF\u548C\n\tmap<ll,ll> M;  // \u77E9\u5F62\
    \u306E\u53F3\u7AEF\u3092\u7BA1\u7406\npublic:\n\tll sum;\n\tAreaRect() {\n\t\t\
    M[0] = 1LL<<60;  // \u756A\u5175\n\t\tM[1LL<<60] = 0;  // \u756A\u5175\n\t\tsum\
    \ = 0;\n\t}\n\tvoid add(ll x, ll y) {\n\t\tauto k = M.lower_bound(x);\n\t\tif\
    \ (k->second >= y) return;\n\t\twhile(true) {\n            if (auto p = *prev(M.lower_bound(x));\
    \ p.second > y){\n                break;\n            }\n            else{;\n\
    \                M.erase(p.first);\n                sum -= (p.first - prev(M.lower_bound(p.first))->first)\
    \ * (p.second - M.lower_bound(x)->second);\n            }\n\t\t}\n\t\tsum += (x\
    \ - prev(M.lower_bound(x))->first) * (y - M.lower_bound(x)->second);\n\t\tM[x]\
    \ = y;\n\t}\n};\n\n//%snippet.end()%\n#line 2 \"library/cpp/include/area_rect.hpp\"\
    \n"
  code: '#include "../math/geometry/area_rect.hpp"'
  dependsOn:
  - library/cpp/math/geometry/area_rect.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/area_rect.hpp
  requiredBy: []
  timestamp: '2021-05-31 23:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/area_rect.hpp
layout: document
redirect_from:
- /library/library/cpp/include/area_rect.hpp
- /library/library/cpp/include/area_rect.hpp.html
title: library/cpp/include/area_rect.hpp
---
