#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"
#include "initialization/segment_tree_lazy.rsq_ruq.hpp"

int main(){
    ll n,q;cin>>n>>q;
    auto lseg = make_lseg_rsq_ruq();
    const int sz = n;
    lseg.build(vector<X>(sz, X(0, 1)));
    rep(i, q){
        int ty;cin>>ty;
        if (ty == 0){
            ll s,t,x;cin>>s>>t>>x;
            lseg.update(s, t+1, x);
        }
        if (ty == 1){
            ll s,t;cin>>s>>t;
            cout << lseg.query(s, t+1).x << endl;
        }
    }
}

