#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja"
#include "initialization/segment_tree_lazy.rmq_raq.hpp"

int main(){
    ll n,q;cin>>n>>q;
    auto lseg = make_lseg_rmq_raq();
    const int sz = n;
    lseg.build(vector<X>(sz, 0));
    rep(i, q){
        int ty;cin>>ty;
        if (ty == 0){
            ll s,t,x;cin>>s>>t>>x;
            lseg.update(s, t+1, x);
        }
        if (ty == 1){
            ll s,t;cin>>s>>t;
            cout << lseg.query(s, t+1) << endl;
        }
    }
}
