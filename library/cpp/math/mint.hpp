#pragma once
#include "../header.hpp"

//%snippet.set('mint')%
int mod = 1e9 + 7;
// int mod = 998244353;
struct mint {  //{{{
    ll x;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    // ?= operator
    mint& operator+=(const mint a) {
        (x += a.x) %= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        (x += mod - a.x) %= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint& operator/=(const mint& rhs) {
        if (rhs.x == 0) throw runtime_error("mint zero division");
        return *this *= rhs.inv();
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    mint pow(int n) const {
        mint res(1), x(*this);
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

    mint inv() const {
        if (x == 0) throw runtime_error("inv does not exist");
        return pow(mod - 2);
    }
    // mint inv()const{
    //     int x,y;
    //     int g=extgcd(v,mod,x,y);
    //     assert(g==1);
    //     if(x<0)x+=mod;
    //     return mint(x);
    // }

    bool operator<(const mint& r) const { return x < r.x; }
    bool operator==(const mint& r) const { return x == r.x; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
//}}}
