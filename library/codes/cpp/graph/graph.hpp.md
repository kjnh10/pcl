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


# :warning: codes/cpp/graph/graph.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/graph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-23 17:29:25+09:00




## Depends on

* :warning: <a href="unionfind.hpp.html">codes/cpp/graph/unionfind.hpp</a>
* :heavy_check_mark: <a href="../template.hpp.html">codes/cpp/template.hpp</a>


## Required by

* :warning: <a href="bridge/codes/solve.cpp.html">codes/cpp/graph/bridge/codes/solve.cpp</a>
* :warning: <a href="test.make_bipartie/codes/solve.cpp.html">codes/cpp/graph/test.make_bipartie/codes/solve.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../template.hpp"
#include "./unionfind.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%

template<class Pos=int, class Cost=int, Cost zerocost=0LL, Cost infcost=INF>
struct Graph{
  struct Edge {
    Pos to;
    Cost cost;
    Edge(Pos to, Cost cost): to(to), cost(cost) {
    }
    friend auto& operator<<(auto &os, const Edge& e){
      os << e.to << " " << e.cost;
      return os;
    }
  };

  int n;  // 頂点数
  // unordered_map<Pos, vector<Edge>> adj_list;//Posがpiiでなくintならunordredの方が早い
  vector<vector<Edge>> adj_list;//Posがpiiでなくintならunordredの方が早い
  UnionFind buf;

  Graph(int n): n(n), adj_list(n){}

  void add_edge(Pos from, Pos to, Cost cost){
    adj_list[from].emplace_back(to, cost);
  }

  auto operator[](Pos pos) {
    return adj_list[pos];
  }

  vector<int> make_bipartite(){
    buf = UnionFind(2*n);
    rep(u, n){
      each(e, adj_list[u]){
        buf.merge(u, e.to+n);
        buf.merge(e.to, u+n);
      }
    }

    vector<int> res(n, -1);
    rep(u, n){
      if(buf.same(u, u+n)){
        return res;
      }
    }
    rep(u, n){
      if (buf.same(0, u)) res[u] = 0;
      else res[u] = 1;
    }
    return res;
  }

  void make_dfstree(){
    // lolinkを構築
  }
};

//%snippet.end()%

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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: codes/cpp/template.hpp: line 48: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

