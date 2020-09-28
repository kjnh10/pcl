#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "tree_non_recursive.hpp"

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
    rep(_, q) {
        int u, v;
        cin >> u >> v;
        cout << tr.lca(u, v) << endl;
    }
}
