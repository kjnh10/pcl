#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include "segment_tree_lazy.hpp"

// snippet:make_lseg_rmq_ruq {{{
using X = ll; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rmq_ruq(){
    X ex = numeric_limits<X>::max();  // s.t merge(x, ex) = x
    M em = numeric_limits<M>::max();
    auto merge = [](X x1, X x2){return min(x1,x2);};
    auto composition = [=](M m1, M m2){ 
        if (m1 == em) return m2;
        if (m2 == em) return m1;
        return m2;
    };
    auto apply = [=](X x, M m){return (m==em ? x : m);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// snippet:make_lseg_rmq_ruq }}}

int main(){
    ll n,q;cin>>n>>q;
    auto lseg = make_lseg_rmq_ruq();
    const int sz = n;
    lseg.build(vector<X>(sz, (1LL<<31)-1));
    rep(i, q){
        cerrendl;
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
