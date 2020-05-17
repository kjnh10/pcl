#include "../header.hpp"
#include "geometry/p2.hpp"

//%snippet.set('rational')%
//%snippet.config({'alias':'fraction'})%
//%snippet.fold()%

template<class T=ll> 
struct rational : public P2<T> {
    rational(){}
    rational(T _x, T _y) : P2<T>(_x, _y) {
        T g = gcd(this->x, this->y);
        this->x /= g; this->y /= g;
        if (this->y<0 or (this->y==0 && this->x==-1)) this->x *= -1, this->y *= -1;
    }
};
// rational(3, 5);
// assert(rational(3, 5) == rational(-6, -10));
// map<rational<ll>, int> cnt;  // keyにもできる。

//%snippet.end()%

// verified by https://atcoder.jp/contests/abc168/tasks/abc168_e
