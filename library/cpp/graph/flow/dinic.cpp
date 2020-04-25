#include "../../header.hpp"

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
