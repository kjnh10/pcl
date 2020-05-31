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


# :warning: library/cpp/math/geometry/angle.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#fc16e9fb7f40757e9b21d2e083b6a084">library/cpp/math/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/geometry/angle.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-31 19:37:19+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>
* :heavy_check_mark: <a href="p2.hpp.html">library/cpp/math/geometry/p2.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
template <class T> inline void chmax(T &a, const T &b) { if ((a) < (b)) (a) = (b); }
template <class T> inline void chmin(T &a, const T &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define divceil(a, b) ((a) + (b)-1) / (b)
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
#line 2 "library/cpp/math/geometry/p2.hpp"

//%snippet.set('P2')%
//%snippet.config({'alias':'pos'})%
//%snippet.config({'alias':'point'})%
//%snippet.config({'alias':'pair'})%

template<class T=ll>/*{{{*/
struct P2 {
    T x, y;
    P2(T _x, T _y) : x(_x), y(_y) {}
    P2() {
        x = 0;
        y = 0;
    }
    bool operator<(const P2 &r) const {
        return (x != r.x ? x < r.x : y < r.y);
    }
    bool operator>(const P2 &r) const {
        return (x != r.x ? x > r.x : y > r.y);
    }
    bool operator==(const P2 &r) const { return (x == r.x && y == r.y); }

    friend ostream &operator<<(ostream &stream, P2 p) {
        stream << "(" << p.x << "," << p.y << ")";
        return stream;
    }

    P2 operator-() const {  // 単項演算子
        return P2(-x, -y);
    }

    P2& operator+=(const P2<T>& r){
        x += r.x;
        y += r.y;
        return *this;
    }
    P2& operator-=(const P2<T>& r){
        x -= r.x;
        y -= r.y;
        return *this;
    }
    P2& operator+=(const T& r){
        x += r;
        y += r;
        return *this;
    }
    P2& operator-=(const T& r){
        x -= r;
        y -= r;
        return *this;
    }
    P2& operator*=(const P2<T>& r){
        x *= r.x;
        y *= r.y;
        return *this;
    }
    P2& operator/=(const P2<T>& r){
        x /= r.x;
        y /= r.y;
        return *this;
    }
    P2& operator*=(const T& r){
        x *= r;
        y *= r;
        return *this;
    }
    P2& operator/=(const T& r){
        x /= r;
        y /= r;
        return *this;
    }

    template<class U>
    P2 operator+(const U& r) const {
        P2 res(*this);
        return res += r;
    }
    template<class U>
    P2 operator-(const U& r) const {
        P2 res(*this);
        return res -= r;
    }

    template<class U>
    P2 operator*(const U& r) const {
        P2 res(*this);
        return res *= r;
    }
    template<class U>
    P2 operator/(const U& r) const {
        P2 res(*this);
        return res /= r;
    }


    bool in(T a, T b, T c, T d) {  // x in [a, b) && y in [c, d)
        if (a <= x && x < b && c <= y && y < d) return true;
        else return false;
    }

};
template<class T>
long double dist(const P2<T>& p, const P2<T>& q){
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

/*}}}*/
using P = P2<ll>;

//%snippet.end%
#line 2 "library/cpp/math/geometry/angle.hpp"

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

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

