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


# :warning: library/python/bit.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#051bb6df61b6c6e7f8c1868985011b07">library/python</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/python/bit.py">View this file on GitHub</a>
    - Last commit date: 2020-04-25 20:06:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# %snippet.set('bit1')%
# Binary Indexd Tree
class BIT():
    def __init__(self, N):
        self.data = [0]*(N+1)  # 1-indexed, 0 not used

    def sum(self, n):
        s = 0
        while n > 0:
            s += self.data[n]
            n -= (n & -n)
        return s

    def add(self, n, x):
        while n <= N:
            self.data[n] += x
            n += (n & -n)
# %snippet.end%


# test
# バブルソートの交換回数
N = 5
A = [3,5,2,1,4]
bit = BIT(N)
ninv = 0
for i in range(N):
    ninv += bit.sum(A[i])
    bit.add(A[i], 1)

ans = N*(N-1)//2 - ninv
assert(ans==6)

print('success')

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

