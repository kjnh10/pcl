#include "../segment_tree_lazy.hpp"
#include "monoid_with_len.hpp"

//%snippet.set('make_lseg_getone_chmin')%
//%snippet.config({'alias':'getone_chmin'})%
//%snippet.include('segment_tree_lazy')%
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
