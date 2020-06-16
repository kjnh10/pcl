// @ignore
#define IGNORE
// #define PROBLEM "https://yukicoder.me/problems/no/1078" 複数解がある。
#include "../two_sat.hpp"

int main() {
    ll n;cin>>n;
    vector<ll> s(n);
    rep(i, n) { cin>>s[i]; s[i]--; }
    vector<ll> t(n);
    rep(i, n) { cin>>t[i]; t[i]--; }
    vector<ll> u(n);
    rep(i, n) { cin>>u[i]; }

    auto toid = [&](int i, int j) {
        return i * n + j;
    };

    two_sat ts(n*n);
    rep(i, n)rep(j, n){
        if (u[i] == 0) { ts.add_condition(toid(s[i], j), 1, toid(j, t[i]), 1); }
        if (u[i] == 1) { ts.add_condition(toid(s[i], j), 0, toid(j, t[i]), 1); }
        if (u[i] == 2) { ts.add_condition(toid(s[i], j), 1, toid(j, t[i]), 0); }
        if (u[i] == 3) { ts.add_condition(toid(s[i], j), 0, toid(j, t[i]), 0); }
    }
    bool valid = ts.build();
    if (!valid){
        cout << -1 << endl;
        return 0;
    }

    vvl ans(n, vl(n));
    rep(i, n) {
        rep(j, n){
            ans[i][j] = ts.assigned[toid(i, j)];
        }
        rep(j, sz(ans[i])) cout << ans[i][j] << (j!=sz(ans[i])-1 ? " " : "\n");
    }

    return 0; 
}
