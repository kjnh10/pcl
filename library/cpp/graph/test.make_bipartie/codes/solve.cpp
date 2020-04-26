#include "../../graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph<int, int> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b, 1);
    }

    auto res = g.make_bipartite();
    dump(res);
    if (res[0] == -1) {
        cout << n * (n - 1) / 2 - m << endl;
    } else {
        int c = accumulate(all(res), 0LL);
        cout << c * (n - c) - m << endl;
    }

    return 0;
}
