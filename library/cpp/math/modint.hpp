#pragma once
#include "../header.hpp"

//%snippet.set('modint')%
//%snippet.config({'alias':'mint'})%
const int mod = 1e9 + 7;
// const int mod = 998244353;
struct modint {  //{{{
    ll x;
    modint(ll x = 0) : x((x % mod + mod) % mod) {}

    // ?= operator
    modint& operator+=(const modint a) {
        (x += a.x) %= mod;
        return *this;
    }
    modint& operator-=(const modint a) {
        (x += mod - a.x) %= mod;
        return *this;
    }
    modint& operator*=(const modint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        if (rhs.x == 0) throw runtime_error("modint zero division");
        return *this *= rhs.inv();
    }

    modint operator+(const modint a) const {
        modint res(*this);
        return res += a;
    }
    modint operator-(const modint a) const {
        modint res(*this);
        return res -= a;
    }
    modint operator*(const modint a) const {
        modint res(*this);
        return res *= a;
    }
    modint operator/(const modint a) const {
        modint res(*this);
        return res /= a;
    }

    modint pow(ll n) const {
        modint res(1), x(*this);
        if (n < 0) {
            n = -n;
            x = (*this).inv();
        }
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    modint inv() const {
        if (x == 0) throw runtime_error("inv does not exist");
        return pow(mod - 2);
    }
    // modint inv()const{
    //     int x,y;
    //     int g=extgcd(v,mod,x,y);
    //     assert(g==1);
    //     if(x<0)x+=mod;
    //     return modint(x);
    // }

    bool operator<(const modint& r) const { return x < r.x; }
    bool operator==(const modint& r) const { return x == r.x; }
};
istream& operator>>(istream& is, const modint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const modint& a) { return os << a.x; }
string to_string_mod(const modint& x){ return to_string(x.x); }
//}}}
using mint = modint;

//%snippet.end()%
