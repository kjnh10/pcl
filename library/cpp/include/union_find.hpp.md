---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/graph/union_find.hpp
    title: library/cpp/graph/union_find.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/graph/union_find.hpp\"\
    \n\n//%snippet.set('union_find')%\n//%snippet.fold()%\n\nstruct union_find {\n\
    \    vector<int> par;   // par[x]: parent of x. if root, -size.\n    int gcount;\
    \         // count of groups\n\n    union_find() {}\n    union_find(int _n) :\
    \ par(_n, -1), gcount(_n) {}\n    int merge(int x, int y) { // -> return new_root\n\
    \        x = root(x);\n        y = root(y);\n        if (x != y) {\n         \
    \   if (par[y] < par[x]) swap(x, y);\n            // y -> x : \u5927\u304D\u3044\
    \u65B9\u306Bmerge\u3059\u308B\u3002\n            par[x] += par[y];\n         \
    \   par[y] = x;\n            gcount--;\n        }\n        return (x != y ? x\
    \ : -1);\n    } \n    int root(int x) {\n        if (is_root(x)){\n          \
    \  return x;\n        }\n        else{\n            return par[x] = root(par[x]);\
    \  // \u7D4C\u8DEF\u5727\u7E2E\n            // return root(par[x]);         //\
    \ \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\n        }\n    }\n    bool is_root(int\
    \ x) { return par[x] < 0; }\n    bool same(int x, int y) { return root(x) == root(y);\
    \ }\n    int size(int x) { return -par[root(x)]; }\n\n    map<int, vector<int>>\
    \ group(){\n        map<int, vector<int>> res;\n        rep(i, sz(this->par))\
    \ { res[this->root(i)].pb(i); }\n        return res;\n    }\n\n    #if defined(PCM)\
    \ || defined(LOCAL)  // {{{\n    friend ostream& operator<<(ostream& os, union_find&\
    \ uf) {\n        auto group = uf.group();\n        os << endl;\n        each(g,\
    \ group) { os << g << endl; }\n        return os;\n    }\n    #endif  // }}}\n\
    };\n\n//%snippet.end()%\n#line 2 \"library/cpp/include/union_find.hpp\"\n"
  code: '#include "../graph/union_find.hpp"'
  dependsOn:
  - library/cpp/graph/union_find.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/union_find.hpp
  requiredBy: []
  timestamp: '2020-11-23 11:30:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/union_find.hpp
layout: document
redirect_from:
- /library/library/cpp/include/union_find.hpp
- /library/library/cpp/include/union_find.hpp.html
title: library/cpp/include/union_find.hpp
---
