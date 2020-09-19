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
    #line 2 \"library/cpp/misc/napsack.cpp\"\n\nint nampsack01all(int n, const vector<int>&\
    \ v, const vector<int>& w) {\n    // abc032_d\n    if (n <= 30) {\n        dump(\"\
    case 1\"); /*{{{*/\n\n        int n1 = n / 2;\n\n        auto f = [&](int l, int\
    \ r) {\n            vector<pair<int, int>> res;\n            int n = r - l;\n\
    \            rep(mask, 1 << n) {\n                int sv = 0;\n              \
    \  int sw = 0;\n                rep(i, n) {\n                    if (mask & (1\
    \ << i)) {\n                        sv += v[l + i];\n                        sw\
    \ += w[l + i];\n                    }\n                }\n                if (sw\
    \ <= W) res.pb(mp(sw, sv));\n            }\n            return res;\n        };\n\
    \n        auto r1 = f(0, n1);\n        auto r2 = f(n1, n);\n        sort(all(r1));\n\
    \        sort(all(r2));\n        int curmax = -1;\n        each(el, r2) {\n  \
    \          chmax(el.second, curmax);\n            curmax = el.second;\n      \
    \  }\n\n        int ans = -INF;\n        each(el, r1) {\n            int res =\
    \ 0;\n            int sw = el.first;\n            int sv = el.second;\n      \
    \      res += sv;\n\n            int load = W - sw;\n            auto i = ub(all(r2),\
    \ mp(load, INF)) - r2.begin();\n            if (i - 1 >= 0) chmax(ans, res + r2[i\
    \ - 1].second);\n        }\n        return ans; /*}}}*/\n    } else if (*max_element(all(w))\
    \ <= 1000) {\n        dump(\"case 2\"); /*{{{*/\n        const int MW = 200002;\n\
    \        vector<int> dp(MW, -INF);\n        dp[0] = 0;\n        rep(i, n) r_rep(j,\
    \ MW) {\n            chmax(dp[min(j + w[i], MW - 1)], dp[j] + v[i]);\n       \
    \ }\n        int ans = -INF;\n        rep(wi, 0, W + 1) { chmax(ans, dp[wi]);\
    \ }\n        return ans; /*}}}*/\n    } else if (*max_element(all(v)) <= 1000)\
    \ {\n        dump(\"case 3\"); /*{{{*/\n        const int V = 200002;\n      \
    \  vector<int> dp(V, INF);\n        dp[0] = 0;\n        rep(i, n) r_rep(j, V)\
    \ {                             // 01 napsack\n            chmin(dp[min(j + v[i],\
    \ V - 1)], dp[j] + w[i]);  // j\u304B\u3089\u914D\u308B\n        }\n        r_rep(j,\
    \ V) {\n            if (dp[j] <= W) {\n                return j;\n           \
    \     return 0;\n            }\n        } /*}}}*/\n    }\n}\n\nsigned main() {\n\
    \    //%snippet.set('napsack')%\n    int n, h;\n    cin >> h >> n;\n    vector<int>\
    \ v(n), w(n);\n    rep(i, n) cin >> v[i] >> w[i];\n\n    vector<int> dp(h + 1,\
    \ INF);\n    dp[0] = 0;\n    rep(i, n) rep(j, h + 1) {  // \u500B\u6570\u5236\u9650\
    \u306A\u3057\n                               // rep(i,n) r_rep(j,h+1){ // 01 napsack\n\
    \        chmin(dp[min(j + v[i], h)], dp[j] + w[i]);  // j\u304B\u3089\u914D\u308B\
    \n    }\n    cout << dp[h] << endl;\n    //%snippet.end()%\n\n    return 0;\n\
    }\n"
  code: "#include \"../header.hpp\"\n\nint nampsack01all(int n, const vector<int>&\
    \ v, const vector<int>& w) {\n    // abc032_d\n    if (n <= 30) {\n        dump(\"\
    case 1\"); /*{{{*/\n\n        int n1 = n / 2;\n\n        auto f = [&](int l, int\
    \ r) {\n            vector<pair<int, int>> res;\n            int n = r - l;\n\
    \            rep(mask, 1 << n) {\n                int sv = 0;\n              \
    \  int sw = 0;\n                rep(i, n) {\n                    if (mask & (1\
    \ << i)) {\n                        sv += v[l + i];\n                        sw\
    \ += w[l + i];\n                    }\n                }\n                if (sw\
    \ <= W) res.pb(mp(sw, sv));\n            }\n            return res;\n        };\n\
    \n        auto r1 = f(0, n1);\n        auto r2 = f(n1, n);\n        sort(all(r1));\n\
    \        sort(all(r2));\n        int curmax = -1;\n        each(el, r2) {\n  \
    \          chmax(el.second, curmax);\n            curmax = el.second;\n      \
    \  }\n\n        int ans = -INF;\n        each(el, r1) {\n            int res =\
    \ 0;\n            int sw = el.first;\n            int sv = el.second;\n      \
    \      res += sv;\n\n            int load = W - sw;\n            auto i = ub(all(r2),\
    \ mp(load, INF)) - r2.begin();\n            if (i - 1 >= 0) chmax(ans, res + r2[i\
    \ - 1].second);\n        }\n        return ans; /*}}}*/\n    } else if (*max_element(all(w))\
    \ <= 1000) {\n        dump(\"case 2\"); /*{{{*/\n        const int MW = 200002;\n\
    \        vector<int> dp(MW, -INF);\n        dp[0] = 0;\n        rep(i, n) r_rep(j,\
    \ MW) {\n            chmax(dp[min(j + w[i], MW - 1)], dp[j] + v[i]);\n       \
    \ }\n        int ans = -INF;\n        rep(wi, 0, W + 1) { chmax(ans, dp[wi]);\
    \ }\n        return ans; /*}}}*/\n    } else if (*max_element(all(v)) <= 1000)\
    \ {\n        dump(\"case 3\"); /*{{{*/\n        const int V = 200002;\n      \
    \  vector<int> dp(V, INF);\n        dp[0] = 0;\n        rep(i, n) r_rep(j, V)\
    \ {                             // 01 napsack\n            chmin(dp[min(j + v[i],\
    \ V - 1)], dp[j] + w[i]);  // j\u304B\u3089\u914D\u308B\n        }\n        r_rep(j,\
    \ V) {\n            if (dp[j] <= W) {\n                return j;\n           \
    \     return 0;\n            }\n        } /*}}}*/\n    }\n}\n\nsigned main() {\n\
    \    //%snippet.set('napsack')%\n    int n, h;\n    cin >> h >> n;\n    vector<int>\
    \ v(n), w(n);\n    rep(i, n) cin >> v[i] >> w[i];\n\n    vector<int> dp(h + 1,\
    \ INF);\n    dp[0] = 0;\n    rep(i, n) rep(j, h + 1) {  // \u500B\u6570\u5236\u9650\
    \u306A\u3057\n                               // rep(i,n) r_rep(j,h+1){ // 01 napsack\n\
    \        chmin(dp[min(j + v[i], h)], dp[j] + w[i]);  // j\u304B\u3089\u914D\u308B\
    \n    }\n    cout << dp[h] << endl;\n    //%snippet.end()%\n\n    return 0;\n\
    }\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/misc/napsack.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/misc/napsack.cpp
layout: document
redirect_from:
- /library/library/cpp/misc/napsack.cpp
- /library/library/cpp/misc/napsack.cpp.html
title: library/cpp/misc/napsack.cpp
---
