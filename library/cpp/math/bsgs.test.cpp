#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "../header.hpp"

int mod = 1e9 + 7;
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
//}}}
string to_string_mod(const modint& x){
    return to_string(x.x);
}
using mint = modint;

int gbsgs(int a, int b) {  //{{{
    // find x s.t a^x = b in (mod: primeである必要はない)

    if (b >= mod) return -1;
    if (1 % mod == b) return 0;

    int h = (int)sqrt(mod) + 1;  // h s.t x = p*h-r (0<=r<h and 0<=p<=h)

    unordered_map<int, vector<int>> rs;  // rs[v]: vector of r s.t b*a^r==v
    mint bar = b;  // b*a^r
    rep(r, 0, h) {
        rs[bar.x].pb(r);
        bar *= a;
    }
    bool looped = false;
    each(el, rs) if (sz(el.second) > 1) looped = true;

    mint ah = mint(a).pow(h);
    rep(p, 1, h + 1) {
        int aph = ah.pow(p).x;
        if (rs.find(aph) != rs.end()) {
            reverse(all(rs[aph]));
            each(r, rs[aph]) {
                if (mint(a).pow(p * h - r) == b){
                    // a^(p*h-r) == b in (mod) => a^(ph) == b*a^rだが逆は成り立たないのでこの確認が必要
                    return p * h - r;
                }
            }
        }
        // sz(rs[aph]) > 0の場合はbreakするので計算量も大丈夫
        if (looped) return -1;
    }

    return -1;
}  //}}}

int query(){
    cerrendl;
    int x,y,p;cin>>x>>y>>p;
    mod = p;
    cout << gbsgs(x, y) << endl;

    return 0;
}

int main(){/*{{{*/
    ll Q;cin>>Q;
    rep(_, Q){
        query();
    }
    check_input();
    return 0;
}/*}}}*/
