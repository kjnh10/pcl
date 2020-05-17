#include "../header.hpp"

//%snippet.set('rational')%
//%snippet.config({'alias':'fraction'})%
//%snippet.fold()%

template<class T=ll> 
pair<T, T> rational(T x, T y){
    // 有理数をユニークな表現にして返す。
    // 0 <= theta < 180で返しているイメージ
    T g = gcd(x, y);
    x /= g; y /= g;
    if (y<0) {
        x *= -1; y *= -1;
    }
    else if (y==0 && x==-1){
        x *= -1; y *= -1;
    }
    return {x, y};
}

//%snippet.end()%

// verified by https://atcoder.jp/contests/abc168/tasks/abc168_e
