#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "segment_tree_lazy.hpp"
#include "../../math/mint.hpp"

// #include <atcoder/modint>
// using namespace atcoder;
// using mint = modint998244353;

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

// snippet:monoid_affin_transformation {{{
struct monoid_affin_transformation {
    mint a, b;
    monoid_affin_transformation(){};
    monoid_affin_transformation(mint a_, mint b_) : a(a_), b(b_){};
};
monoid_affin_transformation operator+(monoid_affin_transformation x, monoid_affin_transformation y){
    return monoid_affin_transformation(x.a * y.a, x.b * y.a + y.b);
}
bool operator==(monoid_affin_transformation m1, monoid_affin_transformation m2) {
    return m1.a == m2.a && m1.b == m2.b;
}
// snippet:monoid_affin_transformation }}}

// snippet:make_lseg_rsq_raffinq {{{
using X = monoid_with_len<mint>; // (X, merge) is monoid
using M = monoid_affin_transformation; // (M, composition) is monoid
auto make_lseg_rsq_raffinq(){
    auto merge = [](X x1, X x2){return x1 + x2;};
    X ex = X(0, 0);  // s.t merge(x, ex) = x
    M em = M(1, 0);
    // s.t composition(m, em) = m && s.t composition(em, m) = m && apply(x, em) = x
    auto composition = [&](M m1, M m2){ return m1 + m2; };
    auto apply = [&](X x, M m){return X(x.x*m.a + m.b*x.len, x.len);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// snippet:make_lseg_rsq_raffinq }}}

int main(){
    ll n,q;cin>>n>>q;
    vector<ll> a(n);
    mod = 998244353;

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


