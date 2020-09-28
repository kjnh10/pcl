---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/geometry/p2.hpp
    title: library/cpp/math/geometry/p2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc168/tasks/abc168_e
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
    #line 2 \"library/cpp/math/geometry/p2.hpp\"\n\n//%snippet.set('P2')%\n//%snippet.config({'alias':'pos'})%\n\
    //%snippet.config({'alias':'point'})%\n//%snippet.config({'alias':'pair'})%\n\n\
    template<class T=ll>/*{{{*/\nstruct P2 {\n    T x, y;\n    P2(T _x, T _y) : x(_x),\
    \ y(_y) {}\n    P2() {\n        x = 0;\n        y = 0;\n    }\n    bool operator<(const\
    \ P2 &r) const {\n        return (x != r.x ? x < r.x : y < r.y);\n    }\n    bool\
    \ operator>(const P2 &r) const {\n        return (x != r.x ? x > r.x : y > r.y);\n\
    \    }\n    bool operator==(const P2 &r) const { return (x == r.x && y == r.y);\
    \ }\n\n    friend ostream &operator<<(ostream &stream, P2 p) {\n        stream\
    \ << \"(\" << p.x << \",\" << p.y << \")\";\n        return stream;\n    }\n\n\
    \    P2 operator-() const {  // \u5358\u9805\u6F14\u7B97\u5B50\n        return\
    \ P2(-x, -y);\n    }\n\n    P2& operator+=(const P2<T>& r){\n        x += r.x;\n\
    \        y += r.y;\n        return *this;\n    }\n    P2& operator-=(const P2<T>&\
    \ r){\n        x -= r.x;\n        y -= r.y;\n        return *this;\n    }\n  \
    \  P2& operator+=(const T& r){\n        x += r;\n        y += r;\n        return\
    \ *this;\n    }\n    P2& operator-=(const T& r){\n        x -= r;\n        y -=\
    \ r;\n        return *this;\n    }\n    P2& operator*=(const P2<T>& r){\n    \
    \    x *= r.x;\n        y *= r.y;\n        return *this;\n    }\n    P2& operator/=(const\
    \ P2<T>& r){\n        x /= r.x;\n        y /= r.y;\n        return *this;\n  \
    \  }\n    P2& operator*=(const T& r){\n        x *= r;\n        y *= r;\n    \
    \    return *this;\n    }\n    P2& operator/=(const T& r){\n        x /= r;\n\
    \        y /= r;\n        return *this;\n    }\n\n    template<class U>\n    P2\
    \ operator+(const U& r) const {\n        P2 res(*this);\n        return res +=\
    \ r;\n    }\n    template<class U>\n    P2 operator-(const U& r) const {\n   \
    \     P2 res(*this);\n        return res -= r;\n    }\n\n    template<class U>\n\
    \    P2 operator*(const U& r) const {\n        P2 res(*this);\n        return\
    \ res *= r;\n    }\n    template<class U>\n    P2 operator/(const U& r) const\
    \ {\n        P2 res(*this);\n        return res /= r;\n    }\n\n\n    bool in(T\
    \ a, T b, T c, T d) {  // x in [a, b) && y in [c, d)\n        if (a <= x && x\
    \ < b && c <= y && y < d) return true;\n        else return false;\n    }\n\n\
    };\ntemplate<class T>\nlong double dist(const P2<T>& p, const P2<T>& q){\n   \
    \ return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));\n}\n\n/*}}}*/\n\
    using P = P2<ll>;\n\n//%snippet.end%\n#line 3 \"library/cpp/math/rational.hpp\"\
    \n\n//%snippet.set('rational')%\n//%snippet.config({'alias':'fraction'})%\n//%snippet.fold()%\n\
    \ntemplate<class T=ll> \nstruct rational : public P2<T> {\n    rational(){}\n\
    \    rational(T _x, T _y) : P2<T>(_x, _y) {\n        T g = gcd(this->x, this->y);\n\
    \        this->x /= g; this->y /= g;\n        if (this->y<0 or (this->y==0 &&\
    \ this->x==-1)) this->x *= -1, this->y *= -1;\n    }\n};\n// rational(3, 5);\n\
    // assert(rational(3, 5) == rational(-6, -10));\n// map<rational<ll>, int> cnt;\
    \  // key\u306B\u3082\u3067\u304D\u308B\u3002\n\n//%snippet.end()%\n\n// verified\
    \ by https://atcoder.jp/contests/abc168/tasks/abc168_e\n"
  code: "#include \"../header.hpp\"\n#include \"geometry/p2.hpp\"\n\n//%snippet.set('rational')%\n\
    //%snippet.config({'alias':'fraction'})%\n//%snippet.fold()%\n\ntemplate<class\
    \ T=ll> \nstruct rational : public P2<T> {\n    rational(){}\n    rational(T _x,\
    \ T _y) : P2<T>(_x, _y) {\n        T g = gcd(this->x, this->y);\n        this->x\
    \ /= g; this->y /= g;\n        if (this->y<0 or (this->y==0 && this->x==-1)) this->x\
    \ *= -1, this->y *= -1;\n    }\n};\n// rational(3, 5);\n// assert(rational(3,\
    \ 5) == rational(-6, -10));\n// map<rational<ll>, int> cnt;  // key\u306B\u3082\
    \u3067\u304D\u308B\u3002\n\n//%snippet.end()%\n\n// verified by https://atcoder.jp/contests/abc168/tasks/abc168_e\n"
  dependsOn:
  - library/cpp/header.hpp
  - library/cpp/math/geometry/p2.hpp
  isVerificationFile: false
  path: library/cpp/math/rational.hpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/math/rational.hpp
layout: document
redirect_from:
- /library/library/cpp/math/rational.hpp
- /library/library/cpp/math/rational.hpp.html
title: library/cpp/math/rational.hpp
---
