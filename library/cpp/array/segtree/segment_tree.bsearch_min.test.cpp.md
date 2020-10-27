---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/array/segtree/segment_tree.hpp
    title: library/cpp/array/segtree/segment_tree.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
    #ifndef HEADER_H\n#define HEADER_H\n\n// template version 2.0\nusing namespace\
    \ std;\n#include <bits/stdc++.h>\n\n// varibable settings\ntemplate <class T>\
    \ constexpr T inf = numeric_limits<T>::max() / 2.1;\n\n#define _overload3(_1,\
    \ _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a,\
    \ b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/array/segtree/segment_tree.hpp\"\
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
    \n//%snippet.end()%\n#line 3 \"library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp\"\
    \n\nSegmentTree<ll> seg;\nvector<ll> a;\nint n;\n\nint64_t rng() {\n    static\
    \ mt19937 x(chrono::steady_clock::now().time_since_epoch().count());\n    return\
    \ uniform_int_distribution<int64_t>(-100, 100)(x);\n}\n\npair<int, int> naive(int\
    \ i){\n    int right = n;\n    rep(j, i+1, sz(a)){\n        if (a[j] < a[i]) {\n\
    \            right = j;\n            break;\n        }\n    }\n    int left =\
    \ -1;\n    r_rep(j, 0, i){\n        if (a[j] < a[i]) {\n            left = j;\n\
    \            break;\n        }\n    }\n    return {left, right};\n}\n\npair<int,\
    \ int> get_nearest_index_of_smaller_element(int i){\n    auto left = seg.find_most_right(i,\
    \ [&](auto x){return x < a[i];});\n    auto right = seg.find_most_left(i, [&](auto\
    \ x){return x < a[i];});\n    return {left, right};\n}\n\nint test(int _n, bool\
    \ compare = true){\n    n = _n;\n    a.clear();\n    rep(i, n){ a.pb(rng()%10);\
    \ }\n    dump(a);\n\n    seg = SegmentTree<ll>(a, [](auto a, auto b){return min(a,b);},\
    \ 1e18);\n    rep(i, sz(a)){\n        auto res = get_nearest_index_of_smaller_element(i);\n\
    \        if (compare){\n            // dump(naive(i), res);\n            assert(naive(i)\
    \ == res);\n        }\n    }\n    return 0;\n}\n\nint main(){\n    int nums =\
    \ 10;\n    while(nums--){\n        test(abs(rng())); \n        test(1000000, false);\
    \ \n    }\n    cout << \"Hello World\" << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"segment_tree.hpp\"\n\nSegmentTree<ll> seg;\nvector<ll> a;\nint n;\n\
    \nint64_t rng() {\n    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<int64_t>(-100, 100)(x);\n}\n\npair<int, int>\
    \ naive(int i){\n    int right = n;\n    rep(j, i+1, sz(a)){\n        if (a[j]\
    \ < a[i]) {\n            right = j;\n            break;\n        }\n    }\n  \
    \  int left = -1;\n    r_rep(j, 0, i){\n        if (a[j] < a[i]) {\n         \
    \   left = j;\n            break;\n        }\n    }\n    return {left, right};\n\
    }\n\npair<int, int> get_nearest_index_of_smaller_element(int i){\n    auto left\
    \ = seg.find_most_right(i, [&](auto x){return x < a[i];});\n    auto right = seg.find_most_left(i,\
    \ [&](auto x){return x < a[i];});\n    return {left, right};\n}\n\nint test(int\
    \ _n, bool compare = true){\n    n = _n;\n    a.clear();\n    rep(i, n){ a.pb(rng()%10);\
    \ }\n    dump(a);\n\n    seg = SegmentTree<ll>(a, [](auto a, auto b){return min(a,b);},\
    \ 1e18);\n    rep(i, sz(a)){\n        auto res = get_nearest_index_of_smaller_element(i);\n\
    \        if (compare){\n            // dump(naive(i), res);\n            assert(naive(i)\
    \ == res);\n        }\n    }\n    return 0;\n}\n\nint main(){\n    int nums =\
    \ 10;\n    while(nums--){\n        test(abs(rng())); \n        test(1000000, false);\
    \ \n    }\n    cout << \"Hello World\" << endl;\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/array/segtree/segment_tree.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:49:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp
- /verify/library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp.html
title: library/cpp/array/segtree/segment_tree.bsearch_min.test.cpp
---
