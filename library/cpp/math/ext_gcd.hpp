#include "../header.hpp"

//%snippet.set('ext_gcd')%
//%snippet.config({'alias':'gcd_ext'})%
//%snippet.fold()%

template<class T>
pair<T, T> ext_gcd(T x, T y){
    // return ax + by = gcd(x,y)
    if (y == 0) return {1, 0};
    auto [aa, bb] = ext_gcd(y, x-y*(x/y));
    return {bb, aa - bb*(x/y)};
}

//%snippet.end()%
