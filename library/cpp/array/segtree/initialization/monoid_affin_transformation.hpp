#include "../segment_tree_lazy.hpp"

const int mod = 998244353;  // mintのmodが動的に変えられないのでテストのために暫定的にmintをここにおく。
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

    mint pow(ll n) const {
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

    bool operator<(const mint& r) const { return x < r.x; }
    bool operator==(const mint& r) const { return x == r.x; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
//}}}

//%snippet.set('monoid_affin_transformation')%
//%snippet.fold()%

struct monoid_affin_transformation {
    mint a, b;
    monoid_affin_transformation(){};
    monoid_affin_transformation(mint a_, mint b_) : a(a_), b(b_){};
};
monoid_affin_transformation operator+(monoid_affin_transformation x, monoid_affin_transformation y){
    return monoid_affin_transformation(x.a * y.a, x.b * y.a + y.b);
}
bool operator==(monoid_affin_transformation m1, monoid_affin_transformation m2) {
    return m1.a == m2.a && m1.b == m2.b;
}
//%snippet.end()%
