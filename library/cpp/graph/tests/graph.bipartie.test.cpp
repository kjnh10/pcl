#define PROBLEM "https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c"
#include "../graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph<ll> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
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
