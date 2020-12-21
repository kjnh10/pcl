---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/cpp/include/sparse_table.hpp
    title: library/cpp/include/sparse_table.hpp
  - icon: ':warning:'
    path: library/cpp/include/suffix_array.hpp
    title: library/cpp/include/suffix_array.hpp
  - icon: ':x:'
    path: library/cpp/string/suffix_array.hpp
    title: library/cpp/string/suffix_array.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/sparse_table.test.cpp
    title: library/cpp/array/sparse_table.test.cpp
  - icon: ':x:'
    path: library/cpp/string/suffix_array.test.cpp
    title: library/cpp/string/suffix_array.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ long double ld;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing pll\
    \ = pair<ll, ll>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/array/sparse_table.hpp\"\
    \n\n//%snippet.set('sparse_table')%\n//%snippet.fold()%\n\ntemplate< class T =\
    \ ll >\nstruct sparse_table {\n    vector< vector< T > > st;\n    vector< int\
    \ > lookup;\n\n    sparse_table(const vector< T > &v) {\n        int b = 0;\n\
    \        while((1 << b) <= sz(v)) ++b;\n        st.assign(b, vector< T >(1 <<\
    \ b));\n        for(int i = 0; i < sz(v); i++) {\n            st[0][i] = v[i];\n\
    \        }\n        for(int i = 1; i < b; i++) {\n            for(int j = 0; j\
    \ + (1 << i) <= (1 << b); j++) {\n                st[i][j] = min(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n        lookup.resize(v.size()\
    \ + 1);\n        for(int i = 2; i < sz(lookup); i++) {\n            lookup[i]\
    \ = lookup[i >> 1] + 1;\n        }\n    }\n\n    inline T query(int l, int r)\
    \ {  // [l, r)\n        int b = lookup[r - l];\n        return min(st[b][l], st[b][r\
    \ - (1 << b)]);\n    }\n};\n\n//%snippet.end()%\n"
  code: "#pragma once\n#include \"../header.hpp\"\n\n//%snippet.set('sparse_table')%\n\
    //%snippet.fold()%\n\ntemplate< class T = ll >\nstruct sparse_table {\n    vector<\
    \ vector< T > > st;\n    vector< int > lookup;\n\n    sparse_table(const vector<\
    \ T > &v) {\n        int b = 0;\n        while((1 << b) <= sz(v)) ++b;\n     \
    \   st.assign(b, vector< T >(1 << b));\n        for(int i = 0; i < sz(v); i++)\
    \ {\n            st[0][i] = v[i];\n        }\n        for(int i = 1; i < b; i++)\
    \ {\n            for(int j = 0; j + (1 << i) <= (1 << b); j++) {\n           \
    \     st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n         \
    \   }\n        }\n        lookup.resize(v.size() + 1);\n        for(int i = 2;\
    \ i < sz(lookup); i++) {\n            lookup[i] = lookup[i >> 1] + 1;\n      \
    \  }\n    }\n\n    inline T query(int l, int r) {  // [l, r)\n        int b =\
    \ lookup[r - l];\n        return min(st[b][l], st[b][r - (1 << b)]);\n    }\n\
    };\n\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/array/sparse_table.hpp
  requiredBy:
  - library/cpp/string/suffix_array.hpp
  - library/cpp/include/suffix_array.hpp
  - library/cpp/include/sparse_table.hpp
  timestamp: '2020-12-21 23:16:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - library/cpp/array/sparse_table.test.cpp
  - library/cpp/string/suffix_array.test.cpp
documentation_of: library/cpp/array/sparse_table.hpp
layout: document
redirect_from:
- /library/library/cpp/array/sparse_table.hpp
- /library/library/cpp/array/sparse_table.hpp.html
title: library/cpp/array/sparse_table.hpp
---
