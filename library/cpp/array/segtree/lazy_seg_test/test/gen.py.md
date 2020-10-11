---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from random import choice, sample, choices\nfrom random import randint as\
    \ rint\nfrom typing import TYPE_CHECKING, List, Optional, Type\nimport string\n\
    import math\n# print(choice(a))  # 1\u3064\u9078\u629E\n# print(sample(a, k=2))\
    \  # \u975E\u5FA9\u5143\u62BD\u51FA\n# print(sample(a, k=len(L)))  # random permutation\n\
    # print(choices(a, k=2))  # \u5FA9\u5143\u62BD\u51FA\n\nclass UnionFind():\n \
    \   def __init__(self, n):\n        self.n = n\n        self.parents = [-1] *\
    \ n\n\n    def find(self, x):\n        if self.parents[x] < 0:\n            return\
    \ x\n        else:\n            self.parents[x] = self.find(self.parents[x])\n\
    \            return self.parents[x]\n\n    def union(self, x, y):\n        x =\
    \ self.find(x)\n        y = self.find(y)\n\n        if x == y:\n            return\n\
    \n        if self.parents[x] > self.parents[y]:\n            x, y = y, x\n\n \
    \       self.parents[x] += self.parents[y]\n        self.parents[y] = x\n\n  \
    \  def size(self, x):\n        return -self.parents[self.find(x)]\n\n    def same(self,\
    \ x, y):\n        return self.find(x) == self.find(y)\n\n    def members(self,\
    \ x):\n        root = self.find(x)\n        return [i for i in range(self.n) if\
    \ self.find(i) == root]\n\n    def roots(self):\n        return [i for i, x in\
    \ enumerate(self.parents) if x < 0]\n\n    def group_count(self):\n        return\
    \ len(self.roots())\n\n    def all_group_members(self):\n        return {r: self.members(r)\
    \ for r in self.roots()}\n\n    def __str__(self):\n        return '\\n'.join('{}:\
    \ {}'.format(r, self.members(r)) for r in self.roots())\n\nclass rperm(object):\n\
    \    def __init__(self, n:int):\n        self.data = sample(list(range(1, n+1)),\
    \ k=n)\n    def __str__(self):\n        return ' '.join(map(str, self.data))\n\
    \nclass rseq(object):\n    def __init__(self, n: int, l: int, r: int, distinct=False):\n\
    \        self.data = []\n        used = set()\n        if (n>r-l+1) and distinct:\n\
    \            raise Exception(print(\"n>r-l+1 and distinct=True is not impossible\"\
    ))\n\n        while len(self.data) < n:\n            v = rint(l, r)\n        \
    \    if distinct and v in used:\n                pass\n            else:\n   \
    \             self.data.append(v)\n                used.add(v)\n\n    def __str__(self):\n\
    \        return ' '.join(map(str, self.data))\n\ndef rstr(length: int, chars:\
    \ List=['a', 'b', 'c', 'd', 'e']):\n# def rstr(length: int, chars: List=string.ascii_lowercase):\n\
    \    res = \"\"\n    for i in range(length):\n        res += choice(chars)\n \
    \   return res\n\ndef rprime(l: int = 2, r: int = 1000000007): # [l, r]\n    def\
    \ is_prime(x):\n        if (x == 1): return False\n        for i in range(2, int(math.sqrt(x))+1):\n\
    \            if x % i == 0:\n                return False\n        return True\n\
    \n\n    cnt = 0\n    while True:\n        res = rint(l, r)\n        if (is_prime(res)):\n\
    \            return res\n        cnt += 1\n        if cnt>=1000:\n           \
    \ assert False\n\nclass rtree(object):\n    def __init__(self, n: int, root: int\
    \ = 0):\n        assert root < n\n        self.edges = []\n        self.n = n\n\
    \        s = set([x for x in range(n) if x!=root])\n        joined = [root]\n\
    \        self.edges = []\n        for _ in range(n-1):\n            a = sample(s,\
    \ 1)[0]\n            b = choice(joined)\n            self.edges.append((b, a))\
    \  # \u3053\u306E\u5411\u304D\u306B\u3059\u308B\u3068graphviz\u306E\u8868\u793A\
    \u304C\u6728\u3089\u3057\u304F\u306A\u308B\u3002\n            s.remove(a)\n  \
    \          joined.append(a)\n\n    def __str__(self, one_index=True, header=False):\n\
    \        res = []\n        if header:\n            res.append(f\"{self.n} {self.n-1}\"\
    )\n\n        for edge in self.edges:\n            res.append(f\"{edge[0]+one_index}\
    \ {edge[1]+one_index}\")\n        return '\\n'.join(res)\n\nclass rgraph(object):\
    \  # undirected\n    def __init__(self, n:int, lb:int=1, ub:int=float('inf'),\
    \ tree_ok=True):\n        self.n = n\n        if ub == float('inf'):\n       \
    \     ub = n*(n-1)/2\n\n        while True:\n            if tree_ok:  # tree graph\n\
    \                # 10%\u304F\u3089\u3044\u306F\u6728\u304C\u751F\u6210\u3055\u308C\
    \u308B\u3088\u3046\u306B\n                r = rint(1, 10)\n                if\
    \ (r<=2):\n                    self.edges = rtree(n).edges\n                 \
    \   return\n\n            # TODO: [line graph, star graph, complete graph]\n\n\
    \            uf = UnionFind(n)\n            self.edges = set()\n            while(uf.group_count()>1\
    \ or len(self.edges)<lb):\n                u = rint(0, n-1)\n                v\
    \ = rint(0, n-1)\n                if (u==v): continue\n\n                if (u>v):\
    \ u,v=v,u\n                self.edges.add((u, v))\n                uf.union(u,\
    \ v)\n            self.edges = list(self.edges)\n            if len(self.edges)\
    \ <= ub:\n                return\n\n    def __str__(self, one_index=True, header=True):\n\
    \        res = []\n        if header:\n            res.append(f\"{self.n} {len(self.edges)}\"\
    )\n        for edge in self.edges:\n            res.append(f\"{edge[0]+one_index}\
    \ {edge[1]+one_index}\")\n        return '\\n'.join(res)\n\n# write down here\n\
    # ---------------------------------------------\n# n = rint(10, 20)\nn, Q = 101,\
    \ 101\nprint(n, Q)\nfor _ in range(Q):\n    ty = rint(1, 4)\n    if (ty == 1):\n\
    \        # range add\n        l = rint(0, n-1)\n        r = rint(l+1, n)\n   \
    \     x = rint(0, 10)\n        print(1, l, r, x)\n    if (ty == 2):\n        #\
    \ range query\n        l = rint(0, n-1)\n        r = rint(l+1, n)\n        print(2,\
    \ l, r)\n    if (ty == 3):\n        # binary search\n        # \u53F3\n      \
    \  i = rint(0, n-1)\n        x = rint(-10, 1000)\n        print(3, i, x)\n   \
    \ if (ty == 4):\n        # binary search\n        # left\n        i = rint(0,\
    \ n-1)\n        x = rint(-10, 1000)\n        print(4, i, x)\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/array/segtree/lazy_seg_test/test/gen.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/segtree/lazy_seg_test/test/gen.py
layout: document
redirect_from:
- /library/library/cpp/array/segtree/lazy_seg_test/test/gen.py
- /library/library/cpp/array/segtree/lazy_seg_test/test/gen.py.html
title: library/cpp/array/segtree/lazy_seg_test/test/gen.py
---
