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


# :warning: library/cpp/graph/topological_sort.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"

//%snippet.set('topological_sort')%
//%snippet.config({'alias':'tps'})%
template <class node>
using graph = vector<vector<node>>;

template <class node>
pair<vector<node>, int> topological_sort(const graph<node>& G) {
    int V = sz(G);     // node数
    vector<node> ans;  // sort後の結果を格納
    vector<int> h(V);  // 頂点ごとの入次数
    stack<node> st;    // 入次数が0になっている頂点の集合
    int max_len = 0;   // 最長経路の長さ
                       /*{{{*/
    // 入次数を計算する。
    rep(v, V) {
        for (auto to : G[v]) {
            h[to]++;
        }
    }

    // 最初に入次数0になっている頂点を集める。
    rep(v, V) {
        if (h[v] == 0) {
            st.push(v);
            ans.push_back(v);
        }
    }

    // 入次数0の頂点をansに追加しそこから出て行く辺は削除していく。O(V+E)
    while (!st.empty()) {
        stack<node> nex_st;
        while (!st.empty()) {
            node v = st.top();
            st.pop();
            for (auto to : G[v]) {
                h[to]--;
                if (h[to] == 0) {
                    ans.push_back(to);
                    nex_st.push(to);
                }
            }
        }
        max_len++;
        st = nex_st;
    }
    /*}}}*/
    return make_pair(
        ans,
        max_len);  // ans.size()<Vなら閉路がありDAGではない。閉路内の頂点はstに入り得ないので。
}
//%snippet.end()%

int solve() {  // ABC139 E:https://atcoder.jp/contests/abc139
               // input
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;

    vvi M(n);
    rep(i, n) {
        rep(j, n - 1) {
            int a;
            cin >> a;
            a--;
            M[i].pb(a);
        }
    }
    dump_2d(M, n, n - 1);

    // encode pair<int, int> -> int
    int id = 0;
    vvi idtable(n, vi(n));
    rep(i, n) rep(j, i + 1, n) { idtable[i][j] = id++; }
    auto toid = [&](int i, int j) {
        if (i > j) swap(i, j);
        return idtable[i][j];
    };

    // generate graph
    graph<int> g(m + 2);
    vi h(m + 2);
    rep(i, n) {
        rep(j, 1, n - 1) {
            int pre = M[i][j - 1];
            int to = M[i][j];
            g[toid(i, pre)].pb(toid(i, to));
            h[toid(i, to)]++;
        }
    }
    dump(g);

    // answer
    auto ans = topological_sort(g);
    cout << ((sz(ans.first) < m) ? -1 : ans.second) << endl;
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

