#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../segment_tree_lazy.rsq_raffinq.hpp"

int main(){
    ll n,q;cin>>n>>q;
    vector<ll> a(n);

    rep(i, n) { cin>>a[i]; }
    auto lseg = make_lseg_rsq_raffinq();
    vector<X> b(n);
    rep(i, n) b[i] = X(a[i], 1);
    lseg.build(b);

    rep(i, q){
        int ty;cin>>ty;
        if (ty == 0){
            ll l,r,b,c;cin>>l>>r>>b>>c;
            lseg.update(l, r, M(b, c));
        }
        if (ty == 1){
            ll l,r;cin>>l>>r;
            cout << lseg.query(l, r).x << endl;
        }
    }
}


