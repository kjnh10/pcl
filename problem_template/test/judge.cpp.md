---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto make_table(X\
    \ x, T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y,\
    \ z, zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T\
    \ cdiv(T a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x,\
    \ a, b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 2 \"problem_template/test/judge.cpp\"\
    \n\nenum JudgeResult {/*{{{*/\n    AC = 0,\n    WA = 1,\n    RE = 2,\n    CE =\
    \ 3,\n    TLE = -2,\n    MLE = 4,\n    QLE = 5,  // Query limit exceeded\n   \
    \ AIE = 6,  // Additional input error\n    NOEXP = 98,\n    TLENAIVE = 99,\n \
    \   YET = 100,\n};/*}}}*/\n\ntemplate <class T>/*{{{*/\nvoid tell(T x) {\n   \
    \ cout << x << endl;\n    fflush(stdout);\n}/*}}}*/\n\nbool check_AIE(){/*{{{*/\n\
    \    ll tmp;cin>>tmp;\n    if (cin.eof()==0) exit(AIE);  // check needles user-output\
    \ does not exist\n}/*}}}*/\n\nint judge_case(ll x) {\n    ll num = 22;  // TODO:\
    \ update query number limit\n    while(num--){\n        string query;\n      \
    \  cin >> query;\n        if (query==\"?\"){ // query\n            ll solver_ans;cin>>solver_ans;\n\
    \            tell(gcd(solver_ans, x));\n        }\n        if (query==\"!\"){\
    \ // ans\n            ll solver_ans;cin>>solver_ans;\n            if (abs(solver_ans-x)<=7\
    \ || (solver_ans<=2*x && x<=2*solver_ans)){\n                return 0;\n     \
    \       }\n            else{\n                cerr << \"WA: \";\n            \
    \    dump(x, solver_ans);\n                exit(WA);\n            }\n        }\n\
    \    }\n    exit(QLE);\n}\n\nint main() {\n    // input case\n    int Q;\n   \
    \ cin >> Q;\n    // Q = 1; if single case\n    vector<ll> x(Q);\n    rep(q, Q){\
    \ cin>>x[q]; }\n\n    // judge\n    tell(Q);  // off if single case\n    rep(q,\
    \ Q) {\n        cerr << \"start judge for: \" << x[q] << \" [judge]\" << endl;;\n\
    \        judge_case(x[q]); \n    }\n\n    // check_AIE(); // \u3053\u308C\u306F\
    \u4F55\u6545\u304B\u52D5\u304B\u306A\u3044\u3002\u7121\u9650\u5F85\u6A5F\u306B\
    \u306A\u3063\u3066\u3057\u307E\u3046\u3002\n    exit(AC);\n    return 0;\n}\n"
  code: "#include \"../codes/header.hpp\"\n\nenum JudgeResult {/*{{{*/\n    AC = 0,\n\
    \    WA = 1,\n    RE = 2,\n    CE = 3,\n    TLE = -2,\n    MLE = 4,\n    QLE =\
    \ 5,  // Query limit exceeded\n    AIE = 6,  // Additional input error\n    NOEXP\
    \ = 98,\n    TLENAIVE = 99,\n    YET = 100,\n};/*}}}*/\n\ntemplate <class T>/*{{{*/\n\
    void tell(T x) {\n    cout << x << endl;\n    fflush(stdout);\n}/*}}}*/\n\nbool\
    \ check_AIE(){/*{{{*/\n    ll tmp;cin>>tmp;\n    if (cin.eof()==0) exit(AIE);\
    \  // check needles user-output does not exist\n}/*}}}*/\n\nint judge_case(ll\
    \ x) {\n    ll num = 22;  // TODO: update query number limit\n    while(num--){\n\
    \        string query;\n        cin >> query;\n        if (query==\"?\"){ // query\n\
    \            ll solver_ans;cin>>solver_ans;\n            tell(gcd(solver_ans,\
    \ x));\n        }\n        if (query==\"!\"){ // ans\n            ll solver_ans;cin>>solver_ans;\n\
    \            if (abs(solver_ans-x)<=7 || (solver_ans<=2*x && x<=2*solver_ans)){\n\
    \                return 0;\n            }\n            else{\n               \
    \ cerr << \"WA: \";\n                dump(x, solver_ans);\n                exit(WA);\n\
    \            }\n        }\n    }\n    exit(QLE);\n}\n\nint main() {\n    // input\
    \ case\n    int Q;\n    cin >> Q;\n    // Q = 1; if single case\n    vector<ll>\
    \ x(Q);\n    rep(q, Q){ cin>>x[q]; }\n\n    // judge\n    tell(Q);  // off if\
    \ single case\n    rep(q, Q) {\n        cerr << \"start judge for: \" << x[q]\
    \ << \" [judge]\" << endl;;\n        judge_case(x[q]); \n    }\n\n    // check_AIE();\
    \ // \u3053\u308C\u306F\u4F55\u6545\u304B\u52D5\u304B\u306A\u3044\u3002\u7121\u9650\
    \u5F85\u6A5F\u306B\u306A\u3063\u3066\u3057\u307E\u3046\u3002\n    exit(AC);\n\
    \    return 0;\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: problem_template/test/judge.cpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: problem_template/test/judge.cpp
layout: document
redirect_from:
- /library/problem_template/test/judge.cpp
- /library/problem_template/test/judge.cpp.html
title: problem_template/test/judge.cpp
---
