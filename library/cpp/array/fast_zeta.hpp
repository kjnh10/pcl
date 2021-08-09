#pragma once
#include "../header.hpp"

//%snippet.set('zeta')%
//%snippet.fold()%

template <class T> 
vector<T> zeta(const vector<T>& a, int d){
    vector<T> res(a);
    rep(j, 0, d) rep(i, 1<<d) if (i >> j & 1) res[i] += res[i ^ 1<<j];
    return res;
}

//%snippet.end()%
