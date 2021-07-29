#include "../header.hpp"

//%snippet.set('ext_gcd')%
//%snippet.config({'alias':'gcd_ext'})%
//%snippet.fold()%

template<class T>
pair<T, T> ext_gcd(T a, T b){
    // return (x, y) s.t ax + by = gcd(a,b)
    if (b == 0) return {1, 0};
    auto [aa, bb] = ext_gcd(b, a-b*(a/b));
    return {bb, aa - bb*(a/b)};
}

//%snippet.end()%
