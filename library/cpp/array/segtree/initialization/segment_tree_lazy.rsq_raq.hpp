#include "../segment_tree_lazy.hpp"
#include "monoid_with_len.hpp"

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
// 初期値X(*, 1)を入れないといけないことに注意する。
//%snippet.end()%
