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


# :warning: codes/cpp/graph/unionfind.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/unionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-23 17:29:25+09:00




## Depends on

* :heavy_check_mark: <a href="../template.hpp.html">codes/cpp/template.hpp</a>


## Required by

* :warning: <a href="bridge/codes/solve.cpp.html">codes/cpp/graph/bridge/codes/solve.cpp</a>
* :warning: <a href="graph.hpp.html">codes/cpp/graph/graph.hpp</a>
* :warning: <a href="test.make_bipartie/codes/solve.cpp.html">codes/cpp/graph/test.make_bipartie/codes/solve.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../template.hpp"

//%snippet.set('UnionFind')%
struct UnionFind {
  vector<int> data;  // size defined only for root node
  int count;  // count of groups

  UnionFind(){}
  UnionFind(int size) : data(size, -1), count(size){}
  bool merge(int x, int y) {/*{{{*/
    x=root(x); y=root(y);
    if (x!=y) {
      if (data[y]<data[x]) swap(x, y);
      data[x]+=data[y]; data[y]=x;
      count--;
    }
    return x != y;
  }/*}}}*/
  int root(int x) { return (data[x]<0 ? x : data[x]=root(data[x])); }
  bool same(int x,int y){ return root(x)==root(y); }
  int size(int x) { return -data[root(x)]; }

  friend auto& operator<<(auto &os, UnionFind& uf){ //{{{
    map<int, vector<int>> group;
    rep(i, sz(uf.data)){ group[uf.root(i)].pb(i); }
    os << endl; each(g, group){ os << g << endl; }
    return os;
  } //}}}
};
//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: codes/cpp/template.hpp: line 48: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

