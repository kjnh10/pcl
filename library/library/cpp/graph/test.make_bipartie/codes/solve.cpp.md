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


# :warning: library/cpp/graph/test.make_bipartie/codes/solve.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#705d3ed53d77dbb4f313b001665c2a66">library/cpp/graph/test.make_bipartie/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/test.make_bipartie/codes/solve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../../../array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :heavy_check_mark: <a href="../../tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>
* :heavy_check_mark: <a href="../../unionfind.hpp.html">library/cpp/graph/unionfind.hpp</a>
* :heavy_check_mark: <a href="../../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph<int, int> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b, 1);
    }

    auto res = g.make_bipartite();
    dump(res);
    if (res[0] == -1) {
        cout << n * (n - 1) / 2 - m << endl;
    } else {
        int c = accumulate(all(res), 0LL);
        cout << c * (n - c) - m << endl;
    }

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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: library/cpp/header.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

