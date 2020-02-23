#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "./tree.hpp"

signed main() {
  // tree tr(8);
  // tr.add_edge(0, 1, 1);
  // tr.add_edge(0, 2, 1);
  // tr.add_edge(1, 3, 1);
  // tr.add_edge(1, 4, 1);
  // tr.add_edge(4, 6, 1);
  // tr.add_edge(4, 7, 1);
  // tr.add_edge(2, 5, 1);
  //
  // tr.build(2);
  // dump(tr.par);
  // dump(tr.dfstrv);
  // dump(tr.ord);
  // dump(tr.pos);
  // dump(tr.depth);
  // dump(tr.children);
  // dump(tr.euler_tour);
  // dump(tr.et_fpos);
  // dump(tr.lca(3, 5));

  int n,q;cin>>n>>q;
  tree tr(n);
  rep(u, 1, n){
    int p;cin>>p;
    tr.add_edge(p,u);
  }
  tr.build(0);
  rep(_, q){
    int u,v;cin>>u>>v;
    cout << tr.lca(u, v) << endl;
  }
}
