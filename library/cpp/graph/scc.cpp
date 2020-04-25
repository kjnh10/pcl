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
