#include "../segment_tree_lazy.hpp"
#include "monoid_with_len.hpp"

//%snippet.set('make_lseg_rsq_ruq')%
//%snippet.config({'alias':'rsq_ruq'})%
//%snippet.include('segment_tree_lazy')%
//%snippet.include('monoid_with_len')%
//%snippet.fold()%

using X = monoid_with_len<ll>; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rsq_ruq(){
    auto merge = [](X x1, X x2){return x1 + x2;};
    X ex = X(0, 0);
    M em = numeric_limits<M>::max();
    auto composition = [em](M m1, M m2){ 
        if (m1 == em) return m2;
        if (m2 == em) return m1;
        return m2;
    };
    auto apply = [em](X x, M m){return (m==em ? x : X(m * x.len, x.len));};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// auto lseg = make_lseg_rsq_ruq();
// lseg.build(vector<X>(sz, X(<初期値>, 1))); // X(*, 1)を入れないといけないことに注意する。

//%snippet.end()%
