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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: codes/cpp/rectanglesum.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/rectanglesum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-02 21:18:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//%snippet.set('RectangleSum')%

template <typename T>
struct RectangleSum {
  vector<vector<T>> sum;
  T GetSum(int left, int right, int top, int bottom) { //[left, right], [top, bottom]{{{
    T res = sum[bottom][right];
    if (left > 0) res -= sum[bottom][left - 1];
    if (top > 0) res -= sum[top - 1][right];
    if (left > 0 && top > 0) res += sum[top - 1][left - 1];
    return res;
  }/*}}}*/

  void init(const vector<vector<T>> &s) {/*{{{*/
    int h = s.size();
    int w = s[0].size();
    sum.resize(h);
    for (int i = 0; i < h; i ++) sum[i].resize(w, 0);
    for (int y = 0; y < h; y ++) {
      for (int x = 0; x < w; x ++) {
        sum[y][x] = s[y][x];
        if (y > 0) sum[y][x] += sum[y - 1][x];
        if (x > 0) sum[y][x] += sum[y][x - 1];
        if (y > 0 && x > 0) sum[y][x] -= sum[y - 1][x - 1];
      }
    }
  }/*}}}*/
};

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/rectanglesum.cpp"
#include <bits/stdc++.h>
using namespace std;

//%snippet.set('RectangleSum')%

template <typename T>
struct RectangleSum {
  vector<vector<T>> sum;
  T GetSum(int left, int right, int top, int bottom) { //[left, right], [top, bottom]{{{
    T res = sum[bottom][right];
    if (left > 0) res -= sum[bottom][left - 1];
    if (top > 0) res -= sum[top - 1][right];
    if (left > 0 && top > 0) res += sum[top - 1][left - 1];
    return res;
  }/*}}}*/

  void init(const vector<vector<T>> &s) {/*{{{*/
    int h = s.size();
    int w = s[0].size();
    sum.resize(h);
    for (int i = 0; i < h; i ++) sum[i].resize(w, 0);
    for (int y = 0; y < h; y ++) {
      for (int x = 0; x < w; x ++) {
        sum[y][x] = s[y][x];
        if (y > 0) sum[y][x] += sum[y - 1][x];
        if (x > 0) sum[y][x] += sum[y][x - 1];
        if (y > 0 && x > 0) sum[y][x] -= sum[y - 1][x - 1];
      }
    }
  }/*}}}*/
};

//%snippet.end()%

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

