#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "kth_root.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    tree tr(n);
    rep(u, 1, n) {
        int p;
        cin >> p;
        tr.add_edge(p, u);
    }
    tr.build(0);

    auto ta = kth_root(tr);

    rep(_, q) {
        int u, v;
        cin >> u >> v;
        cout << ta.lca(u, v) << endl;
    }
}
