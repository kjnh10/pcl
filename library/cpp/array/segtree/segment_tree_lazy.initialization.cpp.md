---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/segtree/segment_tree_lazy.hpp
    title: library/cpp/array/segtree/segment_tree_lazy.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/mint.hpp
    title: library/cpp/math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
    \  void update(index a, index b, M x, int k, index l, index r) {\n        if (a\
    \ <= l && r <= b) {  // \u5B8C\u5168\u306B\u5185\u5074\u306E\u6642\n         \
    \   lazy[k] = composite(lazy[k], x);\n            propagate(k);\n        }\n \
    \       else if (a < r && l < b) {                     // \u4E00\u90E8\u533A\u9593\
    \u304C\u88AB\u308B\u6642\n            propagate(k);\n            update(a, b,\
    \ x, k * 2 + 1, l, (l + r) / 2);  // \u5DE6\u306E\u5B50\n            update(a,\
    \ b, x, k * 2 + 2, (l + r) / 2, r);  // \u53F3\u306E\u5B50\n            dat[k]\
    \ = merge(dat[k * 2 + 1], dat[k * 2 + 2]);\n        }\n        else{\n       \
    \     propagate(k);\n        }\n    }\n    void update(index a, index b, M x)\
    \ { update(a, b, x, 0, 0, N); }\n\n    X query_sub(index a, index b, int k, index\
    \ l, index r) {\n        propagate(k);\n        if (r <= a || b <= l) {  // \u5B8C\
    \u5168\u306B\u5916\u5074\u306E\u6642\n            return ex;\n        }\n    \
    \    else if (a <= l && r <= b) {  // \u5B8C\u5168\u306B\u5185\u5074\u306E\u6642\
    \n            return dat[k];\n        }\n        else {  // \u4E00\u90E8\u533A\
    \u9593\u304C\u88AB\u308B\u6642\n            X lv = query_sub(a, b, k * 2 + 1,\
    \ l, (l + r) / 2);\n            X rv = query_sub(a, b, k * 2 + 2, (l + r) / 2,\
    \ r);\n            return merge(lv, rv);\n        }\n    }\n    X query(index\
    \ a, index b) { return query_sub(a, b, 0, 0, N); }\n\n    // TODO implement binary\
    \ search \n\n    /* debug */\n    inline X operator[](int i) { return query(i,\
    \ i + 1); }\n\n    #if defined(PCM) || defined(LOCAL)\n    friend ostream& operator<<(ostream&\
    \ os, segment_tree_lazy& sg) {  //\n        os << \"[\";\n        for (int i =\
    \ 0; i < sg.n; i++) {\n            os << sg[i] << (i == sg.n - 1 ? \"]\\n\" :\
    \ \", \");\n        }\n        return os;\n    }\n    #endif\n};\n\n/* SegTreeLazyProportional<X,M>(n,fx,fa,fm,ex,em):\
    \ \u30E2\u30CE\u30A4\u30C9(\u96C6\u5408X, \u4E8C\u9805\u6F14\u7B97fx,fa,fm,p \u5358\
    \u4F4D\u5143ex,em)\u306B\u3064\u3044\u3066\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\
    \n    set(int i, X x), build(): i\u756A\u76EE\u306E\u8981\u7D20\u3092x\u306B\u30BB\
    \u30C3\u30C8\u3002\u307E\u3068\u3081\u3066\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u3002O(n)\n    update(i,x): i \u756A\u76EE\u306E\u8981\u7D20\u3092\
    \ x \u306B\u66F4\u65B0\u3002O(log(n))\n    query(a,b):  [a,b) \u5168\u3066\u306B\
    fx\u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\u3092\u53D6\u5F97\u3002O(log(n))\n\
    */\n\n//%snippet.end()%\n\n#line 3 \"library/cpp/math/mint.hpp\"\n\n//%snippet.set('mint')%\n\
    int mod = 1e9 + 7;\n// int mod = 998244353;\nstruct mint {  //{{{\n    ll x;\n\
    \    mint(ll x = 0) : x((x % mod + mod) % mod) {}\n\n    // ?= operator\n    mint&\
    \ operator+=(const mint a) {\n        (x += a.x) %= mod;\n        return *this;\n\
    \    }\n    mint& operator-=(const mint a) {\n        (x += mod - a.x) %= mod;\n\
    \        return *this;\n    }\n    mint& operator*=(const mint a) {\n        (x\
    \ *= a.x) %= mod;\n        return *this;\n    }\n    mint& operator/=(const mint&\
    \ rhs) {\n        if (rhs.x == 0) throw runtime_error(\"mint zero division\");\n\
    \        return *this *= rhs.inv();\n    }\n\n    mint operator+(const mint a)\
    \ const {\n        mint res(*this);\n        return res += a;\n    }\n    mint\
    \ operator-(const mint a) const {\n        mint res(*this);\n        return res\
    \ -= a;\n    }\n    mint operator*(const mint a) const {\n        mint res(*this);\n\
    \        return res *= a;\n    }\n    mint operator/(const mint a) const {\n \
    \       mint res(*this);\n        return res /= a;\n    }\n\n    mint pow(ll n)\
    \ const {\n        mint res(1), x(*this);\n        if (n < 0) {\n            n\
    \ = -n;\n            x = (*this).inv();\n        }\n        while (n) {\n    \
    \        if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    mint inv() const {\n        if (x ==\
    \ 0) throw runtime_error(\"inv does not exist\");\n        return pow(mod - 2);\n\
    \    }\n    // mint inv()const{\n    //     int x,y;\n    //     int g=extgcd(v,mod,x,y);\n\
    \    //     assert(g==1);\n    //     if(x<0)x+=mod;\n    //     return mint(x);\n\
    \    // }\n\n    bool operator<(const mint& r) const { return x < r.x; }\n   \
    \ bool operator==(const mint& r) const { return x == r.x; }\n};\nistream& operator>>(istream&\
    \ is, const mint& a) { return is >> a.x; }\nostream& operator<<(ostream& os, const\
    \ mint& a) { return os << a.x; }\n//}}}\n#line 3 \"library/cpp/array/segtree/segment_tree_lazy.initialization.cpp\"\
    \n\n// Regarding apply and merge, the conditions below should holds.\n// apply(merge(x1,\
    \ x2), m) = merge(apply(x1, m), apply(x2, m))\n// apply(apply(x, m1), m2) = apply(x,\
    \ composition(m1, m2))\n// composition(m, em) = m && composition(em, m) = m &&\
    \ apply(x, em) = x\n\n\n//%snippet.set('make_lseg_rmq_ruq')%\n//%snippet.config({'alias':'rmq_ruq'})%\n\
    //%snippet.fold()%\nusing X = ll; // (X, merge) is monoid\nusing M = ll; // (M,\
    \ composition) is monoid\nauto make_lseg_rmq_ruq(){\n    auto merge = [](X x1,\
    \ X x2){return min(x1,x2);};\n    X ex = numeric_limits<X>::max();  // s.t merge(x,\
    \ ex) = x\n    M em = numeric_limits<M>::max();\n    // s.t composition(m, em)\
    \ = m && s.t composition(em, m) = m && apply(x, em) = x\n    auto composition\
    \ = [=](M m1, M m2){ \n        if (m1 == em) return m2;\n        if (m2 == em)\
    \ return m1;\n        return m2;\n    };\n    auto apply = [=](X x, M m){return\
    \ (m==em ? x : m);};\n    return segment_tree_lazy<X, M>(merge, apply, composition,\
    \ ex, em);\n}\n//%snippet.end()%\n\n\n//%snippet.set('make_lseg_rmq_raq')%\n//%snippet.config({'alias':'rmq_raq'})%\n\
    //%snippet.fold()%\nusing X = ll; // (X, merge) is monoid\nusing M = ll; // (M,\
    \ composition) is monoid\nauto make_lseg_rmq_raq(){\n    auto merge = [](X x1,\
    \ X x2){return min(x1,x2);};\n    X ex = numeric_limits<X>::max();\n    auto composition\
    \ = [](M m1, M m2){return m1 + m2;};\n    M em = 0;\n    auto apply = [](X x,\
    \ M m){return x + m;};\n    return segment_tree_lazy<X, M>(merge, apply, composition,\
    \ ex, em);\n}\n//%snippet.end()%\n\n\n//%snippet.set('monoid_with_len')%\n//%snippet.fold()%\n\
    template<class T>\nstruct monoid_with_len {\n    T x;\n    int len;\n    monoid_with_len(){};\n\
    \    monoid_with_len(T x_, ll len_) : x(x_), len(len_){};\n};\ntemplate<class\
    \ T>\nmonoid_with_len<T> operator+(monoid_with_len<T> a, monoid_with_len<T> b){\n\
    \    return monoid_with_len<T>(a.x + b.x, a.len + b.len);\n}\n//%snippet.end()%\n\
    \n\n//%snippet.set('monoid_affin_transformation')%\n//%snippet.fold()%\nstruct\
    \ monoid_affin_transformation {\n    mint a, b;\n    monoid_affin_transformation(){};\n\
    \    monoid_affin_transformation(mint a_, mint b_) : a(a_), b(b_){};\n};\nmonoid_affin_transformation\
    \ operator+(monoid_affin_transformation x, monoid_affin_transformation y){\n \
    \   return monoid_affin_transformation(x.a * y.a, x.b * y.a + y.b);\n}\nbool operator==(monoid_affin_transformation\
    \ m1, monoid_affin_transformation m2) {\n    return m1.a == m2.a && m1.b == m2.b;\n\
    }\n//%snippet.end()%\n\n\n//%snippet.set('make_lseg_rsq_raffinq')%\n//%snippet.config({'alias':'rsq_raffinq'})%\n\
    //%snippet.include('monoid_with_len')%\n//%snippet.include('monoid_affin_transformation')%\n\
    //%snippet.fold()%\nusing X = monoid_with_len<mint>; // (X, merge) is monoid\n\
    using M = monoid_affin_transformation; // (M, composition) is monoid\nauto make_lseg_rsq_raffinq(){\n\
    \    auto merge = [](X x1, X x2){return x1 + x2;};\n    X ex = X(0, 0);\n    M\
    \ em = M(1, 0);\n    auto composition = [](M m1, M m2){ return m1 + m2; };\n \
    \   auto apply = [](X x, M m){return X(x.x*m.a + m.b*x.len, x.len);};\n    return\
    \ segment_tree_lazy<X, M>(merge, apply, composition, ex, em);\n}\n//%snippet.end()%\n\
    \n\n//%snippet.set('make_lseg_rsq_raq')%\n//%snippet.config({'alias':'rsq_raq'})%\n\
    //%snippet.include('monoid_with_len')%\n//%snippet.fold()%\nusing X = monoid_with_len<ll>;\
    \ // (X, merge) is monoid\nusing M = ll; // (M, composition) is monoid\nauto make_lseg_rsq_raq(){\n\
    \    auto merge = [](X x1, X x2){return x1 + x2;};\n    X ex = X(0, 0);\n    M\
    \ em = 0;\n    auto composition = [](M m1, M m2){ return m1 + m2; };\n    auto\
    \ apply = [](X x, M m){return X(x.x + m*x.len, x.len);};\n    return segment_tree_lazy<X,\
    \ M>(merge, apply, composition, ex, em);\n}\n//%snippet.end()%\n\n\n\n// dual\
    \ segment tree\n\n//%snippet.set('make_lseg_getone_chmin')%\n//%snippet.config({'alias':'getone_chmin'})%\n\
    //%snippet.fold()%\nusing X = ll; // (X, merge) is monoid // \u53CC\u5BFE\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3068\u3057\u3066\u4F7F\u3046\u6642\u306F\u9069\
    \u5F53\u306A\u30E2\u30CE\u30A4\u30C9\u3092\u5165\u308C\u3066\u304A\u3051\u3070\
    \u826F\u3044\u3002\nusing M = ll; // (M, composition) is monoid\nauto make_lseg_getone_chmin(){\n\
    \    auto merge = [](X x1, X x2){return min(x1,x2);};\n    X ex = numeric_limits<X>::max();\n\
    \    M em = numeric_limits<M>::max();\n    auto composition = [](M m1, M m2){return\
    \ min(m1, m2);};\n    auto apply = [](X x, M m){return min(x, m);};\n    return\
    \ segment_tree_lazy<X, M>(merge, apply, composition, ex, em);\n}\n//%snippet.end()%\n"
  code: "#include \"segment_tree_lazy.hpp\"\n#include \"../../math/mint.hpp\"\n\n\
    // Regarding apply and merge, the conditions below should holds.\n// apply(merge(x1,\
    \ x2), m) = merge(apply(x1, m), apply(x2, m))\n// apply(apply(x, m1), m2) = apply(x,\
    \ composition(m1, m2))\n// composition(m, em) = m && composition(em, m) = m &&\
    \ apply(x, em) = x\n\n\n//%snippet.set('make_lseg_rmq_ruq')%\n//%snippet.config({'alias':'rmq_ruq'})%\n\
    //%snippet.fold()%\nusing X = ll; // (X, merge) is monoid\nusing M = ll; // (M,\
    \ composition) is monoid\nauto make_lseg_rmq_ruq(){\n    auto merge = [](X x1,\
    \ X x2){return min(x1,x2);};\n    X ex = numeric_limits<X>::max();  // s.t merge(x,\
    \ ex) = x\n    M em = numeric_limits<M>::max();\n    // s.t composition(m, em)\
    \ = m && s.t composition(em, m) = m && apply(x, em) = x\n    auto composition\
    \ = [=](M m1, M m2){ \n        if (m1 == em) return m2;\n        if (m2 == em)\
    \ return m1;\n        return m2;\n    };\n    auto apply = [=](X x, M m){return\
    \ (m==em ? x : m);};\n    return segment_tree_lazy<X, M>(merge, apply, composition,\
    \ ex, em);\n}\n//%snippet.end()%\n\n\n//%snippet.set('make_lseg_rmq_raq')%\n//%snippet.config({'alias':'rmq_raq'})%\n\
    //%snippet.fold()%\nusing X = ll; // (X, merge) is monoid\nusing M = ll; // (M,\
    \ composition) is monoid\nauto make_lseg_rmq_raq(){\n    auto merge = [](X x1,\
    \ X x2){return min(x1,x2);};\n    X ex = numeric_limits<X>::max();\n    auto composition\
    \ = [](M m1, M m2){return m1 + m2;};\n    M em = 0;\n    auto apply = [](X x,\
    \ M m){return x + m;};\n    return segment_tree_lazy<X, M>(merge, apply, composition,\
    \ ex, em);\n}\n//%snippet.end()%\n\n\n//%snippet.set('monoid_with_len')%\n//%snippet.fold()%\n\
    template<class T>\nstruct monoid_with_len {\n    T x;\n    int len;\n    monoid_with_len(){};\n\
    \    monoid_with_len(T x_, ll len_) : x(x_), len(len_){};\n};\ntemplate<class\
    \ T>\nmonoid_with_len<T> operator+(monoid_with_len<T> a, monoid_with_len<T> b){\n\
    \    return monoid_with_len<T>(a.x + b.x, a.len + b.len);\n}\n//%snippet.end()%\n\
    \n\n//%snippet.set('monoid_affin_transformation')%\n//%snippet.fold()%\nstruct\
    \ monoid_affin_transformation {\n    mint a, b;\n    monoid_affin_transformation(){};\n\
    \    monoid_affin_transformation(mint a_, mint b_) : a(a_), b(b_){};\n};\nmonoid_affin_transformation\
    \ operator+(monoid_affin_transformation x, monoid_affin_transformation y){\n \
    \   return monoid_affin_transformation(x.a * y.a, x.b * y.a + y.b);\n}\nbool operator==(monoid_affin_transformation\
    \ m1, monoid_affin_transformation m2) {\n    return m1.a == m2.a && m1.b == m2.b;\n\
    }\n//%snippet.end()%\n\n\n//%snippet.set('make_lseg_rsq_raffinq')%\n//%snippet.config({'alias':'rsq_raffinq'})%\n\
    //%snippet.include('monoid_with_len')%\n//%snippet.include('monoid_affin_transformation')%\n\
    //%snippet.fold()%\nusing X = monoid_with_len<mint>; // (X, merge) is monoid\n\
    using M = monoid_affin_transformation; // (M, composition) is monoid\nauto make_lseg_rsq_raffinq(){\n\
    \    auto merge = [](X x1, X x2){return x1 + x2;};\n    X ex = X(0, 0);\n    M\
    \ em = M(1, 0);\n    auto composition = [](M m1, M m2){ return m1 + m2; };\n \
    \   auto apply = [](X x, M m){return X(x.x*m.a + m.b*x.len, x.len);};\n    return\
    \ segment_tree_lazy<X, M>(merge, apply, composition, ex, em);\n}\n//%snippet.end()%\n\
    \n\n//%snippet.set('make_lseg_rsq_raq')%\n//%snippet.config({'alias':'rsq_raq'})%\n\
    //%snippet.include('monoid_with_len')%\n//%snippet.fold()%\nusing X = monoid_with_len<ll>;\
    \ // (X, merge) is monoid\nusing M = ll; // (M, composition) is monoid\nauto make_lseg_rsq_raq(){\n\
    \    auto merge = [](X x1, X x2){return x1 + x2;};\n    X ex = X(0, 0);\n    M\
    \ em = 0;\n    auto composition = [](M m1, M m2){ return m1 + m2; };\n    auto\
    \ apply = [](X x, M m){return X(x.x + m*x.len, x.len);};\n    return segment_tree_lazy<X,\
    \ M>(merge, apply, composition, ex, em);\n}\n//%snippet.end()%\n\n\n\n// dual\
    \ segment tree\n\n//%snippet.set('make_lseg_getone_chmin')%\n//%snippet.config({'alias':'getone_chmin'})%\n\
    //%snippet.fold()%\nusing X = ll; // (X, merge) is monoid // \u53CC\u5BFE\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3068\u3057\u3066\u4F7F\u3046\u6642\u306F\u9069\
    \u5F53\u306A\u30E2\u30CE\u30A4\u30C9\u3092\u5165\u308C\u3066\u304A\u3051\u3070\
    \u826F\u3044\u3002\nusing M = ll; // (M, composition) is monoid\nauto make_lseg_getone_chmin(){\n\
    \    auto merge = [](X x1, X x2){return min(x1,x2);};\n    X ex = numeric_limits<X>::max();\n\
    \    M em = numeric_limits<M>::max();\n    auto composition = [](M m1, M m2){return\
    \ min(m1, m2);};\n    auto apply = [](X x, M m){return min(x, m);};\n    return\
    \ segment_tree_lazy<X, M>(merge, apply, composition, ex, em);\n}\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/array/segtree/segment_tree_lazy.hpp
  - library/cpp/header.hpp
  - library/cpp/math/mint.hpp
  isVerificationFile: false
  path: library/cpp/array/segtree/segment_tree_lazy.initialization.cpp
  requiredBy: []
  timestamp: '2020-09-23 17:16:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/segtree/segment_tree_lazy.initialization.cpp
layout: document
redirect_from:
- /library/library/cpp/array/segtree/segment_tree_lazy.initialization.cpp
- /library/library/cpp/array/segtree/segment_tree_lazy.initialization.cpp.html
title: library/cpp/array/segtree/segment_tree_lazy.initialization.cpp
---
