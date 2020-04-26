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


# :warning: library/cpp/graph/dijkstra.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"
// https://atcoder.jp/contests/abc151/tasks/abc151_d
// this module is depricated. use graph.hpp

//%snippet.set('dijkstra')%

// this module is depricated. use graph.hpp
using Pos = int;  // TODO: update if needed

using Cost = int;     // TODO: update if needed
Cost zerocost = 0LL;  // TODO: update if needed
Cost infcost = INF;   // TODO: update if needed
// using Cost = pii;
// Cost zerocost = mp(0, 0);
// Cost infcost = mp(INF, INF);

struct Edge {
    Pos to; /*{{{*/
    Cost cost;
    Edge(Pos to, Cost cost) : to(to), cost(cost) {}
    friend auto& operator<<(auto& os, const Edge& e) {
        os << e.to << " " << e.cost;
        return os;
    } /*}}}*/
};
struct Graph {
    unordered_map<Pos, vector<Edge>>
        all_edges;  // Posがpiiでなくintならunordredの方が早い{{{
    void add_edge(Pos from, Pos to, Cost cost) {
        all_edges[from].emplace_back(to, cost);
    }

    auto operator[](Pos pos) { return all_edges[pos]; }

    friend auto& operator<<(auto& os, const Graph& G) {
        os << G.all_edges;
        return os;
    } /*}}}*/
};
struct Dist {
    unordered_map<Pos, Cost> data; /*{{{*/
    Cost operator[](Pos pos) {
        if (data.find(pos) != data.end())
            return data[pos];
        else
            return infcost;
    } /*}}}*/
};
Dist dijkstra(Graph& G, vector<Pos> starts) {  // 多点スタート
    Dist d;                                    // 最短距離{{{
    PQ<pair<Cost, Pos>> pq;
    each(start, starts) {
        d.data[start] = zerocost;
        pq.push(mp(zerocost, start));
    }
    while (!pq.empty()) {
        auto cp = pq.top();
        pq.pop();
        auto cost = cp.first;
        auto u = cp.second;
        for (const auto& edge : G[u]) {
            Pos v = edge.to;
            Cost ncost = cost + edge.cost;
            if (ncost < d[v]) {
                d.data[v] = ncost;
                pq.push(mp(ncost, v));
            }
        }
    }
    return d; /*}}}*/
};
Dist dijkstra(Graph& G, Pos start) {
    vector<Pos> starts = {start};
    return dijkstra(G, starts);
};

// int sample(){
// init and build G
// Graph G;
//
// int n,m;cin>>n>>m;
// rep(i, m){
//     Pos from, to;
//     Cost cost;
//     cin>>from>>to>>cost;
//     from--;to--;
//     G.add_edge(from, to, cost);
//     G.add_edge(to, from, cost);  // TODO: if directed, remove this line
// }
//
// // calc min distance by G
// auto d = dijkstra(G, {start});
// cout << d[{goal}] << endl;  // 到達不可能ならd[goal] -> INF
// return 0;
// }

//%snippet.end()%

signed main() {
    int h, w;
    cin >> h >> w;
    int n = h * w;
    vvi block(h, vi(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) { block[i][j] = (s[j] == '.' ? 0 : 1); }
    }

    // vvi g(n);
    Graph G;

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    rep(i, h) rep(j, w) {
        if (block[i][j]) continue;  // blockから出る辺はない
        int u = i * w + j;

        rep(k, 4) {
            int ni = i + di[k];
            int nj = j + dj[k];
            int v = ni * w + nj;
            if (is_in(ni, 0, h) && is_in(nj, 0, w)) {
                if (block[ni][nj]) continue;  // blockに入る辺はない
                // g[u].pb(v);
                G.add_edge(u, v, 1);
            }
        }
    }
    int ans = 1;
    rep(u, n) {
        auto d = dijkstra(G, u);
        rep(i, n) {
            if (d[i] < INF) chmax(ans, d[i]);
        }
    }
    cout << ans << endl;

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

