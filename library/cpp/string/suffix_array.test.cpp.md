---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/array/segtree/segment_tree.hpp
    title: library/cpp/array/segtree/segment_tree.hpp
  - icon: ':question:'
    path: library/cpp/array/sparse_table.hpp
    title: library/cpp/array/sparse_table.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':x:'
    path: library/cpp/string/suffix_array.hpp
    title: library/cpp/string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"library/cpp/string/suffix_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/suffixarray\"\n#line 2 \"library/cpp/header.hpp\"\
    \n\n//%snippet.set('header')%\n//%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\
    \n// template version 2.0\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    // varibable settings\ntemplate <class T> constexpr T inf = numeric_limits<T>::max()\
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
    \ zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T cdiv(T\
    \ a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x, a,\
    \ b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
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
    \n//%snippet.end()%\n#line 3 \"library/cpp/array/sparse_table.hpp\"\n\n//%snippet.set('sparse_table')%\n\
    //%snippet.fold()%\n\ntemplate< class T = ll >\nstruct sparse_table {\n    vector<\
    \ vector< T > > st;\n    vector< int > lookup;\n\n    sparse_table(const vector<\
    \ T > &v) {\n        int b = 0;\n        while((1 << b) <= sz(v)) ++b;\n     \
    \   st.assign(b, vector< T >(1 << b));\n        for(int i = 0; i < sz(v); i++)\
    \ {\n            st[0][i] = v[i];\n        }\n        for(int i = 1; i < b; i++)\
    \ {\n            for(int j = 0; j + (1 << i) <= (1 << b); j++) {\n           \
    \     st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n         \
    \   }\n        }\n        lookup.resize(v.size() + 1);\n        for(int i = 2;\
    \ i < sz(lookup); i++) {\n            lookup[i] = lookup[i >> 1] + 1;\n      \
    \  }\n    }\n\n    inline T query(int l, int r) {  // [l, r)\n        int b =\
    \ lookup[r - l];\n        return min(st[b][l], st[b][r - (1 << b)]);\n    }\n\
    };\n\n//%snippet.end()%\n#line 5 \"library/cpp/string/suffix_array.hpp\"\n\n//%snippet.set('suffix_array')%\n\
    //%snippet.config({'alias':'sa'})%\n//%snippet.include('segment_tree')%\n//%snippet.include('sparse_table')%\n\
    //%snippet.fold()%\n\nstruct suffix_array { \n    vector<int> a;\n    vector<int>\
    \ pos;   // pos[j]: j\u4F4D\u306Esumffix\u306F\u3069\u3053\u304B\u3089\u59CB\u307E\
    \u308B\u304B\n    vector<int> rank;  // rank[i]: s[i:]\u306F\u4F55\u4F4D\u304B\
    \n    // pos = rank^-1\n    vector<int> lcp_array;           // lcp_arry[j]: s[pos[j]:]\u3068\
    s[pos[j]+1:]\u306Elcp\n    SegmentTree<int> _seg_lcp_array;\n    int n;\n    string\
    \ s;\n\n    // constructor{{{\n    suffix_array() {}\n    suffix_array(vector<int>&\
    \ a) : a(a), n(a.size()) { _build(); }\n    suffix_array(string& s_): s(s_) {\n\
    \        n = s.size();\n        a.resize(n);\n        rep(i, n) a[i] = s[i];\n\
    \        _build();\n    } /*}}}*/\n\n    void _build() { /*{{{*/\n        _build_order();\n\
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
    \ [](auto a, auto b) { return min(a, b); };\n        _seg_lcp_array = SegmentTree<int>(lcp_array,\
    \ mymin, 1e9);\n        // sparse_lcp_array = SparseTable<int>(lcp_array);\n \
    \   } /*}}}*/\n\n    int lcp(int i, int j) {  // longest cummon prefix length\
    \ between s[i:] and s[j:]{{{\n        if (rank[i]<rank[j])   return _seg_lcp_array.query(rank[i],\
    \ rank[j]);\n        else                   return _seg_lcp_array.query(rank[j],\
    \ rank[i]);\n        // if (rank[i] < rank[j]) return sparse_lcp_array.get(rank[i],\
    \ rank[j]);\n        // else                   return sparse_lcp_array.get(rank[j],\
    \ rank[i]);\n    } /*}}}*/\n\n    #if defined(PCM) || defined(LOCAL)/*{{{*/\n\
    \    friend ostream& operator<<(ostream& os, suffix_array& sa) {\n        os <<\
    \ endl;\n        rep(j_th, sa.n){\n            int i = sa.pos[j_th];\n       \
    \     os << right << setw(4);\n            os << j_th << \":\" << sa.s.substr(i,\
    \ sa.n-i) << endl;\n        }\n        return os;\n    }\n    #endif/*}}}*/\n\
    };    \n// how to use\n    // string s;cin>>s;\n    // ll n = sz(s);\n    // suffix_array\
    \ sa(s);\n    // dump(sa);\n    // dump(sa.lcp_array);\n    // sa.pos[j]  : j\u4F4D\
    \u306Esuffix\u306F\u3069\u3053\u304B\u3089\u59CB\u307E\u308B\u304B\n    // sa.rank[i]\
    \ : s[i:]\u306F\u4F55\u4F4D\u304B\n    // sa.lcp_arry[j] : return lcp(s[pos[j]:],\
    \ s[pos[j+1]:])\n    // sa.lcp(i, j) :   return lcp(s[i:], s[j:])\n\n//%snippet.end()%\n\
    #line 3 \"library/cpp/string/suffix_array.test.cpp\"\n\nint main() {\n  string\
    \ s;cin>>s;\n  suffix_array sa(s);\n  rep(i, sz(sa.pos)) cout << sa.pos[i] <<\
    \ (i!=sz(sa.pos)-1 ? \" \" : \"\\n\");\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ \"suffix_array.hpp\"\n\nint main() {\n  string s;cin>>s;\n  suffix_array sa(s);\n\
    \  rep(i, sz(sa.pos)) cout << sa.pos[i] << (i!=sz(sa.pos)-1 ? \" \" : \"\\n\"\
    );\n  return 0;\n}\n"
  dependsOn:
  - library/cpp/string/suffix_array.hpp
  - library/cpp/header.hpp
  - library/cpp/array/segtree/segment_tree.hpp
  - library/cpp/array/sparse_table.hpp
  isVerificationFile: true
  path: library/cpp/string/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2020-12-21 23:16:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/string/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/string/suffix_array.test.cpp
- /verify/library/cpp/string/suffix_array.test.cpp.html
title: library/cpp/string/suffix_array.test.cpp
---
