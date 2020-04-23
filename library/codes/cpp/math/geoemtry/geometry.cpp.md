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


# :warning: codes/cpp/math/geoemtry/geometry.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#1c523b37df8bf18147b947ed8ab931bc">codes/cpp/math/geoemtry</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/math/geoemtry/geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 14:21:22+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// template version 1.9

// varibable settings {{{
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define int long long
const int INF=1e18;
const int MOD=1e9+7;
#define infile "../test/sample-1.in"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define fi first
#define se second

// }}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;

// dump macro
#ifdef PCM
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

//%snippet.set('Pos')%
struct Pos{
  int x,y;
  Pos(int _x, int _y) : x(_x), y(_y){
  }
  Pos() {
    x = 0; y = 0;
  }
  bool in(int a, int b, int c, int d){ // x in [a, b) && y in [c, d)
    if (a<=x && x<b && c<=y && y<d) return true;
    else return false;
  }

  bool operator<(const Pos &r) const { return (x!=r.x ? x<r.x : y<r.y); }
  bool operator>(const Pos &r) const { return (x!=r.x ? x>r.x : y>r.y); }
  bool operator==(const Pos &r) const { return (x==r.x && y==r.y); }

  friend ostream& operator<<(ostream& stream, Pos p){
    stream << "(" << p.x <<  "," << p.y << ")";
    return stream;
  }
};
//%snippet.config({'alias':'pos'})%
//%snippet.end%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/math/geoemtry/geometry.cpp"
// template version 1.9

// varibable settings {{{
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define int long long
const int INF=1e18;
const int MOD=1e9+7;
#define infile "../test/sample-1.in"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define fi first
#define se second

// }}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;

// dump macro
#ifdef PCM
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

//%snippet.set('Pos')%
struct Pos{
  int x,y;
  Pos(int _x, int _y) : x(_x), y(_y){
  }
  Pos() {
    x = 0; y = 0;
  }
  bool in(int a, int b, int c, int d){ // x in [a, b) && y in [c, d)
    if (a<=x && x<b && c<=y && y<d) return true;
    else return false;
  }

  bool operator<(const Pos &r) const { return (x!=r.x ? x<r.x : y<r.y); }
  bool operator>(const Pos &r) const { return (x!=r.x ? x>r.x : y>r.y); }
  bool operator==(const Pos &r) const { return (x==r.x && y==r.y); }

  friend ostream& operator<<(ostream& stream, Pos p){
    stream << "(" << p.x <<  "," << p.y << ")";
    return stream;
  }
};
//%snippet.config({'alias':'pos'})%
//%snippet.end%

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

