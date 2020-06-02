#define PROBLEM "https://yukicoder.me/problems/no/30"
#include "../topological_sort.hpp"


int main() {
    ll n;cin>>n;
    ll m;cin>>m;

    Graph<ll> g(n);
    rep(i, m){
        ll a,c,b;cin>>a>>c>>b;
        a--;b--;
        g.add_edge(b, a, c);
    }
    auto tp = get<1>(topological_sort(g));

    vl ans(n-1);
    vl cnt(n);
    cnt[n-1] = 1;
    each(u, tp){
        each(edge, g.adj_list[u]) cnt[edge.to] += cnt[u] * edge.cost;
        if (g.adj_list[u].empty()) ans[u] += cnt[u];
    }
    rep(i, n-1) cout << ans[i] << endl;
    return 0; 
}
