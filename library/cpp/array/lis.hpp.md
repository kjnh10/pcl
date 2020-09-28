---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/lis.test.cpp
    title: library/cpp/array/lis.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    #line 2 \"library/cpp/array/lis.hpp\"\n\n//%snippet.set('lis')%\n\ntemplate<class\
    \ T>\nint lis(const vector<T>& x, bool strict=true) { /*{{{*/\n    int n = sz(x);\n\
    \    vector<T> dp(n+1, numeric_limits<T>().max());\n    vector<pair<int, T>> update_info(n);\n\
    \    dp[0] = numeric_limits<T>().min();\n    int res = 0;\n    rep(i, n) {\n \
    \       int j;\n        if (strict) j = lb(all(dp), x[i]) - dp.begin();\n    \
    \    else        j = ub(all(dp), x[i]) - dp.begin();\n        chmax(res, j);\n\
    \        update_info[i] = make_pair(j, dp[j]);\n        dp[j] = x[i];\n    }\n\
    \    dump(dp);\n\n    // \u5FA9\u5143\n    int now_len = res;\n    vector<T> lis;\n\
    \    r_rep(i, n){\n        auto [j, pre] = update_info[i];\n        if (j==now_len)\
    \ {\n            now_len--;\n            lis.push_back(x[i]);\n        }\n   \
    \     dp[j] = pre;\n    }\n    assert(now_len==0);\n    reverse(all(lis));\n \
    \   dump(lis);\n\n    return res;\n} /*}}}*/\n\n\n//%snippet.end()%\n\n// lis\u306B\
    \u306FBIT\u3092\u4F7F\u3063\u305Fmethod\u3082\u3042\u308B\u3002\n// signed main()\
    \ {\n//     vector<ll> x({1, 5, 4, 2, 3, 3, 7});\n//     auto res = lis(x);\n\
    //     auto res_not_strict = lis(x, false);\n//     dump(res);\n//     dump(res_not_strict);\n\
    //     return 0;\n// }\n"
  code: "#include \"../header.hpp\"\n\n//%snippet.set('lis')%\n\ntemplate<class T>\n\
    int lis(const vector<T>& x, bool strict=true) { /*{{{*/\n    int n = sz(x);\n\
    \    vector<T> dp(n+1, numeric_limits<T>().max());\n    vector<pair<int, T>> update_info(n);\n\
    \    dp[0] = numeric_limits<T>().min();\n    int res = 0;\n    rep(i, n) {\n \
    \       int j;\n        if (strict) j = lb(all(dp), x[i]) - dp.begin();\n    \
    \    else        j = ub(all(dp), x[i]) - dp.begin();\n        chmax(res, j);\n\
    \        update_info[i] = make_pair(j, dp[j]);\n        dp[j] = x[i];\n    }\n\
    \    dump(dp);\n\n    // \u5FA9\u5143\n    int now_len = res;\n    vector<T> lis;\n\
    \    r_rep(i, n){\n        auto [j, pre] = update_info[i];\n        if (j==now_len)\
    \ {\n            now_len--;\n            lis.push_back(x[i]);\n        }\n   \
    \     dp[j] = pre;\n    }\n    assert(now_len==0);\n    reverse(all(lis));\n \
    \   dump(lis);\n\n    return res;\n} /*}}}*/\n\n\n//%snippet.end()%\n\n// lis\u306B\
    \u306FBIT\u3092\u4F7F\u3063\u305Fmethod\u3082\u3042\u308B\u3002\n// signed main()\
    \ {\n//     vector<ll> x({1, 5, 4, 2, 3, 3, 7});\n//     auto res = lis(x);\n\
    //     auto res_not_strict = lis(x, false);\n//     dump(res);\n//     dump(res_not_strict);\n\
    //     return 0;\n// }\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/array/lis.hpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - library/cpp/array/lis.test.cpp
documentation_of: library/cpp/array/lis.hpp
layout: document
redirect_from:
- /library/library/cpp/array/lis.hpp
- /library/library/cpp/array/lis.hpp.html
title: library/cpp/array/lis.hpp
---
