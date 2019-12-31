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


# :warning: codes/cpp/modcomb.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/modcomb.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-04 23:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//%snippet.set('com')%
const int MAX = 510000;
const int MOD = 1000000007;
// Calculate COM(MAX, k) for k<=MAX by O(1) after COMinit() by O(MAX)
// {{{
ll fac[MAX], finv[MAX], inv[MAX];

// 前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//}}}
//%snippet.end()%

int main() {
    // 前処理
    COMinit();

    // 計算例
    assert(COM(5, 2) == 10);
    cout << COM(10, 3) << endl;  // 120
}

// ref: [http://drken1215.hatenablog.com/entry/2018/06/08/210000]

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/modcomb.cpp"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//%snippet.set('com')%
const int MAX = 510000;
const int MOD = 1000000007;
// Calculate COM(MAX, k) for k<=MAX by O(1) after COMinit() by O(MAX)
// {{{
ll fac[MAX], finv[MAX], inv[MAX];

// 前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//}}}
//%snippet.end()%

int main() {
    // 前処理
    COMinit();

    // 計算例
    assert(COM(5, 2) == 10);
    cout << COM(10, 3) << endl;  // 120
}

// ref: [http://drken1215.hatenablog.com/entry/2018/06/08/210000]

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

