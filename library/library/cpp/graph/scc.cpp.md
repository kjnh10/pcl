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


# :warning: library/cpp/graph/scc.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 00:22:11+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../../problem_template/codes/header.hpp"

//%snippet.set('StronglyConnectedComponents')%
//%snippet.config({'alias':'scc'})%
using Graph = vector< vector< int > >;
struct StronglyConnectedComponents {
  // how to use
  // StronglyConnectedComponents scc(g); // g: Graph
  // scc.build();
  // dump(scc.comp, scc.dag);

  const Graph &g; //{{{
  vector< int > comp;  // comp[i]: iが属する強連結成分が何番目の成分か
  Graph dag;  // 縮約されたDAG graph. sizeをとれば強連結成分の個数が分かる。
  Graph _rg;  // reversed graph
  vector< int > _order; // order[i]: 行きがけの番号
  vector< int > _used;

  StronglyConnectedComponents(Graph &g)
    : g(g), comp(g.size(), -1), _rg(g.size()), _used(g.size()) {
    for(int i = 0; i < sz(g); i++) {
      for(auto e : g[i]) {
        _rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void build() {
    for(int i = 0; i < sz(g); i++) _dfs(i);
    reverse(begin(_order), end(_order));
    int cnt = 0;
    for(int i : _order) if(comp[i] == -1) _rdfs(i, cnt), cnt++;

    dag.resize(cnt);
    for(int i = 0; i < sz(g); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        dag[x].push_back(y);
      }
    }
  }

  void _dfs(int idx) {
    if(_used[idx]) return;
    _used[idx] = true;
    for(int to : g[idx]) _dfs(to);
    _order.push_back(idx);
  }

  void _rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : _rg[idx]) _rdfs(to, cnt);
  } //}}}
};
//%snippet.end()%

int solve(){
  int n,m;cin>>n>>m;
  Graph g(n);
  rep(i, m){
    int from,to;cin>>from>>to;
    g[from].pb(to);
  }
  StronglyConnectedComponents scc(g);
  scc.build();
  dump(scc.comp);
  dump(scc.dag);
  int q;cin>>q;
  rep(_, q){
    int x,y;cin>>x>>y;
    if (scc[x]==scc[y]){
      cout << 1 << endl;
    }
    else{
      cout << 0 << endl;
    }
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
#line 2 "library/cpp/header.hpp"

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define r_rep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x)-A.begin())
#define upos(A, x) (upper_bound(all(A),x)-A.begin())
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
  #define dump(...) ;
  #define dump_1d(...) ;
  #define dump_2d(...) ;
  #define cerrendl ;
#endif

#line 2 "library/cpp/graph/scc.cpp"

//%snippet.set('StronglyConnectedComponents')%
//%snippet.config({'alias':'scc'})%
using Graph = vector< vector< int > >;
struct StronglyConnectedComponents {
  // how to use
  // StronglyConnectedComponents scc(g); // g: Graph
  // scc.build();
  // dump(scc.comp, scc.dag);

  const Graph &g; //{{{
  vector< int > comp;  // comp[i]: iが属する強連結成分が何番目の成分か
  Graph dag;  // 縮約されたDAG graph. sizeをとれば強連結成分の個数が分かる。
  Graph _rg;  // reversed graph
  vector< int > _order; // order[i]: 行きがけの番号
  vector< int > _used;

  StronglyConnectedComponents(Graph &g)
    : g(g), comp(g.size(), -1), _rg(g.size()), _used(g.size()) {
    for(int i = 0; i < sz(g); i++) {
      for(auto e : g[i]) {
        _rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void build() {
    for(int i = 0; i < sz(g); i++) _dfs(i);
    reverse(begin(_order), end(_order));
    int cnt = 0;
    for(int i : _order) if(comp[i] == -1) _rdfs(i, cnt), cnt++;

    dag.resize(cnt);
    for(int i = 0; i < sz(g); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        dag[x].push_back(y);
      }
    }
  }

  void _dfs(int idx) {
    if(_used[idx]) return;
    _used[idx] = true;
    for(int to : g[idx]) _dfs(to);
    _order.push_back(idx);
  }

  void _rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : _rg[idx]) _rdfs(to, cnt);
  } //}}}
};
//%snippet.end()%

int solve(){
  int n,m;cin>>n>>m;
  Graph g(n);
  rep(i, m){
    int from,to;cin>>from>>to;
    g[from].pb(to);
  }
  StronglyConnectedComponents scc(g);
  scc.build();
  dump(scc.comp);
  dump(scc.dag);
  int q;cin>>q;
  rep(_, q){
    int x,y;cin>>x>>y;
    if (scc[x]==scc[y]){
      cout << 1 << endl;
    }
    else{
      cout << 0 << endl;
    }
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

<a href="../../../../index.html">Back to top page</a>

