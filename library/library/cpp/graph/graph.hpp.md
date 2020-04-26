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


# :heavy_check_mark: library/cpp/graph/graph.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/graph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :heavy_check_mark: <a href="tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>
* :heavy_check_mark: <a href="unionfind.hpp.html">library/cpp/graph/unionfind.hpp</a>
* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Required by

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
#include "tree.lib/tree.hpp"
#include "unionfind.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%
//%snippet.include('tree')%

template <class Pos = int, class Cost = ll, Cost zerocost = 0LL,
          Cost infcost = INF>
struct Graph {
    struct Edge {
        Pos from, to;
        Cost cost;
        int idx;
        Edge(){};
        Edge(Pos from, Pos to, Cost cost, int idx)
            : from(from), to(to), cost(cost), idx(idx) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {
            os << e.from << " " << e.to << " " << e.cost << " " << e.idx;
            return os;
        }
    };

    int n;  // 頂点数
    // unordered_map<Pos, vector<Edge>>
    // adj_list;//Posがpiiでなくintならunordredの方が早い
    vector<vector<Edge>> adj_list;
    vector<Edge> edges;
    UnionFind buf;
    tree tr;
    Pos root;
    vector<int> _used_in_dfs;
    vector<int> lowlink;

    Graph() {}
    Graph(int _n) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n) {}

    void add_edge(Pos from, Pos to, Cost cost, int idx) {
        adj_list[from].emplace_back(from, to, cost, idx);
        edges.emplace_back(from, to, cost, idx);
    }

    void build_tree(int _root) {
        root = _root;
        _dfs_tree(root);
        tr.build(root);
        _make_lowlink();
    }

    auto operator[](Pos pos) { return adj_list[pos]; }

    vector<int> make_bipartite() {
        buf = UnionFind(2 * n);
        rep(u, n) {
            each(e, adj_list[u]) {
                buf.merge(u, e.to + n);
                buf.merge(e.to, u + n);
            }
        }

        vector<int> res(n, -1);
        rep(u, n) {
            if (buf.same(u, u + n)) {
                return res;
            }
        }
        rep(u, n) {
            if (buf.same(0, u))
                res[u] = 0;
            else
                res[u] = 1;
        }
        return res;
    }

    void _dfs_tree(int u) {
        _used_in_dfs[u] = 1;
        each(e, adj_list[u]) {
            if (_used_in_dfs[e.to]) continue;
            tr.add_edge(u, e.to, e.cost);
            _dfs_tree(e.to);
        }
    }

    void _make_lowlink() {
        lowlink = vector<int>(n, INF);
        r_rep(i, n) {
            Pos u = tr.dfstrv[i];
            chmin(lowlink[u], tr.ord[u]);

            each(e, adj_list[u]) {
                if (e.to == tr.par[u])
                    continue;
                else if (tr.ord[e.to] < tr.ord[u]) {
                    chmin(lowlink[u], tr.ord[e.to]);
                } else {
                    chmin(lowlink[u], lowlink[e.to]);
                }
            }
        }
    }

    vector<Pos> get_articulation_points() {
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");

        vector<Pos> res;
        dump(tr.children[root]);
        if (sz(tr.children[root]) > 1) {
            res.push_back(root);
        }
        rep(u, 0, n) {
            if (u == root) continue;
            bool is_kan = false;
            each(v, tr.children[u]) {
                if (tr.ord[u] <= lowlink[v]) {
                    is_kan = true;
                }
            }
            if (is_kan) res.push_back(u);
        }
        return res;
    }

    vector<Edge> kruskal_tree() {
        // 使用される辺のindexのvectorを返す
        vector<Edge> res(n - 1);
        sort(all(edges), [&](auto l, auto r) { return l.cost < r.cost; });
        UnionFind uf(n);

        int total_cost = 0;
        int i = 0;
        each(e, edges) {
            if (uf.same(e.from, e.to)) continue;
            uf.merge(e.from, e.to);
            total_cost += e.cost;
            res[i] = e;
            i++;
        }
        assert(i == n - 1);

        return res;
    }

    vector<Cost> dijkstra(vector<Pos> starts) {  // 多点スタート
        vector<Cost> dist(n, infcost);           // 最短距離
        PQ<pair<Cost, Pos>> pq;
        each(start, starts) {
            dist[start] = zerocost;
            pq.push(make_pair(zerocost, start));
        }
        while (!pq.empty()) {
            auto cp = pq.top();
            pq.pop();
            auto [cost, u] = cp;
            for (const auto& edge : adj_list[u]) {
                Pos v = edge.to;
                Cost new_cost = cost + edge.cost;
                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.push(make_pair(new_cost, v));
                }
            }
        }
        return dist;
    };

    vector<Cost> dijkstra(Pos start) {  // 1点スタート
        vector<Pos> starts = {start};
        return dijkstra(starts);
    };
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

