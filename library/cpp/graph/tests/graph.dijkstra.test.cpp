#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C"

#include "../../header.hpp"
#include "../graph.hpp"

signed main() {
    int n;
    cin >> n;
    Graph g(n);
    rep(i, n) {
        int u;
        cin >> u;
        int k;
        cin >> k;
        rep(j, k) {
            int to, cost;
            cin >> to >> cost;
            g.add_edge(u, to, cost, i);
        }
    }
    auto d = g.dijkstra(0);
    rep(i, n) { cout << i << " " << d[i] << endl; }

    return 0;
}
