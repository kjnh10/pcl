// #define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "./tree.hpp"

signed main() {
    tree tr(12);
    tr.add_edge(9, 6, 1);
    tr.add_edge(0, 9, 1);
    tr.add_edge(0, 3, 1);
    tr.add_edge(9, 5, 1);
    tr.add_edge(6, 8, 1);
    tr.add_edge(0, 10, 1);
    tr.add_edge(10, 2, 1);
    tr.add_edge(3, 7, 1);
    tr.add_edge(6, 11, 1);
    tr.add_edge(2, 4, 1);
    tr.add_edge(2, 1, 1);
    tr.build(0);
    dump(tr);
    dump(tr.get_range_of_HLD(1, 0));
    return 0;
}
