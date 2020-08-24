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
<script type="text/javascript" src="../../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/string/suffix_array/test/gen.py

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#bc0d468ae7d171bfd708aa3d24de637c">library/cpp/string/suffix_array/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/string/suffix_array/test/gen.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from random import randint, choice, sample, choices
from typing import TYPE_CHECKING, List, Optional, Type
import string
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

a = [3, 5, 7, 9]
# print(randint(1, 100))  # # [1, 100]
# print(choice(a))  # 1つ選択
# print(sample(a, k=2))  # 非復元抽出
# print(sample(a, k=len(L)))  # random permutation
# print(choices(a, k=2))  # 復元抽出
def randperm(n: int):
    return sample(list(range(1, n+1)), k=n)
def randseq(n: int, l: int, r: int, distinct=False):
    res = []
    used = set()
    if (n>r-l+1) and distinct:
        raise Exception(print("n>r-l+1 and distinct=True is not impossible"))

    while len(res) < n:
        v = randint(l, r)
        if distinct and v in used:
            pass
        else:
            res.append(v)
            used.add(v)
    return res
def randstr(length: int, chars: List=['a', 'b', 'c', 'd', 'e']):
# def randstr(length: int, chars: List=string.ascii_lowercase):
    res = ""
    for i in range(length):
        res += choice(chars)
    return res

def print_tree(n: int, one_index=True, header=False):
    if header: print(n, n-1)

    s = set(range(1, n))
    joined = [0]
    edges = []
    for _ in range(n-1):
        a = sample(s, 1)[0]
        b = choice(joined)
        edges.append((a, b))
        s.remove(a)
        joined.append(a)
    for edge in edges:
        print(edge[0]+one_index, edge[1]+one_index)
def print_connected_graph(n: int, one_index=True, tree_ok=True):
    if tree_ok:
        # 10%くらいは木が生成されるように
        r = randint(1, 10)
        if (r<=2):
            print_tree(n, one_index=one_index)
            return 0

    uf = UnionFind(n)
    edges = set()
    while(uf.group_count()>1 and (tree_ok or len(edges)>=n)):
        u = randint(0, n-1)
        v = randint(0, n-1)
        if (u==v): continue

        if (u>v): u,v=v,u
        edges.add((u, v))
        uf.union(u, v)

    print(n, len(edges))
    for edge in edges:
        print(edge[0]+one_index, edge[1]+one_index)

def pl(x: List):
    print(' '.join(map(str, x)))

N = randint(1, 5000)
print(N)
print(randstr(N))
# K = randint(1, 100000)
# print(N, K)
# pl(randperm(5))
# pl(randseq(10, 1, 100, True))

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

<a href="../../../../../../index.html">Back to top page</a>

