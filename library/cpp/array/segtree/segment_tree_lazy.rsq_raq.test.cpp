#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "segment_tree_lazy.hpp"

// snippet:monoid_with_len {{{
template<class T>
struct monoid_with_len {
    T x;
    int len;
    monoid_with_len(){};
    monoid_with_len(T x_, ll len_) : x(x_), len(len_){};
};
template<class T>
monoid_with_len<T> operator+(monoid_with_len<T> a, monoid_with_len<T> b){
    return monoid_with_len<T>(a.x + b.x, a.len + b.len);
}
// snippet:monoid_with_len }}}

// snippet:make_lseg_rsq_raq {{{
using X = monoid_with_len<ll>; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rsq_raq(){
    auto merge = [](X x1, X x2){return x1 + x2;};
    X ex = X(0, 0);  // s.t merge(x, ex) = x
    M em = 0;
    // s.t composition(m, em) = m && s.t composition(em, m) = m && apply(x, em) = x
    auto composition = [&](M m1, M m2){ return m1 + m2; };
    auto apply = [&](X x, M m){return X(x.x + m*x.len, x.len);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// snippet:make_lseg_rsq_raq }}}

int main(){
    ll n,q;cin>>n>>q;
    auto lseg = make_lseg_rsq_raq();
    const int sz = n;
    lseg.build(vector<X>(sz, X(0, 1)));
    rep(i, q){
        int ty;cin>>ty;
        if (ty == 0){
            ll s,t,x;cin>>s>>t>>x;
            s--;t--;
            lseg.update(s, t+1, x);
        }
        if (ty == 1){
            ll s,t;cin>>s>>t;
            s--;t--;
            cout << lseg.query(s, t+1).x << endl;
        }
    }
}

