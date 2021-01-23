---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/array/segtree/segment_tree.hpp
    title: library/cpp/array/segtree/segment_tree.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/misc/zipper.lib/zipper.hpp
    title: library/cpp/misc/zipper.lib/zipper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"library/cpp/array/reversed_cnt.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\n#line 2\
    \ \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
    #ifndef HEADER_H\n#define HEADER_H\n\n// template version 2.0\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// varibable settings\ntemplate <class T> constexpr T\
    \ inf = numeric_limits<T>::max() / 2.1;\n\n#define _overload3(_1, _2, _3, name,\
    \ ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for (ll i\
    \ = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi,\
    \ _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i, 0, n)\n#define rrepi(i, a,\
    \ b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n#define r_rep(...) _overload3(__VA_ARGS__,\
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/misc/zipper.lib/zipper.hpp\"\
    \n\n//%snippet.set('zipper')%\n\nstruct zipper {                             /*{{{*/\n\
    \    // unordered_map<long long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3] debug\u3057\
    \u3065\u3089\u3044\n    map<long long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3]\n\
    \    vector<long long> _unzipper;            // [2, 3, 5, 10]\n    bool _is_build\
    \ = false;\n    int n = 0;\n\n    zipper(){};\n    zipper(long long inf_value)\
    \ { /*{{{*/\n        _unzipper.push_back(-inf_value);\n        _unzipper.push_back(inf_value);\n\
    \    }                                                        /*}}}*/\n\n    template\
    \ <class T>\n    zipper(const vector<T>& a, long long inf_value = inf<ll>) { /*{{{*/\n\
    \        _unzipper = vector<long long>(sz(a));\n        rep(i, sz(a)) { _unzipper[i]\
    \ = a[i]; }\n        _unzipper.push_back(-inf_value);\n        _unzipper.push_back(inf_value);\n\
    \        build();\n    }                              /*}}}*/\n    void add_value(long\
    \ long lv) { /*{{{*/\n        _unzipper.push_back(lv);\n        _is_build = false;\n\
    \    }              /*}}}*/\n    void build() { /*{{{*/\n        uni(_unzipper);\n\
    \        zip_map.clear();\n        n = sz(_unzipper);\n        rep(i, n) { zip_map[_unzipper[i]]\
    \ = i; }\n        _is_build = true;\n    }                              /*}}}*/\n\
    \    vector<int> zip(vector<long long> lvs) { /*{{{*/\n        if (!_is_build)\
    \ assert(false);\n        int n = sz(lvs);\n        vector<int> res(n);\n    \
    \    rep(i, n) res[i] = zip_map[lvs[i]];\n        return res;\n    }         \
    \                     /*}}}*/\n    int zip(long long lv) { /*{{{*/\n        if\
    \ (!_is_build) assert(false);\n        return zip_map[lv];\n    }            \
    \                                   /*}}}*/\n    int operator()(long long lv)\
    \ { return zip(lv); }\n\n    long long unzip(int sv) { /*{{{*/\n        if (!_is_build)\
    \ assert(false);\n        return _unzipper[sv];\n    }                       \
    \       /*}}}*/\n    int operator[](int sv) { return unzip(sv); }\n\n    int size()\
    \ {return n;}\n\n#if defined(PCM) || defined(LOCAL) /*{{{*/\n    friend ostream&\
    \ operator<<(ostream& os, const zipper& zp) {\n        os << endl;\n        os\
    \ << \"_is_build: \" << zp._is_build << endl;\n        os << \"zip_map:   \" <<\
    \ zp.zip_map << endl;\n        os << \"_unzipper:   \" << zp._unzipper << endl;\n\
    \        return os;\n    }\n#endif /*}}}*/\n};     /*}}}*/\n// How to use {{{\n\
    // construct\n// auto z = zipper(x); // x: vector<long long>;\n// auto z = zipper(x,\
    \ inf<ll>);\n\n// auto z = zipper();\n// z.add_value(3);\n// z.add_value(5);\n\
    // z.add_value(10);\n// z.add_value(100000000);\n// z.build();\n\n// other method\n\
    // z(x[i]); -> zipped x[i]\n// z.unzip(z(x[i])) -> x[i];\n// z.zip(ll x) -> zipped\
    \ x\n// z.zip(vl v) -> zipped v\n// }}}\n\n//%snippet.end()%\n#line 3 \"library/cpp/array/segtree/segment_tree.hpp\"\
    \n// http://tsutaj.hatenablog.com/entry/2017/03/29/204841\n\n//%snippet.set('segment_tree')%\n\
    //%snippet.config({'alias':'rmq'})%\n//%snippet.fold()%\n\ntemplate <typename\
    \ X> struct SegmentTree {  // {{{\n    private:\n        using F = function<X(X,\
    \ X)>;\n        using index = int;\n        int n;  // \u5143\u306E\u914D\u5217\
    \u306E\u30B5\u30A4\u30BA\n        int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    2\u51AA\n        vector<X> node;\n        F merge;\n        X identity;\n\n  \
    \  public:\n        SegmentTree() {}\n        SegmentTree(vector<X> a, F f, X\
    \ id) : merge(f), identity(id) {\n            n = (int)a.size();\n           \
    \ N = 1;\n            while (N < n) N *= 2;\n            node.resize(2 * N - 1,\
    \ identity);\n            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n\
    \            for (int i = N - 2; i >= 0; i--)\n                node[i] = merge(node[2\
    \ * i + 1], node[2 * i + 2]);\n        }\n        SegmentTree(int sz, F f, X id)\
    \ : SegmentTree(vector<X>(sz, id), f, id) {}\n\n        X& operator[](index i)\
    \ { return node[i + N - 1]; }\n\n        void set(index i, X val) {\n        \
    \    i += (N - 1);\n            node[i] = val;\n            while (i > 0) {\n\
    \                i = (i - 1) / 2;\n                node[i] = merge(node[2 * i\
    \ + 1], node[2 * i + 2]);\n            }\n        }\n\n        void add(index\
    \ i, X val) {\n            i += (N - 1);\n            node[i] += val;\n      \
    \      while (i > 0) {\n                i = (i - 1) / 2;\n                node[i]\
    \ = merge(node[2 * i + 1], node[2 * i + 2]);\n            }\n        }\n\n   \
    \     // query for [a, b)\n        X query(index a, index b, int k = 0, index\
    \ l = 0, index r = -1) {\n            if (r < 0) r = N;\n            if (r <=\
    \ a || b <= l) return identity;\n            if (a <= l && r <= b) return node[k];\n\
    \n            X lv = query(a, b, 2 * k + 1, l, (l + r) / 2);\n            X rv\
    \ = query(a, b, 2 * k + 2, (l + r) / 2, r);\n            return merge(lv, rv);\n\
    \        }\n\n        index find_most_left(index l, const function<bool(X)>& is_ok){\n\
    \            // l\u304B\u3089\u53F3\u306B\u63A2\u3057\u3066\u3044\u3063\u3066\
    is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\
    \u8FD4\u3059\u3002\n            // assume query(l, *) has monotonity\n       \
    \     // return index i s.t is_ok(query(l, i)) does not holds, but is_ok(query(l,\
    \ i+1)) does.\n            // if such i does not exist, return n\n           \
    \ index res = _find_most_left(l, is_ok, 0, 0, N, identity).first;\n          \
    \  assert(l <= res);\n            return res;\n        }\n        pair<index,\
    \ X> _find_most_left(index a, const function<bool(X)>& is_ok, int k, index l,\
    \ index r, X left_value){\n            // params:\n                // left_value\
    \ = (a < l ? query(a, l) : ex)\n            // return (index i, X v)\n       \
    \         // i is the index in [a, n)^[l, r) s.t query(a, i+1) is ok but query(a,\
    \ i) isn't ok. if such i does not exist, i = n\n                // v is the value\
    \ s.t query(a, r)\n\n            if (r <= a) return {n, identity};  // \u533A\u9593\
    \u304C\u5168\u304F\u88AB\u3063\u3066\u3044\u306A\u3044\n            else if (a\
    \ <= l && !is_ok(merge(left_value, node[k]))) return {n, merge(left_value, node[k])};\n\
    \            else if (k >= N-1) return {k - (N-1), merge(left_value, node[k])};\n\
    \            else{\n                auto [lv, xl] = _find_most_left(a, is_ok,\
    \ 2 * k + 1, l, (l + r) / 2, left_value);\n                if (lv != n) return\
    \ {lv, xl};\n                auto [rv, xr] = _find_most_left(a, is_ok, 2 * k +\
    \ 2, (l + r) / 2, r, xl);\n                return {rv, xr};\n            }\n \
    \       }\n\n        index find_most_right(index r, const function<bool(X)>& is_ok){\n\
    \            // r\u304B\u3089\u5DE6\u306B\u63A2\u3057\u3066\u3044\u3063\u3066\
    is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\
    \u8FD4\u3059\u3002\n            // assume query(*, r) has monotonity\n       \
    \     // return index i s.t is_ok(query(i+1, r+1)) does not holds, but is_ok(query(i,\
    \ r+1)) does.\n            // if such i does not exist, return -1\n          \
    \  index res = _find_most_right(r+1, is_ok, 0, 0, N, identity).first;\n      \
    \      assert(res <= r);\n            return res;\n        }\n        pair<index,\
    \ X> _find_most_right(index b, const function<bool(X)>& is_ok, int k, index l,\
    \ index r, X right_value){\n            if (b <= l) return {-1, identity};  //\
    \ \u533A\u9593\u304C\u5168\u304F\u88AB\u3063\u3066\u3044\u306A\u3044\n       \
    \     else if (r <= b && !is_ok(merge(node[k], right_value))) return {-1, merge(node[k],\
    \ right_value)};\n            else if (k >= N-1) return {k - (N-1), merge(node[k],\
    \ right_value)};\n            else{\n                auto [rv, xr] = _find_most_right(b,\
    \ is_ok, 2 * k + 2, (l + r) / 2, r, right_value);\n                if (rv != -1)\
    \ return {rv, xr};\n                auto [lv, xl] = _find_most_right(b, is_ok,\
    \ 2 * k + 1, l, (l + r) / 2, xr);\n                return {lv, xl};\n        \
    \    }\n        }\n\n        #if defined(PCM) || defined(LOCAL)\n        friend\
    \ ostream& operator<<(ostream& os, SegmentTree<X>& sg) {  //\n            os <<\
    \ \"[\";\n            for (int i = 0; i < sg.n; i++) {\n                os <<\
    \ sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n            }\n            return\
    \ os;\n        }\n        #endif\n};/*}}}*/\n// sample of initialize SegmentTree:\n\
    // -----------------------------------------------\n// auto mymin=[](auto a, auto\
    \ b){return min(a,b);};\n// ll e = 1e18;\n// SegmentTree<ll> seg(a, mymin, e);\n\
    \n// auto mymax=[](auto a, auto b){return max(a,b);};\n// ll e = -1e18;\n// SegmentTree<ll>\
    \ seg(a, mymax, e);\n\n// auto add=[](auto a, auto b){return a+b;};\n// ll e =\
    \ 0;\n// SegmentTree<ll> seg(a, add, e);\n\n// pair<int, int> get_nearest_index_of_smaller_element(int\
    \ i){\n//     auto left = seg.find_most_right(i, [&](auto x){return x < a[i];});\n\
    //     auto right = seg.find_most_left(i, [&](auto x){return x < a[i];});\n//\
    \     return {left, right};\n// }\n// -----------------------------------------------\n\
    \n//%snippet.end()%\n#line 4 \"library/cpp/array/reversed_cnt.cpp\"\n\n//%snippet.set('reversed_cnt')%\n\
    //%snippet.config({'alias':'tentousu'})%\n//%snippet.config({'alias':'cnt_reversed'})%\n\
    //%snippet.include('zipper')%\n//%snippet.include('segment_tree')%\n//%snippet.fold()%\n\
    template<class T>\nll reversed_cnt(const vector<T>& v){\n    int n = sz(v);\n\
    \    if (n == 0) return 0;\n    ll max_v = *max_element(all(v));\n    ll min_v\
    \ = *min_element(all(v));\n\n    zipper z;\n    bool zipped = false;\n    if (max_v\
    \ > n-1 || min_v < 0) {\n        z = zipper(v);\n        max_v = z.n - 1;\n  \
    \      zipped = true;\n    }\n\n    auto add=[](auto a, auto b){return a+b;};\n\
    \    ll e = 0;\n    SegmentTree<ll> seg(max_v + 1, add, e);\n\n    ll res = 0;\n\
    \    rep(i, n){\n        ll w = (zipped ? z(v[i]) : v[i]);\n        res += seg.query(w+1,\
    \ max_v+1);\n        seg.add(w, 1);\n    }\n    return res;\n}\n\ntemplate<class\
    \ T>\nll reversed_dist(const vector<T>& a, const vector<T>& b){\n    // assume\
    \ a and b are permutaion of same size\n    int n = sz(a);\n    vector<int> d(n+1);\n\
    \    rep(i, n){ d[a[i]] = i; }\n    vector<T> c(n);\n    rep(i, n){ c[i] = d[b[i]];\
    \ }\n    return reversed_cnt(c);\n}\n//%snippet.end()%\n\nint main(){\n    int\
    \ n;cin>>n;\n    vector<int> a(n);\n    rep(i, n) cin>>a[i];\n    cout << reversed_cnt(a)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include \"../misc/zipper.lib/zipper.hpp\"\n#include \"segtree/segment_tree.hpp\"\
    \n\n//%snippet.set('reversed_cnt')%\n//%snippet.config({'alias':'tentousu'})%\n\
    //%snippet.config({'alias':'cnt_reversed'})%\n//%snippet.include('zipper')%\n\
    //%snippet.include('segment_tree')%\n//%snippet.fold()%\ntemplate<class T>\nll\
    \ reversed_cnt(const vector<T>& v){\n    int n = sz(v);\n    if (n == 0) return\
    \ 0;\n    ll max_v = *max_element(all(v));\n    ll min_v = *min_element(all(v));\n\
    \n    zipper z;\n    bool zipped = false;\n    if (max_v > n-1 || min_v < 0) {\n\
    \        z = zipper(v);\n        max_v = z.n - 1;\n        zipped = true;\n  \
    \  }\n\n    auto add=[](auto a, auto b){return a+b;};\n    ll e = 0;\n    SegmentTree<ll>\
    \ seg(max_v + 1, add, e);\n\n    ll res = 0;\n    rep(i, n){\n        ll w = (zipped\
    \ ? z(v[i]) : v[i]);\n        res += seg.query(w+1, max_v+1);\n        seg.add(w,\
    \ 1);\n    }\n    return res;\n}\n\ntemplate<class T>\nll reversed_dist(const\
    \ vector<T>& a, const vector<T>& b){\n    // assume a and b are permutaion of\
    \ same size\n    int n = sz(a);\n    vector<int> d(n+1);\n    rep(i, n){ d[a[i]]\
    \ = i; }\n    vector<T> c(n);\n    rep(i, n){ c[i] = d[b[i]]; }\n    return reversed_cnt(c);\n\
    }\n//%snippet.end()%\n\nint main(){\n    int n;cin>>n;\n    vector<int> a(n);\n\
    \    rep(i, n) cin>>a[i];\n    cout << reversed_cnt(a) << endl;\n}\n"
  dependsOn:
  - library/cpp/misc/zipper.lib/zipper.hpp
  - library/cpp/header.hpp
  - library/cpp/array/segtree/segment_tree.hpp
  isVerificationFile: false
  path: library/cpp/array/reversed_cnt.cpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/reversed_cnt.cpp
layout: document
redirect_from:
- /library/library/cpp/array/reversed_cnt.cpp
- /library/library/cpp/array/reversed_cnt.cpp.html
title: library/cpp/array/reversed_cnt.cpp
---
