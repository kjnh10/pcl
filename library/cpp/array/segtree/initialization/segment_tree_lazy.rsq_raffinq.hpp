#include "../segment_tree_lazy.hpp"
#include "../../../math/mint.hpp"
#include "monoid_with_len.hpp"
#include "monoid_affin_transformation.hpp"

//%snippet.set('make_lseg_rsq_raffinq')%
//%snippet.config({'alias':'rsq_raffinq'})%
//%snippet.include('segment_tree_lazy')%
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
// auto lseg = make_lseg_rsq_raffinq();
// lseg.build(vector<X>(sz, X(<初期値>, 1))); // X(*, 1)を入れないといけないことに注意する。

//%snippet.end()%
