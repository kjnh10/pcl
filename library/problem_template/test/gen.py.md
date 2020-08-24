---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: problem_template/test/gen.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76c92c32675513a9b45b3a525f3ad871">problem_template/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/problem_template/test/gen.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from random import choice, sample, choices
from random import randint as rint
from typing import TYPE_CHECKING, List, Optional, Type
import string
import math
# print(choice(a))  # 1つ選択
# print(sample(a, k=2))  # 非復元抽出
# print(sample(a, k=len(L)))  # random permutation
# print(choices(a, k=2))  # 復元抽出

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

class rperm(object):
    def __init__(self, n:int):
        self.data = sample(list(range(1, n+1)), k=n)
    def __str__(self):
        return ' '.join(map(str, self.data))

class rseq(object):
    def __init__(self, n: int, l: int, r: int, distinct=False):
        self.data = []
        used = set()
        if (n>r-l+1) and distinct:
            raise Exception(print("n>r-l+1 and distinct=True is not impossible"))

        while len(self.data) < n:
            v = rint(l, r)
            if distinct and v in used:
                pass
            else:
                self.data.append(v)
                used.add(v)

    def __str__(self):
        return ' '.join(map(str, self.data))

def rstr(length: int, chars: List=['a', 'b', 'c', 'd', 'e']):
# def rstr(length: int, chars: List=string.ascii_lowercase):
    res = ""
    for i in range(length):
        res += choice(chars)
    return res

def rprime(l: int = 2, r: int = 1000000007): # [l, r]
    def is_prime(x):
        if (x == 1): return False
        for i in range(2, int(math.sqrt(x))+1):
            if x % i == 0:
                return False
        return True


    cnt = 0
    while True:
        res = rint(l, r)
        if (is_prime(res)):
            return res
        cnt += 1
        if cnt>=1000:
            assert False

class rtree(object):
    def __init__(self, n: int, root: int = 0):
        assert root < n
        self.edges = []
        self.n = n
        s = set([x for x in range(n) if x!=root])
        joined = [root]
        self.edges = []
        for _ in range(n-1):
            a = sample(s, 1)[0]
            b = choice(joined)
            self.edges.append((b, a))  # この向きにするとgraphvizの表示が木らしくなる。
            s.remove(a)
            joined.append(a)

    def __str__(self, one_index=True, header=False):
        res = []
        if header:
            res.append(f"{self.n} {self.n-1}")

        for edge in self.edges:
            res.append(f"{edge[0]+one_index} {edge[1]+one_index}")
        return '\n'.join(res)

class rgraph(object):  # undirected
    def __init__(self, n:int, lb:int=1, ub:int=float('inf'), tree_ok=True):
        self.n = n
        if ub == float('inf'):
            ub = n*(n-1)/2

        while True:
            if tree_ok:  # tree graph
                # 10%くらいは木が生成されるように
                r = rint(1, 10)
                if (r<=2):
                    self.edges = rtree(n).edges
                    return

            # TODO: [line graph, star graph, complete graph]

            uf = UnionFind(n)
            self.edges = set()
            while(uf.group_count()>1 or len(self.edges)<lb):
                u = rint(0, n-1)
                v = rint(0, n-1)
                if (u==v): continue

                if (u>v): u,v=v,u
                self.edges.add((u, v))
                uf.union(u, v)
            self.edges = list(self.edges)
            if len(self.edges) <= ub:
                return

    def __str__(self, one_index=True, header=True):
        res = []
        if header:
            res.append(f"{self.n} {len(self.edges)}")
        for edge in self.edges:
            res.append(f"{edge[0]+one_index} {edge[1]+one_index}")
        return '\n'.join(res)

# write down here
# ---------------------------------------------
a = rint(2, 10)
b = rint(2, 10)
print(a, b)

# if you want to test some specified ranges,
# def generator():  # you should implement as generator
#     for a in range(1, 5):
#         for b in range(1, 5):
#             # single case
#             print(a, b)
#             yield 0

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

