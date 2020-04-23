#pragma once
#include "template.hpp"
#include "graph/unionfind.hpp"

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
