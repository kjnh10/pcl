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


# :warning: library/cpp/math/mint.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#38e8a99339d0d505d14feb619e0537d8">library/cpp/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/mint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :warning: <a href="bsgs/bsgs.cpp.html">library/cpp/math/bsgs/bsgs.cpp</a>
* :warning: <a href="combination.hpp.html">library/cpp/math/combination.hpp</a>
* :warning: <a href="gbsgs/gbsgs.cpp.html">library/cpp/math/gbsgs/gbsgs.cpp</a>
* :warning: <a href="../string/rollinghash.cpp.html">library/cpp/string/rollinghash.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../header.hpp"

//%snippet.set('mint')%
int mod = 1e9 + 7;
// int mod = 998244353;
struct mint {  //{{{
    int x;
    mint(int x = 0) : x((x % mod + mod) % mod) {}

    // ?= operator
    mint& operator+=(const mint a) {
        (x += a.x) %= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        (x += mod - a.x) %= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint& operator/=(const mint& rhs) {
        if (rhs.x == 0) throw runtime_error("mint zero division");
        return *this *= rhs.inv();
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    mint pow(int n) const {
        mint res(1), x(*this);
        if (n < 0) {
            n = -n;
            x = (*this).inv();
        }
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    mint inv() const {
        if (x == 0) throw runtime_error("inv does not exist");
        return pow(mod - 2);
    }
    // mint inv()const{
    //     int x,y;
    //     int g=extgcd(v,mod,x,y);
    //     assert(g==1);
    //     if(x<0)x+=mod;
    //     return mint(x);
    // }

    bool operator<(const mint& r) const { return x < r.x; }
    bool operator==(const mint& r) const { return x == r.x; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
//}}}

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

