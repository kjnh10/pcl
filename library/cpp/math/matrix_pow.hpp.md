---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: library/cpp/math/matrix_pow.test.cpp
    title: library/cpp/math/matrix_pow.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/math/matrix_pow.hpp\"\
    \n\n//%snippet.set('matrix_pow')%\n//%snippet.fold()%\n\ntemplate <class value\
    \ = ll>\nusing mat = vector<vector<value>>;\n\ntemplate <class T>\nmat<T> mul(const\
    \ mat<T>& A, const mat<T>& B) {\n    mat<T> res(A.size(), vector<T>(B[0].size()));\n\
    \    rep(i, A.size()) {\n        rep(j, B[0].size()) {\n            rep(k, B.size())\
    \ {\n                res[i][j] = (res[i][j] + A[i][k] * B[k][j]);\n          \
    \  }\n        }\n    }\n    return res;\n}\n\ntemplate <class T>\nmat<T> pow(mat<T>\
    \ A, ll n) {\n    mat<T> B(A.size(), vector<T>(A.size()));\n    rep(i, A.size())\
    \ {\n        B[i][i] = 1;  // E\n    }\n    while (n > 0) {\n        if (n & 1)\
    \ B = mul(B, A);\n        A = mul(A, A);\n        n >>= 1;\n    }\n    return\
    \ B;\n}\n\n//%snippet.end()%\n"
  code: "#include \"../header.hpp\"\n\n//%snippet.set('matrix_pow')%\n//%snippet.fold()%\n\
    \ntemplate <class value = ll>\nusing mat = vector<vector<value>>;\n\ntemplate\
    \ <class T>\nmat<T> mul(const mat<T>& A, const mat<T>& B) {\n    mat<T> res(A.size(),\
    \ vector<T>(B[0].size()));\n    rep(i, A.size()) {\n        rep(j, B[0].size())\
    \ {\n            rep(k, B.size()) {\n                res[i][j] = (res[i][j] +\
    \ A[i][k] * B[k][j]);\n            }\n        }\n    }\n    return res;\n}\n\n\
    template <class T>\nmat<T> pow(mat<T> A, ll n) {\n    mat<T> B(A.size(), vector<T>(A.size()));\n\
    \    rep(i, A.size()) {\n        B[i][i] = 1;  // E\n    }\n    while (n > 0)\
    \ {\n        if (n & 1) B = mul(B, A);\n        A = mul(A, A);\n        n >>=\
    \ 1;\n    }\n    return B;\n}\n\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/math/matrix_pow.hpp
  requiredBy: []
  timestamp: '2020-10-17 17:32:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - library/cpp/math/matrix_pow.test.cpp
documentation_of: library/cpp/math/matrix_pow.hpp
layout: document
redirect_from:
- /library/library/cpp/math/matrix_pow.hpp
- /library/library/cpp/math/matrix_pow.hpp.html
title: library/cpp/math/matrix_pow.hpp
---
