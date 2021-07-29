---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/cpp/array/myvec.hpp
    title: library/cpp/array/myvec.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
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
    #endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/array/myvec.hpp\"\
    \n\n//%snippet.set('pyvec')%\n//%snippet.config({'alias':'vector_neg'})%\n//%snippet.fold()%\n\
    template <class T>\nstruct pyvec {\n    vector<T> v;\n    pyvec(){}\n    pyvec(int\
    \ n_){ v = vector<T>(n_); }\n    pyvec(int n_, T x){ v = vector<T>(n_, x); }\n\
    \    T& operator[](int i){\n        if (i>=0) return v[i];\n        else return\
    \ v[(int)v.size()+i];\n    }\n    auto begin(){ return v.begin(); }\n    auto\
    \ end(){ return v.end(); }\n    auto push_back(){ return v.push_back(); }\n  \
    \  auto emplace_back(){ return v.emplace_back(); }\n    auto size() const { return\
    \ v.size(); }\n    auto clear() { v.clear(); }\n    auto resize(int x) { v.resize(x);\
    \ }\n    auto back() {this[-1];}\n};\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const pyvec<T>& a) {\n    os << a.v; return os; \n}\ntemplate<class T=ll>\
    \ using vec = pyvec<T>;\n//%snippet.end()%\n\n\n//%snippet.set('asvector')%\n\
    //%snippet.fold()%\n// acumulative sum vector \ntemplate<typename T=ll>\nstruct\
    \ asvector {\n    vector<T> v; //accumulative sum\n    vector<T> cum; //accumulative\
    \ sum\n    bool is_build = false;\n    asvector(){};\n    asvector(int n_){ v\
    \ = vector<T>(n_); }\n    asvector(int n_, T x){ v = vector<T>(n_, x); }\n   \
    \ asvector(vector<T> a){ v  = a;}\n    T& operator[](int i){\n        if (i>=0)\
    \ return v[i];\n        else return v[(int)v.size()+i];\n    }\n    auto begin(){\
    \ return v.begin(); }\n    auto end(){ return v.end(); }\n    auto push_back(){\
    \ return v.push_back(); }\n    auto emplace_back(){ return v.emplace_back(); }\n\
    \    auto size() const { return v.size(); }\n    auto clear() { v.clear(); }\n\
    \    auto resize(int x) { v.resize(x); }\n    auto back() {this[-1];}\n\n    void\
    \ build() {\n        is_build = true;\n        cum = vector<T>(v);\n        rep(i,\
    \ 1, sz(v)) cum[i]+=cum[i-1];\n    }\n\n    T sum(int l, int r) {  // return sum\
    \ of [l, r) of data.  {{{\n        if (!is_build) build();\n        l = max(0,\
    \ l);\n        r = min(r, sz(cum));\n        if (l<r) return cum[r-1] - (l-1>=0\
    \ ? cum[l-1] : 0);\n        else     return 0;\n    } // }}}\n\n    friend ostream&\
    \ operator<<(ostream &os, asvector<T>& as){//{{{\n        os << as.v; return os;\n\
    \    } //}}}\n};\n//\n\n\n// TODO\n// neg shifter vec\n#line 2 \"library/cpp/include/myvec.hpp\"\
    \n"
  code: '#include "../array/myvec.hpp"'
  dependsOn:
  - library/cpp/array/myvec.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/myvec.hpp
  requiredBy: []
  timestamp: '2021-07-29 23:23:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/myvec.hpp
layout: document
redirect_from:
- /library/library/cpp/include/myvec.hpp
- /library/library/cpp/include/myvec.hpp.html
title: library/cpp/include/myvec.hpp
---
