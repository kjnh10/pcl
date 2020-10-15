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
    \ zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T cdiv(T\
    \ a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x, a,\
    \ b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing pll\
    \ = pair<ll, ll>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"library/cpp/string/kmp/codes/solve.cpp\"\
    \n\n//%snippet.set('kmp')%\n\n// Morris-Pratt\ntemplate <typename T>\nstruct KMP\
    \ {\n    int n;\n    T pattern;\n    vector<int> a;\n    KMP() {} /*{{{*/\n  \
    \  KMP(const T& pattern) : pattern(pattern) {\n        n = pattern.size();\n \
    \       a = vector<int>(n + 1);\n        a[0] = -1;\n        int j = -1;\n   \
    \     for (int i = 0; i < n; ++i) {\n            while (j != -1 && pattern[j]\
    \ != pattern[i]) j = a[j];\n            j++;\n            a[i + 1] = j;\n    \
    \    }\n    } /*}}}*/\n    int operator[](int i) { return a[i]; }\n    vector<int>\
    \ findAll(const T& s) { /*{{{*/\n        vector<int> res;\n        int j = 0;\n\
    \        for (int i = 0; i < sz(s); ++i) {\n            while (j != -1 && pattern[j]\
    \ != s[i]) j = a[j];\n            j++;\n            if (j == n) {\n          \
    \      res.push_back(i - j + 1);\n                j = a[j];\n            }\n \
    \       }\n        return res;\n    } /*}}}*/\n};\n\n// KMP<vector<int>> kmp({1,2,3});\n\
    // KMP<string> kmp(\"abc\");\n\n//%snippet.end()%\n\nvector<int> f(vector<int>&\
    \ a) {\n    int n = a.size();\n    vector<int> res(n);\n    rep(i, n) res[i] =\
    \ a[i] ^ a[(i + 1) % n];\n    return res;\n}\n\nsigned main() {\n    int n;\n\
    \    cin >> n;\n    vector<int> a(n), b(n);\n    rep(i, n) cin >> a[i];\n    rep(i,\
    \ n) cin >> b[i];\n    vector<int> xa = f(a);\n    vector<int> xb = f(b);\n  \
    \  dump(xa);\n    dump(xb);\n\n    KMP<vector<int>> kmp(xa);\n    dump(\"hello\"\
    );\n    vector<ll> wxb;\n    wxb.insert(wxb.end(), xb.begin(), xb.end());\n  \
    \  wxb.insert(wxb.end(), xb.begin(), xb.end());\n\n    vector<int> res = kmp.findAll(wxb);\n\
    \    vector<int> ks;\n    for (int p : res) ks.push_back(n - p);\n    sort(ks.begin(),\
    \ ks.end());\n    for (int k : ks) {\n        if (k >= n) continue;\n        int\
    \ x = a[k] ^ b[0];\n        cout << k << \" \" << x << endl;\n    }\n    return\
    \ 0;\n}\n"
  code: "#include \"../../../header.hpp\"\n\n//%snippet.set('kmp')%\n\n// Morris-Pratt\n\
    template <typename T>\nstruct KMP {\n    int n;\n    T pattern;\n    vector<int>\
    \ a;\n    KMP() {} /*{{{*/\n    KMP(const T& pattern) : pattern(pattern) {\n \
    \       n = pattern.size();\n        a = vector<int>(n + 1);\n        a[0] = -1;\n\
    \        int j = -1;\n        for (int i = 0; i < n; ++i) {\n            while\
    \ (j != -1 && pattern[j] != pattern[i]) j = a[j];\n            j++;\n        \
    \    a[i + 1] = j;\n        }\n    } /*}}}*/\n    int operator[](int i) { return\
    \ a[i]; }\n    vector<int> findAll(const T& s) { /*{{{*/\n        vector<int>\
    \ res;\n        int j = 0;\n        for (int i = 0; i < sz(s); ++i) {\n      \
    \      while (j != -1 && pattern[j] != s[i]) j = a[j];\n            j++;\n   \
    \         if (j == n) {\n                res.push_back(i - j + 1);\n         \
    \       j = a[j];\n            }\n        }\n        return res;\n    } /*}}}*/\n\
    };\n\n// KMP<vector<int>> kmp({1,2,3});\n// KMP<string> kmp(\"abc\");\n\n//%snippet.end()%\n\
    \nvector<int> f(vector<int>& a) {\n    int n = a.size();\n    vector<int> res(n);\n\
    \    rep(i, n) res[i] = a[i] ^ a[(i + 1) % n];\n    return res;\n}\n\nsigned main()\
    \ {\n    int n;\n    cin >> n;\n    vector<int> a(n), b(n);\n    rep(i, n) cin\
    \ >> a[i];\n    rep(i, n) cin >> b[i];\n    vector<int> xa = f(a);\n    vector<int>\
    \ xb = f(b);\n    dump(xa);\n    dump(xb);\n\n    KMP<vector<int>> kmp(xa);\n\
    \    dump(\"hello\");\n    vector<ll> wxb;\n    wxb.insert(wxb.end(), xb.begin(),\
    \ xb.end());\n    wxb.insert(wxb.end(), xb.begin(), xb.end());\n\n    vector<int>\
    \ res = kmp.findAll(wxb);\n    vector<int> ks;\n    for (int p : res) ks.push_back(n\
    \ - p);\n    sort(ks.begin(), ks.end());\n    for (int k : ks) {\n        if (k\
    \ >= n) continue;\n        int x = a[k] ^ b[0];\n        cout << k << \" \" <<\
    \ x << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/string/kmp/codes/solve.cpp
  requiredBy: []
  timestamp: '2020-10-15 12:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/string/kmp/codes/solve.cpp
layout: document
redirect_from:
- /library/library/cpp/string/kmp/codes/solve.cpp
- /library/library/cpp/string/kmp/codes/solve.cpp.html
title: library/cpp/string/kmp/codes/solve.cpp
---
