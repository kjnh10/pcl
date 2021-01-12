---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':warning:'
    path: library/cpp/math/geometry/angle.hpp
    title: library/cpp/math/geometry/angle.hpp
  - icon: ':question:'
    path: library/cpp/math/geometry/p2.hpp
    title: library/cpp/math/geometry/p2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/math/geometry/p2.hpp\"\
    \n\n//%snippet.set('P2')%\n//%snippet.config({'alias':'pos'})%\n//%snippet.config({'alias':'point'})%\n\
    //%snippet.config({'alias':'pair'})%\n//%snippet.fold()%\n\ntemplate<class T=ll>/*{{{*/\n\
    struct P2 {\n    T x, y;\n    P2(T _x, T _y) : x(_x), y(_y) {}\n    P2() {\n \
    \       x = 0;\n        y = 0;\n    }\n    bool operator<(const P2 &r) const {\n\
    \        return (x != r.x ? x < r.x : y < r.y);\n    }\n    bool operator>(const\
    \ P2 &r) const {\n        return (x != r.x ? x > r.x : y > r.y);\n    }\n    bool\
    \ operator==(const P2 &r) const { return (x == r.x && y == r.y); }\n\n    friend\
    \ ostream &operator<<(ostream &stream, P2 p) {\n        stream << \"(\" << p.x\
    \ << \",\" << p.y << \")\";\n        return stream;\n    }\n\n    P2 operator-()\
    \ const {  // \u5358\u9805\u6F14\u7B97\u5B50\n        return P2(-x, -y);\n   \
    \ }\n\n    P2& operator+=(const P2<T>& r){\n        x += r.x;\n        y += r.y;\n\
    \        return *this;\n    }\n    P2& operator-=(const P2<T>& r){\n        x\
    \ -= r.x;\n        y -= r.y;\n        return *this;\n    }\n    P2& operator+=(const\
    \ T& r){\n        x += r;\n        y += r;\n        return *this;\n    }\n   \
    \ P2& operator-=(const T& r){\n        x -= r;\n        y -= r;\n        return\
    \ *this;\n    }\n    P2& operator*=(const P2<T>& r){\n        x *= r.x;\n    \
    \    y *= r.y;\n        return *this;\n    }\n    P2& operator/=(const P2<T>&\
    \ r){\n        x /= r.x;\n        y /= r.y;\n        return *this;\n    }\n  \
    \  P2& operator*=(const T& r){\n        x *= r;\n        y *= r;\n        return\
    \ *this;\n    }\n    P2& operator/=(const T& r){\n        x /= r;\n        y /=\
    \ r;\n        return *this;\n    }\n\n    template<class U>\n    P2 operator+(const\
    \ U& r) const {\n        P2 res(*this);\n        return res += r;\n    }\n   \
    \ template<class U>\n    P2 operator-(const U& r) const {\n        P2 res(*this);\n\
    \        return res -= r;\n    }\n\n    template<class U>\n    P2 operator*(const\
    \ U& r) const {\n        P2 res(*this);\n        return res *= r;\n    }\n   \
    \ template<class U>\n    P2 operator/(const U& r) const {\n        P2 res(*this);\n\
    \        return res /= r;\n    }\n\n\n    bool in(T a, T b, T c, T d) {  // x\
    \ in [a, b) && y in [c, d)\n        if (a <= x && x < b && c <= y && y < d) return\
    \ true;\n        else return false;\n    }\n\n};\ntemplate<class T>\nlong double\
    \ dist(const P2<T>& p, const P2<T>& q){\n    return sqrt((p.x - q.x) * (p.x -\
    \ q.x) + (p.y - q.y) * (p.y - q.y));\n}\n\n/*}}}*/\nusing P = P2<ll>;\n\n//%snippet.end%\n\
    #line 3 \"library/cpp/math/geometry/angle.hpp\"\n\n//%snippet.set('angle')%\n\
    //%snippet.config({'alias':'argment_sort'})%\n//%snippet.fold()%\n\nstruct Angle{\n\
    \    ll x, y; // \u5B9F\u969B\u306B\u306F10^9\u304F\u3089\u3044\u307E\u3067\u3057\
    \u304B\u5165\u308C\u3089\u308C\u306A\u3044\u3002operator<\u3067\u5916\u7A4D\u3092\
    \u8A08\u7B97\u3059\u308B\u306E\u3067\u3002\n    int _orthant;  // \u8C61\u9650\
    \n    Angle(){};\n    Angle(ll _x, ll _y): x(_x), y(_y){\n        assert(x !=\
    \ 0 || y != 0);\n        ll g = gcd(abs(x), abs(y));\n        x /= g;\n      \
    \  y /= g;\n        if(y >= 0) _orthant = (x >= 0 ? 0 : 1);\n        else _orthant\
    \ = (x >= 0 ? 3 : 2);\n    }\n\n    bool operator<(const Angle &r) const {  //\
    \ for argment_sort\n        // [0, 2*pi)\u3067\u9806\u5E8F\u4ED8\u3051\u3089\u308C\
    \u308B\n        return (_orthant != r._orthant ? _orthant < r._orthant : x * r.y\
    \ - y * r.x > 0);\n    }\n\n    bool operator==(const Angle &r) const { return\
    \ (x == r.x && y == r.y); }\n\n    long double operator-(const Angle& r) const\
    \ {\n        // r\u3092\u8D77\u70B9\u306B\u898B\u3066\u4F55\u5EA6\u9032\u3093\u3067\
    \u3044\u308B\u304Bradian\u3067\u8FD4\u3059\n        return rad() - r.rad();\n\
    \    }\n\n    long double rad() const {\n        long double r = atan2(y, x);\
    \ \n        return (r<0 ? (r + M_PI*2.0) : r);\n    }\n    long double const deg(){\
    \ return rad() * 180.0/ M_PI; }\n\n    Angle rot_90() const { return Angle(-y,\
    \ x); }\n\n    Angle rot_r90() const { return Angle(y, -x); }\n\n    friend ostream\
    \ &operator<<(ostream &stream, Angle p) {\n        stream << \"(\" << p.x << \"\
    ,\" << p.y << \"):\" << p.deg() << \"\xB0\";\n        return stream;\n    }\n\
    };\n\n//%snippet.end%\n\n// from: https://betrue12.hateblo.jp/entry/2020/01/05/151244\n\
    #line 2 \"library/cpp/include/angle.hpp\"\n"
  code: '#include "../math/geometry/angle.hpp"'
  dependsOn:
  - library/cpp/math/geometry/angle.hpp
  - library/cpp/math/geometry/p2.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/angle.hpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/angle.hpp
layout: document
redirect_from:
- /library/library/cpp/include/angle.hpp
- /library/library/cpp/include/angle.hpp.html
title: library/cpp/include/angle.hpp
---
