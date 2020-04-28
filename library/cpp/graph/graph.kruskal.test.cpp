#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp"

#include "../header.hpp"
#include "graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, 0LL, INF);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c, i);
        g.add_edge(b, a, c, i);
    }
    auto ks = g.kruskal_tree();
    int ans = 0;
    each(e, ks) ans += e.cost;
    cout << ans << endl;

    return 0;
}
