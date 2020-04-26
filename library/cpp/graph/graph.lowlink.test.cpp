#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp"
// 関節点

#include "graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v, 1);
        g.add_edge(v, u, 1);
    }
    g.build_tree(0);
    dump(g.tr);

    auto res = g.get_articulation_points();
    each(el, res) cout << el << endl;
}
