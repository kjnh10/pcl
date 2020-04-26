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


# :warning: library/cpp/math/geoemtry/geometry.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#cef394f212ede05bd80525fdb8bcaf21">library/cpp/math/geoemtry</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/geoemtry/geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"

//%snippet.set('Pos')%
struct Pos {
    int x, y;
    Pos(int _x, int _y) : x(_x), y(_y) {}
    Pos() {
        x = 0;
        y = 0;
    }
    bool in(int a, int b, int c, int d) {  // x in [a, b) && y in [c, d)
        if (a <= x && x < b && c <= y && y < d)
            return true;
        else
            return false;
    }

    bool operator<(const Pos &r) const {
        return (x != r.x ? x < r.x : y < r.y);
    }
    bool operator>(const Pos &r) const {
        return (x != r.x ? x > r.x : y > r.y);
    }
    bool operator==(const Pos &r) const { return (x == r.x && y == r.y); }

    friend ostream &operator<<(ostream &stream, Pos p) {
        stream << "(" << p.x << "," << p.y << ")";
        return stream;
    }
};
//%snippet.config({'alias':'pos'})%
//%snippet.end%

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

