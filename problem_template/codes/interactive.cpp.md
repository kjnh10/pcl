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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"problem_template/codes/interactive.cpp\"\
    \ntemplate<class T=ll> using vec = vector<T>;\n// TODO: struct flush\u3092\u5207\
    \u3063\u3066\u3042\u3052\u306A\u3044\u3068\u3044\u3051\u306A\u3044\uFF1F\n\ntemplate<class\
    \ T, class R>\nR query(T q){/*{{{*/\n    cout << \"?\" << \" \" << q << endl;\n\
    \    fflush(stdout);\n\n    R res; cin>>res;\n    if (cin.eof()==1) exit(1); \
    \ // judge\u304CWA\u3067\u6B62\u307E\u3063\u305F\u6642\u306A\u3069\u306B\u7D42\
    \u4E86\u3059\u308B\u305F\u3081\u306E\u30B3\u30FC\u30C9\n    return res;\n}/*}}}*/\n\
    \ntemplate<class T>\nvoid answer(T u){/*{{{*/\n    cout << \"!\" << \" \" << u\
    \ << endl;\n    fflush(stdout);\n}/*}}}*/\n\nvoid solve(){\n    ll res = 1;\n\
    \    ll num = 22;\n    rep(i, num-1){\n        // ll g = query(3);\n        //\
    \ res += g;\n        // dump(g, res);\n    }\n    answer(res);\n\n    return 0;\n\
    }\n\nint main(){/*{{{*/\n    ll Q;cin>>Q;\n    rep(_, Q){\n        solve();\n\
    \    }\n    return 0;\n}/*}}}*/\n"
  code: "#include \"header.hpp\"\ntemplate<class T=ll> using vec = vector<T>;\n//\
    \ TODO: struct flush\u3092\u5207\u3063\u3066\u3042\u3052\u306A\u3044\u3068\u3044\
    \u3051\u306A\u3044\uFF1F\n\ntemplate<class T, class R>\nR query(T q){/*{{{*/\n\
    \    cout << \"?\" << \" \" << q << endl;\n    fflush(stdout);\n\n    R res; cin>>res;\n\
    \    if (cin.eof()==1) exit(1);  // judge\u304CWA\u3067\u6B62\u307E\u3063\u305F\
    \u6642\u306A\u3069\u306B\u7D42\u4E86\u3059\u308B\u305F\u3081\u306E\u30B3\u30FC\
    \u30C9\n    return res;\n}/*}}}*/\n\ntemplate<class T>\nvoid answer(T u){/*{{{*/\n\
    \    cout << \"!\" << \" \" << u << endl;\n    fflush(stdout);\n}/*}}}*/\n\nvoid\
    \ solve(){\n    ll res = 1;\n    ll num = 22;\n    rep(i, num-1){\n        //\
    \ ll g = query(3);\n        // res += g;\n        // dump(g, res);\n    }\n  \
    \  answer(res);\n\n    return 0;\n}\n\nint main(){/*{{{*/\n    ll Q;cin>>Q;\n\
    \    rep(_, Q){\n        solve();\n    }\n    return 0;\n}/*}}}*/\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: problem_template/codes/interactive.cpp
  requiredBy: []
  timestamp: '2020-10-17 17:32:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: problem_template/codes/interactive.cpp
layout: document
redirect_from:
- /library/problem_template/codes/interactive.cpp
- /library/problem_template/codes/interactive.cpp.html
title: problem_template/codes/interactive.cpp
---
