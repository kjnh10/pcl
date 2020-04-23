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


# :warning: codes/cpp/math/bsgs/bsgs.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#13af3eb46e86c75dd001992172805b75">codes/cpp/math/bsgs</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/math/bsgs/bsgs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 15:35:17+09:00




## Depends on

* :warning: <a href="../mint.hpp.html">codes/cpp/math/mint.hpp</a>
* :x: <a href="../../template.hpp.html">codes/cpp/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('template')%
// template version 1.11
using namespace std;
#include <bits/stdc++.h>

// varibable settings {{{
#define int long long
#define infile "../test/sample-1.in"
// }}}
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
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

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
#endif
//}}}

#include "codes/cpp/math/mint.hpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b){ //{{{
  if (b>=mod) {
    return -1;
  }

  // find x s.t a^x = b in (mod)
  mint x;
  int sq = sqrt(mod);
  // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

  map<int, int> minr; // minr[v]: min(r s.t a^r=v)
  mint ar = 1;
  rep(r, 0, sq){
    if (minr.find(ar.x)==minr.end()) minr[ar.x] = r;
    ar *= a;
  }

  mint A = mint(a).pow(-sq);
  rep(p, 0, sq+1){
    int Ab = (A.pow(p)*b).x;
    if (minr.find(Ab)!=minr.end()){
      int r = minr[Ab];
      return p*sq + r;
    }
  }

  return -1;
} //}}}
// %snippet.end()%

signed main(){
  int a,b,p;cin>>a>>b>>p;
  mod = p;
  cout << bsgs(a, b) << endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/math/bsgs/bsgs.cpp"
//%snippet.set('template')%
// template version 1.11
using namespace std;
#include <bits/stdc++.h>

// varibable settings {{{
#define int long long
#define infile "../test/sample-1.in"
// }}}
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
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

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
#endif
//}}}

#line 2 "codes/cpp/template.hpp"

// template version 1.15
using namespace std;
#line 6 "codes/cpp/template.hpp"

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

#line 3 "codes/cpp/math/mint.hpp"

//%snippet.set('mint')%
int mod = 1e9+7;
// int mod = 998244353;
struct mint { //{{{
    int x;
    mint(int x=0):x((x%mod+mod)%mod){}

    // ?= operator
    mint& operator+=(const mint a) { (x += a.x) %= mod; return *this; }
    mint& operator-=(const mint a) { (x += mod-a.x) %= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint& operator/=(const mint&rhs){
        if (rhs.x==0) throw runtime_error("mint zero division");
        return *this*=rhs.inv(); 
    }

    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }

    mint pow(int n)const{
        mint res(1),x(*this);
        if (n<0){
            n = -n;
            x =(*this).inv();
        }
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }

    mint inv() const{
        if (x==0) throw runtime_error("inv does not exist");
        return pow(mod-2);
    }
    // mint inv()const{
    //     int x,y;
    //     int g=extgcd(v,mod,x,y);
    //     assert(g==1);
    //     if(x<0)x+=mod;
    //     return mint(x);
    // }

    bool operator<(const mint&r)const{return x<r.x;}
    bool operator==(const mint&r)const{return x==r.x;}
};
istream& operator>>(istream& is, const mint& a) {return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}
//}}}
#line 50 "codes/cpp/math/bsgs/bsgs.cpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b){ //{{{
  if (b>=mod) {
    return -1;
  }

  // find x s.t a^x = b in (mod)
  mint x;
  int sq = sqrt(mod);
  // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

  map<int, int> minr; // minr[v]: min(r s.t a^r=v)
  mint ar = 1;
  rep(r, 0, sq){
    if (minr.find(ar.x)==minr.end()) minr[ar.x] = r;
    ar *= a;
  }

  mint A = mint(a).pow(-sq);
  rep(p, 0, sq+1){
    int Ab = (A.pow(p)*b).x;
    if (minr.find(Ab)!=minr.end()){
      int r = minr[Ab];
      return p*sq + r;
    }
  }

  return -1;
} //}}}
// %snippet.end()%

signed main(){
  int a,b,p;cin>>a>>b>>p;
  mod = p;
  cout << bsgs(a, b) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

