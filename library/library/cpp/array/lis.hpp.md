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


# :heavy_check_mark: library/cpp/array/lis.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0e902850ca3e9230d87c81984f25b3bb">library/cpp/array</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/lis.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 20:29:09+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/library/cpp/array/lis.test.cpp.html">library/cpp/array/lis.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"

//%snippet.set('lis')%

template<class T>
int lis(const vector<T>& x, bool strict=true) { /*{{{*/
    int n = sz(x);
    vector<T> dp(n+1, numeric_limits<T>().max());
    vector<pair<int, T>> update_info(n);
    dp[0] = numeric_limits<T>().min();
    int res = 0;
    rep(i, n) {
        int j;
        if (strict) j = lb(all(dp), x[i]) - dp.begin();
        else        j = ub(all(dp), x[i]) - dp.begin();
        chmax(res, j);
        update_info[i] = make_pair(j, dp[j]);
        dp[j] = x[i];
    }
    dump(dp);

    // 復元
    int now_len = res;
    vector<T> lis;
    r_rep(i, n){
        auto [j, pre] = update_info[i];
        if (j==now_len) {
            now_len--;
            lis.push_back(x[i]);
        }
        dp[j] = pre;
    }
    assert(now_len==0);
    reverse(all(lis));
    dump(lis);

    return res;
} /*}}}*/


//%snippet.end()%

// lisにはBITを使ったmethodもある。
// signed main() {
//     vi x({1, 5, 4, 2, 3, 3, 7});
//     auto res = lis(x);
//     auto res_not_strict = lis(x, false);
//     dump(res);
//     dump(res_not_strict);
//     return 0;
// }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "library/cpp/header.hpp"

//%snippet.set('header')%
//%snippet.fold()%
#ifndef HEADER_H
#define HEADER_H

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
const long long INF = 1e18;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T> inline void chmax(T &a, const T &b) { if ((a) < (b)) (a) = (b); }
template <class T> inline void chmin(T &a, const T &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define divceil(a, b) ((a) + (b)-1) / (b)
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast() { std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif /* HEADER_H */
//%snippet.end()%
#line 2 "library/cpp/array/lis.hpp"

//%snippet.set('lis')%

template<class T>
int lis(const vector<T>& x, bool strict=true) { /*{{{*/
    int n = sz(x);
    vector<T> dp(n+1, numeric_limits<T>().max());
    vector<pair<int, T>> update_info(n);
    dp[0] = numeric_limits<T>().min();
    int res = 0;
    rep(i, n) {
        int j;
        if (strict) j = lb(all(dp), x[i]) - dp.begin();
        else        j = ub(all(dp), x[i]) - dp.begin();
        chmax(res, j);
        update_info[i] = make_pair(j, dp[j]);
        dp[j] = x[i];
    }
    dump(dp);

    // 復元
    int now_len = res;
    vector<T> lis;
    r_rep(i, n){
        auto [j, pre] = update_info[i];
        if (j==now_len) {
            now_len--;
            lis.push_back(x[i]);
        }
        dp[j] = pre;
    }
    assert(now_len==0);
    reverse(all(lis));
    dump(lis);

    return res;
} /*}}}*/


//%snippet.end()%

// lisにはBITを使ったmethodもある。
// signed main() {
//     vi x({1, 5, 4, 2, 3, 3, 7});
//     auto res = lis(x);
//     auto res_not_strict = lis(x, false);
//     dump(res);
//     dump(res_not_strict);
//     return 0;
// }

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
