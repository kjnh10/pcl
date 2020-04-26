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


# :warning: library/cpp/string/rollinghash.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6e84951d1d0c19ce3fef1705f200b877">library/cpp/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/string/rollinghash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>
* :warning: <a href="../math/mint.hpp.html">library/cpp/math/mint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"
#include "../math/mint.hpp"

template <typename T, T MOD, T B>
struct rolling_hash {
    using ll = long long;
    vector<T> hash, bpow;  // 1-index
    rolling_hash() {}
    rolling_hash(vector<T> vs) { init(vs); }
    rolling_hash(string &s) {
        vector<T> vs;
        for (char c : s) vs.emplace_back(c);
        init(vs);
    }

    void init(vector<T> vs) {
        int n = vs.size();
        hash.assign(n + 1, 0);
        bpow.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = ((ll)hash[i] * B + vs[i]) % MOD;
            bpow[i + 1] = (ll)bpow[i] * B % MOD;
        }
    }

    // S[l, r)
    T find(int l, int r) {
        T res = (ll)hash[r] + MOD - (ll)hash[l] * bpow[r - l] % MOD;
        return res >= MOD ? res - MOD : res;
    }
};

signed main() {
    // https://atcoder.jp/contests/abc150/tasks/abc150_f
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }
    vector<int> b(n);
    rep(i, n) { cin >> b[i]; }

    vi c(n), d(n);
    rep(i, n) {
        c[i] = a[i] ^ a[(i + 1) % n];
        d[i] = b[i] ^ b[(i + 1) % n];
    }

    const int B = 1e9 + 9;  // random if codeforces
    rolling_hash<int, mod, B> arh(c);
    rolling_hash<int, mod, B> brh(d);
    mint x = arh.find(0, n);
    mint y = brh.find(0, n);

    vi ans;
    rep(k, n) {
        x -= c[k] * arh.bpow[n - 1];
        x *= B;
        x += c[k];
        if (x == y) ans.pb((k + 1) % n);
    }

    sort(all(ans));
    each(k, ans) {
        int x = a[n - 1] ^ b[n - 1 - k];
        cout << k << " " << x << endl;
    }

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

