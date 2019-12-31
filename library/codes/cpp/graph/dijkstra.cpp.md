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


# :warning: codes/cpp/graph/dijkstra.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-28 23:53:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// template version 1.8

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
  #include "dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

//%snippet.set('dijkstra')%

using COST = int;  // TODO: update
using POS = pair<int, int>;  // TODO: update
using EDGE = pair<POS, COST>;
struct GRAPH{
  map<POS, vector<EDGE>> all_edges;
  vector<POS> all_nodes;

  void add_edge(POS from, POS to, COST cost){
    all_edges[from].emplace_back(mp(to, cost));
  }

  auto operator[](POS pos){
    return all_edges[pos];
  }
};
auto& operator<<(auto& stream, GRAPH G){
  stream << G.all_edges;
  return stream;
}

map<POS, COST> dijkstra(GRAPH& G, POS start){
  map<POS, COST> d;  // 最短距離
  each(node, G.all_nodes) {d[node] = INF;}

  PQ<pair<COST, POS>> q;
  q.push(mp(0LL, start));
  while (!q.empty()){
    auto cp = q.top(); q.pop();
    auto cost = cp.first;
    auto pos = cp.second;

    if (cost < d[pos]) {
      d[pos] = cost;
      for (const auto &el:G[pos]){
        auto ncost = cost + el.second;
        auto npos = el.first;
        if (ncost < d[npos]) q.push(mp(ncost, npos));
      }
    }
  }
  return d;
}

// int sample(){
//   // init and build G
//   GRAPH G;
//
//   int n,m;cin>>n>>m;
//   rep(i, n) G.all_nodes.pb(i);  // add node
//   rep(i, m){
//     POS from, to;
//     COST cost;
//     cin>>from>>to>>cost;
//     from--;to--;
//     G.add_edge(from, to, cost);
//     G.add_edge(to, from, cost);  // TODO: if directed, remove this line
//   }
//
//   // calc min distance by G
//   POS start=...;
//   POS goal=...;
//   auto d = dijkstra(G, start);
//   cout << d[goal] << endl;
//   return 0;
// }

//%snippet.end()%

int solve(){
  int N,M,K;cin>>N>>M>>K;

  // build G
  GRAPH G;
  rep(i, M){
    int a,b,c;
    cin>>a>>b>>c;a--;b--;
    rep(k, K+1){
      G.add_edge(mp(a, k), mp(b, k), c);
      G.add_edge(mp(b, k), mp(a, k), c);
    }
  }
  rep(i, N){
    int x,y;cin>>x>>y;
    if (x==0) continue;
    rep(j, K) G.add_edge(mp(i, j), mp(i, min(j+x, K)), y);
  }

  // call dijkstra with G
  auto d = dijkstra(G, mp(0, 0));
  if (d.find(mp(N-1, K))!=d.end()){
    cout << d[mp(N-1, K)] << endl;
  }
  else{
    cout << -1 << endl;
  }
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 153, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.bundle.BundleError: codes/cpp/graph/dijkstra.cpp: line 45: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

