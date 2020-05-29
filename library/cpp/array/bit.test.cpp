#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "bit.hpp"

int main(){
    ll N,Q;cin>>N>>Q;
    vector<ll> a(N);
    rep(i, N) {
        cin>>a[i];
    }

    bit<ll> b(a);
    rep(q, Q){
        int t;cin>>t;
        if (t==0){
            int i;cin>>i;
            ll x;cin>>x;
            b.add(i, x);
        }
        if (t==1){
            int l,r;cin>>l>>r;
            cout << b.query(l, r) << endl;
        }
    }
}
