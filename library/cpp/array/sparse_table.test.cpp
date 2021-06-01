#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "sparse_table.hpp"

int main(){
    ll N,Q;cin>>N>>Q;
    vector<ll> a(N);
    rep(n, N) cin>>a[n];

    sparse_table<ll> sp(a);
    rep(q, Q){
        ll l,r;cin>>l>>r;
        cout << sp.query(l, r) << endl;
    }
}
