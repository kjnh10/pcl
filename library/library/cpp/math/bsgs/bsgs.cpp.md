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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/math/bsgs/bsgs.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#51139f4eb77e81dbd61f182500602d94">library/cpp/math/bsgs</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/bsgs/bsgs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 14:30:26+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>
* :warning: <a href="../mint.hpp.html">library/cpp/math/mint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"
#include "../mint.hpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b) {  //{{{
    if (b >= mod) {
        return -1;
    }

    // find x s.t a^x = b in (mod)
    mint x;
    int sq = sqrt(mod);
    // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

    map<int, int> minr;  // minr[v]: min(r s.t a^r=v)
    mint ar = 1;
    rep(r, 0, sq) {
        if (minr.find(ar.x) == minr.end()) minr[ar.x] = r;
        ar *= a;
    }

    mint A = mint(a).pow(-sq);
    rep(p, 0, sq + 1) {
        int Ab = (A.pow(p) * b).x;
        if (minr.find(Ab) != minr.end()) {
            int r = minr[Ab];
            return p * sq + r;
        }
    }

    return -1;
}  //}}}
// %snippet.end()%

signed main() {
    int a, b, p;
    cin >> a >> b >> p;
    mod = p;
    cout << bsgs(a, b) << endl;
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

<a href="../../../../../index.html">Back to top page</a>

