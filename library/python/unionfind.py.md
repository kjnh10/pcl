---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class UnionFind():\n    #\u8CA0\u306E\u5024\u306F\u30EB\u30FC\u30C8\u3067\
    \u96C6\u5408\u306E\u500B\u6570\n    #\u6B63\u306E\u5024\u306F\u6B21\u306E\u8981\
    \u7D20\u3092\u8FD4\u3059\n    def __init__(self,size):\n        self.table = [-1\
    \ for _  in range(size)]\n\n    #\u96C6\u5408\u306E\u4EE3\u8868\u3092\u6C42\u3081\
    \u308B\n    def root(self, x):\n        while self.table[x] >= 0:\n          \
    \  #\u6839\u306B\u6765\u305F\u6642,self.table[\u6839\u306Eindex]\u306F\u8CA0\u306E\
    \u5024\u306A\u306E\u3067x = \u6839\u306Eindex\u3067\u5024\u304C\u8FD4\u3055\u308C\
    \u308B\u3002\n            x = self.table[x]\n        return x\n\n    #\u4F75\u5408\
    \n    def connect(self,x,y):\n        s1 = self.find(x)#\u6839\u306Eindex,table[s1]\u304C\
    \u30B0\u30E9\u30D5\u306E\u9AD8\u3055\n        s2 = self.find(y)\n        if s1\
    \ != s2:#\u6839\u304C\u7570\u306A\u308B\u5834\u5408\n            if self.table[s1]\
    \ != self.table[s2]:#\u30B0\u30E9\u30D5\u306E\u9AD8\u3055\u304C\u7570\u306A\u308B\
    \u5834\u5408\n                if self.table[s1] < self.table[s2]:\n          \
    \          self.table[s2] = s1\n                else:\n                    self.table[s1]\
    \ = s2\n            else:\n                #\u30B0\u30E9\u30D5\u306E\u9577\u3055\
    \u304C\u540C\u3058\u5834\u5408,\u3069\u3061\u3089\u3092\u6839\u306B\u3057\u3066\
    \u3082\u5909\u308F\u3089\u306A\u3044\n                #\u305D\u306E\u969B,\u30B0\
    \u30E9\u30D5\u304C1\u9577\u304F\u306A\u308B\u3053\u3068\u3092\u8003\u616E\u3059\
    \u308B\n                self.table[s1] += -1\n                self.table[s2] =\
    \ s1\n        return\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/unionfind.py
  requiredBy: []
  timestamp: '2020-04-25 20:06:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/python/unionfind.py
layout: document
redirect_from:
- /library/library/python/unionfind.py
- /library/library/python/unionfind.py.html
title: library/python/unionfind.py
---
