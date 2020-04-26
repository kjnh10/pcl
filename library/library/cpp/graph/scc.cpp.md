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


# :warning: library/cpp/graph/scc.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"

//%snippet.set('StronglyConnectedComponents')%
//%snippet.config({'alias':'scc'})%
using Graph = vector<vector<int> >;
struct StronglyConnectedComponents {
    // how to use
    // StronglyConnectedComponents scc(g); // g: Graph
    // scc.build();
    // dump(scc.comp, scc.dag);

    const Graph &g;  //{{{
    vector<int> comp;  // comp[i]: iが属する強連結成分が何番目の成分か
    Graph dag;  // 縮約されたDAG graph. sizeをとれば強連結成分の個数が分かる。
    Graph _rg;  // reversed graph
    vector<int> _order;  // order[i]: 行きがけの番号
    vector<int> _used;

    StronglyConnectedComponents(Graph &g)
        : g(g), comp(g.size(), -1), _rg(g.size()), _used(g.size()) {
        for (int i = 0; i < sz(g); i++) {
            for (auto e : g[i]) {
                _rg[(int)e].emplace_back(i);
            }
        }
    }

    int operator[](int k) { return comp[k]; }

    void build() {
        for (int i = 0; i < sz(g); i++) _dfs(i);
        reverse(begin(_order), end(_order));
        int cnt = 0;
        for (int i : _order)
            if (comp[i] == -1) _rdfs(i, cnt), cnt++;

        dag.resize(cnt);
        for (int i = 0; i < sz(g); i++) {
            for (auto &to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y) continue;
                dag[x].push_back(y);
            }
        }
    }

    void _dfs(int idx) {
        if (_used[idx]) return;
        _used[idx] = true;
        for (int to : g[idx]) _dfs(to);
        _order.push_back(idx);
    }

    void _rdfs(int idx, int cnt) {
        if (comp[idx] != -1) return;
        comp[idx] = cnt;
        for (int to : _rg[idx]) _rdfs(to, cnt);
    }  //}}}
};
//%snippet.end()%

int solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i, m) {
        int from, to;
        cin >> from >> to;
        g[from].pb(to);
    }
    StronglyConnectedComponents scc(g);
    scc.build();
    dump(scc.comp);
    dump(scc.dag);
    int q;
    cin >> q;
    rep(_, q) {
        int x, y;
        cin >> x >> y;
        if (scc[x] == scc[y]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

signed main() {  //{{{
#ifdef INPUT_FROM_FILE
    std::ifstream in(infile);
    std::cin.rdbuf(in.rdbuf());
#endif
    solve();
    return 0;
}  //}}}

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

