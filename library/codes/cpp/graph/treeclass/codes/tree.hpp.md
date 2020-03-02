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


# :heavy_check_mark: codes/cpp/graph/treeclass/codes/tree.hpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#54dcc55c2c64fd1eb0de496df8f72752">codes/cpp/graph/treeclass/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/treeclass/codes/tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-23 17:50:19+09:00




## Depends on

* :heavy_check_mark: <a href="../../../template.hpp.html">codes/cpp/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../../verify/codes/cpp/graph/treeclass/codes/lca.test.cpp.html">codes/cpp/graph/treeclass/codes/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../../template.hpp"
// (参考) https://www.slideshare.net/Proktmr/ss-138534092

//%snippet.set('tree')%

template<typename T> struct SegmentTree { // {{{
  private:
    using F = function<T(T,T)>;
    int n;  // 元の配列のサイズ
    int N;  // n以上の最小の2冪
    vector<T> node;
    F merge;
    T identity;

  public:
    SegmentTree(){}
    SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
      n = a.size();
      N = 1; while(N < n) N *= 2;
      node.resize(2*N-1, identity);
      for(int i=0; i<n; i++) node[i+N-1] = a[i];
      for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
    }
    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

    T& operator[](int i) { return node[i+N-1]; }

    void update(int x, T val) {
      x += (N - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    void add(int x, T val) {
      x += (N - 1);
      node[x] += val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    // query for [l, r)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}
struct tree{/*{{{*/
  int n;
  vector<int> par;  // par[i]: dfs木における親
  vector<int> cost;  // par[i]: dfs木における親への辺のコスト
  vector<int> dfstrv; // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
  vector<int> ord;  // ord[u]: uのdfs木における訪問順
  vector<int> pos;  // pos[u]: uのdfs終了時のカウンター
  vector<int> psize; // psize[u]: uのpartial tree size
  // vの部分木は[ord[v], pos[v])
  // ordとdfstrvは逆変換

  vector<int> depth;  // depth[i]: dfs木でのiの深さ
  vector<int> ldepth;  //  ldepth[i]: dfs木でのrootからの距離
  vector<vector<pair<int, int>>> g; // 辺(隣接リスト)
  vector<vector<int>> children;
  vector<int> euler_tour;
  vector<int> et_fpos;  // euler_tour first occurence position
  SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)

  int _counter = 0;

  tree(int n):
    n(n),par(n),cost(n,1),ord(n),pos(n),
    psize(n),depth(n),ldepth(n),g(n),children(n),et_fpos(n)
  {};

  void add_edge(int u, int v, int cost){
    g[u].emplace_back(v, cost);
    g[v].emplace_back(u, cost);
  }
  void add_edge(int u, int v){
    g[u].emplace_back(v, 1);
    g[v].emplace_back(u, 1);
  }

  void build(int root){
    _counter = 0;
    par[root] = -1;
    cost[root] = INF;
    _dfs_tree(root, -1);
    _dfs_et(root);
    vector<int> ini(2*n-1); rep(i, 2*n-1) ini[i] = ord[euler_tour[i]];
    _seg = SegmentTree<int>(ini, [](auto a, auto b){return min(a,b);}, 1e18);
  }

  void _dfs_tree(int u, int pre){
    dfstrv.pb(u);
    ord[u] = _counter;
    if (pre!=-1){
      depth[u] = depth[pre]+1; 
      ldepth[u] = ldepth[pre]+cost[u]; 
    }

    _counter++;
    each(el, g[u]){
      int v = el.first;
      if (v==pre) continue;

      children[u].pb(v);
      par[v] = u;
      cost[v] = el.second;
      _dfs_tree(v, u);
    }
    pos[u] = _counter;
    psize[u] = pos[u] - ord[u];
  }

  void _dfs_et(int u){
    et_fpos[u] = euler_tour.size();
    euler_tour.pb(u);
    each(v, children[u]){
      _dfs_et(v);
      euler_tour.pb(u);
    }
  }

  int lca(int u, int v){
    if (u==v) return u;
    if (et_fpos[u]>et_fpos[v]) swap(u, v);
    return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
  }

  int dist(int u, int v){
    int p = lca(u, v);
    return depth[u] + depth[v] - 2*depth[p];
  }
  int ldist(int u, int v){  // length dist
    int p = lca(u, v);
    return ldepth[u] + ldepth[v] - 2*ldepth[p];
  }
  pair<int, int> diameter(){
    int u, v;
    int max_len = *max_element(all(ldepth));
    rep(i, n){
      if(ldepth[i]==max_len){
        u = i; break;
      }
    }
    int md = -1;
    rep(i, n){
      int d = ldist(u, i);
      if (d>md){ v = i; md = d; }
    }
    return mp(u, v);
  }

};/*}}}*/
  // ----sample------
  // int n,q;cin>>n>>q;
  // tree tr(n);
  // rep(u, 1, n){
  //   int p;cin>>p;
  //   tr.add_edge(p,u);
  // }
  // tr.build(0);
  // rep(_, q){
  //   int u,v;cin>>u>>v;
  //   cout << tr.lca(u, v) << endl;
  // }

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

<a href="../../../../../../index.html">Back to top page</a>

