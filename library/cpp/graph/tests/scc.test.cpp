#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp"
#include "../strongly_connected_components.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i, m) {
        int from, to;
        cin >> from >> to;
        g.add_edge(from, to);
    }
    StronglyConnectedComponents scc(g);
    dump(scc.comp);
    rep(i, sz(scc.dag.adj_list)){
        dump(scc.dag.adj_list[i]);
    }
    dump(scc._order);

    // 01_small_01.in
    // scc.comp:[0, 0, 2, 1, 0, 0, 4, 3, 3, 3, 3, 4, 4, 4] in [15:main]
    // scc.dag.adj_list[i]:[(0,2), (0,1), (0,4), (0,4)] in [17:main]
    // scc.dag.adj_list[i]:[(1,3), (1,3)] in [17:main]
    // scc.dag.adj_list[i]:[(2,3)] in [17:main]
    // scc.dag.adj_list[i]:[] in [17:main]
    // scc.dag.adj_list[i]:[] in [17:main]
    // scc._order:[0, 3, 2, 7, 8, 9, 10, 1, 5, 11, 12, 13, 6, 4] in [19:main]

    int q;
    cin >> q;
    rep(_, q) {
        int x, y;
        cin >> x >> y;
        if (scc[x] == scc[y]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
