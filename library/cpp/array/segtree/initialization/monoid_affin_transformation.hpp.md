---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/segtree/segment_tree_lazy.hpp
    title: library/cpp/array/segtree/segment_tree_lazy.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/segtree/initialization/segment_tree_lazy.rsq_raffinq.hpp
    title: library/cpp/array/segtree/initialization/segment_tree_lazy.rsq_raffinq.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rsq_raffinq.test.cpp
    title: library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rsq_raffinq.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n// varibable settings\n\
    const long long INF = 1e18;\ntemplate <class T> constexpr T inf = numeric_limits<T>::max()\
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
    \ zs...); return vector<decltype(cont)>(x, cont); }\n\n#define cdiv(a, b) (((a)\
    \ + (b)-1) / (b))\n#define is_in(x, a, b) ((a) <= (x) && (x) < (b))\n#define uni(x)\
    \ sort(all(x)); x.erase(unique(all(x)), x.end())\n#define slice(l, r) substr(l,\
    \ r - l)\n\ntypedef long long ll;\ntypedef long double ld;\nusing vl = vector<ll>;\n\
    using vvl = vector<vl>;\nusing pll = pair<ll, ll>;\n\ntemplate <typename T>\n\
    using PQ = priority_queue<T, vector<T>, greater<T>>;\nvoid check_input() { assert(cin.eof()\
    \ == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }\n\n#if defined(PCM) ||\
    \ defined(LOCAL)\n#else\n#define dump(...) ;\n#define dump_1d(...) ;\n#define\
    \ dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n\
    #line 3 \"library/cpp/array/segtree/segment_tree_lazy.hpp\"\n\n//%snippet.set('segment_tree_lazy')%\n\
    //%snippet.config({'alias':'lazy'})%\n//%snippet.fold()%\n\ntemplate <typename\
    \ X, typename M>\nstruct segment_tree_lazy {\n    using FX = function<X(X, X)>;\n\
    \    using FA = function<X(X, M)>;\n    using FM = function<M(M, M)>;\n    using\
    \ index = int;\n    int n;  // \u5143\u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\
    \n    int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n    FX merge;\n\
    \    FA apply;\n    FM composite;\n    const X ex;\n    const M em;\n    vector<X>\
    \ dat;\n    vector<M> lazy;\n    segment_tree_lazy(FX merge_, FA apply_, FM composite_,\
    \ X ex_, M em_)\n        : merge(merge_), apply(apply_), composite(composite_),\
    \ ex(ex_), em(em_) {\n    }\n\n    void set(index i, X x) { dat[i + n - 1] = x;\
    \ }\n    void init(index n_) { \n        N = 1;\n        n = n_;\n        while\
    \ (N < n_) N <<= 1;\n        dat.assign(2 * N, ex);\n        lazy.assign(2 * N,\
    \ em);\n    } \n\n    void build(const vector<X> &v) { \n        int n_ = v.size();\n\
    \        init(n_);\n        for (int i = 0; i < n_; i++) dat[i + N - 1] = v[i];\n\
    \        for (int k = N - 2; k >= 0; k--) dat[k] = merge(dat[2 * k + 1], dat[2\
    \ * k + 2]);\n    } \n\n    /* lazy propagate */\n    void propagate(int k) {\n\
    \        if (lazy[k] == em) return;  // \u66F4\u65B0\u3059\u308B\u3082\u306E\u304C\
    \u7121\u3051\u308C\u3070\u7D42\u4E86\n        if (k < N - 1) {            // \u8449\
    \u3067\u306A\u3051\u308C\u3070\u5B50\u306B\u4F1D\u642C\n            lazy[k * 2\
    \ + 1] = composite(lazy[k * 2 + 1], lazy[k]);\n            lazy[k * 2 + 2] = composite(lazy[k\
    \ * 2 + 2], lazy[k]);\n        }\n        // \u81EA\u8EAB\u3092\u66F4\u65B0\n\
    \        dat[k] = apply(dat[k], lazy[k]);\n        lazy[k] = em;\n    }\n\n  \
    \  void update(index a, index b, M x) { update(a, b, x, 0, 0, N); }\n    void\
    \ update(index a, index b, M x, int k, index l, index r) {\n        if (a <= l\
    \ && r <= b) {  // \u5B8C\u5168\u306B\u5185\u5074\u306E\u6642\n            lazy[k]\
    \ = composite(lazy[k], x);\n            propagate(k);\n        }\n        else\
    \ if (a < r && l < b) {                     // \u4E00\u90E8\u533A\u9593\u304C\u88AB\
    \u308B\u6642\n            propagate(k);\n            update(a, b, x, k * 2 + 1,\
    \ l, (l + r) / 2);  // \u5DE6\u306E\u5B50\n            update(a, b, x, k * 2 +\
    \ 2, (l + r) / 2, r);  // \u53F3\u306E\u5B50\n            dat[k] = merge(dat[k\
    \ * 2 + 1], dat[k * 2 + 2]);\n        }\n        else{\n            propagate(k);\n\
    \        }\n    }\n\n    X query(index a, index b) { return query_sub(a, b, 0,\
    \ 0, N); }\n    X query_sub(index a, index b, int k, index l, index r) {\n   \
    \     propagate(k);\n        if (r <= a || b <= l) {  // \u5B8C\u5168\u306B\u5916\
    \u5074\u306E\u6642\n            return ex;\n        }\n        else if (a <= l\
    \ && r <= b) {  // \u5B8C\u5168\u306B\u5185\u5074\u306E\u6642\n            return\
    \ dat[k];\n        }\n        else {  // \u4E00\u90E8\u533A\u9593\u304C\u88AB\u308B\
    \u6642\n            X lv = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);\n     \
    \       X rv = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);\n            return\
    \ merge(lv, rv);\n        }\n    }\n\n    index find_most_left(index l, const\
    \ function<bool(X)>& is_ok){\n        // l\u304B\u3089\u53F3\u306B\u63A2\u3057\
    \u3066\u3044\u3063\u3066is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\
    \u3046\u306Aindex\u3092\u8FD4\u3059\u3002\n        // assume query(l, *) has monotonity\n\
    \        // return index i s.t is_ok(query(l, i)) does not holds, but is_ok(query(l,\
    \ i+1)) does.\n        // if such i does not exist, return n\n        index res\
    \ = _find_most_left(l, is_ok, 0, 0, N, ex).first;\n        assert(l <= res);\n\
    \        return res;\n    }\n    pair<index, X> _find_most_left(index a, const\
    \ function<bool(X)>& is_ok, int k, index l, index r, X left_value){\n        //\
    \ params:\n            // left_value = (a < l ? query(a, l) : ex)\n        //\
    \ return (index i, X v)\n            // i is the index in [a, n)^[l, r) s.t query(a,\
    \ i+1) is ok but query(a, i) isn't ok. if such i does not exist, i = n\n     \
    \       // v is the value s.t query(a, r)\n\n        propagate(k);\n        if\
    \ (r <= a) return {n, ex};  // \u533A\u9593\u304C\u5168\u304F\u88AB\u3063\u3066\
    \u3044\u306A\u3044\n        else if (a <= l && !is_ok(merge(left_value, dat[k])))\
    \ return {n, merge(left_value, dat[k])};\n        else if (k >= N-1) return {k\
    \ - (N-1), merge(left_value, dat[k])};\n        else{\n            auto [vl, xl]\
    \ = _find_most_left(a, is_ok, 2 * k + 1, l, (l + r) / 2, left_value);\n      \
    \      if (vl != n) return {vl, xl};\n            auto [vr, xr] = _find_most_left(a,\
    \ is_ok, 2 * k + 2, (l + r) / 2, r, xl);\n            return {vr, xr};\n     \
    \   }\n    }\n\n    index find_most_right(index r, const function<bool(X)>& is_ok){\n\
    \        // r\u304B\u3089\u5DE6\u306B\u63A2\u3057\u3066\u3044\u3063\u3066is_ok\u304C\
    \u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\u8FD4\u3059\
    \u3002\n        // assume query(*, r) has monotonity\n        // return index\
    \ i s.t is_ok(query(i+1, r+1)) does not holds, but is_ok(query(i, r+1)) does.\n\
    \        // if such i does not exist, return -1\n        index res = _find_most_right(r+1,\
    \ is_ok, 0, 0, N, ex).first;\n        assert(res <= r);\n        return res;\n\
    \    }\n    pair<index, X> _find_most_right(index b, const function<bool(X)>&\
    \ is_ok, int k, index l, index r, X right_value){\n        propagate(k);\n   \
    \     if (b <= l) return {-1, ex};  // \u533A\u9593\u304C\u5168\u304F\u88AB\u3063\
    \u3066\u3044\u306A\u3044\n        else if (r <= b && !is_ok(merge(dat[k], right_value)))\
    \ return {-1, merge(dat[k], right_value)};\n        else if (k >= N-1) return\
    \ {k - (N-1), merge(dat[k], right_value)};\n        else{\n            auto [vr,\
    \ xr] = _find_most_right(b, is_ok, 2 * k + 2, (l + r) / 2, r, right_value);\n\
    \            if (vr != -1) return {vr, xr};\n            auto [vl, xl] = _find_most_right(b,\
    \ is_ok, 2 * k + 1, l, (l + r) / 2, xr);\n            return {vl, xl};\n     \
    \   }\n    }\n\n    /* debug */\n    inline X operator[](int i) { return query(i,\
    \ i + 1); }\n\n    #if defined(PCM) || defined(LOCAL)\n    friend ostream& operator<<(ostream&\
    \ os, segment_tree_lazy& sg) {  //\n        os << \"[\";\n        for (int i =\
    \ 0; i < sg.n; i++) {\n            os << sg[i] << (i == sg.n - 1 ? \"]\\n\" :\
    \ \", \");\n        }\n        return os;\n    }\n    #endif\n};\n// Regarding\
    \ apply and merge, the conditions below should holds.\n// apply(merge(x1, x2),\
    \ m) = merge(apply(x1, m), apply(x2, m))\n// apply(apply(x, m1), m2) = apply(x,\
    \ composition(m1, m2))\n// composition(m, em) = m && composition(em, m) = m &&\
    \ apply(x, em) = x\n\n//%snippet.end()%\n\n#line 2 \"library/cpp/array/segtree/initialization/monoid_affin_transformation.hpp\"\
    \n\n//%snippet.set('monoid_affin_transformation')%\n//%snippet.fold()%\nstruct\
    \ monoid_affin_transformation {\n    mint a, b;\n    monoid_affin_transformation(){};\n\
    \    monoid_affin_transformation(mint a_, mint b_) : a(a_), b(b_){};\n};\nmonoid_affin_transformation\
    \ operator+(monoid_affin_transformation x, monoid_affin_transformation y){\n \
    \   return monoid_affin_transformation(x.a * y.a, x.b * y.a + y.b);\n}\nbool operator==(monoid_affin_transformation\
    \ m1, monoid_affin_transformation m2) {\n    return m1.a == m2.a && m1.b == m2.b;\n\
    }\n//%snippet.end()%\n"
  code: "#include \"../segment_tree_lazy.hpp\"\n\n//%snippet.set('monoid_affin_transformation')%\n\
    //%snippet.fold()%\nstruct monoid_affin_transformation {\n    mint a, b;\n   \
    \ monoid_affin_transformation(){};\n    monoid_affin_transformation(mint a_, mint\
    \ b_) : a(a_), b(b_){};\n};\nmonoid_affin_transformation operator+(monoid_affin_transformation\
    \ x, monoid_affin_transformation y){\n    return monoid_affin_transformation(x.a\
    \ * y.a, x.b * y.a + y.b);\n}\nbool operator==(monoid_affin_transformation m1,\
    \ monoid_affin_transformation m2) {\n    return m1.a == m2.a && m1.b == m2.b;\n\
    }\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/array/segtree/segment_tree_lazy.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/array/segtree/initialization/monoid_affin_transformation.hpp
  requiredBy:
  - library/cpp/array/segtree/initialization/segment_tree_lazy.rsq_raffinq.hpp
  timestamp: '2020-09-26 18:55:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rsq_raffinq.test.cpp
documentation_of: library/cpp/array/segtree/initialization/monoid_affin_transformation.hpp
layout: document
redirect_from:
- /library/library/cpp/array/segtree/initialization/monoid_affin_transformation.hpp
- /library/library/cpp/array/segtree/initialization/monoid_affin_transformation.hpp.html
title: library/cpp/array/segtree/initialization/monoid_affin_transformation.hpp
---
