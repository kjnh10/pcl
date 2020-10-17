#include "../../header.hpp"
//%snippet.set('mincostflow')%
//%snippet.config({'alias':'mcf'})%
//%snippet.fold()%

#include <atcoder/mincostflow>
using namespace atcoder;

mcf_graph<ll, ll> g(2*n + 4);
// auto debug = [&](){
//     auto edges = (g.edges());
//     for (auto& e : edges){ dump(e.from, e.to, e.cap, e.flow, e.cost); }
// };
ll s0 = 2*n;     // super source
ll s1 = 2*n+1;   // original source
ll t1 = 2*n+2;   // original target
ll t0 = 2*n+3;   // super target

ll total_cost = 0;
ll surplus_at_super_source = 0;
auto add_negative_edge = [&](ll u, ll v, ll cap, ll cost){
    assert(cost <= 0);
    g.add_edge(s0, v, cap, 0);
    g.add_edge(u, t0, cap, 0);
    g.add_edge(v, u, cap, -cost);
    total_cost += cost;
    surplus_at_super_source += cap;
};

// add edge
g.add_edge(t1, s1, inf<ll>, 0);
rep(x, n) g.add_edge(s1, x, k, 0);
rep(x, n, 2*n) g.add_edge(x, t1, k, 0);
rep(i, n)rep(j, n) add_negative_edge(i, n+j, 1, -a[i][j]);

auto res = g.flow(s0, t0, surplus_at_super_source);
cout << -(total_cost + res.second) << endl;

// 復元
auto edges = (g.edges());
vec<string> ans(n, string(n, '.'));
for (auto& e : edges){
    if (e.flow == 0 && e.cost > 0){
        ans[e.to][e.from-n] = 'X';
    }
}
rep(i, n) cout << ans[i] << endl;

//%snippet.end()%
