---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# ---- memo -----------------\n# \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
    \u30F3\u554F\u984C\n# ---------------------------\n\ndef tsp(d):\n    N = len(d)\
    \  # node num\n    dp = [[float('inf') for j in range(N)] for i in range(2**N)]\n\
    \n    V = (1<<N)-1\n    dp[V][0] = 0\n\n    for S in range(V-1, -1, -1):\n   \
    \ # S(i) <= S(j) => i <= j\u304C\u8A00\u3048\u308B\u306E\u3067\u3053\u306E\u9806\
    \u756A\u3067OK\u3002\u30EB\u30FC\u30D7\u306E\u9806\u5E8F\u304C\u6B63\u3057\u3044\
    \u81EA\u4FE1\u304C\u306A\u3051\u308C\u3070\u30E1\u30E2\u5316\u518D\u5E30\u3067\
    \u884C\u3048\u3070\u826F\u3044\u3002\n        for now in range(N):\n         \
    \   for new in range(N):\n                if (S >> new) & 1 != 0:\n          \
    \          continue\n                dp[S][now] = min(dp[S][now], dp[S + (1 <<\
    \ new)][new] + d[now][new])\n\n    return dp[0][0]\n\n\nif __name__ == '__main__':\n\
    \    inf = float('inf')\n    data = [ [inf, 3, inf, 4, inf],\n             [inf,\
    \ inf, 5, inf, inf],\n             [4, inf, inf, 5, inf],\n             [inf,\
    \ inf, inf, inf, 3],\n             [7, 6, inf, inf, inf]\n           ]\n    print(tsp(data))\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/tsp.py
  requiredBy: []
  timestamp: '2020-04-25 20:06:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/python/tsp.py
layout: document
redirect_from:
- /library/library/python/tsp.py
- /library/library/python/tsp.py.html
title: library/python/tsp.py
---
