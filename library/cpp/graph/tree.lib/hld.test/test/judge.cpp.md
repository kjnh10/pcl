---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/cpp/graph/tree.lib/hld.test/test/judge.cpp: line 47: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "// template version 1.15\nusing namespace std;\n#include <bits/stdc++.h>\n\
    \n// varibable settings\n#define int long long\nconst int INF=1e18;\n\n// define\
    \ basic macro {{{\n#define _overload3(_1,_2,_3,name,...) name\n#define _rep(i,n)\
    \ repi(i,0,n)\n#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)\n#define\
    \ rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)\n#define _rrep(i,n)\
    \ rrepi(i,0,n)\n#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)\n\
    #define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)\n#define each(i,a)\
    \ for (auto&& i : a)\n#define all(x) (x).begin(),(x).end()\n#define rall(x) (x).rbegin(),(x).rend()\n\
    #define sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b)\
    \ make_pair(a, b)\n#define mt(a, b, c) make_tuple(a, b, c)\n#define ub upper_bound\n\
    #define lb lower_bound\n#define posl(A, x) (lower_bound(all(A), x)-A.begin())\n\
    #define posu(A, x) (upper_bound(all(A),x)-A.begin())\ntemplate<class T> inline\
    \ void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }\ntemplate<class T>\
    \ inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }\n\n#define\
    \ divceil(a,b) ((a)+(b)-1)/(b)\n#define is_in(x, a, b) ((a)<=(x) && (x)<(b))\n\
    #define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())\n#define slice(l,\
    \ r) substr(l, r-l)\n\ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef\
    \ vector<vi> vvi;\ntypedef long double ld;\ntypedef pair<int,int> pii;\ntypedef\
    \ tuple<int,int,int> iii;\n\ntemplate<typename T> using PQ = priority_queue<T,\
    \ vector<T>, greater<T>>;\n// struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false);\
    \ } } fast;\n\n#if defined(PCM) || defined(LOCAL)\n    #include \"../codes/lib/dump.hpp\"\
    \n#else\n    #define dump(...) 42\n    #define dump_1d(...) 42\n    #define dump_2d(...)\
    \ 42\n    #define cerrendl 42\n#endif\n//}}}\n\nint T;\nint b;\n\ntemplate<class\
    \ T>\nvoid tell(T x){\n    dump(x);\n    cout << x << endl;\n    fflush(stdout);\n\
    }\n\nint judge_case(string a){\n    dump(a);\n    for(int cnt=1; cnt<=150; cnt++){\n\
    \        if (cnt%10==1){ reverse(all(a)); }\n\n        string query;cin>>query;\n\
    \        if (sz(query)!=b){ tell(a[stoi(query)-1]); }\n        else{\n       \
    \     if (query==a){\n                tell(\"Y\");\n                return 0;\n\
    \            }\n            else{\n                tell(\"N\");\n            \
    \    dump(\"judge-ans\", a);\n                dump(\"contestant-ans\", query);\n\
    \                throw(\"WA\");\n            }\n        }\n        cnt += 1;\n\
    \    }\n    throw(\"query's limit exceeded\");\n}\n\nsigned main(){\n    // input\
    \ case\n    cin>>T>>b;\n    tell(T);\n    tell(b);\n    vector<string> A(T);\n\
    \    rep(t, T){ cin>>A[t]; }\n\n    // judge\n    rep(i, T){\n        judge_case(A[i]);\n\
    \    }\n\n    // TODO: check contestant code is continuing to needles queries.\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/tree.lib/hld.test/test/judge.cpp
  requiredBy: []
  timestamp: '2020-05-11 21:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/tree.lib/hld.test/test/judge.cpp
layout: document
redirect_from:
- /library/library/cpp/graph/tree.lib/hld.test/test/judge.cpp
- /library/library/cpp/graph/tree.lib/hld.test/test/judge.cpp.html
title: library/cpp/graph/tree.lib/hld.test/test/judge.cpp
---
