---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/math/bsgs/bsgs.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#51139f4eb77e81dbd61f182500602d94">library/cpp/math/bsgs</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/bsgs/bsgs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-05 21:34:55+09:00




## Depends on

* :question: <a href="../../header.hpp.html">library/cpp/header.hpp</a>
* :x: <a href="../mint.hpp.html">library/cpp/math/mint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"
#include "../mint.hpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b) {  //{{{
    if (b >= mod) {
        return -1;
    }

    // find x s.t a^x = b in (mod)
    mint x;
    int sq = sqrt(mod);
    // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

    map<int, int> minr;  // minr[v]: min(r s.t a^r=v)
    mint ar = 1;
    rep(r, 0, sq) {
        if (minr.find(ar.x) == minr.end()) minr[ar.x] = r;
        ar *= a;
    }

    mint A = mint(a).pow(-sq);
    rep(p, 0, sq + 1) {
        int Ab = (A.pow(p) * b).x;
        if (minr.find(Ab) != minr.end()) {
            int r = minr[Ab];
            return p * sq + r;
        }
    }

    return -1;
}  //}}}
// %snippet.end()%

signed main() {
    int a, b, p;
    cin >> a >> b >> p;
    mod = p;
    cout << bsgs(a, b) << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "library/cpp/header.hpp"

//%snippet.set('header')%
//%snippet.fold()%
#ifndef HEADER_H
#define HEADER_H

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
const long long INF = 1e18;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }
template <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define cdiv(a, b) (((a) + (b)-1) / (b))
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif /* HEADER_H */
//%snippet.end()%
#line 3 "library/cpp/math/mint.hpp"

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
#line 3 "library/cpp/math/bsgs/bsgs.cpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b) {  //{{{
    if (b >= mod) {
        return -1;
    }

    // find x s.t a^x = b in (mod)
    mint x;
    int sq = sqrt(mod);
    // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

    map<int, int> minr;  // minr[v]: min(r s.t a^r=v)
    mint ar = 1;
    rep(r, 0, sq) {
        if (minr.find(ar.x) == minr.end()) minr[ar.x] = r;
        ar *= a;
    }

    mint A = mint(a).pow(-sq);
    rep(p, 0, sq + 1) {
        int Ab = (A.pow(p) * b).x;
        if (minr.find(Ab) != minr.end()) {
            int r = minr[Ab];
            return p * sq + r;
        }
    }

    return -1;
}  //}}}
// %snippet.end()%

signed main() {
    int a, b, p;
    cin >> a >> b >> p;
    mod = p;
    cout << bsgs(a, b) << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

