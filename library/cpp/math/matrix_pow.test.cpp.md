---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/matrix_pow.hpp
    title: library/cpp/math/matrix_pow.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/mint.hpp
    title: library/cpp/math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1073
    links:
    - https://yukicoder.me/problems/no/1073
  bundledCode: "#line 1 \"library/cpp/math/matrix_pow.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1073\"\n#line 2 \"library/cpp/header.hpp\"\
    \n\n//%snippet.set('header')%\n//%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\
    \n// template version 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n\
    // varibable settings\nconst long long INF = 1e18;\ntemplate <class T> constexpr\
    \ T inf = numeric_limits<T>::max() / 2.1;\n\n#define _overload3(_1, _2, _3, name,\
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
    \ long double ld;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing pll\
    \ = pair<ll, ll>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/math/matrix_pow.hpp\"\
    \n\n//%snippet.set('matrix_pow')%\n//%snippet.fold()%\n\ntemplate <class value\
    \ = ll>\nusing mat = vector<vector<value>>;\n\ntemplate <class T>\nmat<T> mul(const\
    \ mat<T>& A, const mat<T>& B) {\n    mat<T> res(A.size(), vector<T>(B[0].size()));\n\
    \    rep(i, A.size()) {\n        rep(j, B[0].size()) {\n            rep(k, B.size())\
    \ {\n                res[i][j] = (res[i][j] + A[i][k] * B[k][j]);\n          \
    \  }\n        }\n    }\n    return res;\n}\n\ntemplate <class T>\nmat<T> pow(mat<T>\
    \ A, ll n) {\n    mat<T> B(A.size(), vector<T>(A.size()));\n    rep(i, A.size())\
    \ {\n        B[i][i] = 1;  // E\n    }\n    while (n > 0) {\n        if (n & 1)\
    \ B = mul(B, A);\n        A = mul(A, A);\n        n >>= 1;\n    }\n    return\
    \ B;\n}\n\n//%snippet.end()%\n#line 3 \"library/cpp/math/mint.hpp\"\n\n//%snippet.set('mint')%\n\
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
    \ mint& a) { return os << a.x; }\n//}}}\n#line 4 \"library/cpp/math/matrix_pow.test.cpp\"\
    \n\nint solve() {\n    ll n;cin>>n;\n\n    mat<mint> A(6, vector<mint>(6));\n\
    \    mint x = mint(1)/6;\n    A[0] = {x, x, x, x, x, x};\n    A[1] = {1, 0, 0,\
    \ 0, 0, 0};\n    A[2] = {0, 1, 0, 0, 0, 0};\n    A[3] = {0, 0, 1, 0, 0, 0};\n\
    \    A[4] = {0, 0, 0, 1, 0, 0};\n    A[5] = {0, 0, 0, 0, 1, 0};\n\n    mat<mint>\
    \ B(6, vector<mint>(1, 0));\n    B[0] = {x};\n    B[1] = {1};\n\n    cout << mul(pow(A,\
    \ n-1), B)[0][0] << endl;\n\n    return 0; \n}\n\n\nint main(){/*{{{*/\n    solve();\n\
    \    check_input();\n    return 0;\n}/*}}}*/\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1073\"\n#include \"matrix_pow.hpp\"\
    \n#include \"mint.hpp\"\n\nint solve() {\n    ll n;cin>>n;\n\n    mat<mint> A(6,\
    \ vector<mint>(6));\n    mint x = mint(1)/6;\n    A[0] = {x, x, x, x, x, x};\n\
    \    A[1] = {1, 0, 0, 0, 0, 0};\n    A[2] = {0, 1, 0, 0, 0, 0};\n    A[3] = {0,\
    \ 0, 1, 0, 0, 0};\n    A[4] = {0, 0, 0, 1, 0, 0};\n    A[5] = {0, 0, 0, 0, 1,\
    \ 0};\n\n    mat<mint> B(6, vector<mint>(1, 0));\n    B[0] = {x};\n    B[1] =\
    \ {1};\n\n    cout << mul(pow(A, n-1), B)[0][0] << endl;\n\n    return 0; \n}\n\
    \n\nint main(){/*{{{*/\n    solve();\n    check_input();\n    return 0;\n}/*}}}*/\n"
  dependsOn:
  - library/cpp/math/matrix_pow.hpp
  - library/cpp/header.hpp
  - library/cpp/math/mint.hpp
  isVerificationFile: true
  path: library/cpp/math/matrix_pow.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 12:21:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/math/matrix_pow.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/math/matrix_pow.test.cpp
- /verify/library/cpp/math/matrix_pow.test.cpp.html
title: library/cpp/math/matrix_pow.test.cpp
---
