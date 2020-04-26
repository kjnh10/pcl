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


# :warning: library/cpp/misc/napsack.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b4c52cffc478acefbc1ee6a9d0578055">library/cpp/misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/misc/napsack.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"

int nampsack01all(int n, const vector<int>& v, const vector<int>& w) {
    // abc032_d
    if (n <= 30) {
        dump("case 1"); /*{{{*/

        int n1 = n / 2;

        auto f = [&](int l, int r) {
            vector<pii> res;
            int n = r - l;
            rep(mask, 1 << n) {
                int sv = 0;
                int sw = 0;
                rep(i, n) {
                    if (mask & (1 << i)) {
                        sv += v[l + i];
                        sw += w[l + i];
                    }
                }
                if (sw <= W) res.pb(mp(sw, sv));
            }
            return res;
        };

        auto r1 = f(0, n1);
        auto r2 = f(n1, n);
        sort(all(r1));
        sort(all(r2));
        int curmax = -1;
        each(el, r2) {
            chmax(el.second, curmax);
            curmax = el.second;
        }

        int ans = -INF;
        each(el, r1) {
            int res = 0;
            int sw = el.first;
            int sv = el.second;
            res += sv;

            int load = W - sw;
            auto i = ub(all(r2), mp(load, INF)) - r2.begin();
            if (i - 1 >= 0) chmax(ans, res + r2[i - 1].second);
        }
        return ans; /*}}}*/
    } else if (*max_element(all(w)) <= 1000) {
        dump("case 2"); /*{{{*/
        const int MW = 200002;
        vector<int> dp(MW, -INF);
        dp[0] = 0;
        rep(i, n) r_rep(j, MW) {
            chmax(dp[min(j + w[i], MW - 1)], dp[j] + v[i]);
        }
        int ans = -INF;
        rep(wi, 0, W + 1) { chmax(ans, dp[wi]); }
        return ans; /*}}}*/
    } else if (*max_element(all(v)) <= 1000) {
        dump("case 3"); /*{{{*/
        const int V = 200002;
        vector<int> dp(V, INF);
        dp[0] = 0;
        rep(i, n) r_rep(j, V) {                             // 01 napsack
            chmin(dp[min(j + v[i], V - 1)], dp[j] + w[i]);  // jから配る
        }
        r_rep(j, V) {
            if (dp[j] <= W) {
                return j;
                return 0;
            }
        } /*}}}*/
    }
}

signed main() {
    //%snippet.set('napsack')%
    int n, h;
    cin >> h >> n;
    vector<int> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    vector<int> dp(h + 1, INF);
    dp[0] = 0;
    rep(i, n) rep(j, h + 1) {  // 個数制限なし
                               // rep(i,n) r_rep(j,h+1){ // 01 napsack
        chmin(dp[min(j + v[i], h)], dp[j] + w[i]);  // jから配る
    }
    cout << dp[h] << endl;
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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: library/cpp/header.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

