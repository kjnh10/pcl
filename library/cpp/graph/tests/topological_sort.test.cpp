// @ignore
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp"
#define IGNORE
#include "../topological_sort.hpp"

signed main() {
    int n,m;cin>>n>>m;
    Graph g(n);
    rep(i, m){
        int s,t;
        cin>>s>>t;
        g.add_edge(s, t);
    }
    auto [is_valid, ans, max_len] = topological_sort(g);
    rep(i, sz(ans)) cout << ans[i] << endl;

    return 0;
}
