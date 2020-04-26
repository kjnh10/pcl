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


# :heavy_check_mark: library/cpp/graph/unionfind.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/unionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :heavy_check_mark: <a href="graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="test.make_bipartie/codes/solve.cpp.html">library/cpp/graph/test.make_bipartie/codes/solve.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/graph.dijkstra.test.cpp.html">library/cpp/graph/graph.dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/graph.kruskal.test.cpp.html">library/cpp/graph/graph.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/graph.lowlink.test.cpp.html">library/cpp/graph/graph.lowlink.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../header.hpp"

//%snippet.set('UnionFind')%
struct UnionFind {
    vector<int> data;  // size defined only for root node
    int count;         // count of groups

    UnionFind() {}
    UnionFind(int size) : data(size, -1), count(size) {}
    bool merge(int x, int y) { /*{{{*/
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
            count--;
        }
        return x != y;
    } /*}}}*/
    int root(int x) { return (data[x] < 0 ? x : data[x] = root(data[x])); }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -data[root(x)]; }

#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.data)) { group[uf.root(i)].pb(i); }
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
#endif  // }}}
};
//%snippet.end()%

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

