#include "../header.hpp"

//%snippet.set('mypow')%
//%snippet.config({'alias':'pow'})%

template<class T>
T mypow(T x, int n, T e = 1) {  // e : *の単位元
    // return x^n
    T res(e);
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

//%snippet.end()%
