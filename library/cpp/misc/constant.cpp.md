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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/math/modint.hpp\"\
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
    \ \"library/cpp/misc/constant.cpp\"\n\nnamespace std {\n    template<> class numeric_limits<pair<int,\
    \ int>> {\n    public:\n        static pair<int, int> max() {return pair<int,\
    \ int>(100, 100);};\n    };\n    template<> class numeric_limits<mint> {\n   \
    \     public:\n        static mint max() { \n            mint res = 0;\n     \
    \       res.x = mod;\n            return res;\n        };\n    };\n}\n\ntemplate\
    \ <class T>\nT get_inf(){\n    T t; return t;\n}\n\ntemplate <>\npair<int, int>\
    \ get_inf(){\n    int inf = numeric_limits<int>().max();\n    return make_pair(inf,\
    \ inf);\n}\n\nint main(){\n    dump(get_inf<pair<int, int>>());\n}\n"
  code: "#include \"../header.hpp\"\n#include \"../math/modint.hpp\"\n\nnamespace\
    \ std {\n    template<> class numeric_limits<pair<int, int>> {\n    public:\n\
    \        static pair<int, int> max() {return pair<int, int>(100, 100);};\n   \
    \ };\n    template<> class numeric_limits<mint> {\n        public:\n        static\
    \ mint max() { \n            mint res = 0;\n            res.x = mod;\n       \
    \     return res;\n        };\n    };\n}\n\ntemplate <class T>\nT get_inf(){\n\
    \    T t; return t;\n}\n\ntemplate <>\npair<int, int> get_inf(){\n    int inf\
    \ = numeric_limits<int>().max();\n    return make_pair(inf, inf);\n}\n\nint main(){\n\
    \    dump(get_inf<pair<int, int>>());\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  - library/cpp/math/modint.hpp
  isVerificationFile: false
  path: library/cpp/misc/constant.cpp
  requiredBy: []
  timestamp: '2020-11-26 16:25:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/misc/constant.cpp
layout: document
redirect_from:
- /library/library/cpp/misc/constant.cpp
- /library/library/cpp/misc/constant.cpp.html
title: library/cpp/misc/constant.cpp
---
