---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/string/rolling_hash.hpp
    title: library/cpp/string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"library/cpp/string/rolling_hash.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/string/rolling_hash.hpp\"\
    \n\n\n//%snippet.set('rolling_hash')%\n//%snippet.fold()%\n\ntemplate<class Z>\
    \ Z rng(Z a, Z b) {\n    auto tmp = mt19937(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<Z>(a, b - 1)(tmp);\n}\n\nstruct rolling_hash\
    \ {\n    // static constexpr uint64_t P0 = 4111144441, P1 = 4111444111;\n    static\
    \ constexpr uint64_t P0 = 1e9+7, P1 = 998244353;\n    static uint64_t B0, B1;\n\
    \    vector<ll> hash0, hash1, _bpow0, _bpow1;  // 1-index\n    int n;\n\n    rolling_hash()\
    \ {}\n    template<class T = vector<int>>\n    rolling_hash(T &vs) {\n       \
    \ n = vs.size();\n        init(vs, hash0, B0, P0, _bpow0); \n        init(vs,\
    \ hash1, B1, P1, _bpow1); \n    }\n    rolling_hash(string &s) {\n        n =\
    \ s.size();\n        vector<int> vs;\n        for (char c : s) vs.emplace_back(c);\n\
    \        init(vs, hash0, B0, P0, _bpow0); \n        init(vs, hash1, B1, P1, _bpow1);\
    \ \n    }\n\n    template<class T>\n    void init(T& vs, vector<ll>& hash, ll\
    \ B, ll P, vector<ll>& _bpow) {\n        hash.assign(n + 1, 0);\n        _bpow.assign(n\
    \ + 1, 1);\n        for (int i = 0; i < n; i++) {\n            hash[i + 1] = (hash[i]\
    \ * B + vs[i]) % P;\n            _bpow[i + 1] = _bpow[i] * B % P;\n        }\n\
    \    }\n\n    pair<ll, ll> get_hash() { // [l, r)\n        ll h0 = _get_hash(0,\
    \ n, hash0, B0, P0, _bpow0);\n        ll h1 = _get_hash(0, n, hash1, B1, P1, _bpow1);\n\
    \        return {h0, h1};\n    }\n    pair<ll, ll> get_hash(int l, int r) { //\
    \ [l, r)\n        ll h0 = _get_hash(l, r, hash0, B0, P0, _bpow0);\n        ll\
    \ h1 = _get_hash(l, r, hash1, B1, P1, _bpow1);\n        return {h0, h1};\n   \
    \ }\n    ll _get_hash(int l, int r,  const vector<ll>& hash, ll B, ll P, const\
    \ vector<ll>& _bpow) {\n        ll res = (hash[r] - hash[l]*_bpow[r - l]) % P;\n\
    \        res = (res < 0 ? res + P : res);\n        assert(res>=0);\n        return\
    \ res;\n    }\n\n    pair<ll, ll> merge(pair<ll, ll> x, pair<ll, ll> y, int len_y)\
    \ {\n        // merge hash: \n        // How to use\n        // rolling_hash op(vec<int>(n,\
    \ max_len));\n        // op.merge(rh_s.get_hash(), rh_t.get_hash(), rh_t.n);\n\
    \        return {(x.first * _bpow0[len_y] + y.first)%P0, (x.second * _bpow1[len_y]\
    \ + y.second)%P1};\n    }\n\n    #if defined(PCM) || defined(LOCAL)\n    friend\
    \ ostream& operator<<(ostream& os, rolling_hash<X>& rh) {  //\n        os << rh.get_hash();\n\
    \        return os;\n    }\n    #endif\n};\nuint64_t rolling_hash::B0 = rng<ll>(1000000,\
    \ rolling_hash::P0);\nuint64_t rolling_hash::B1 = rng<ll>(1000000, rolling_hash::P1);\n\
    \n//%snippet.end()%\n\n#line 4 \"library/cpp/string/rolling_hash.test.cpp\"\n\n\
    int main() {\n    string t, p;\n    using RH = rolling_hash;\n\n    cin >> t;\n\
    \    cin >> p;\n    RH rh(t), rh2(p);\n    for(int i = 0; i + p.size() <= t.size();\
    \ i++) {\n        if(rh.get_hash(i, i + p.size()) == rh2.get_hash(0, p.size()))\
    \ {\n            cout << i << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"rolling_hash.hpp\"\n\nint main() {\n    string t, p;\n    using\
    \ RH = rolling_hash;\n\n    cin >> t;\n    cin >> p;\n    RH rh(t), rh2(p);\n\
    \    for(int i = 0; i + p.size() <= t.size(); i++) {\n        if(rh.get_hash(i,\
    \ i + p.size()) == rh2.get_hash(0, p.size())) {\n            cout << i << endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - library/cpp/string/rolling_hash.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 17:32:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/string/rolling_hash.test.cpp
- /verify/library/cpp/string/rolling_hash.test.cpp.html
title: library/cpp/string/rolling_hash.test.cpp
---
