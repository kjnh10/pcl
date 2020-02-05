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
<script type="text/javascript" src="../../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../../assets/css/copy-button.css" />


# :warning: codes/cpp/string/suffix_array/codes/solve.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#319ca7f5ba57e96381c85edf1b8dc54b">codes/cpp/string/suffix_array/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/string/suffix_array/codes/solve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-05 13:24:54+09:00




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

struct suffix_array{
  vector<int> a, order, lcp;
  int n;

  suffix_array(){}
  suffix_array(vector<int>& a) : a(a), n(a.size()){}
  suffix_array(string& s){
    n = s.size();
    a.resize(n);
    rep(i, n) a[i] = s[i];
  }

  void build(){
    _build_order();
    // _build_lcp();
  }

  void _build_order(){
    order.resize(n);
    iota(all(order), 0);
    vector<int> rank(a);  // k=1でのrank. rank[i]: iのスコア

    for (int k=1; k<n; k*=2){
      // kでのrankが生成されている前提で2*kでのrankを生成する

      auto _comp = [&](int l, int r){
        auto left = mp(rank[l], (l+k<n ? rank[l+k] : -1));
        auto right = mp(rank[r], (r+k<n ? rank[r+k] : -1));
        return left < right;
      };
      sort(all(order), _comp);

      vector<int> next_rank(n);
      next_rank[order[0]] = 0;
      int r = 0;
      rep(i, 1, n){
        if (_comp(order[i-1], order[i])) r++;
        next_rank[order[i]] = r;
      }
      rank = next_rank;
    }
  }

  void _build_lcp(){
  }
};

signed main() {
  // string s = "adcdacbdcab";
  // string s = "aaaaa";
  string s;cin>>s;

  suffix_array sa(s);
  sa.build();
  dump(sa.order);

  rep(i, sz(sa.order)) cout << sa.order[i] << (i!=sz(sa.order)-1 ? " " : "\n");
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
onlinejudge_verify.bundle.BundleError: codes/cpp/string/suffix_array/codes/solve.cpp: line 44: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

