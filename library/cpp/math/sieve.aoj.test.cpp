#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"

#include "sieve.hpp"

int main(){
    ll n;cin>>n;
    auto ps = sv.prime_factor(n);

    vector<ll> ans;
    each(el, ps){
        auto [p, c] = el;
        rep(_, c) ans.pb(p);
    }

    cout << n << ": ";
    rep(i, sz(ans)) cout << ans[i] << (i!=sz(ans)-1 ? " " : "\n");
}
