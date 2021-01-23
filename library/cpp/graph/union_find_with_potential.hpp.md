---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/cpp/include/union_find_with_potential.hpp
    title: library/cpp/include/union_find_with_potential.hpp
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/graph/union_find_with_potential.hpp\"\
    \n\n//%snippet.set('union_find_with_potential')%\n//%snippet.fold()%\n\ntemplate<class\
    \ Pot = ll>  // Pot: Abel\nstruct union_find {\n    vector<int> par;   // par[x]:\
    \ parent of x. if root, -size.\n    int gcount;         // count of groups\n \
    \   vector<Pot>  diff;\n    union_find() {}\n    union_find(int _n, Pot SUM_UNITY\
    \ = 0) : par(_n, -1), gcount(_n), diff(_n, SUM_UNITY) {}\n    bool merge(int x,\
    \ int y, Pot d) { /*{{{*/\n        // d:= wight(y) - weight(x)\n        int rx\
    \ = root(x);\n        int ry = root(y);\n        if (rx != ry) {\n           \
    \ if (par[ry] >= par[rx]) {\n                par[rx] += par[ry];\n           \
    \     par[ry] = rx;\n                diff[ry] = diff[x] + d + (-diff[y]);\n  \
    \          }\n            else{\n                par[ry] += par[rx];\n       \
    \         par[rx] = ry;\n                diff[rx] = (-diff[x]) + (-d) + diff[y];\n\
    \            }\n            gcount--;\n        }\n        else{\n            if\
    \ (weight(y) + (-weight(x)) != d){\n                throw runtime_error(\"contradiction\
    \ exist\");\n            }\n        }\n        return rx != ry;\n    } /*}}}*/\n\
    \    int root(int x) {/*{{{*/\n        if (is_root(x)){\n            return x;\n\
    \        }\n        else{\n            int r = root(par[x]);\n            diff[x]\
    \ += diff[par[x]];\n            par[x] = r;\n            return par[x];\n    \
    \    }\n    }/*}}}*/\n    Pot weight(int x){/*{{{*/\n        root(x); // \u7D4C\
    \u8DEF\u5727\u7E2E\n        return diff[x];\n    }/*}}}*/\n    Pot diff(int x,\
    \ int y){/*{{{*/\n        if (!same(x, y)){\n            string s = to_string(x)\
    \ + \" and \" + to_string(y) + \" are not in the same group.\";\n            throw\
    \ invalid_argument(s);\n        }\n        else{\n            return weight(y)\
    \ + (-weight(x));\n        }\n    }/*}}}*/\n    bool is_root(int x) { return par[x]\
    \ < 0; }\n    bool same(int x, int y) { return root(x) == root(y); }\n    int\
    \ size(int x) { return -par[root(x)]; }\n#if defined(PCM) || defined(LOCAL)  //\
    \ {{{\n    friend ostream& operator<<(ostream& os, union_find& uf) {\n       \
    \ map<int, vector<int>> group;\n        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i);\
    \ }\n        os << endl;\n        each(g, group) { os << g << endl; }\n      \
    \  return os;\n    }\n#endif  // }}}\n};\n\n//%snippet.end()%\n"
  code: "#pragma once\n#include \"../header.hpp\"\n\n//%snippet.set('union_find_with_potential')%\n\
    //%snippet.fold()%\n\ntemplate<class Pot = ll>  // Pot: Abel\nstruct union_find\
    \ {\n    vector<int> par;   // par[x]: parent of x. if root, -size.\n    int gcount;\
    \         // count of groups\n    vector<Pot>  diff;\n    union_find() {}\n  \
    \  union_find(int _n, Pot SUM_UNITY = 0) : par(_n, -1), gcount(_n), diff(_n, SUM_UNITY)\
    \ {}\n    bool merge(int x, int y, Pot d) { /*{{{*/\n        // d:= wight(y) -\
    \ weight(x)\n        int rx = root(x);\n        int ry = root(y);\n        if\
    \ (rx != ry) {\n            if (par[ry] >= par[rx]) {\n                par[rx]\
    \ += par[ry];\n                par[ry] = rx;\n                diff[ry] = diff[x]\
    \ + d + (-diff[y]);\n            }\n            else{\n                par[ry]\
    \ += par[rx];\n                par[rx] = ry;\n                diff[rx] = (-diff[x])\
    \ + (-d) + diff[y];\n            }\n            gcount--;\n        }\n       \
    \ else{\n            if (weight(y) + (-weight(x)) != d){\n                throw\
    \ runtime_error(\"contradiction exist\");\n            }\n        }\n        return\
    \ rx != ry;\n    } /*}}}*/\n    int root(int x) {/*{{{*/\n        if (is_root(x)){\n\
    \            return x;\n        }\n        else{\n            int r = root(par[x]);\n\
    \            diff[x] += diff[par[x]];\n            par[x] = r;\n            return\
    \ par[x];\n        }\n    }/*}}}*/\n    Pot weight(int x){/*{{{*/\n        root(x);\
    \ // \u7D4C\u8DEF\u5727\u7E2E\n        return diff[x];\n    }/*}}}*/\n    Pot\
    \ diff(int x, int y){/*{{{*/\n        if (!same(x, y)){\n            string s\
    \ = to_string(x) + \" and \" + to_string(y) + \" are not in the same group.\"\
    ;\n            throw invalid_argument(s);\n        }\n        else{\n        \
    \    return weight(y) + (-weight(x));\n        }\n    }/*}}}*/\n    bool is_root(int\
    \ x) { return par[x] < 0; }\n    bool same(int x, int y) { return root(x) == root(y);\
    \ }\n    int size(int x) { return -par[root(x)]; }\n#if defined(PCM) || defined(LOCAL)\
    \  // {{{\n    friend ostream& operator<<(ostream& os, union_find& uf) {\n   \
    \     map<int, vector<int>> group;\n        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i);\
    \ }\n        os << endl;\n        each(g, group) { os << g << endl; }\n      \
    \  return os;\n    }\n#endif  // }}}\n};\n\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/graph/union_find_with_potential.hpp
  requiredBy:
  - library/cpp/include/union_find_with_potential.hpp
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/union_find_with_potential.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/union_find_with_potential.hpp
- /library/library/cpp/graph/union_find_with_potential.hpp.html
title: library/cpp/graph/union_find_with_potential.hpp
---
