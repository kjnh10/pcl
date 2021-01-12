---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/array/sparse_table.hpp
    title: library/cpp/array/sparse_table.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"library/cpp/array/sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"library/cpp/header.hpp\"\
    \n\n//%snippet.set('header')%\n//%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\
    \n// template version 2.0\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    // varibable settings\ntemplate <class T> constexpr T inf = numeric_limits<T>::max()\
    \ / 2.1;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n)\
    \ repi(i, 0, n)\n#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n\
    #define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define _rrep(i,\
    \ n) rrepi(i, 0, n)\n#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a);\
    \ --i)\n#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)\n\
    #define each(i, a) for (auto &&i : a)\n#define all(x) (x).begin(), (x).end()\n\
    #define sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b)\
    \ make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n#define ub upper_bound\n\
    #define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A), x) - A.begin())\n\
    #define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate <class T, class\
    \ U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }\ntemplate\
    \ <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b)) (a)\
    \ = (b); }\ntemplate <typename X, typename T> auto make_table(X x, T a) { return\
    \ vector<T>(x, a); }\ntemplate <typename X, typename Y, typename Z, typename...\
    \ Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z,\
    \ zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T cdiv(T\
    \ a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x, a,\
    \ b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
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
    \ - (1 << b)]);\n    }\n};\n\n//%snippet.end()%\n#line 3 \"library/cpp/array/sparse_table.test.cpp\"\
    \n\nint main(){\n    ll N,Q;cin>>N>>Q;\n    vl a(N);\n    rep(n, N) cin>>a[n];\n\
    \n    sparse_table<ll> sp(a);\n    rep(q, Q){\n        ll l,r;cin>>l>>r;\n   \
    \     cout << sp.query(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    sparse_table.hpp\"\n\nint main(){\n    ll N,Q;cin>>N>>Q;\n    vl a(N);\n    rep(n,\
    \ N) cin>>a[n];\n\n    sparse_table<ll> sp(a);\n    rep(q, Q){\n        ll l,r;cin>>l>>r;\n\
    \        cout << sp.query(l, r) << endl;\n    }\n}\n"
  dependsOn:
  - library/cpp/array/sparse_table.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/array/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/array/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/array/sparse_table.test.cpp
- /verify/library/cpp/array/sparse_table.test.cpp.html
title: library/cpp/array/sparse_table.test.cpp
---
