#include "../segment_tree_lazy.hpp"

//%snippet.set('make_lseg_rmq_ruq')%
//%snippet.config({'alias':'rmq_ruq'})%
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
