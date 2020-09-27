#include "../segment_tree_lazy.hpp"

//%snippet.set('make_lseg_rmq_ruq')%
//%snippet.config({'alias':'rmq_ruq'})%
//%snippet.include('segment_tree_lazy')%
//%snippet.fold()%

using X = ll; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rmq_ruq(){
    auto merge = [](X x1, X x2){return min(x1,x2);};
    X ex = numeric_limits<X>::max();
    M em = numeric_limits<M>::max();
    auto composition = [em](M m1, M m2){ 
        if (m1 == em) return m2;
        if (m2 == em) return m1;
        return m2;
    };
    auto apply = [em](X x, M m){return (m==em ? x : m);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// auto lseg = make_lseg_rmq_ruq();
// lseg.build(a);
//   or
// lseg.build(vector<X>(n, <初期値>);

//%snippet.end()%
