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


# :heavy_check_mark: library/cpp/array/segtree/segment_tree.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#ebc279bbe94c10384fe9898d1a2c958d">library/cpp/array/segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/segtree/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :heavy_check_mark: <a href="../../graph/graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="../../graph/test.make_bipartie/codes/solve.cpp.html">library/cpp/graph/test.make_bipartie/codes/solve.cpp</a>
* :warning: <a href="../../graph/tree.lib/reroot.cpp.html">library/cpp/graph/tree.lib/reroot.cpp</a>
* :heavy_check_mark: <a href="../../graph/tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/library/cpp/array/segtree/segment_tree.test.cpp.html">library/cpp/array/segtree/segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/graph.dijkstra.test.cpp.html">library/cpp/graph/graph.dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/graph.kruskal.test.cpp.html">library/cpp/graph/graph.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/graph.lowlink.test.cpp.html">library/cpp/graph/graph.lowlink.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/hld.test.cpp.html">library/cpp/graph/tree.lib/hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/lca.test.cpp.html">library/cpp/graph/tree.lib/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../../header.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%

template <typename T>
struct SegmentTree {  // {{{
   private:
    using F = function<T(T, T)>;
    int n;  // 元の配列のサイズ
    int N;  // n以上の最小の2冪
    vector<T> node;
    F merge;
    T identity;

   public:
    SegmentTree() {}
    SegmentTree(vector<T> a, F f, T id) : merge(f), identity(id) {
        n = a.size();
        N = 1;
        while (N < n) N *= 2;
        node.resize(2 * N - 1, identity);
        for (int i = 0; i < n; i++) node[i + N - 1] = a[i];
        for (int i = N - 2; i >= 0; i--)
            node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
    }
    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

    T& operator[](int i) { return node[i + N - 1]; }

    void update(int x, T val) {
        x += (N - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = merge(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    void add(int x, T val) {
        x += (N - 1);
        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = merge(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    // query for [l, r)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = N;
        if (r <= a || b <= l) return identity;
        if (a <= l && r <= b) return node[k];

        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return merge(vl, vr);
    }

#if defined(PCM) || defined(LOCAL)
    friend ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //
        os << "[";
        for (int i = 0; i < sg.n; i++) {
            os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
        }
        return os;
    }
#endif
};
// }}}
// Sample:
// -----------------------------------------------
// auto mymin=[](auto a, auto b){return min(a,b);};
// SegmentTree<int> seg(a, mymin, 1e18);

// auto mymax=[](auto a, auto b){return max(a,b);};
// SegmentTree<int> seg(a, mymax, -1e18);

// auto add=[](auto a, auto b){return a+b;};
// SegmentTree<int> seg(a, add, 0);
// -----------------------------------------------

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

