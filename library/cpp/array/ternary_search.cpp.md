---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/array/ternary_search.cpp\"\n//%snippet.set('tsearch')%\n\
    ll l = 0;\nll r = 1000000001;\n\n// ll num = 100;\n// while(num--){\nwhile(r-l>2){\n\
    \    ll d = (r-l)/3;\n    ll ml = l + d;\n    ll mr = l + 2*d;\n    if ((score(ml)\
    \ < score(mr))){\n        r = mr;\n    }\n    else{\n        l = ml;\n    }\n\
    }\ndump(l, r);\nll ans = INF;\nrep(i, l, r+1) chmin(ans, score(i));\n"
  code: "//%snippet.set('tsearch')%\nll l = 0;\nll r = 1000000001;\n\n// ll num =\
    \ 100;\n// while(num--){\nwhile(r-l>2){\n    ll d = (r-l)/3;\n    ll ml = l +\
    \ d;\n    ll mr = l + 2*d;\n    if ((score(ml) < score(mr))){\n        r = mr;\n\
    \    }\n    else{\n        l = ml;\n    }\n}\ndump(l, r);\nll ans = INF;\nrep(i,\
    \ l, r+1) chmin(ans, score(i));\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/array/ternary_search.cpp
  requiredBy: []
  timestamp: '2020-05-18 01:47:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/ternary_search.cpp
layout: document
redirect_from:
- /library/library/cpp/array/ternary_search.cpp
- /library/library/cpp/array/ternary_search.cpp.html
title: library/cpp/array/ternary_search.cpp
---
