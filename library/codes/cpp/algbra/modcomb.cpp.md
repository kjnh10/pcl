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


# :warning: codes/cpp/algbra/modcomb.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#23a23c125caf8741d8c92b2934bce27d">codes/cpp/algbra</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/algbra/modcomb.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-23 17:29:25+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//%snippet.set('com')%
// %snippet.include('mint')%
struct combination {  // {{{
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} // }}}
com(500001);
//%snippet.end()%


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/algbra/modcomb.cpp"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//%snippet.set('com')%
// %snippet.include('mint')%
struct combination {  // {{{
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} // }}}
com(500001);
//%snippet.end()%


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

