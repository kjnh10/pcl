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


# :warning: codes/cpp/graph/test.make_bipartie/codes/solve.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#6dd0511cf921e627379fb6f893780804">codes/cpp/graph/test.make_bipartie/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/test.make_bipartie/codes/solve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 17:19:22+09:00




## Depends on

* :warning: <a href="../../graph.hpp.html">codes/cpp/graph/graph.hpp</a>
* :warning: <a href="../../unionfind.hpp.html">codes/cpp/graph/unionfind.hpp</a>
* :heavy_check_mark: <a href="../../../template.hpp.html">codes/cpp/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../graph.hpp"

signed main() {
  int n,m;cin>>n>>m;
  Graph<int, int> g(n);
  rep(i, m){
    int a,b;cin>>a>>b;
    a--;b--;
    g.add_edge(a, b, 1);
  }

  auto res = g.make_bipartite();
  dump(res);
  if (res[0]==-1){
    cout << n*(n-1)/2 - m << endl;
  }
  else{
    int c = accumulate(all(res), 0LL);
    cout << c*(n-c) - m << endl;
  }

  return 0;
}

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

#line 3 "codes/cpp/graph/unionfind.hpp"

//%snippet.set('UnionFind')%
struct UnionFind {
  vector<int> data;  // size defined only for root node
  int count;  // count of groups

  UnionFind(){}
  UnionFind(int size) : data(size, -1), count(size){}
  bool merge(int x, int y) {/*{{{*/
    x=root(x); y=root(y);
    if (x!=y) {
      if (data[y]<data[x]) swap(x, y);
      data[x]+=data[y]; data[y]=x;
      count--;
    }
    return x != y;
  }/*}}}*/
  int root(int x) { return (data[x]<0 ? x : data[x]=root(data[x])); }
  bool same(int x,int y){ return root(x)==root(y); }
  int size(int x) { return -data[root(x)]; }

  friend auto& operator<<(auto &os, UnionFind& uf){ //{{{
    map<int, vector<int>> group;
    rep(i, sz(uf.data)){ group[uf.root(i)].pb(i); }
    os << endl; each(g, group){ os << g << endl; }
    return os;
  } //}}}
};
//%snippet.end()%
#line 4 "codes/cpp/graph/graph.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%

template<class Pos=int, class Cost=int, Cost zerocost=0LL, Cost infcost=INF>
struct Graph{
  struct Edge {
    Pos to;
    Cost cost;
    Edge(Pos to, Cost cost): to(to), cost(cost) {
    }
    friend auto& operator<<(auto &os, const Edge& e){
      os << e.to << " " << e.cost;
      return os;
    }
  };

  int n;  // 頂点数
  // unordered_map<Pos, vector<Edge>> adj_list;//Posがpiiでなくintならunordredの方が早い
  vector<vector<Edge>> adj_list;//Posがpiiでなくintならunordredの方が早い
  UnionFind buf;

  Graph(int n): n(n), adj_list(n){}

  void add_edge(Pos from, Pos to, Cost cost){
    adj_list[from].emplace_back(to, cost);
  }

  auto operator[](Pos pos) {
    return adj_list[pos];
  }

  vector<int> make_bipartite(){
    buf = UnionFind(2*n);
    rep(u, n){
      each(e, adj_list[u]){
        buf.merge(u, e.to+n);
        buf.merge(e.to, u+n);
      }
    }

    vector<int> res(n, -1);
    rep(u, n){
      if(buf.same(u, u+n)){
        return res;
      }
    }
    rep(u, n){
      if (buf.same(0, u)) res[u] = 0;
      else res[u] = 1;
    }
    return res;
  }

  void make_dfstree(){
    // lolinkを構築
  }
};

//%snippet.end()%
#line 2 "codes/cpp/graph/test.make_bipartie/codes/solve.cpp"

signed main() {
  int n,m;cin>>n>>m;
  Graph<int, int> g(n);
  rep(i, m){
    int a,b;cin>>a>>b;
    a--;b--;
    g.add_edge(a, b, 1);
  }

  auto res = g.make_bipartite();
  dump(res);
  if (res[0]==-1){
    cout << n*(n-1)/2 - m << endl;
  }
  else{
    int c = accumulate(all(res), 0LL);
    cout << c*(n-c) - m << endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

