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


# :warning: library/cpp/string/kmp/codes/solve.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#c4edc97866360646965a77b5500cc883">library/cpp/string/kmp/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/string/kmp/codes/solve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../../header.hpp"

//%snippet.set('kmp')%

// Morris-Pratt
template <typename T>
struct KMP {
    int n;
    T pattern;
    vector<int> a;
    KMP() {} /*{{{*/
    KMP(const T& pattern) : pattern(pattern) {
        n = pattern.size();
        a = vector<int>(n + 1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && pattern[j] != pattern[i]) j = a[j];
            j++;
            a[i + 1] = j;
        }
    } /*}}}*/
    int operator[](int i) { return a[i]; }
    vector<int> findAll(const T& s) { /*{{{*/
        vector<int> res;
        int j = 0;
        for (int i = 0; i < sz(s); ++i) {
            while (j != -1 && pattern[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i - j + 1);
                j = a[j];
            }
        }
        return res;
    } /*}}}*/
};

// KMP<vector<int>> kmp({1,2,3});
// KMP<string> kmp("abc");

//%snippet.end()%

vector<int> f(vector<int>& a) {
    int n = a.size();
    vector<int> res(n);
    rep(i, n) res[i] = a[i] ^ a[(i + 1) % n];
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> xa = f(a);
    vector<int> xb = f(b);
    dump(xa);
    dump(xb);

    KMP<vector<int>> kmp(xa);
    dump("hello");
    vi wxb;
    wxb.insert(wxb.end(), xb.begin(), xb.end());
    wxb.insert(wxb.end(), xb.begin(), xb.end());

    vector<int> res = kmp.findAll(wxb);
    vector<int> ks;
    for (int p : res) ks.push_back(n - p);
    sort(ks.begin(), ks.end());
    for (int k : ks) {
        if (k >= n) continue;
        int x = a[k] ^ b[0];
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

<a href="../../../../../../index.html">Back to top page</a>

