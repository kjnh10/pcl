#include "p2.hpp"

//%snippet.set('angle')%

struct Angle{
    ll x, y; // 実際には10^9くらいまでしか入れられない。
    int _orthant;  // 象限
    Angle(){};
    Angle(ll _x, ll _y): x(_x), y(_y){
        assert(x != 0 || y != 0);
        ll g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        if(y >= 0) _orthant = (x >= 0 ? 0 : 1);
        else _orthant = (x >= 0 ? 3 : 2);
    }

    bool operator<(const Angle &r) const {
        return (_orthant != r._orthant ? _orthant < r._orthant : x * r.y - y * r.x > 0);
    }

    bool operator==(const Angle &r) const { return (x == r.x && y == r.y); }

    long double operator-(const Angle& r) const {
        // rを起点に見て何度進んでいるかradianで返す
        return rad() - r.rad();
    }

    long double rad() const {
        long double r = atan2(y, x); 
        return (r<0 ? (r + M_PI*2.0) : r);
    }
    long double const deg(){ return rad() * 180.0/ M_PI; }

    Angle rot_90() const { return Angle(-y, x); }

    Angle rot_r90() const { return Angle(y, -x); }

    friend ostream &operator<<(ostream &stream, Angle p) {
        stream << "(" << p.x << "," << p.y << ")";
        return stream;
    }
};

//%snippet.end%

// from: https://betrue12.hateblo.jp/entry/2020/01/05/151244
