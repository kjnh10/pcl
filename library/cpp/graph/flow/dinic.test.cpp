#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp"
#include "dinic.hpp"

int main(){
    int n,m;cin>>n>>m;
    Graph g(n);
    rep(i, m){
        int u,v,c;cin>>u>>v>>c;
        g[u].emplace_back(u, v, c);
    }
    dinic<int> din(g);
    int max_flow = din.solve(0, n-1);
    cout << max_flow << endl;
}
