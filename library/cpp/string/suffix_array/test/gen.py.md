---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from random import randint, choice, sample, choices\nfrom typing import TYPE_CHECKING,\
    \ List, Optional, Type\nimport string\nclass UnionFind():\n    def __init__(self,\
    \ n):\n        self.n = n\n        self.parents = [-1] * n\n\n    def find(self,\
    \ x):\n        if self.parents[x] < 0:\n            return x\n        else:\n\
    \            self.parents[x] = self.find(self.parents[x])\n            return\
    \ self.parents[x]\n\n    def union(self, x, y):\n        x = self.find(x)\n  \
    \      y = self.find(y)\n\n        if x == y:\n            return\n\n        if\
    \ self.parents[x] > self.parents[y]:\n            x, y = y, x\n\n        self.parents[x]\
    \ += self.parents[y]\n        self.parents[y] = x\n\n    def size(self, x):\n\
    \        return -self.parents[self.find(x)]\n\n    def same(self, x, y):\n   \
    \     return self.find(x) == self.find(y)\n\n    def members(self, x):\n     \
    \   root = self.find(x)\n        return [i for i in range(self.n) if self.find(i)\
    \ == root]\n\n    def roots(self):\n        return [i for i, x in enumerate(self.parents)\
    \ if x < 0]\n\n    def group_count(self):\n        return len(self.roots())\n\n\
    \    def all_group_members(self):\n        return {r: self.members(r) for r in\
    \ self.roots()}\n\n    def __str__(self):\n        return '\\n'.join('{}: {}'.format(r,\
    \ self.members(r)) for r in self.roots())\n\na = [3, 5, 7, 9]\n# print(randint(1,\
    \ 100))  # # [1, 100]\n# print(choice(a))  # 1\u3064\u9078\u629E\n# print(sample(a,\
    \ k=2))  # \u975E\u5FA9\u5143\u62BD\u51FA\n# print(sample(a, k=len(L)))  # random\
    \ permutation\n# print(choices(a, k=2))  # \u5FA9\u5143\u62BD\u51FA\ndef randperm(n:\
    \ int):\n    return sample(list(range(1, n+1)), k=n)\ndef randseq(n: int, l: int,\
    \ r: int, distinct=False):\n    res = []\n    used = set()\n    if (n>r-l+1) and\
    \ distinct:\n        raise Exception(print(\"n>r-l+1 and distinct=True is not\
    \ impossible\"))\n\n    while len(res) < n:\n        v = randint(l, r)\n     \
    \   if distinct and v in used:\n            pass\n        else:\n            res.append(v)\n\
    \            used.add(v)\n    return res\ndef randstr(length: int, chars: List=['a',\
    \ 'b', 'c', 'd', 'e']):\n# def randstr(length: int, chars: List=string.ascii_lowercase):\n\
    \    res = \"\"\n    for i in range(length):\n        res += choice(chars)\n \
    \   return res\n\ndef print_tree(n: int, one_index=True, header=False):\n    if\
    \ header: print(n, n-1)\n\n    s = set(range(1, n))\n    joined = [0]\n    edges\
    \ = []\n    for _ in range(n-1):\n        a = sample(s, 1)[0]\n        b = choice(joined)\n\
    \        edges.append((a, b))\n        s.remove(a)\n        joined.append(a)\n\
    \    for edge in edges:\n        print(edge[0]+one_index, edge[1]+one_index)\n\
    def print_connected_graph(n: int, one_index=True, tree_ok=True):\n    if tree_ok:\n\
    \        # 10%\u304F\u3089\u3044\u306F\u6728\u304C\u751F\u6210\u3055\u308C\u308B\
    \u3088\u3046\u306B\n        r = randint(1, 10)\n        if (r<=2):\n         \
    \   print_tree(n, one_index=one_index)\n            return 0\n\n    uf = UnionFind(n)\n\
    \    edges = set()\n    while(uf.group_count()>1 and (tree_ok or len(edges)>=n)):\n\
    \        u = randint(0, n-1)\n        v = randint(0, n-1)\n        if (u==v):\
    \ continue\n\n        if (u>v): u,v=v,u\n        edges.add((u, v))\n        uf.union(u,\
    \ v)\n\n    print(n, len(edges))\n    for edge in edges:\n        print(edge[0]+one_index,\
    \ edge[1]+one_index)\n\ndef pl(x: List):\n    print(' '.join(map(str, x)))\n\n\
    N = randint(1, 5000)\nprint(N)\nprint(randstr(N))\n# K = randint(1, 100000)\n\
    # print(N, K)\n# pl(randperm(5))\n# pl(randseq(10, 1, 100, True))\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/string/suffix_array/test/gen.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/string/suffix_array/test/gen.py
layout: document
redirect_from:
- /library/library/cpp/string/suffix_array/test/gen.py
- /library/library/cpp/string/suffix_array/test/gen.py.html
title: library/cpp/string/suffix_array/test/gen.py
---
