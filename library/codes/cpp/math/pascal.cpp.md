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


# :warning: codes/cpp/math/pascal.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#29eb2bc680bfa8c6d4c98720ef2f247a">codes/cpp/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/math/pascal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 17:19:22+09:00




## Depends on

* :heavy_check_mark: <a href="../template.hpp.html">codes/cpp/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.hpp"

//%snippet.set('pascal')%

template<class T> vector<vector<T>> pascal(int N){ // {{{
    vector<vector<T>> com(N+1, vector<T>(N+1));
    com[0][0] = 1;
    rep(i, 1, N+1){
        // パスカルの三角形は0-indexdで段を数えるとよい。
        // com[i]を計算。
        rep(j, 0, i+1){
            if (j-1>=0) com[i][j] += com[i-1][j-1];
            com[i][j] += com[i-1][j];
            // com[i][j] /= 2.0;  // probability version
        }
    }
    return com;
} // }}}

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "codes/cpp/template.hpp"

// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
  #define cerrendl 42
#endif

#line 2 "codes/cpp/math/pascal.cpp"

//%snippet.set('pascal')%

template<class T> vector<vector<T>> pascal(int N){ // {{{
    vector<vector<T>> com(N+1, vector<T>(N+1));
    com[0][0] = 1;
    rep(i, 1, N+1){
        // パスカルの三角形は0-indexdで段を数えるとよい。
        // com[i]を計算。
        rep(j, 0, i+1){
            if (j-1>=0) com[i][j] += com[i-1][j-1];
            com[i][j] += com[i-1][j];
            // com[i][j] /= 2.0;  // probability version
        }
    }
    return com;
} // }}}

//%snippet.end()%

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

