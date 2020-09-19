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
  bundledCode: "#line 1 \"library/cpp/array/segtree/segment_tree.test.cpp\"\n#define\
    \ PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    #line 3 \"library/cpp/array/segtree/segment_tree.hpp\"\n// http://tsutaj.hatenablog.com/entry/2017/03/29/204841\n\
    \n//%snippet.set('segment_tree')%\n//%snippet.config({'alias':'rmq'})%\n//%snippet.fold()%\n\
    \ntemplate <typename T> struct SegmentTree {  // {{{\n    private:\n        using\
    \ F = function<T(T, T)>;\n        int n;  // \u5143\u306E\u914D\u5217\u306E\u30B5\
    \u30A4\u30BA\n        int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n\
    \        vector<T> node;\n        F merge;\n        T identity;\n\n    public:\n\
    \        SegmentTree() {}\n        SegmentTree(vector<T> a, F f, T id) : merge(f),\
    \ identity(id) {\n            n = a.size();\n            N = 1;\n            while\
    \ (N < n) N *= 2;\n            node.resize(2 * N - 1, identity);\n           \
    \ for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n            for (int i\
    \ = N - 2; i >= 0; i--)\n                node[i] = merge(node[2 * i + 1], node[2\
    \ * i + 2]);\n        }\n        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n,\
    \ id), f, id) {}\n\n        T& operator[](int i) { return node[i + N - 1]; }\n\
    \n        void update(int i, T val) {\n            i += (N - 1);\n           \
    \ node[i] = val;\n            while (i > 0) {\n                i = (i - 1) / 2;\n\
    \                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);\n        \
    \    }\n        }\n\n        void add(int i, T val) {\n            i += (N - 1);\n\
    \            node[i] += val;\n            while (i > 0) {\n                i =\
    \ (i - 1) / 2;\n                node[i] = merge(node[2 * i + 1], node[2 * i +\
    \ 2]);\n            }\n        }\n\n        // query for [a, b)\n        T query(int\
    \ a, int b, int k = 0, int l = 0, int r = -1) {\n            if (r < 0) r = N;\n\
    \            if (r <= a || b <= l) return identity;\n            if (a <= l &&\
    \ r <= b) return node[k];\n\n            T vl = query(a, b, 2 * k + 1, l, (l +\
    \ r) / 2);\n            T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n     \
    \       return merge(vl, vr);\n        }\n\n        // find most right element\
    \ for [a, b)\n        int find_mr(int a, int b, function<bool(T)> is_ok, int k\
    \ = 0, int l = 0, int r = -1){\n            if (r < 0) r = N;\n            if\
    \ (r <= a || b <= l || !is_ok(node[k])) return a-1;\n            if (k >= N-1)\
    \ return k - (N-1);  // leaf\n\n            T vr = find_mr(a, b, is_ok, 2 * k\
    \ + 2, (l + r) / 2, r);\n            if (vr != a-1) return vr;\n\n           \
    \ T vl = find_mr(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);\n            return\
    \ vl;\n        }\n\n        // find most left element for [a, b)\n        int\
    \ find_ml(int a, int b, function<bool(T)> is_ok, int k = 0, int l = 0, int r =\
    \ -1){\n            // find most left\n            if (r < 0) r = N;\n       \
    \     if (r <= a || b <= l || !is_ok(node[k])) return b;\n            if (k >=\
    \ N-1) return k - (N-1);  // leaf\n\n            T vl = find_ml(a, b, is_ok, 2\
    \ * k + 1, l, (l + r) / 2);\n            if (vl != b) return vl;\n\n         \
    \   T vr = find_ml(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);\n            return\
    \ vr;\n        }\n\n        #if defined(PCM) || defined(LOCAL)\n        friend\
    \ ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //\n            os <<\
    \ \"[\";\n            for (int i = 0; i < sg.n; i++) {\n                os <<\
    \ sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n            }\n            return\
    \ os;\n        }\n        #endif\n};/*}}}*/\n// sample of initialize SegmentTree:\n\
    // -----------------------------------------------\n// auto mymin=[](auto a, auto\
    \ b){return min(a,b);};\n// SegmentTree<ll> seg(a, mymin, 1e18);\n\n// auto mymax=[](auto\
    \ a, auto b){return max(a,b);};\n// SegmentTree<ll> seg(a, mymax, -1e18);\n\n\
    // auto add=[](auto a, auto b){return a+b;};\n// SegmentTree<ll> seg(a, add, 0);\n\
    // -----------------------------------------------\n\n//%snippet.end()%\n#line\
    \ 4 \"library/cpp/array/segtree/segment_tree.test.cpp\"\n\nsigned main() {\n \
    \   vector<int> a = {1, 4, -2, 3, 6, 7};\n    auto f = [&](auto a, auto b) { return\
    \ max(a, b); };\n    SegmentTree<int> seg(a, f, -1e9);\n\n    assert(seg.query(0,\
    \ 8) == 7);\n    dump(seg.query(0, 8));\n    dump(seg.query(0, 10));\n    dump(seg.query(-3,\
    \ 10));\n    dump(seg[0]);\n    dump(seg[1]);\n    dump(seg[2]);\n    dump(seg);\n\
    \    seg.update(2, 10);\n    dump(seg.query(0, 8));\n\n    // double\u306A\u3069\
    \u4ED6\u306E\u578B\u3067\u3082\u52D5\u304F\u304B\u30C1\u30A7\u30C3\u30AF\n   \
    \ auto mymax = [&](auto a, auto b) { return max(a, b); };\n    vector<double>\
    \ p(6);\n    SegmentTree<double> segd(p, mymax, -1e18);\n    segd.update(0, 1.2);\n\
    \    segd.update(1, 1.4);\n    segd.update(2, 1.6);\n    double v = segd.query(0,\
    \ 6);\n    dump(v);\n\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"segment_tree.hpp\"\n\nsigned main() {\n    vector<int> a = {1, 4,\
    \ -2, 3, 6, 7};\n    auto f = [&](auto a, auto b) { return max(a, b); };\n   \
    \ SegmentTree<int> seg(a, f, -1e9);\n\n    assert(seg.query(0, 8) == 7);\n   \
    \ dump(seg.query(0, 8));\n    dump(seg.query(0, 10));\n    dump(seg.query(-3,\
    \ 10));\n    dump(seg[0]);\n    dump(seg[1]);\n    dump(seg[2]);\n    dump(seg);\n\
    \    seg.update(2, 10);\n    dump(seg.query(0, 8));\n\n    // double\u306A\u3069\
    \u4ED6\u306E\u578B\u3067\u3082\u52D5\u304F\u304B\u30C1\u30A7\u30C3\u30AF\n   \
    \ auto mymax = [&](auto a, auto b) { return max(a, b); };\n    vector<double>\
    \ p(6);\n    SegmentTree<double> segd(p, mymax, -1e18);\n    segd.update(0, 1.2);\n\
    \    segd.update(1, 1.4);\n    segd.update(2, 1.6);\n    double v = segd.query(0,\
    \ 6);\n    dump(v);\n\n    cout << \"Hello World\" << endl;\n}\n"
  dependsOn:
  - library/cpp/array/segtree/segment_tree.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/array/segtree/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/array/segtree/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/array/segtree/segment_tree.test.cpp
- /verify/library/cpp/array/segtree/segment_tree.test.cpp.html
title: library/cpp/array/segtree/segment_tree.test.cpp
---
