#include "segment_tree_lazy.hpp"
#include "../../math/mint.hpp"

// Regarding apply and merge, the conditions below should holds.
// apply(merge(x1, x2), m) = merge(apply(x1, m), apply(x2, m))
// apply(apply(x, m1), m2) = apply(x, composition(m1, m2))
// composition(m, em) = m && composition(em, m) = m && apply(x, em) = x


//%snippet.set('make_lseg_rmq_ruq')%
//%snippet.config({'alias':'rmq_ruq'})%
//%snippet.fold()%
using X = ll; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rmq_ruq(){
    auto merge = [](X x1, X x2){return min(x1,x2);};
    X ex = numeric_limits<X>::max();  // s.t merge(x, ex) = x
    M em = numeric_limits<M>::max();
    // s.t composition(m, em) = m && s.t composition(em, m) = m && apply(x, em) = x
    auto composition = [=](M m1, M m2){ 
        if (m1 == em) return m2;
        if (m2 == em) return m1;
        return m2;
    };
    auto apply = [=](X x, M m){return (m==em ? x : m);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
//%snippet.end()%


//%snippet.set('make_lseg_rmq_raq')%
//%snippet.config({'alias':'rmq_raq'})%
//%snippet.fold()%
using X = ll; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rmq_raq(){
    auto merge = [](X x1, X x2){return min(x1,x2);};
    X ex = numeric_limits<X>::max();
    auto composition = [](M m1, M m2){return m1 + m2;};
    M em = 0;
    auto apply = [](X x, M m){return x + m;};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
//%snippet.end()%


//%snippet.set('monoid_with_len')%
//%snippet.fold()%
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
//%snippet.end()%


//%snippet.set('monoid_affin_transformation')%
//%snippet.fold()%
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
//%snippet.end()%


//%snippet.set('make_lseg_rsq_raffinq')%
//%snippet.config({'alias':'rsq_raffinq'})%
//%snippet.include('monoid_with_len')%
//%snippet.include('monoid_affin_transformation')%
//%snippet.fold()%
using X = monoid_with_len<mint>; // (X, merge) is monoid
using M = monoid_affin_transformation; // (M, composition) is monoid
auto make_lseg_rsq_raffinq(){
    auto merge = [](X x1, X x2){return x1 + x2;};
    X ex = X(0, 0);
    M em = M(1, 0);
    auto composition = [](M m1, M m2){ return m1 + m2; };
    auto apply = [](X x, M m){return X(x.x*m.a + m.b*x.len, x.len);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
//%snippet.end()%


//%snippet.set('make_lseg_rsq_raq')%
//%snippet.config({'alias':'rsq_raq'})%
//%snippet.include('monoid_with_len')%
//%snippet.fold()%
using X = monoid_with_len<ll>; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rsq_raq(){
    auto merge = [](X x1, X x2){return x1 + x2;};
    X ex = X(0, 0);
    M em = 0;
    auto composition = [](M m1, M m2){ return m1 + m2; };
    auto apply = [](X x, M m){return X(x.x + m*x.len, x.len);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
//%snippet.end()%



// dual segment tree

//%snippet.set('make_lseg_getone_chmin')%
//%snippet.config({'alias':'getone_chmin'})%
//%snippet.fold()%
using X = ll; // (X, merge) is monoid // 双対セグメント木として使う時は適当なモノイドを入れておけば良い。
using M = ll; // (M, composition) is monoid
auto make_lseg_getone_chmin(){
    auto merge = [](X x1, X x2){return min(x1,x2);};
    X ex = numeric_limits<X>::max();
    M em = numeric_limits<M>::max();
    auto composition = [](M m1, M m2){return min(m1, m2);};
    auto apply = [](X x, M m){return min(x, m);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
//%snippet.end()%
