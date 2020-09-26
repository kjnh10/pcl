#include "../segment_tree_lazy.hpp"

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

