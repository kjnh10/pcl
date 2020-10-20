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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/array/segtree/rmq_2d.cpp\"\
    \n\n//%snippet.set('SegmentTree2DRMQ')%\n//%snippet.config({'alias':'2drmq'})%\n\
    struct segtree {\n    int H, W;\n    vector<vector<int>> dat;\n    segtree() {}\n\
    \    segtree(vector<vector<int>> &f) {\n        H = W = 1;\n        while (H <\
    \ (int)f.size()) H <<= 1;\n        while (W < (int)f[0].size()) W <<= 1;\n   \
    \     dat.assign(2 * H - 1, vector<int>(2 * W - 1, inf<int>));\n        init(f);\n\
    \    }\n    void init(vector<vector<int>> &f) {\n        for (int i = 0; i < (int)f.size();\
    \ i++)\n            for (int j = 0; j < (int)f[0].size(); j++)\n             \
    \   dat[i + H - 1][j + W - 1] = f[i][j];\n        dump(\"hello\");\n        for\
    \ (int i = 2 * H - 2; i > H - 2; i--)\n            for (int j = W - 2; j >= 0;\
    \ j--)\n                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2 * j + 2]);\n\
    \        dump(\"hello1\");\n        for (int i = H - 2; i >= 0; i--)\n       \
    \     for (int j = 0; j < 2 * W - 1; j++)\n                dat[i][j] = min(dat[2\
    \ * i + 1][j], dat[2 * i + 2][j]);\n        dump(\"hello2\");\n    }\n    int\
    \ minimum(int li, int lj, int ri, int rj) {\n        return minimum_h(li, lj,\
    \ ri, rj, 0, H, 0);\n    }\n    int minimum_h(int li, int lj, int ri, int rj,\
    \ int si, int ti, int k) {\n        if (ri <= si or ti <= li) return inf<int>;\n\
    \        if (li <= si and ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);\n  \
    \      const int mi = (si + ti) / 2;\n        return min(minimum_h(li, lj, ri,\
    \ rj, si, mi, 2 * k + 1),\n                   minimum_h(li, lj, ri, rj, mi, ti,\
    \ 2 * k + 2));\n    }\n    int minimum_w(int lj, int rj, int sj, int tj, int i,\
    \ int k) {\n        if (rj <= sj or tj <= lj) return inf<int>;\n        if (lj\
    \ <= sj and tj <= rj) return dat[i][k];\n        const int mj = (sj + tj) / 2;\n\
    \        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),\n               \
    \    minimum_w(lj, rj, mj, tj, i, 2 * k + 2));\n    }\n};\n//%snippet.end()%\n"
  code: "#include \"../../header.hpp\"\n\n//%snippet.set('SegmentTree2DRMQ')%\n//%snippet.config({'alias':'2drmq'})%\n\
    struct segtree {\n    int H, W;\n    vector<vector<int>> dat;\n    segtree() {}\n\
    \    segtree(vector<vector<int>> &f) {\n        H = W = 1;\n        while (H <\
    \ (int)f.size()) H <<= 1;\n        while (W < (int)f[0].size()) W <<= 1;\n   \
    \     dat.assign(2 * H - 1, vector<int>(2 * W - 1, inf<int>));\n        init(f);\n\
    \    }\n    void init(vector<vector<int>> &f) {\n        for (int i = 0; i < (int)f.size();\
    \ i++)\n            for (int j = 0; j < (int)f[0].size(); j++)\n             \
    \   dat[i + H - 1][j + W - 1] = f[i][j];\n        dump(\"hello\");\n        for\
    \ (int i = 2 * H - 2; i > H - 2; i--)\n            for (int j = W - 2; j >= 0;\
    \ j--)\n                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2 * j + 2]);\n\
    \        dump(\"hello1\");\n        for (int i = H - 2; i >= 0; i--)\n       \
    \     for (int j = 0; j < 2 * W - 1; j++)\n                dat[i][j] = min(dat[2\
    \ * i + 1][j], dat[2 * i + 2][j]);\n        dump(\"hello2\");\n    }\n    int\
    \ minimum(int li, int lj, int ri, int rj) {\n        return minimum_h(li, lj,\
    \ ri, rj, 0, H, 0);\n    }\n    int minimum_h(int li, int lj, int ri, int rj,\
    \ int si, int ti, int k) {\n        if (ri <= si or ti <= li) return inf<int>;\n\
    \        if (li <= si and ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);\n  \
    \      const int mi = (si + ti) / 2;\n        return min(minimum_h(li, lj, ri,\
    \ rj, si, mi, 2 * k + 1),\n                   minimum_h(li, lj, ri, rj, mi, ti,\
    \ 2 * k + 2));\n    }\n    int minimum_w(int lj, int rj, int sj, int tj, int i,\
    \ int k) {\n        if (rj <= sj or tj <= lj) return inf<int>;\n        if (lj\
    \ <= sj and tj <= rj) return dat[i][k];\n        const int mj = (sj + tj) / 2;\n\
    \        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),\n               \
    \    minimum_w(lj, rj, mj, tj, i, 2 * k + 2));\n    }\n};\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/array/segtree/rmq_2d.cpp
  requiredBy: []
  timestamp: '2020-10-17 17:32:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/segtree/rmq_2d.cpp
layout: document
redirect_from:
- /library/library/cpp/array/segtree/rmq_2d.cpp
- /library/library/cpp/array/segtree/rmq_2d.cpp.html
title: library/cpp/array/segtree/rmq_2d.cpp
---
