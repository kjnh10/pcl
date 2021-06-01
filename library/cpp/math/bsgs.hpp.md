---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/modint.hpp
    title: library/cpp/math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
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
    #endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/math/modint.hpp\"\
    \n\n//%snippet.set('modint')%\n//%snippet.config({'alias':'mint'})%\nconst int\
    \ mod = 1e9 + 7;\n// const int mod = 998244353;\nstruct modint {  //{{{\n    ll\
    \ x;\n    modint(ll x = 0) : x((x % mod + mod) % mod) {}\n\n    // ?= operator\n\
    \    modint& operator+=(const modint a) {\n        (x += a.x) %= mod;\n      \
    \  return *this;\n    }\n    modint& operator-=(const modint a) {\n        (x\
    \ += mod - a.x) %= mod;\n        return *this;\n    }\n    modint& operator*=(const\
    \ modint a) {\n        (x *= a.x) %= mod;\n        return *this;\n    }\n    modint&\
    \ operator/=(const modint& rhs) {\n        if (rhs.x == 0) throw runtime_error(\"\
    modint zero division\");\n        return *this *= rhs.inv();\n    }\n\n    modint\
    \ operator+(const modint a) const {\n        modint res(*this);\n        return\
    \ res += a;\n    }\n    modint operator-(const modint a) const {\n        modint\
    \ res(*this);\n        return res -= a;\n    }\n    modint operator*(const modint\
    \ a) const {\n        modint res(*this);\n        return res *= a;\n    }\n  \
    \  modint operator/(const modint a) const {\n        modint res(*this);\n    \
    \    return res /= a;\n    }\n\n    modint pow(ll n) const {\n        modint res(1),\
    \ x(*this);\n        if (n < 0) {\n            n = -n;\n            x = (*this).inv();\n\
    \        }\n        while (n) {\n            if (n & 1) res *= x;\n          \
    \  x *= x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n  \
    \  modint inv() const {\n        if (x == 0) throw runtime_error(\"inv does not\
    \ exist\");\n        return pow(mod - 2);\n    }\n    // modint inv()const{\n\
    \    //     int x,y;\n    //     int g=extgcd(v,mod,x,y);\n    //     assert(g==1);\n\
    \    //     if(x<0)x+=mod;\n    //     return modint(x);\n    // }\n\n    bool\
    \ operator<(const modint& r) const { return x < r.x; }\n    bool operator==(const\
    \ modint& r) const { return x == r.x; }\n};\nistream& operator>>(istream& is,\
    \ const modint& a) { return is >> a.x; }\nostream& operator<<(ostream& os, const\
    \ modint& a) { return os << a.x; }\nstring to_string_mod(const modint& x){ return\
    \ to_string(x.x); }\n//}}}\nusing mint = modint;\n\n//%snippet.end()%\n#line 3\
    \ \"library/cpp/math/bsgs.hpp\"\n\n// %snippet.set('baybe_step_giant_step')%\n\
    // %snippet.config({'alias':'bsgs'})%\n// %snippet.include('modint')%\n\nint bsgs(int\
    \ a, int b) {  //{{{\n    if (b >= mod) return -1;\n\n    // find x s.t a^x =\
    \ b in (mod)\n    int h = sqrt(mod);\n    // x = p*h + r  (0<=r<h and 0<=p<=h)\n\
    \n    unordered_map<int, int> minr;  // minr[v]: min(r s.t a^r=v)\n    mint ar\
    \ = 1;  // a^r\n    rep(r, 0, h) {\n        if (minr.find(ar.x) == minr.end())\
    \ minr[ar.x] = r;\n        ar *= a;\n    }\n\n    mint A = mint(a).pow(-h);\n\
    \    rep(p, 0, h + 1) {\n        int Ab = (A.pow(p) * b).x;\n        if (minr.find(Ab)\
    \ != minr.end()) {\n            int r = minr[Ab];\n            return p * h +\
    \ r;\n        }\n    }\n\n    return -1;\n}  //}}}\n\n// %snippet.end()%\n\n\n\
    // %snippet.set('generalized_baybe_step_giant_step')%\n// %snippet.config({'alias':'gbsgs'})%\n\
    // %snippet.include('modint')%\n\nint gbsgs(int a, int b) {  //{{{\n    // find\
    \ x s.t a^x = b in (mod: prime\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\
    )\n\n    if (b >= mod) return -1;\n    if (1 % mod == b) return 0;\n\n    int\
    \ h = (int)sqrt(mod) + 1;  // h s.t x = p*h-r (0<=r<h and 0<=p<=h)\n\n    unordered_map<int,\
    \ vector<int>> rs;  // rs[v]: vector of r s.t b*a^r==v\n    mint bar = b;  //\
    \ b*a^r\n    rep(r, 0, h) {\n        rs[bar.x].pb(r);\n        bar *= a;\n   \
    \ }\n    bool looped = false;\n    each(el, rs) if (sz(el.second) > 1) looped\
    \ = true;\n\n    mint ah = mint(a).pow(h);\n    rep(p, 1, h + 1) {\n        int\
    \ aph = ah.pow(p).x;\n        if (rs.find(aph) != rs.end()) {\n            reverse(all(rs[aph]));\n\
    \            each(r, rs[aph]) {\n                if (mint(a).pow(p * h - r) ==\
    \ b){\n                    // a^(p*h-r) == b in (mod) => a^(ph) == b*a^r\u3060\
    \u304C\u9006\u306F\u6210\u308A\u7ACB\u305F\u306A\u3044\u306E\u3067\u3053\u306E\
    \u78BA\u8A8D\u304C\u5FC5\u8981\n                    return p * h - r;\n      \
    \          }\n            }\n        }\n        // sz(rs[aph]) > 0\u306E\u5834\
    \u5408\u306Fbreak\u3059\u308B\u306E\u3067\u8A08\u7B97\u91CF\u3082\u5927\u4E08\u592B\
    \n        if (looped) return -1;\n    }\n\n    return -1;\n}  //}}}\n\n// %snippet.end()%\n"
  code: "#include \"../header.hpp\"\n#include \"modint.hpp\"\n\n// %snippet.set('baybe_step_giant_step')%\n\
    // %snippet.config({'alias':'bsgs'})%\n// %snippet.include('modint')%\n\nint bsgs(int\
    \ a, int b) {  //{{{\n    if (b >= mod) return -1;\n\n    // find x s.t a^x =\
    \ b in (mod)\n    int h = sqrt(mod);\n    // x = p*h + r  (0<=r<h and 0<=p<=h)\n\
    \n    unordered_map<int, int> minr;  // minr[v]: min(r s.t a^r=v)\n    mint ar\
    \ = 1;  // a^r\n    rep(r, 0, h) {\n        if (minr.find(ar.x) == minr.end())\
    \ minr[ar.x] = r;\n        ar *= a;\n    }\n\n    mint A = mint(a).pow(-h);\n\
    \    rep(p, 0, h + 1) {\n        int Ab = (A.pow(p) * b).x;\n        if (minr.find(Ab)\
    \ != minr.end()) {\n            int r = minr[Ab];\n            return p * h +\
    \ r;\n        }\n    }\n\n    return -1;\n}  //}}}\n\n// %snippet.end()%\n\n\n\
    // %snippet.set('generalized_baybe_step_giant_step')%\n// %snippet.config({'alias':'gbsgs'})%\n\
    // %snippet.include('modint')%\n\nint gbsgs(int a, int b) {  //{{{\n    // find\
    \ x s.t a^x = b in (mod: prime\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\
    )\n\n    if (b >= mod) return -1;\n    if (1 % mod == b) return 0;\n\n    int\
    \ h = (int)sqrt(mod) + 1;  // h s.t x = p*h-r (0<=r<h and 0<=p<=h)\n\n    unordered_map<int,\
    \ vector<int>> rs;  // rs[v]: vector of r s.t b*a^r==v\n    mint bar = b;  //\
    \ b*a^r\n    rep(r, 0, h) {\n        rs[bar.x].pb(r);\n        bar *= a;\n   \
    \ }\n    bool looped = false;\n    each(el, rs) if (sz(el.second) > 1) looped\
    \ = true;\n\n    mint ah = mint(a).pow(h);\n    rep(p, 1, h + 1) {\n        int\
    \ aph = ah.pow(p).x;\n        if (rs.find(aph) != rs.end()) {\n            reverse(all(rs[aph]));\n\
    \            each(r, rs[aph]) {\n                if (mint(a).pow(p * h - r) ==\
    \ b){\n                    // a^(p*h-r) == b in (mod) => a^(ph) == b*a^r\u3060\
    \u304C\u9006\u306F\u6210\u308A\u7ACB\u305F\u306A\u3044\u306E\u3067\u3053\u306E\
    \u78BA\u8A8D\u304C\u5FC5\u8981\n                    return p * h - r;\n      \
    \          }\n            }\n        }\n        // sz(rs[aph]) > 0\u306E\u5834\
    \u5408\u306Fbreak\u3059\u308B\u306E\u3067\u8A08\u7B97\u91CF\u3082\u5927\u4E08\u592B\
    \n        if (looped) return -1;\n    }\n\n    return -1;\n}  //}}}\n\n// %snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  - library/cpp/math/modint.hpp
  isVerificationFile: false
  path: library/cpp/math/bsgs.hpp
  requiredBy: []
  timestamp: '2021-05-31 23:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/math/bsgs.hpp
layout: document
redirect_from:
- /library/library/cpp/math/bsgs.hpp
- /library/library/cpp/math/bsgs.hpp.html
title: library/cpp/math/bsgs.hpp
---
