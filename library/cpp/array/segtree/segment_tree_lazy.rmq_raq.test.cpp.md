---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/segtree/segment_tree_lazy.hpp
    title: library/cpp/array/segtree/segment_tree_lazy.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
  bundledCode: "#line 1 \"library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja\"\
    \n#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
    #ifndef HEADER_H\n#define HEADER_H\n\n// template version 2.0\nusing namespace\
    \ std;\n#include <bits/stdc++.h>\n\n// varibable settings\nconst long long INF\
    \ = 1e18;\ntemplate <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i,\
    \ 0, n)\n#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n\
    #define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)\n#define\
    \ each(i, a) for (auto &&i : a)\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b) make_pair(a,\
    \ b)\n#define mt(...) make_tuple(__VA_ARGS__)\n#define ub upper_bound\n#define\
    \ lb lower_bound\n#define lpos(A, x) (lower_bound(all(A), x) - A.begin())\n#define\
    \ upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate <class T, class U>\
    \ inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }\ntemplate\
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
    \ * k + 2]);\n    } \n\n    /* lazy eval */\n    void eval(int k) {\n        if\
    \ (lazy[k] == em) return;  // \u66F4\u65B0\u3059\u308B\u3082\u306E\u304C\u7121\
    \u3051\u308C\u3070\u7D42\u4E86\n        if (k < N - 1) {            // \u8449\u3067\
    \u306A\u3051\u308C\u3070\u5B50\u306B\u4F1D\u642C\n            lazy[k * 2 + 1]\
    \ = composite(lazy[k * 2 + 1], lazy[k]);\n            lazy[k * 2 + 2] = composite(lazy[k\
    \ * 2 + 2], lazy[k]);\n        }\n        // \u81EA\u8EAB\u3092\u66F4\u65B0\n\
    \        dat[k] = apply(dat[k], lazy[k]);\n        lazy[k] = em;\n    }\n\n  \
    \  void update(index a, index b, M x, int k, index l, index r) {\n        eval(k);\n\
    \        if (a <= l && r <= b) {  // \u5B8C\u5168\u306B\u5185\u5074\u306E\u6642\
    \n            lazy[k] = composite(lazy[k], x);\n            eval(k);\n       \
    \ } else if (a < r && l < b) {                     // \u4E00\u90E8\u533A\u9593\
    \u304C\u88AB\u308B\u6642\n            update(a, b, x, k * 2 + 1, l, (l + r) /\
    \ 2);  // \u5DE6\u306E\u5B50\n            update(a, b, x, k * 2 + 2, (l + r) /\
    \ 2, r);  // \u53F3\u306E\u5B50\n            dat[k] = merge(dat[k * 2 + 1], dat[k\
    \ * 2 + 2]);\n        }\n    }\n    void update(index a, index b, M x) { update(a,\
    \ b, x, 0, 0, N); }\n\n    X query_sub(index a, index b, int k, index l, index\
    \ r) {\n        eval(k);\n        if (r <= a || b <= l) {  // \u5B8C\u5168\u306B\
    \u5916\u5074\u306E\u6642\n            return ex;\n        } else if (a <= l &&\
    \ r <= b) {  // \u5B8C\u5168\u306B\u5185\u5074\u306E\u6642\n            return\
    \ dat[k];\n        } else {  // \u4E00\u90E8\u533A\u9593\u304C\u88AB\u308B\u6642\
    \n            X lv = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);\n           \
    \ X rv = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);\n            return merge(lv,\
    \ rv);\n        }\n    }\n    X query(index a, index b) { return query_sub(a,\
    \ b, 0, 0, N); }\n\n    // TODO implement binary search \n\n    /* debug */\n\
    \    inline X operator[](int i) { return query(i, i + 1); }\n\n    #if defined(PCM)\
    \ || defined(LOCAL)\n    friend ostream& operator<<(ostream& os, segment_tree_lazy&\
    \ sg) {  //\n        os << \"[\";\n        for (int i = 0; i < sg.n; i++) {\n\
    \            os << sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n        }\n\
    \        return os;\n    }\n    #endif\n};\n\n/* SegTreeLazyProportional<X,M>(n,fx,fa,fm,ex,em):\
    \ \u30E2\u30CE\u30A4\u30C9(\u96C6\u5408X, \u4E8C\u9805\u6F14\u7B97fx,fa,fm,p \u5358\
    \u4F4D\u5143ex,em)\u306B\u3064\u3044\u3066\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\
    \n    set(int i, X x), build(): i\u756A\u76EE\u306E\u8981\u7D20\u3092x\u306B\u30BB\
    \u30C3\u30C8\u3002\u307E\u3068\u3081\u3066\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u3002O(n)\n    update(i,x): i \u756A\u76EE\u306E\u8981\u7D20\u3092\
    \ x \u306B\u66F4\u65B0\u3002O(log(n))\n    query(a,b):  [a,b) \u5168\u3066\u306B\
    fx\u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\u3092\u53D6\u5F97\u3002O(log(n))\n\
    */\n\n//%snippet.end()%\n\n#line 3 \"library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp\"\
    \n\n// snippet:make_lseg_rmq_raq {{{\nusing X = ll; // (X, merge) is monoid\n\
    using M = ll; // (M, composition) is monoid\nauto make_lseg_rmq_raq(){\n    auto\
    \ merge = [](X x1, X x2){return min(x1,x2);};\n    X ex = 1e18;  // s.t merge(x,\
    \ ex) = x\n    auto composition = [](M m1, M m2){return m1 + m2;};\n    M em =\
    \ 0;  // s.t composition(m, em) = m && composition(em, m) = m && apply(x, em)\
    \ = x\n    auto apply = [](X x, M m){return x + m;};\n    return segment_tree_lazy<X,\
    \ M>(merge, apply, composition, ex, em);\n}\n// snippet:make_lseg_rmq_raq }}}\n\
    \nint main(){\n    ll n,q;cin>>n>>q;\n    auto lseg = make_lseg_rmq_raq();\n \
    \   const int sz = n;\n    lseg.build(vector<X>(sz, 0));\n    rep(i, q){\n   \
    \     int ty;cin>>ty;\n        if (ty == 0){\n            ll s,t,x;cin>>s>>t>>x;\n\
    \            lseg.update(s, t+1, x);\n        }\n        if (ty == 1){\n     \
    \       ll s,t;cin>>s>>t;\n            cout << lseg.query(s, t+1) << endl;\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja\"\
    \n#include \"segment_tree_lazy.hpp\"\n\n// snippet:make_lseg_rmq_raq {{{\nusing\
    \ X = ll; // (X, merge) is monoid\nusing M = ll; // (M, composition) is monoid\n\
    auto make_lseg_rmq_raq(){\n    auto merge = [](X x1, X x2){return min(x1,x2);};\n\
    \    X ex = 1e18;  // s.t merge(x, ex) = x\n    auto composition = [](M m1, M\
    \ m2){return m1 + m2;};\n    M em = 0;  // s.t composition(m, em) = m && composition(em,\
    \ m) = m && apply(x, em) = x\n    auto apply = [](X x, M m){return x + m;};\n\
    \    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);\n}\n//\
    \ snippet:make_lseg_rmq_raq }}}\n\nint main(){\n    ll n,q;cin>>n>>q;\n    auto\
    \ lseg = make_lseg_rmq_raq();\n    const int sz = n;\n    lseg.build(vector<X>(sz,\
    \ 0));\n    rep(i, q){\n        int ty;cin>>ty;\n        if (ty == 0){\n     \
    \       ll s,t,x;cin>>s>>t>>x;\n            lseg.update(s, t+1, x);\n        }\n\
    \        if (ty == 1){\n            ll s,t;cin>>s>>t;\n            cout << lseg.query(s,\
    \ t+1) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - library/cpp/array/segtree/segment_tree_lazy.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 01:02:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp
- /verify/library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp.html
title: library/cpp/array/segtree/segment_tree_lazy.rmq_raq.test.cpp
---
