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


# :warning: library/cpp/math/gbsgs/gbsgs.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#9d994c49b3b2b338ab838471a698a660">library/cpp/math/gbsgs</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/gbsgs/gbsgs.cpp">View this file on GitHub</a>
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
// %snippet.set('generalized_baybe_step_giant_step')%
// %snippet.config({'alias':'gbsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b) {  //{{{
    // find x s.t a^x = b in (mod)

    if (b >= mod) return -1;
    if (1 % mod == b) return 0;

    int h = (int)sqrt(mod) + 1;  // h s.t x = p*h-r (0<=r<h and 0<=p<=h)

    unordered_map<int, vector<int>> rs;  // rs[v]: vector of r s.t b*a^r==v
    mint bar = b;
    rep(r, 0, h) {
        rs[bar.x].pb(r);
        bar *= a;
    }
    bool looped = false;
    each(el, rs) if (sz(el.second) > 1) looped = true;

    mint ah = mint(a).pow(h);
    rep(p, 1, h + 1) {
        int aph = ah.pow(p).x;
        if (rs.find(aph) != rs.end()) {
            reverse(all(rs[aph]));
            each(r, rs[aph]) {
                if ((p * h - r) >= 0 && mint(a).pow(p * h - r) == b)
                    return p * h - r;
            }
        }
        if (looped) return -1;
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

