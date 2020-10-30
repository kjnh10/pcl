#pragma once
#include "../header.hpp"

//%snippet.set('zeta')%
//%snippet.fold()%

template <class T> 
vec<T> zeta(const vec<T>& a, int n){
    vec<T> res(a);
    // 自由度0
    rep(j, 0, n){
        // j桁目を自由にする。
        rep(i, 1<<n) {
            if (i >> j & 1) {
                res[i] += res[i ^ 1<<j];
                // j桁目が立ってないやつからj桁目が立ってるやつに更新が行くので順番の心配は不要
            }
        }
    }
    return res;
}

//%snippet.end()%
