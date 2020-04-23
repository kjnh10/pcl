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


# :warning: codes/cpp/array/syakutori.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2ccaf388340b410f2f5de77ef560fb20">codes/cpp/array</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/array/syakutori.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 12:58:45+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('syakutori')%
//%snippet.config({'abbr':'syakutori-hou-[l,r)', 'indent':True})%
  int res = 0;
  int sum = 0;

  auto isok=[&](int r){ // [l, r] e.g [l, r+1) is ok?
    if (sum + s[r-1]<=k) return true;
    else               return false;
  };

  int r = 0;
  for (int l=0; l<n; ++l) {
    while (r<n && isok(r+1)) {
      sum += s[r];
      ++r;
    }
    chmax(res, (r-l));

    // leftをincrementする準備
    if (r==l) ++r;  // l,rが同時に動くのでsumは変動しない。
    else sum -= s[l];
  }
//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/array/syakutori.cpp"
//%snippet.set('syakutori')%
//%snippet.config({'abbr':'syakutori-hou-[l,r)', 'indent':True})%
  int res = 0;
  int sum = 0;

  auto isok=[&](int r){ // [l, r] e.g [l, r+1) is ok?
    if (sum + s[r-1]<=k) return true;
    else               return false;
  };

  int r = 0;
  for (int l=0; l<n; ++l) {
    while (r<n && isok(r+1)) {
      sum += s[r];
      ++r;
    }
    chmax(res, (r-l));

    // leftをincrementする準備
    if (r==l) ++r;  // l,rが同時に動くのでsumは変動しない。
    else sum -= s[l];
  }
//%snippet.end()%

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

