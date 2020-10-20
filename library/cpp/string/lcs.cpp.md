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
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n// varibable settings\n\
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/string/lcs.cpp\"\
    \n\n//%snippet.set('lcs')%\n#define MAX_N 5000\n#define MAX_M 5000\nint lcs(string\
    \ s, string t) {\n    int n = sz(s);\n    int m = sz(t);\n    int dp[MAX_N + 1][MAX_M\
    \ + 1] = {};  // 1-index\n\n    rep(i, n) {\n        rep(j, m) {\n           \
    \ if (s[i] == t[j])\n                chmax(dp[i + 1][j + 1], dp[i][j] + 1);\n\
    \            else {\n                chmax(dp[i + 1][j + 1], dp[i][j + 1]);\n\
    \                chmax(dp[i + 1][j + 1], dp[i + 1][j]);\n            }\n     \
    \   }\n    }\n    return dp[n][m];\n}\n// %snippet.end()%\n\nint solve() { /*{{{*/\n\
    \    string s, t;\n    cin >> s >> t;\n    cout << lcs(s, t) + 1 << endl;\n\n\
    \    return 0;\n} /*}}}*/\n\nsigned main() {  //{{{\n#ifdef INPUT_FROM_FILE\n\
    \    std::ifstream in(infile);\n    std::cin.rdbuf(in.rdbuf());\n#endif\n    solve();\n\
    \    return 0;\n}  //}}}\n"
  code: "#include \"../header.hpp\"\n\n//%snippet.set('lcs')%\n#define MAX_N 5000\n\
    #define MAX_M 5000\nint lcs(string s, string t) {\n    int n = sz(s);\n    int\
    \ m = sz(t);\n    int dp[MAX_N + 1][MAX_M + 1] = {};  // 1-index\n\n    rep(i,\
    \ n) {\n        rep(j, m) {\n            if (s[i] == t[j])\n                chmax(dp[i\
    \ + 1][j + 1], dp[i][j] + 1);\n            else {\n                chmax(dp[i\
    \ + 1][j + 1], dp[i][j + 1]);\n                chmax(dp[i + 1][j + 1], dp[i +\
    \ 1][j]);\n            }\n        }\n    }\n    return dp[n][m];\n}\n// %snippet.end()%\n\
    \nint solve() { /*{{{*/\n    string s, t;\n    cin >> s >> t;\n    cout << lcs(s,\
    \ t) + 1 << endl;\n\n    return 0;\n} /*}}}*/\n\nsigned main() {  //{{{\n#ifdef\
    \ INPUT_FROM_FILE\n    std::ifstream in(infile);\n    std::cin.rdbuf(in.rdbuf());\n\
    #endif\n    solve();\n    return 0;\n}  //}}}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/string/lcs.cpp
  requiredBy: []
  timestamp: '2020-10-17 17:32:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/string/lcs.cpp
layout: document
redirect_from:
- /library/library/cpp/string/lcs.cpp
- /library/library/cpp/string/lcs.cpp.html
title: library/cpp/string/lcs.cpp
---
