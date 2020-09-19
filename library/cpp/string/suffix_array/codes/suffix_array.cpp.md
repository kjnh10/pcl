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
    #line 2 \"library/cpp/string/suffix_array/codes/suffix_array.cpp\"\n\n//%snippet.set('suffix_array')%\n\
    \ntemplate <typename T>\nstruct SegmentTree {  // {{{\n   private:\n    using\
    \ F = function<T(T, T)>;\n    int n;  // \u5143\u306E\u914D\u5217\u306E\u30B5\u30A4\
    \u30BA\n    int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n    vector<T>\
    \ node;\n    F merge;\n    T identity;\n\n   public:\n    SegmentTree() {}\n \
    \   SegmentTree(vector<T> a, F f, T id) : merge(f), identity(id) {\n        n\
    \ = a.size();\n        N = 1;\n        while (N < n) N *= 2;\n        node.resize(2\
    \ * N - 1, identity);\n        for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n\
    \        for (int i = N - 2; i >= 0; i--)\n            node[i] = merge(node[2\
    \ * i + 1], node[2 * i + 2]);\n    }\n    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n,\
    \ id), f, id) {}\n\n    T& operator[](int i) { return node[i + N - 1]; }\n\n \
    \   void update(int x, T val) {\n        x += (N - 1);\n        node[x] = val;\n\
    \        while (x > 0) {\n            x = (x - 1) / 2;\n            node[x] =\
    \ merge(node[2 * x + 1], node[2 * x + 2]);\n        }\n    }\n\n    void add(int\
    \ x, T val) {\n        x += (N - 1);\n        node[x] += val;\n        while (x\
    \ > 0) {\n            x = (x - 1) / 2;\n            node[x] = merge(node[2 * x\
    \ + 1], node[2 * x + 2]);\n        }\n    }\n\n    // query for [l, r)\n    T\
    \ query(int a, int b, int k = 0, int l = 0, int r = -1) {\n        if (r < 0)\
    \ r = N;\n        if (r <= a || b <= l) return identity;\n        if (a <= l &&\
    \ r <= b) return node[k];\n\n        T vl = query(a, b, 2 * k + 1, l, (l + r)\
    \ / 2);\n        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n        return\
    \ merge(vl, vr);\n    }\n\n    friend ostream& operator<<(ostream& os, SegmentTree<T>&\
    \ sg) {  //\n        os << \"[\";\n        for (int i = 0; i < sg.n; i++) {\n\
    \            os << sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n        }\n\
    \        return os;\n    }\n};\n// }}}\ntemplate <class MeetSemiLattice>\nstruct\
    \ SparseTable { /*{{{*/\n    vector<vector<MeetSemiLattice> > dat;\n    vector<int>\
    \ height;\n\n    SparseTable() {}\n    SparseTable(const vector<MeetSemiLattice>&\
    \ vec) { init(vec); }\n    void init(const vector<MeetSemiLattice>& vec) {\n \
    \       int n = (int)vec.size(), h = 0;\n        while ((1 << h) < n) ++h;\n \
    \       dat.assign(h, vector<MeetSemiLattice>(1 << h));\n        height.assign(n\
    \ + 1, 0);\n        for (int i = 2; i <= n; i++) height[i] = height[i >> 1] +\
    \ 1;\n        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];\n        for (int\
    \ i = 1; i < h; ++i)\n            for (int j = 0; j < n; ++j)\n              \
    \  dat[i][j] = min(dat[i - 1][j],\n                                dat[i - 1][min(j\
    \ + (1 << (i - 1)), n - 1)]);\n    }\n\n    MeetSemiLattice get(int a, int b)\
    \ {\n        if (a == b) return INF;\n        return min(dat[height[b - a]][a],\n\
    \                   dat[height[b - a]][b - (1 << height[b - a])]);\n    }\n};\
    \                    /*}}}*/\nstruct suffix_array { /*{{{*/\n    vector<int> a;\n\
    \    vector<int> pos;   // pos[j]: j\u4F4D\u306Esumffix\u306F\u3069\u3053\u304B\
    \u3089\u59CB\u307E\u308B\u304B\n    vector<int> rank;  // rank[i]: s[i:]\u306F\
    \u4F55\u4F4D\u304B\n    // pos = rank^-1\n    vector<int> lcp_array;         \
    \  // lcp_arry[j]: s[j:]\u3068s[j+1:]\u306Elcp\n    SegmentTree<int> seg_lcp_array;\
    \  // lcp_arry[j]: s[j:]\u3068s[j+1:]\u306Elcp\n    SparseTable<int> sparse_lcp_array;\n\
    \    int n;\n\n    // constructor{{{\n    suffix_array() {}\n    suffix_array(vector<int>&\
    \ a) : a(a), n(a.size()) { _build(); }\n    suffix_array(string& s) {\n      \
    \  n = s.size();\n        a.resize(n);\n        rep(i, n) a[i] = s[i];\n     \
    \   _build();\n    } /*}}}*/\n\n    void _build() { /*{{{*/\n        _build_order();\n\
    \        _build_lcp_array();\n    } /*}}}*/\n\n    void _build_order() { /*{{{*/\n\
    \        pos.resize(n);\n        iota(all(pos), 0);\n        rank = a;  // a\u3067\
    \u305D\u306E\u307E\u307E\u30B9\u30B3\u30A2\u5316\n\n        for (int k = 1; k\
    \ < n; k *= 2) {\n            // k\u3067\u306Erank\u304C\u751F\u6210\u3055\u308C\
    \u3066\u3044\u308B\u524D\u63D0\u30672*k\u3067\u306Erank\u3092\u751F\u6210\u3059\
    \u308B\n\n            auto _comp = [&](int l, int r) {\n                auto left\
    \ = mp(rank[l], (l + k < n ? rank[l + k] : -1));\n                auto right =\
    \ mp(rank[r], (r + k < n ? rank[r + k] : -1));\n                return left <\
    \ right;\n            };\n            sort(all(pos), _comp);\n\n            vector<int>\
    \ next_rank(n);\n            next_rank[pos[0]] = 0;\n            int r = 0;\n\
    \            rep(i, 1, n) {\n                if (_comp(pos[i - 1], pos[i])) r++;\n\
    \                next_rank[pos[i]] = r;\n            }\n            rank = next_rank;\n\
    \        }\n    } /*}}}*/\n\n    void _build_lcp_array() { /*{{{*/\n        lcp_array.resize(n);\n\
    \        int con = 1;\n        rep(l, 0, n) {\n            if (rank[l] + 1 ==\
    \ n) {\n                lcp_array[rank[l]] = -1;\n                con = 1;\n \
    \               continue;\n            }\n\n            if (con > 0) con--;\n\
    \            int r = pos[rank[l] + 1];\n            while (l + con < n && r +\
    \ con < n && a[l + con] == a[r + con]) {\n                con++;\n           \
    \ }\n            lcp_array[rank[l]] = con;\n        }\n\n        auto mymin =\
    \ [](auto a, auto b) { return min(a, b); };\n        seg_lcp_array = SegmentTree<int>(lcp_array,\
    \ mymin, 1e18);\n        sparse_lcp_array = SparseTable<int>(lcp_array);\n   \
    \ } /*}}}*/\n\n    int lcp(int i,\n            int j) {  // longest cummon prefix\
    \ length between s[i:] and s[j:]{{{\n        // if (rank[i]<rank[j]) return seg_lcp_array.query(rank[i],\
    \ rank[j]);\n        // else                 return seg_lcp_array.query(rank[j],\
    \ rank[i]);\n        if (rank[i] < rank[j])\n            return sparse_lcp_array.get(rank[i],\
    \ rank[j]);\n        else\n            return sparse_lcp_array.get(rank[j], rank[i]);\n\
    \    } /*}}}*/\n};    /*}}}*/\n\n// sample: abc141E\n// int n;cin>>n;\n// string\
    \ s;cin>>s;\n// suffix_array sa(s);\n//\n// int ans = 0;\n// rep(i, n)rep(j, n){\n\
    //   chmax(ans, min(j-i, sa.lcp(i, j)));\n// }\n// cout << ans << endl;\n\n//%snippet.end()%\n\
    \nvoid test_sa() {\n    string s;\n    cin >> s;\n    suffix_array sa(s);\n\n\
    \    rep(i, sz(sa.pos)) cout << sa.pos[i] << (i != sz(sa.pos) - 1 ? \" \" : \"\
    \\n\");\n}\n\nvoid test_lcp() {\n    // abc141E\n    int n;\n    cin >> n;\n \
    \   string s;\n    cin >> s;\n    suffix_array sa(s);\n\n    int ans = 0;\n  \
    \  rep(i, n) rep(j, n) { chmax(ans, min(j - i, sa.lcp(i, j))); }\n    cout <<\
    \ ans << endl;\n}\n\nsigned main() {\n    // string s = \"adcdacbdcab\";\n   \
    \ // // string s = \"aaaaa\";\n    // dump(s);\n    // suffix_array sa(s);\n \
    \   // sa.build();\n    // dump(sa.pos);\n    // dump(sa.rank);\n    // dump(sa.lcp_array);\n\
    \    // dump(sa.lcp(1, 7));\n    test_lcp();\n\n    return 0;\n}\n"
  code: "#include \"../../../header.hpp\"\n\n//%snippet.set('suffix_array')%\n\ntemplate\
    \ <typename T>\nstruct SegmentTree {  // {{{\n   private:\n    using F = function<T(T,\
    \ T)>;\n    int n;  // \u5143\u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    int\
    \ N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n    vector<T> node;\n \
    \   F merge;\n    T identity;\n\n   public:\n    SegmentTree() {}\n    SegmentTree(vector<T>\
    \ a, F f, T id) : merge(f), identity(id) {\n        n = a.size();\n        N =\
    \ 1;\n        while (N < n) N *= 2;\n        node.resize(2 * N - 1, identity);\n\
    \        for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n        for (int\
    \ i = N - 2; i >= 0; i--)\n            node[i] = merge(node[2 * i + 1], node[2\
    \ * i + 2]);\n    }\n    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n,\
    \ id), f, id) {}\n\n    T& operator[](int i) { return node[i + N - 1]; }\n\n \
    \   void update(int x, T val) {\n        x += (N - 1);\n        node[x] = val;\n\
    \        while (x > 0) {\n            x = (x - 1) / 2;\n            node[x] =\
    \ merge(node[2 * x + 1], node[2 * x + 2]);\n        }\n    }\n\n    void add(int\
    \ x, T val) {\n        x += (N - 1);\n        node[x] += val;\n        while (x\
    \ > 0) {\n            x = (x - 1) / 2;\n            node[x] = merge(node[2 * x\
    \ + 1], node[2 * x + 2]);\n        }\n    }\n\n    // query for [l, r)\n    T\
    \ query(int a, int b, int k = 0, int l = 0, int r = -1) {\n        if (r < 0)\
    \ r = N;\n        if (r <= a || b <= l) return identity;\n        if (a <= l &&\
    \ r <= b) return node[k];\n\n        T vl = query(a, b, 2 * k + 1, l, (l + r)\
    \ / 2);\n        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n        return\
    \ merge(vl, vr);\n    }\n\n    friend ostream& operator<<(ostream& os, SegmentTree<T>&\
    \ sg) {  //\n        os << \"[\";\n        for (int i = 0; i < sg.n; i++) {\n\
    \            os << sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n        }\n\
    \        return os;\n    }\n};\n// }}}\ntemplate <class MeetSemiLattice>\nstruct\
    \ SparseTable { /*{{{*/\n    vector<vector<MeetSemiLattice> > dat;\n    vector<int>\
    \ height;\n\n    SparseTable() {}\n    SparseTable(const vector<MeetSemiLattice>&\
    \ vec) { init(vec); }\n    void init(const vector<MeetSemiLattice>& vec) {\n \
    \       int n = (int)vec.size(), h = 0;\n        while ((1 << h) < n) ++h;\n \
    \       dat.assign(h, vector<MeetSemiLattice>(1 << h));\n        height.assign(n\
    \ + 1, 0);\n        for (int i = 2; i <= n; i++) height[i] = height[i >> 1] +\
    \ 1;\n        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];\n        for (int\
    \ i = 1; i < h; ++i)\n            for (int j = 0; j < n; ++j)\n              \
    \  dat[i][j] = min(dat[i - 1][j],\n                                dat[i - 1][min(j\
    \ + (1 << (i - 1)), n - 1)]);\n    }\n\n    MeetSemiLattice get(int a, int b)\
    \ {\n        if (a == b) return INF;\n        return min(dat[height[b - a]][a],\n\
    \                   dat[height[b - a]][b - (1 << height[b - a])]);\n    }\n};\
    \                    /*}}}*/\nstruct suffix_array { /*{{{*/\n    vector<int> a;\n\
    \    vector<int> pos;   // pos[j]: j\u4F4D\u306Esumffix\u306F\u3069\u3053\u304B\
    \u3089\u59CB\u307E\u308B\u304B\n    vector<int> rank;  // rank[i]: s[i:]\u306F\
    \u4F55\u4F4D\u304B\n    // pos = rank^-1\n    vector<int> lcp_array;         \
    \  // lcp_arry[j]: s[j:]\u3068s[j+1:]\u306Elcp\n    SegmentTree<int> seg_lcp_array;\
    \  // lcp_arry[j]: s[j:]\u3068s[j+1:]\u306Elcp\n    SparseTable<int> sparse_lcp_array;\n\
    \    int n;\n\n    // constructor{{{\n    suffix_array() {}\n    suffix_array(vector<int>&\
    \ a) : a(a), n(a.size()) { _build(); }\n    suffix_array(string& s) {\n      \
    \  n = s.size();\n        a.resize(n);\n        rep(i, n) a[i] = s[i];\n     \
    \   _build();\n    } /*}}}*/\n\n    void _build() { /*{{{*/\n        _build_order();\n\
    \        _build_lcp_array();\n    } /*}}}*/\n\n    void _build_order() { /*{{{*/\n\
    \        pos.resize(n);\n        iota(all(pos), 0);\n        rank = a;  // a\u3067\
    \u305D\u306E\u307E\u307E\u30B9\u30B3\u30A2\u5316\n\n        for (int k = 1; k\
    \ < n; k *= 2) {\n            // k\u3067\u306Erank\u304C\u751F\u6210\u3055\u308C\
    \u3066\u3044\u308B\u524D\u63D0\u30672*k\u3067\u306Erank\u3092\u751F\u6210\u3059\
    \u308B\n\n            auto _comp = [&](int l, int r) {\n                auto left\
    \ = mp(rank[l], (l + k < n ? rank[l + k] : -1));\n                auto right =\
    \ mp(rank[r], (r + k < n ? rank[r + k] : -1));\n                return left <\
    \ right;\n            };\n            sort(all(pos), _comp);\n\n            vector<int>\
    \ next_rank(n);\n            next_rank[pos[0]] = 0;\n            int r = 0;\n\
    \            rep(i, 1, n) {\n                if (_comp(pos[i - 1], pos[i])) r++;\n\
    \                next_rank[pos[i]] = r;\n            }\n            rank = next_rank;\n\
    \        }\n    } /*}}}*/\n\n    void _build_lcp_array() { /*{{{*/\n        lcp_array.resize(n);\n\
    \        int con = 1;\n        rep(l, 0, n) {\n            if (rank[l] + 1 ==\
    \ n) {\n                lcp_array[rank[l]] = -1;\n                con = 1;\n \
    \               continue;\n            }\n\n            if (con > 0) con--;\n\
    \            int r = pos[rank[l] + 1];\n            while (l + con < n && r +\
    \ con < n && a[l + con] == a[r + con]) {\n                con++;\n           \
    \ }\n            lcp_array[rank[l]] = con;\n        }\n\n        auto mymin =\
    \ [](auto a, auto b) { return min(a, b); };\n        seg_lcp_array = SegmentTree<int>(lcp_array,\
    \ mymin, 1e18);\n        sparse_lcp_array = SparseTable<int>(lcp_array);\n   \
    \ } /*}}}*/\n\n    int lcp(int i,\n            int j) {  // longest cummon prefix\
    \ length between s[i:] and s[j:]{{{\n        // if (rank[i]<rank[j]) return seg_lcp_array.query(rank[i],\
    \ rank[j]);\n        // else                 return seg_lcp_array.query(rank[j],\
    \ rank[i]);\n        if (rank[i] < rank[j])\n            return sparse_lcp_array.get(rank[i],\
    \ rank[j]);\n        else\n            return sparse_lcp_array.get(rank[j], rank[i]);\n\
    \    } /*}}}*/\n};    /*}}}*/\n\n// sample: abc141E\n// int n;cin>>n;\n// string\
    \ s;cin>>s;\n// suffix_array sa(s);\n//\n// int ans = 0;\n// rep(i, n)rep(j, n){\n\
    //   chmax(ans, min(j-i, sa.lcp(i, j)));\n// }\n// cout << ans << endl;\n\n//%snippet.end()%\n\
    \nvoid test_sa() {\n    string s;\n    cin >> s;\n    suffix_array sa(s);\n\n\
    \    rep(i, sz(sa.pos)) cout << sa.pos[i] << (i != sz(sa.pos) - 1 ? \" \" : \"\
    \\n\");\n}\n\nvoid test_lcp() {\n    // abc141E\n    int n;\n    cin >> n;\n \
    \   string s;\n    cin >> s;\n    suffix_array sa(s);\n\n    int ans = 0;\n  \
    \  rep(i, n) rep(j, n) { chmax(ans, min(j - i, sa.lcp(i, j))); }\n    cout <<\
    \ ans << endl;\n}\n\nsigned main() {\n    // string s = \"adcdacbdcab\";\n   \
    \ // // string s = \"aaaaa\";\n    // dump(s);\n    // suffix_array sa(s);\n \
    \   // sa.build();\n    // dump(sa.pos);\n    // dump(sa.rank);\n    // dump(sa.lcp_array);\n\
    \    // dump(sa.lcp(1, 7));\n    test_lcp();\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/string/suffix_array/codes/suffix_array.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/string/suffix_array/codes/suffix_array.cpp
layout: document
redirect_from:
- /library/library/cpp/string/suffix_array/codes/suffix_array.cpp
- /library/library/cpp/string/suffix_array/codes/suffix_array.cpp.html
title: library/cpp/string/suffix_array/codes/suffix_array.cpp
---
