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


# :warning: codes/cpp/zip.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/zip.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-28 13:23:04+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('zip')%

// zip: a = [3, 10, 5, 5, 2]
vector<int> unzipper; // [2, 3, 5, 10]
map<int, int> zipper; // [2:0, 3:2, 5:3, 10:4]
vector<int> zipped; // [2, 4, 3, 3, 0]
auto zip=[&](vector<int> a){
    int n = sz(a);
    unzipper = vector<int>(n); zipped = vector<int>(n);
    rep(i, n) { unzipper[i]=a[i]; }
    uni(unzipper);
    rep(i, sz(unzipper)){ zipper[unzipper[i]] = i; }
    rep(i, n){ zipped[i] = zipper[a[i]]; }
    return 0;
};
zip(/*your vector*/);
dump(unzipper); dump(zipper); dump(zipped);

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/zip.cpp"
//%snippet.set('zip')%

// zip: a = [3, 10, 5, 5, 2]
vector<int> unzipper; // [2, 3, 5, 10]
map<int, int> zipper; // [2:0, 3:2, 5:3, 10:4]
vector<int> zipped; // [2, 4, 3, 3, 0]
auto zip=[&](vector<int> a){
    int n = sz(a);
    unzipper = vector<int>(n); zipped = vector<int>(n);
    rep(i, n) { unzipper[i]=a[i]; }
    uni(unzipper);
    rep(i, sz(unzipper)){ zipper[unzipper[i]] = i; }
    rep(i, n){ zipped[i] = zipper[a[i]]; }
    return 0;
};
zip(/*your vector*/);
dump(unzipper); dump(zipper); dump(zipped);

//%snippet.end()%

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

