#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=ja"
// 橋

#include "graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v, 1, i);
        g.add_edge(v, u, 1, i);
    }
    g.build_tree(0);
    dump(g.tr);

    auto res = g.get_bridges();
    vector<pii> ans;
    for(auto&&el: res){
        int s = el.from;
        int t = el.to;
        if (s>t) swap(s, t);
        ans.pb(mp(s, t));
    }
    sort(all(ans));
    each(el, ans){
        cout << el.first << " " << el.second << endl;
    }
}
