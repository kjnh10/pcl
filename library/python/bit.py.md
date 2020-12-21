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
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# %snippet.set('bit1')%\n# Binary Indexd Tree\nclass BIT():\n    def __init__(self,\
    \ N):\n        self.data = [0]*(N+1)  # 1-indexed, 0 not used\n\n    def sum(self,\
    \ n):\n        s = 0\n        while n > 0:\n            s += self.data[n]\n  \
    \          n -= (n & -n)\n        return s\n\n    def add(self, n, x):\n     \
    \   while n <= N:\n            self.data[n] += x\n            n += (n & -n)\n\
    # %snippet.end%\n\n\n# test\n# \u30D0\u30D6\u30EB\u30BD\u30FC\u30C8\u306E\u4EA4\
    \u63DB\u56DE\u6570\nN = 5\nA = [3,5,2,1,4]\nbit = BIT(N)\nninv = 0\nfor i in range(N):\n\
    \    ninv += bit.sum(A[i])\n    bit.add(A[i], 1)\n\nans = N*(N-1)//2 - ninv\n\
    assert(ans==6)\n\nprint('success')\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/bit.py
  requiredBy: []
  timestamp: '2020-04-25 20:06:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/python/bit.py
layout: document
redirect_from:
- /library/library/python/bit.py
- /library/library/python/bit.py.html
title: library/python/bit.py
---
