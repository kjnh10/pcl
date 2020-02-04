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


# :warning: codes/cpp/string/rollinghash.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f42fe2b40278a2240b94f3b23e9cd7ad">codes/cpp/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/string/rollinghash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-05 02:49:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
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
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

const int mod = 1e9+7;
struct mint { //{{{
  int x;
  mint(int x=0):x((x%mod+mod)%mod){}

  // ?= operator
  mint& operator+=(const mint a) { (x += a.x) %= mod; return *this; }
  mint& operator-=(const mint a) { (x += mod-a.x) %= mod; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint&operator/=(const mint&rhs){return *this*=rhs.inv();}

  mint operator+(const mint a) const { mint res(*this); return res+=a; }
  mint operator-(const mint a) const { mint res(*this); return res-=a; }
  mint operator*(const mint a) const { mint res(*this); return res*=a; }
  mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}

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
  mint inv()const{return pow(mod-2);}
  /*mint inv()const{
    int x,y;
    int g=extgcd(v,mod,x,y);
    assert(g==1);
    if(x<0)x+=mod;
    return mint(x);
    }*/
  friend ostream& operator<<(ostream&os,const mint&m){
    return os<<m.x;
  }
  bool operator<(const mint&r)const{return x<r.x;}
  bool operator==(const mint&r)const{return x==r.x;}
};
//}}}

template<typename T, T MOD, T B>
struct rolling_hash{
  using ll = long long;
  vector<T> hash,bpow;  // 1-index
  rolling_hash(){}
  rolling_hash(vector<T> vs){init(vs);}
  rolling_hash(string &s){
    vector<T> vs;
    for(char c:s) vs.emplace_back(c);
    init(vs);
  }

  void init(vector<T> vs){
    int n=vs.size();
    hash.assign(n+1,0);
    bpow.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;
      bpow[i+1]=(ll)bpow[i]*B%MOD;
    }
  }

  //S[l, r)
  T find(int l,int r){
    T res=(ll)hash[r]+MOD-(ll)hash[l]*bpow[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};

signed main() {
  // https://atcoder.jp/contests/abc150/tasks/abc150_f
  int n;cin>>n;
  vector<int> a(n);
  rep(i, n) { cin>>a[i]; }
  vector<int> b(n);
  rep(i, n) { cin>>b[i]; }

  vi c(n), d(n);
  rep(i, n){
    c[i] = a[i]^a[(i+1)%n];
    d[i] = b[i]^b[(i+1)%n];
  }

  const int B = 1e9+9; // random if codeforces
  rolling_hash<int, mod, B> arh(c);
  rolling_hash<int, mod, B> brh(d);
  mint x = arh.find(0, n);
  mint y = brh.find(0, n);

  vi ans;
  rep(k, n){
    x -= c[k]*arh.bpow[n-1];
    x *= B;
    x += c[k];
    if (x==y) ans.pb((k+1)%n);
  }

  sort(all(ans));
  each(k, ans){
    int x = a[n-1]^b[n-1-k];
    cout << k << " " << x << endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 342, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.bundle.BundleError: codes/cpp/string/rollinghash.cpp: line 44: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

