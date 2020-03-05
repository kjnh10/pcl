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


# :heavy_check_mark: codes/cpp/graph/treeclass/codes/lca.test.cpp

<a href="../../../../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/treeclass/codes/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-23 17:50:19+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../../../../../library/codes/cpp/graph/treeclass/codes/tree.hpp.html">codes/cpp/graph/treeclass/codes/tree.hpp</a>
* :heavy_check_mark: <a href="../../../../../../library/codes/cpp/template.hpp.html">codes/cpp/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "./tree.hpp"

signed main() {
  // tree tr(8);
  // tr.add_edge(0, 1, 1);
  // tr.add_edge(0, 2, 1);
  // tr.add_edge(1, 3, 1);
  // tr.add_edge(1, 4, 1);
  // tr.add_edge(4, 6, 1);
  // tr.add_edge(4, 7, 1);
  // tr.add_edge(2, 5, 1);
  //
  // tr.build(2);
  // dump(tr.par);
  // dump(tr.dfstrv);
  // dump(tr.ord);
  // dump(tr.pos);
  // dump(tr.depth);
  // dump(tr.children);
  // dump(tr.euler_tour);
  // dump(tr.et_fpos);
  // dump(tr.lca(3, 5));

  int n,q;cin>>n>>q;
  tree tr(n);
  rep(u, 1, n){
    int p;cin>>p;
    tr.add_edge(p,u);
  }
  tr.build(0);
  rep(_, q){
    int u,v;cin>>u>>v;
    cout << tr.lca(u, v) << endl;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: codes/cpp/template.hpp: line 48: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

