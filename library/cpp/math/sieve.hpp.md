---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/cpp/include/sieve.hpp
    title: library/cpp/include/sieve.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/sieve.aoj.test.cpp
    title: library/cpp/math/sieve.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/sieve.test.cpp
    title: library/cpp/math/sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\n#include <bits/stdc++.h>\nusing namespace std;\n\n// varibable settings\n\
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
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto mv(X x,\
    \ T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto mv(X x, Y y, Z z, Zs... zs) { auto cont = mv(y, z, zs...);\
    \ return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T cdiv(T a,\
    \ T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x, a, b)\
    \ ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\n#include <cxxabi.h>\nstring\
    \ demangle(const char * name) {\n    size_t len = strlen(name) + 256;\n    char\
    \ output_buffer[len];\n    int status = 0;\n    return string(abi::__cxa_demangle(name,\
    \ output_buffer, &len, &status));\n}\ntemplate<class T> string type(T x){ return\
    \ demangle(typeid(x).name()); }\n\ntypedef long long ll;\ntypedef long double\
    \ ld;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>, greater<T>>;\n\
    void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof()\
    \ == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define dump(...) ;\n\
    #define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n\
    #endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/math/sieve.hpp\"\
    \n\n//%snippet.set('sieve')%\n//%snippet.config({'alias':'prime_factor_by_sieve'})%\n\
    //%snippet.fold()%\n\nstruct Sieve {/*{{{*/\n    // \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u3075\u308B\u3044 O(NloglogN)\n    ll n;                  \
    \            // n: max number for defined minfactor and primes\n    vector<ll>\
    \ minfactor;              // [-1, 2, 3, 2, 5, 2, 7, 2, 3, ....]\n    vector<ll>\
    \ primes;                 // [2, 3, 5, .......]\n    vector<int> mobius;     \
    \           // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u5024\n\n    Sieve(ll n =\
    \ 1) : n(n), minfactor(n + 1), mobius(n + 1, 1) { /*{{{*/\n        minfactor[0]\
    \ = minfactor[1] = -1;\n        for (ll p = 2; p <= n; ++p) {\n            if\
    \ (minfactor[p]) continue;\n            primes.push_back(p);\n            minfactor[p]\
    \ = p;\n            mobius[p] = -1;\n            for (ll x = p * p; x <= n; x\
    \ += p) {\n                if (!minfactor[x]) minfactor[x] = p;\n            \
    \    if ((x / p) % p == 0) mobius[x] = 0;\n                else mobius[x] *= -1;\n\
    \            }\n        }\n    } /*}}}*/\n\n    bool is_prime(ll x) {/*{{{*/\n\
    \        if (x <= n) return minfactor[x] == x; \n        return sz(factor_list(x))\
    \ == 1;\n    }/*}}}*/\n\n    vector<ll> factor_list(ll x) { /*{{{*/\n        assert(0\
    \ < x && x <= n*n); // \u3053\u308C\u304C\u6E80\u305F\u3055\u308C\u306A\u3044\u3068\
    \u6B63\u3057\u304F\u8A08\u7B97\u3055\u308C\u306A\u3044\u53EF\u80FD\u6027\u304C\
    \u3042\u308B\u3002\n\n        vector<ll> res;\n        if (x <= n) {\n       \
    \     while (x != 1) {\n                res.push_back(minfactor[x]);\n       \
    \         x /= minfactor[x];\n            }\n        }\n        else {\n     \
    \       for (ll i = 0; primes[i] * primes[i] <= x; i++) {\n                while\
    \ (x % primes[i] == 0) {\n                    res.pb(primes[i]);\n           \
    \         x /= primes[i];\n                }\n            }\n            if (x\
    \ != 1) res.pb(x);\n        }\n\n        return res;  // [2, 3, 3, 5, 5, 5.....]\n\
    \    }                /*}}}*/\n\n    vector<pair<ll, ll>> prime_factor(ll x) {\
    \ /*{{{*/\n        // just change fl vector to map form\n        vector<ll> fl\
    \ = factor_list(x);\n        if (fl.size() == 0) return {};\n        vector<pair<ll,\
    \ ll>> res = {mp(fl[0], 0)};\n        for (ll p : fl) {\n            if (res.back().first\
    \ == p) {\n                res.back().second++;\n            } else {\n      \
    \          res.emplace_back(p, 1);\n            }\n        }\n        return res;\
    \  // [(2,1), (3,2), (5,3), .....]\n    }                /*}}}*/\n\n    vector<ll>\
    \ divisors(ll x) { // \u9AD8\u901F\u7D04\u6570\u5217\u6319{{{\n        vector<ll>\
    \ res({1});\n        auto ps = prime_factor(x);\n\n        // \u7D04\u6570\u5217\
    \u6319\n        for (auto p : ps) {\n            ll s = (ll)res.size();\n    \
    \        for (ll i = 0; i < s; ++i) {\n                ll v = 1;\n           \
    \     for (ll j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }/*}}}*/\n\n};/*}}}*/\nSieve sv(1e6);\n\
    // How to use\n    // sv.primes            // \u7D20\u6570\u306E\u30EA\u30B9\u30C8\
    \n    // sv.prime_factor(x);  // \u7D20\u56E0\u6570\u5206\u89E3\n\n//%snippet.end()%\n"
  code: "#pragma once\n#include \"../header.hpp\"\n\n//%snippet.set('sieve')%\n//%snippet.config({'alias':'prime_factor_by_sieve'})%\n\
    //%snippet.fold()%\n\nstruct Sieve {/*{{{*/\n    // \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u3075\u308B\u3044 O(NloglogN)\n    ll n;                  \
    \            // n: max number for defined minfactor and primes\n    vector<ll>\
    \ minfactor;              // [-1, 2, 3, 2, 5, 2, 7, 2, 3, ....]\n    vector<ll>\
    \ primes;                 // [2, 3, 5, .......]\n    vector<int> mobius;     \
    \           // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u5024\n\n    Sieve(ll n =\
    \ 1) : n(n), minfactor(n + 1), mobius(n + 1, 1) { /*{{{*/\n        minfactor[0]\
    \ = minfactor[1] = -1;\n        for (ll p = 2; p <= n; ++p) {\n            if\
    \ (minfactor[p]) continue;\n            primes.push_back(p);\n            minfactor[p]\
    \ = p;\n            mobius[p] = -1;\n            for (ll x = p * p; x <= n; x\
    \ += p) {\n                if (!minfactor[x]) minfactor[x] = p;\n            \
    \    if ((x / p) % p == 0) mobius[x] = 0;\n                else mobius[x] *= -1;\n\
    \            }\n        }\n    } /*}}}*/\n\n    bool is_prime(ll x) {/*{{{*/\n\
    \        if (x <= n) return minfactor[x] == x; \n        return sz(factor_list(x))\
    \ == 1;\n    }/*}}}*/\n\n    vector<ll> factor_list(ll x) { /*{{{*/\n        assert(0\
    \ < x && x <= n*n); // \u3053\u308C\u304C\u6E80\u305F\u3055\u308C\u306A\u3044\u3068\
    \u6B63\u3057\u304F\u8A08\u7B97\u3055\u308C\u306A\u3044\u53EF\u80FD\u6027\u304C\
    \u3042\u308B\u3002\n\n        vector<ll> res;\n        if (x <= n) {\n       \
    \     while (x != 1) {\n                res.push_back(minfactor[x]);\n       \
    \         x /= minfactor[x];\n            }\n        }\n        else {\n     \
    \       for (ll i = 0; primes[i] * primes[i] <= x; i++) {\n                while\
    \ (x % primes[i] == 0) {\n                    res.pb(primes[i]);\n           \
    \         x /= primes[i];\n                }\n            }\n            if (x\
    \ != 1) res.pb(x);\n        }\n\n        return res;  // [2, 3, 3, 5, 5, 5.....]\n\
    \    }                /*}}}*/\n\n    vector<pair<ll, ll>> prime_factor(ll x) {\
    \ /*{{{*/\n        // just change fl vector to map form\n        vector<ll> fl\
    \ = factor_list(x);\n        if (fl.size() == 0) return {};\n        vector<pair<ll,\
    \ ll>> res = {mp(fl[0], 0)};\n        for (ll p : fl) {\n            if (res.back().first\
    \ == p) {\n                res.back().second++;\n            } else {\n      \
    \          res.emplace_back(p, 1);\n            }\n        }\n        return res;\
    \  // [(2,1), (3,2), (5,3), .....]\n    }                /*}}}*/\n\n    vector<ll>\
    \ divisors(ll x) { // \u9AD8\u901F\u7D04\u6570\u5217\u6319{{{\n        vector<ll>\
    \ res({1});\n        auto ps = prime_factor(x);\n\n        // \u7D04\u6570\u5217\
    \u6319\n        for (auto p : ps) {\n            ll s = (ll)res.size();\n    \
    \        for (ll i = 0; i < s; ++i) {\n                ll v = 1;\n           \
    \     for (ll j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }/*}}}*/\n\n};/*}}}*/\nSieve sv(1e6);\n\
    // How to use\n    // sv.primes            // \u7D20\u6570\u306E\u30EA\u30B9\u30C8\
    \n    // sv.prime_factor(x);  // \u7D20\u56E0\u6570\u5206\u89E3\n\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/math/sieve.hpp
  requiredBy:
  - library/cpp/include/sieve.hpp
  timestamp: '2021-08-09 13:06:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - library/cpp/math/sieve.aoj.test.cpp
  - library/cpp/math/sieve.test.cpp
documentation_of: library/cpp/math/sieve.hpp
layout: document
redirect_from:
- /library/library/cpp/math/sieve.hpp
- /library/library/cpp/math/sieve.hpp.html
title: library/cpp/math/sieve.hpp
---
