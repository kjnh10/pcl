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


# :warning: library/python/tsp.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#051bb6df61b6c6e7f8c1868985011b07">library/python</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/python/tsp.py">View this file on GitHub</a>
    - Last commit date: 2020-04-25 20:06:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# ---- memo -----------------
# 巡回セールスマン問題
# ---------------------------

def tsp(d):
    N = len(d)  # node num
    dp = [[float('inf') for j in range(N)] for i in range(2**N)]

    V = (1<<N)-1
    dp[V][0] = 0

    for S in range(V-1, -1, -1):
    # S(i) <= S(j) => i <= jが言えるのでこの順番でOK。ループの順序が正しい自信がなければメモ化再帰で行えば良い。
        for now in range(N):
            for new in range(N):
                if (S >> new) & 1 != 0:
                    continue
                dp[S][now] = min(dp[S][now], dp[S + (1 << new)][new] + d[now][new])

    return dp[0][0]


if __name__ == '__main__':
    inf = float('inf')
    data = [ [inf, 3, inf, 4, inf],
             [inf, inf, 5, inf, inf],
             [4, inf, inf, 5, inf],
             [inf, inf, inf, inf, 3],
             [7, 6, inf, inf, inf]
           ]
    print(tsp(data))


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
