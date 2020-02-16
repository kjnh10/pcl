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


# :warning: codes/cpp/graph/topological_sort.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 15:20:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// template version 1.12
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// varibable settings
#define infile "../test/sample-1.in"
#define int long long //{{{
const int INF=1e18;
const int MOD=1e9+7; //}}}

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
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

//%snippet.set('topological_sort')%
//%snippet.config({'alias':'tps'})%
template<class node>
using graph = vector<vector<node>>;

template<class node>
pair<vector<node>, int> topological_sort(const graph<node>& G){
  int V = sz(G);  // node数
  vector<node> ans;  // sort後の結果を格納
  vector<int> h(V); // 頂点ごとの入次数
  stack<node> st;  // 入次数が0になっている頂点の集合
  int max_len = 0; // 最長経路の長さ
/*{{{*/
  // 入次数を計算する。
  rep(v, V){
    for(auto to: G[v]){
      h[to]++;
    }
  }

  // 最初に入次数0になっている頂点を集める。
  rep(v, V){
    if (h[v]==0){
      st.push(v); 
      ans.push_back(v);
    }
  }

  // 入次数0の頂点をansに追加しそこから出て行く辺は削除していく。O(V+E)
  while(!st.empty()){
    stack<node> nex_st;
    while(!st.empty()){
      node v = st.top();st.pop();
      for(auto to: G[v]){
        h[to]--;
        if (h[to]==0){
          ans.push_back(to);
          nex_st.push(to);
        }
      }
    }
    max_len++;
    st = nex_st;
  }
/*}}}*/
  return make_pair(ans, max_len);  // ans.size()<Vなら閉路がありDAGではない。閉路内の頂点はstに入り得ないので。
}
//%snippet.end()%


int solve(){  // ABC139 E:https://atcoder.jp/contests/abc139
// input
  int n;cin>>n;
  int m = n*(n-1)/2;

  vvi M(n);
  rep(i, n){
    rep(j, n-1){
      int a;cin>>a;a--;
      M[i].pb(a);
    }
  }
  dump_2d(M, n, n-1);

// encode pair<int, int> -> int
  int id = 0;
  vvi idtable(n, vi(n));
  rep(i, n)rep(j, i+1, n){
    idtable[i][j] = id++;
  }
  auto toid = [&](int i, int j){
    if (i>j) swap(i,j);
    return idtable[i][j];
  };

// generate graph
  graph<int> g(m+2);
  vi h(m+2);
  rep(i, n){
    rep(j, 1, n-1){
      int pre = M[i][j-1];
      int to = M[i][j];
      g[toid(i, pre)].pb(toid(i,to));
      h[toid(i, to)]++;
    }
  }
  dump(g);

// answer
  auto ans = topological_sort(g);
  cout << ((sz(ans.first)<m)?-1:ans.second) << endl;
  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: codes/cpp/graph/topological_sort.cpp: line 44: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

