---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://pakapa104.hatenablog.com/entry/2016/02/09/230443
  bundledCode: "#line 1 \"library/cpp/math/int.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// {{{ gcd, lcm\n// %snippet.set('gcd')%\n// %snippet.config({'abbr':'great\
    \ common divisor', 'indent':True})%\nll gcd(ll a, ll b) {\n    if (b > a) swap(a,\
    \ b);\n    if (b == 0) return a;\n    return gcd(b, a % b);\n}\n// %snippet.end()%\
    \  \u660E\u793A\u7684\u306B\u7D42\u4E86\u3057\u305F\u3044\u5834\u5408\n\n// %snippet.set('lcm')%\n\
    // %snippet.include('gcd')%\nll lcm(ll a, ll b) {\n    return (a / gcd(a, b))\
    \ * b;  // overflow\u3057\u306B\u304F\u3044\u3088\u3046\u306B\u6700\u521D\u306B\
    \u5272\u308A\u7B97\u3092\u3059\u308B\u3002\n}\n// %snippet.end()%\n\n//}}}\n\n\
    //%snippet.set('reverse_int')%\n//%snippet.include('lcm')%  //\u518D\u5E30\u306E\
    \u30C6\u30B9\u30C8 {{{\nll reverse_int(ll number) {\n    ll reverse = 0;\n   \
    \ while (number > 0) {\n        reverse = reverse * 10 + number % 10;\n      \
    \  number /= 10;\n    }\n    return reverse;\n}\n// %snippet.end()% }}}\n\n//%snippet.set('digitSum')%\n\
    int digitSum(ll x) { /*{{{*/\n    int res = 0;\n    while (true) {\n        res\
    \ += x % 10;\n        x /= 10;\n        if (x == 0) {\n            break;\n  \
    \      }\n    }\n    return res;\n} /*}}}*/\n\n//%snippet.set('is_prime')%\nbool\
    \ is_prime(ll n) { /*{{{*/\n    for (ll i = 2; i * i <= n; i++) {\n        if\
    \ (n % i == 0) return false;\n    }\n    return n != 1;\n} /*}}}*/\n\n//%snippet.set('prime_factor')%\n\
    map<ll, ll> prime_factor(ll n) {  // \u7D20\u56E0\u6570\u5206\u89E3 (o(\u221A\
    N)){{{\n    map<ll, ll> res;  // vector\u3067\u6301\u3064\u3053\u3068\u3082\u8003\
    \u3048\u3089\u308C\u308B\u3002\n    for (ll i = 2; i * i <= n; i++) {\n      \
    \  while (n % i == 0) {\n            ++res[i];\n            n /= i;\n        }\n\
    \    }\n    if (n != 1) res[n] += 1;\n    return res;\n}\n// (\u53C2\u8003)http://pakapa104.hatenablog.com/entry/2016/02/09/230443\n\
    //}}}\n\n//%snippet.set('divisor')%\nvector<ll> divisor(ll n) {  // \u7D04\u6570\
    \u5168\u5217\u6319{{{\n    vector<ll> p, q;\n    for (ll i = 1; i * i <= n; i++)\
    \ {\n        if (n % i == 0) {\n            p.pb(i);\n            if (i * i !=\
    \ n) q.pb(n / i);\n        }\n    }\n    reverse(all(q));\n    p.insert(p.end(),\
    \ all(q));\n    return p;\n}  //}}}\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// {{{ gcd, lcm\n// %snippet.set('gcd')%\n\
    // %snippet.config({'abbr':'great common divisor', 'indent':True})%\nll gcd(ll\
    \ a, ll b) {\n    if (b > a) swap(a, b);\n    if (b == 0) return a;\n    return\
    \ gcd(b, a % b);\n}\n// %snippet.end()%  \u660E\u793A\u7684\u306B\u7D42\u4E86\u3057\
    \u305F\u3044\u5834\u5408\n\n// %snippet.set('lcm')%\n// %snippet.include('gcd')%\n\
    ll lcm(ll a, ll b) {\n    return (a / gcd(a, b)) * b;  // overflow\u3057\u306B\
    \u304F\u3044\u3088\u3046\u306B\u6700\u521D\u306B\u5272\u308A\u7B97\u3092\u3059\
    \u308B\u3002\n}\n// %snippet.end()%\n\n//}}}\n\n//%snippet.set('reverse_int')%\n\
    //%snippet.include('lcm')%  //\u518D\u5E30\u306E\u30C6\u30B9\u30C8 {{{\nll reverse_int(ll\
    \ number) {\n    ll reverse = 0;\n    while (number > 0) {\n        reverse =\
    \ reverse * 10 + number % 10;\n        number /= 10;\n    }\n    return reverse;\n\
    }\n// %snippet.end()% }}}\n\n//%snippet.set('digitSum')%\nint digitSum(ll x) {\
    \ /*{{{*/\n    int res = 0;\n    while (true) {\n        res += x % 10;\n    \
    \    x /= 10;\n        if (x == 0) {\n            break;\n        }\n    }\n \
    \   return res;\n} /*}}}*/\n\n//%snippet.set('is_prime')%\nbool is_prime(ll n)\
    \ { /*{{{*/\n    for (ll i = 2; i * i <= n; i++) {\n        if (n % i == 0) return\
    \ false;\n    }\n    return n != 1;\n} /*}}}*/\n\n//%snippet.set('prime_factor')%\n\
    map<ll, ll> prime_factor(ll n) {  // \u7D20\u56E0\u6570\u5206\u89E3 (o(\u221A\
    N)){{{\n    map<ll, ll> res;  // vector\u3067\u6301\u3064\u3053\u3068\u3082\u8003\
    \u3048\u3089\u308C\u308B\u3002\n    for (ll i = 2; i * i <= n; i++) {\n      \
    \  while (n % i == 0) {\n            ++res[i];\n            n /= i;\n        }\n\
    \    }\n    if (n != 1) res[n] += 1;\n    return res;\n}\n// (\u53C2\u8003)http://pakapa104.hatenablog.com/entry/2016/02/09/230443\n\
    //}}}\n\n//%snippet.set('divisor')%\nvector<ll> divisor(ll n) {  // \u7D04\u6570\
    \u5168\u5217\u6319{{{\n    vector<ll> p, q;\n    for (ll i = 1; i * i <= n; i++)\
    \ {\n        if (n % i == 0) {\n            p.pb(i);\n            if (i * i !=\
    \ n) q.pb(n / i);\n        }\n    }\n    reverse(all(q));\n    p.insert(p.end(),\
    \ all(q));\n    return p;\n}  //}}}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/math/int.cpp
  requiredBy: []
  timestamp: '2020-05-31 23:26:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/math/int.cpp
layout: document
redirect_from:
- /library/library/cpp/math/int.cpp
- /library/library/cpp/math/int.cpp.html
title: library/cpp/math/int.cpp
---
