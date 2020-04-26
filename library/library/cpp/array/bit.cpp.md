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


# :warning: library/cpp/array/bit.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0e902850ca3e9230d87c81984f25b3bb">library/cpp/array</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/bit.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"

//%snippet.set('bit')%

template <typename T = int>
struct bit {  //{{{
    int n;
    vector<T> dat;
    vector<T> raw;

    bit(int _n = 0) {  //{{{
        n = _n;
        dat = vector<T>(n);
        raw = vector<T>(n);
    }  //}}}

    bit(vector<T> a) {  // {{{
        n = (int)a.size();
        dat = vector<T>(n);
        raw = vector<T>(n);
        for (int i = 0; i < n; i++) {
            add(i, a[i]);
            raw[i] = a[i];
        }
    }  //}}}

    T _rsum(int i) {  //{{{ [0, i]
        T s = 0;
        while (i >= 0) {
            s += dat[i];
            i = (i & (i + 1)) - 1;
        }
        return s;
    }  //}}}

    T sum(int l, int r) {  //{{{  [l, r)
        if (l > r - 1) return 0;
        return _rsum(r - 1) - _rsum(l - 1);
    }  //}}}

    void add(int i, T x) {  //{{{
        raw[i] += x;
        while (i < n) {
            dat[i] += x;
            i |= i + 1;
        }
    }  //}}}

    int lower_bound(T x) {  // a[0]+...+a[ret] >= x{{{
        int ret = -1;
        int k = 1;
        while (2 * k <= n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (ret + k < n && dat[ret + k] < x) {
                x -= dat[ret + k];
                ret += k;
            }
        }
        return ret + 1;
    }  //}}}

    friend ostream& operator<<(ostream& os, bit<T>& b) {  //{{{
        os << endl << "  raw:" << b.raw << endl;
        vector<T> acum;
        rep(i, b.n) { acum.pb(b.sum(i)); }
        os << "  acm:" << acum << endl;
        return os;
    }  //}}}
};     //}}}

//%snippet.end()%

signed main() {
    // vi x = {1, 2, 3, 4, 5};
    // bit<int> b(x);
    bit<int> b(5);
    b.add(0, 1);
    b.add(1, 2);
    b.add(2, 4);
    b.add(3, 8);
    b.add(4, 16);
    rep(i, 5) { cout << b.raw[i] << (i != 5 - 1 ? " " : "\n"); }
    // cout << b << endl;  // dump.hppをimportしないと使えない。
    cout << b._rsum(0) << endl;   // 1
    cout << b._rsum(1) << endl;   // 3
    cout << b._rsum(2) << endl;   // 7
    cout << b._rsum(3) << endl;   // 15
    cout << b._rsum(4) << endl;   // 31
    cout << b.sum(2, 4) << endl;  // 12

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

