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


# :warning: codes/cpp/graph/treeclass/codes/reroot.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#54dcc55c2c64fd1eb0de496df8f72752">codes/cpp/graph/treeclass/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/treeclass/codes/reroot.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-04 15:53:48+09:00




## Depends on

* :heavy_check_mark: <a href="tree.hpp.html">codes/cpp/graph/treeclass/codes/tree.hpp</a>
* :heavy_check_mark: <a href="../../../template.hpp.html">codes/cpp/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// %test('http://codeforces.com/contest/1324/problem/F')%
#include "../../../template.hpp"
#include "./tree.hpp"

signed main() {
    int n; cin>>n;
    vector<int> col(n);
    rep(i, n){
        cin>>col[i];
        if (col[i]==0) col[i] = -1;
    }

    //%snippet.set('reroot')%
    tree tr(n);
    rep(i, n-1){
        int u, v;cin>>u>>v;
        u--;v--;
        tr.add_edge(u, v);
    }
    tr.build(0);

    vector<map<int, int>> dp(n);

    // first dfs
    rrep(i, 1, n){
        // 葉からdp
        int u = tr.dfstrv[i];
        dp[u][tr.par[u]] = col[u];  // TODO: update: 子供がいない場合
        each(ch, tr.children[u]){
            dp[u][tr.par[u]] += max(0LL, dp[ch][u]);  // TODO: update
        }
    }
    dump_2d(dp, n, n);

    // second dfs
    rep(i, 0, n){
        cerrendl;
        // uを頂点とする部分木の情報dp[u][*]を配る。
        int u = tr.dfstrv[i];
        int m = sz(tr.adj[u]);

        vector<int> lcum(m+2);
        vector<int> rcum(m+2);
        { // 前処理
            vector<int> child_info(m+2);
            rep(j, 1, m+1){
                int v = tr.adj[u][j-1];
                child_info[j] = max(dp[v][u], 0LL);  // TODO: update
            }
            lcum[0] = 0; lcum[m+1] = 0;  // 単位元を番兵に  // TODO: update
            rcum[0] = 0; rcum[m+1] = 0;  // 単位元を番兵に  // TODO: update
            rep(j, 1, m+1){
                lcum[j] = lcum[j-1] + child_info[j];  // TODO: update
            }
            rrep(j, 1, m+1){
                rcum[j] = rcum[j+1] + child_info[j];  // TODO: update
            }
            dump(child_info);
        }

        dump(lcum);
        dump(rcum);
        rep(j, 1, m+1){
            int v = tr.adj[u][j-1];
            dp[u][v] = lcum[j-1] + rcum[j+1];  // TODO: update
            dp[u][v] += col[u];  // 追加条件  // TODO: update
            dump(u, v, j, dp[u][v], lcum[j-1], rcum[j+1], col[u]);
        }
    }
    dump_2d(dp, n, n);

    // answer
    vector<int> ans;
    rep(u, n){
        int res = col[u];  // TODO: update
        each(v, tr.adj[u]){
            res += max(0LL, dp[v][u]);  // TODO: update
        }
        ans.push_back(res);
    }
    rep(i, sz(ans)) cout << ans[i] << (i!=sz(ans)-1 ? " " : "\n");

    //%snippet.end()%

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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: codes/cpp/template.hpp: line 48: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

