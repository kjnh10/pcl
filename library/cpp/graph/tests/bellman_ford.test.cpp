#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp"
#include "../bellman_ford.hpp"

signed main() {
    int n, m, s;
    cin >> n >> m >> s;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g.add_edge(from, to, cost);
    }

    auto [negative_cycle, d] = bellman_ford(g, s);
    if (negative_cycle){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        rep(u, n){
            cout << (d[u]==INF ? "INF" : to_string(d[u])) << endl;
        }
    }

    return 0;
}
