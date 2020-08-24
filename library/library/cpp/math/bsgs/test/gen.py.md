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


# :warning: library/cpp/math/bsgs/test/gen.py

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#09912b019734122c0fb6e1c53d1f8569">library/cpp/math/bsgs/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/bsgs/test/gen.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from random import randint, choice, sample, choices
from typing import TYPE_CHECKING, List, Optional, Type

L = [3, 5, 7, 9]
# print(randint(1, 100))  # # [1, 100]
# print(choice(L))  # 1つ選択
# print(sample(L, k=2))  # 非復元抽出
# print(sample(L, k=len(L)))  # random permutation
# print(choices(L, k=2))  # 復元抽出


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


def printtree(n: int):
    pass


def printgraph(n: int, m: int):
    pass


def pl(x: List):
    print(' '.join(map(str, x)))


def get_sieve_of_eratosthenes(n):
    if not isinstance(n, int):
        raise TypeError('n is int type.')
    if n < 2:
        raise ValueError('n is more than 2')
    prime = [2]
    limit = int(n**0.5)
    data = [i + 1 for i in range(2, n, 2)]
    while True:
        p = data[0]
        if limit <= p:
            return prime + data
        prime.append(p)
        data = [e for e in data if e % p != 0]


a = randint(1, 10000)
b = randint(1, 10000)
p = choice(get_sieve_of_eratosthenes(100000))
print(a, b, p)

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

