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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: library/cpp/graph/graph.dijkstra.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/graph.dijkstra.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/library/cpp/array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../../library/library/cpp/graph/graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :heavy_check_mark: <a href="../../../../library/library/cpp/graph/tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>
* :heavy_check_mark: <a href="../../../../library/library/cpp/graph/unionfind.hpp.html">library/cpp/graph/unionfind.hpp</a>
* :heavy_check_mark: <a href="../../../../library/library/cpp/header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C"

#include "../header.hpp"
#include "graph.hpp"

signed main() {
    int n;
    cin >> n;
    Graph g(n);
    rep(i, n) {
        int u;
        cin >> u;
        int k;
        cin >> k;
        rep(j, k) {
            int to, cost;
            cin >> to >> cost;
            g.add_edge(u, to, cost, i);
        }
    }
    auto d = g.dijkstra(0);
    rep(i, n) { cout << i << " " << d[i] << endl; }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: library/cpp/header.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

