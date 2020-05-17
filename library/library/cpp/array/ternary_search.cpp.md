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


# :warning: library/cpp/array/ternary_search.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0e902850ca3e9230d87c81984f25b3bb">library/cpp/array</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/ternary_search.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-18 01:47:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('tsearch')%
ll l = 0;
ll r = 1000000001;

// ll num = 100;
// while(num--){
while(r-l>2){
    ll d = (r-l)/3;
    ll ml = l + d;
    ll mr = l + 2*d;
    if ((score(ml) < score(mr))){
        r = mr;
    }
    else{
        l = ml;
    }
}
dump(l, r);
ll ans = INF;
rep(i, l, r+1) chmin(ans, score(i));

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/array/ternary_search.cpp"
//%snippet.set('tsearch')%
ll l = 0;
ll r = 1000000001;

// ll num = 100;
// while(num--){
while(r-l>2){
    ll d = (r-l)/3;
    ll ml = l + d;
    ll mr = l + 2*d;
    if ((score(ml) < score(mr))){
        r = mr;
    }
    else{
        l = ml;
    }
}
dump(l, r);
ll ans = INF;
rep(i, l, r+1) chmin(ans, score(i));

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

