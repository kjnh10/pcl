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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :heavy_check_mark: library/cpp/graph/tree.lib/tree.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#eaeee77e776a943cad05fb3e3b603f65">library/cpp/graph/tree.lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/tree.lib/tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00




## Depends on

* :heavy_check_mark: <a href="../../array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :heavy_check_mark: <a href="../graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="../test.make_bipartie/codes/solve.cpp.html">library/cpp/graph/test.make_bipartie/codes/solve.cpp</a>
* :warning: <a href="reroot.cpp.html">library/cpp/graph/tree.lib/reroot.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/graph.dijkstra.test.cpp.html">library/cpp/graph/graph.dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/graph.kruskal.test.cpp.html">library/cpp/graph/graph.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/graph.lowlink.test.cpp.html">library/cpp/graph/graph.lowlink.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/hld.test.cpp.html">library/cpp/graph/tree.lib/hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/lca.test.cpp.html">library/cpp/graph/tree.lib/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../../array/segtree/segment_tree.hpp"
#include "../../header.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree')%
//%snippet.include('segment_tree')%
struct tree { /*{{{*/
    int n;
    vector<int> par;   // par[i]: dfs木における親
    vector<int> cost;  // par[i]: dfs木における親への辺のコスト
    vector<int>
        dfstrv;  // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
    vector<int> ord;    // ord[u]: uのdfs木における訪問順
    vector<int> end;    // end[u]: uのdfs終了時のカウンター
    vector<int> psize;  // psize[u]: uのpartial tree size
    // uの部分木は[ord[u], end[u])
    // ordとdfstrvは逆変換

    vector<int> depth;   // depth[i]: dfs木でのiの深さ
    vector<int> ldepth;  //  ldepth[i]: dfs木でのrootからの距離
    vector<vector<pair<int, int>>> g;  // 辺(隣接リスト)
    vector<vector<int>> adj;           // 辺(隣接リスト)
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;    // euler_tour first occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;

    int _counter = 0;

    tree(){};
    tree(int n)
        : n(n),
          par(n),
          cost(n, 1),
          ord(n),
          end(n),
          psize(n),
          depth(n),
          ldepth(n),
          g(n),
          adj(n),
          children(n),
          et_fpos(n),
          head_of_comp(n){};

    void add_edge(int u, int v, int cost) { /*{{{*/
        g[u].emplace_back(v, cost);
        g[v].emplace_back(u, cost);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }                             /*}}}*/
    void add_edge(int u, int v) { /*{{{*/
        g[u].emplace_back(v, 1);
        g[v].emplace_back(u, 1);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }                      /*}}}*/
    void build(int root) { /*{{{*/
        _counter = 0;
        par[root] = -1;
        cost[root] = -1;
        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
            ini, [](auto a, auto b) { return min(a, b); }, 1e18);
    }                                /*}}}*/
    int _dfs_psize(int u, int pre) { /*{{{*/
        psize[u] = 1;
        each(el, g[u]) {
            int v = el.first;
            if (v == pre) continue;
            psize[u] += _dfs_psize(v, u);
        }
        return psize[u];
    }                                               /*}}}*/
    void _dfs_tree(int u, int pre, int head_node) { /*{{{*/
        dfstrv.pb(u);
        ord[u] = _counter;
        if (pre != -1) {
            depth[u] = depth[pre] + 1;
            ldepth[u] = ldepth[pre] + cost[u];
        }

        _counter++;
        {
            // set most heavy child to top
            int max_psize = 0;
            int most_heavy_i = -1;
            rep(i, sz(g[u])) {
                if (g[u][i].first == pre) continue;
                if (psize[g[u][i].first] > max_psize) {
                    most_heavy_i = i;
                    max_psize = psize[g[u][i].first];
                }
            }
            if (most_heavy_i != -1) swap(g[u][most_heavy_i], g[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(g[u])) {
            int v = g[u][i].first;
            if (v == pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = g[u][i].second;

            if (i == 0)
                _dfs_tree(v, u, head_node);  // continue components
            else
                _dfs_tree(v, u, v);  // new
        }
        end[u] = _counter;
    }                     /*}}}*/
    void _dfs_et(int u) { /*{{{*/
        et_fpos[u] = euler_tour.size();
        euler_tour.pb(u);
        each(v, children[u]) {
            _dfs_et(v);
            euler_tour.pb(u);
        }
    }                       /*}}}*/
    int lca(int u, int v) { /*{{{*/
        if (u == v) return u;
        if (et_fpos[u] > et_fpos[v]) swap(u, v);
        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
    }                        /*}}}*/
    int dist(int u, int v) { /*{{{*/
        int p = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[p];
    }                          /*}}}*/
    int ldist(int u, int v) {  // length dist{{{
        int p = lca(u, v);
        return ldepth[u] + ldepth[v] - 2 * ldepth[p];
    }                           /*}}}*/
    pair<int, int> diameter() { /*{{{*/
        int u, v;
        int max_len = *max_element(all(ldepth));
        rep(i, n) {
            if (ldepth[i] == max_len) {
                u = i;
                break;
            }
        }
        int md = -1;
        rep(i, n) {
            int d = ldist(u, i);
            if (d > md) {
                v = i;
                md = d;
            }
        }
        return mp(u, v);
    }                                                /*}}}*/
    vector<pair<int, int>> hld_path(int u, int v) {  //{{{
        // 閉区間をvectorで返す
        vector<pair<int, int>> res;
        while (head_of_comp[u] != head_of_comp[v]) {
            if (depth[head_of_comp[u]] < depth[head_of_comp[v]]) {
                res.push_back({ord[head_of_comp[v]], ord[v]});
                v = par[head_of_comp[v]];
            } else {
                res.push_back({ord[head_of_comp[u]], ord[u]});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u], ord[v]), max(ord[u], ord[v])});
        return res;
    }                              //}}}
#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const tree& tr) {
        os << endl;
        os << "par:         " << tr.par << endl;
        os << "cost:        " << tr.cost << endl;
        os << "dfstrv:      " << tr.dfstrv << endl;
        os << "ord:         " << tr.ord << endl;
        os << "end:         " << tr.end << endl;
        os << "depth:       " << tr.depth << endl;
        os << "children:    " << tr.children << endl;
        os << "euler_tour:  " << tr.euler_tour << endl;
        os << "et_fpos:     " << tr.et_fpos << endl;
        os << "head_of_comp:" << tr.head_of_comp << endl;
        return os;
    }
#endif /*}}}*/

}; /*}}}*/

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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: library/cpp/header.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

