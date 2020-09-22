#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja"
#include "segment_tree_lazy.hpp"

// snippet:make_lseg_rmq_raq {{{
using X = ll; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rmq_raq(){
    auto merge = [](X x1, X x2){return min(x1,x2);};
    X ex = 1e18;  // s.t merge(x, ex) = x
    auto composition = [](M m1, M m2){return m1 + m2;};
    M em = 0;  // s.t composition(m, em) = m && composition(em, m) = m && apply(x, em) = x
    auto apply = [](X x, M m){return x + m;};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// snippet:make_lseg_rmq_raq }}}

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
