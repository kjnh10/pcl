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


# :warning: codes/cpp/flow/dinic.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#682f2e9a44f3ba26447e5aba3266306e">codes/cpp/flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/flow/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 01:09:17+09:00




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

// Dinic: https://tubo28.me/compprog/algorithm/dinic/
using Capacity = int;
struct Edge {
  int src, dst;
  Capacity cap;
  Edge(int src_, int dst_, Capacity cap_) :
    src(src_), dst(dst_), cap(cap_) { }
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;
template<typename Flow> struct dinic {
  int n, s, t;
  vector<int> level, prog, que;
  vector<vector<Flow>> cap, flow;
  vector<vector<int>> g;
  Flow inf;
  dinic(const Graph &graph)
    : n(graph.size()),
      cap(n, vector<Flow>(n)),
      flow(n, vector<Flow>(n)),
      g(n, vector<int>()),
      inf(numeric_limits<Flow>::max() / 8) {
    for (int i = 0; i < n; i++) {
      for (auto &e : graph[i]) {
        int u = e.src, v = e.dst;
        Flow c = e.cap;
        cap[u][v] += c;
        cap[v][u] += c;
        flow[v][u] += c;
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
  }
  inline Flow residue(int u, int v) { return cap[u][v] - flow[u][v]; }

  Flow solve(int s_, int t_) {
    this->t = t_, this->s = s_;
    que.resize(n + 1);
    Flow res = 0;
    while (levelize()) {
      prog.assign(n, 0);
      res += augment(s, inf);
    }
    return res;
  }
  bool levelize() {
    int l = 0, r = 0;
    level.assign(n, -1);
    level[s] = 0;
    que[r++] = s;
    while (l != r) {
      int v = que[l++];
      if (v == t) break;
      for (const int &d : g[v])
        if (level[d] == -1 && residue(v, d) != 0) {
          level[d] = level[v] + 1;
          que[r++] = d;
        }
    }
    return level[t] != -1;
  }
  Flow augment(int v, Flow lim) {
    Flow res = 0;
    if (v == t) return lim;
    for (int &i = prog[v]; i < (int)g[v].size(); i++) {
      const int &d = g[v][i];
      if (residue(v, d) == 0 || level[v] >= level[d]) continue;
      const Flow aug = augment(d, std::min(lim, residue(v, d)));
      flow[v][d] += aug;
      flow[d][v] -= aug;
      res += aug;
      lim -= aug;
      if (lim == 0) break;
    }
    return res;
  }
};

signed main() {
  int L,D;cin>>L>>D;
  int n;cin>>n;

  Graph g(2*(n+1));
  vi x(n), y(n), r(n);
  rep(i, n){
    cin>>x[i]>>y[i]>>r[i];
    // 2*i: 入頂点
    // 2*i+1: 出頂点
    g[2*i].emplace_back(2*i, 2*i+1, 1);  // 頂点を２つに分ける。
  }
  dump(x);
  dump(y);
  dump(r);

  rep(i, n)rep(j, n){
    if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= (r[i]+r[j])*(r[i]+r[j])){
      g[2*i+1].emplace_back(2*i+1, 2*j, 1);
      g[2*j+1].emplace_back(2*j+1, 2*i, 1);
    }
  }

  rep(i, n){
    // 2*n:   y = D
    // 2*n+1: y = -D
    if (y[i]+r[i]>=D){
      g[2*n].emplace_back(2*n, 2*i, 1);
    }
    if (y[i]-r[i]<=-D){
      // g[2*n+1].emplace_back(2*n+1, 2*i, 1);
      g[2*i+1].emplace_back(2*i+1, 2*n+1, 1);
    }
  }

  dinic<int> din(g);
  int mincut = din.solve(2*n, 2*n+1);
  cout << mincut << endl;

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
onlinejudge_verify.bundle.BundleError: codes/cpp/flow/dinic.cpp: line 44: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

