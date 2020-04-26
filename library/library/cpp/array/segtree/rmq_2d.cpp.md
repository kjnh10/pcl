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


# :warning: library/cpp/array/segtree/rmq_2d.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#ebc279bbe94c10384fe9898d1a2c958d">library/cpp/array/segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/segtree/rmq_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"

//%snippet.set('SegmentTree2DRMQ')%
//%snippet.config({'alias':'2drmq'})%
struct segtree {
    int H, W;
    vector<vector<int>> dat;
    segtree() {}
    segtree(vector<vector<int>> &f) {
        H = W = 1;
        while (H < (int)f.size()) H <<= 1;
        while (W < (int)f[0].size()) W <<= 1;
        dat.assign(2 * H - 1, vector<int>(2 * W - 1, INF));
        init(f);
    }
    void init(vector<vector<int>> &f) {
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i + H - 1][j + W - 1] = f[i][j];
        dump("hello");
        for (int i = 2 * H - 2; i > H - 2; i--)
            for (int j = W - 2; j >= 0; j--)
                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2 * j + 2]);
        dump("hello1");
        for (int i = H - 2; i >= 0; i--)
            for (int j = 0; j < 2 * W - 1; j++)
                dat[i][j] = min(dat[2 * i + 1][j], dat[2 * i + 2][j]);
        dump("hello2");
    }
    int minimum(int li, int lj, int ri, int rj) {
        return minimum_h(li, lj, ri, rj, 0, H, 0);
    }
    int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if (ri <= si or ti <= li) return INF;
        if (li <= si and ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);
        const int mi = (si + ti) / 2;
        return min(minimum_h(li, lj, ri, rj, si, mi, 2 * k + 1),
                   minimum_h(li, lj, ri, rj, mi, ti, 2 * k + 2));
    }
    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
        if (rj <= sj or tj <= lj) return INF;
        if (lj <= sj and tj <= rj) return dat[i][k];
        const int mj = (sj + tj) / 2;
        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),
                   minimum_w(lj, rj, mj, tj, i, 2 * k + 2));
    }
};
//%snippet.end()%

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

