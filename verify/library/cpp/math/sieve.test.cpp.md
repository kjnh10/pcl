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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: library/cpp/math/sieve.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#38e8a99339d0d505d14feb619e0537d8">library/cpp/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/sieve.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-01 23:57:45+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/library/cpp/header.hpp.html">library/cpp/header.hpp</a>
* :heavy_check_mark: <a href="../../../../library/library/cpp/math/sieve.hpp.html">library/cpp/math/sieve.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "sieve.hpp"

bool is_prime_naive(ll n) { /*{{{*/
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
} /*}}}*/

uint64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<uint64_t>(0, sv.n * 2)(x);
}

void test(ll m){
    // dump(m);

    auto ps = sv.prime_factor(m);
    // dump(ps);

    ll restore = 1;
    each(p, ps){
        if (is_prime_naive(p.first)==false) assert(false);
        rep(i, p.second) restore *= p.first;
    }
    assert(restore == m);
}

int main(){
    assert(sz(sv.prime_factor(1))==0);
    // test(sv.n * sv.n + 1);  // make sure that this will fail

    int num = 100000;
    while(num--){
        ll m = rng();
        test(m);
    }

    cout << "Hello World" << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/math/sieve.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
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
#line 2 "library/cpp/math/sieve.hpp"

//%snippet.set('sieve')%
//%snippet.config({'alias':'prime_factor_by_sieve'})%
//%snippet.fold()%

struct Sieve {/*{{{*/
    // エラトステネスのふるい O(NloglogN)
    ll n;                              // n: max number for defined f and primes
    vector<ll> f;                      // [-1, 2, 3, 2, 5, 2, 7, 2, 3, ....]
    vector<ll> primes;                 // [2, 3, 5, .......]
    Sieve(ll n = 1) : n(n), f(n + 1) { /*{{{*/
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    } /*}}}*/
    bool is_prime(ll x) {
        if (x <= n) return f[x] == x; 
        return sz(factor_list(x)) == 1;
    }

    vector<ll> factor_list(ll x) { /*{{{*/
        assert(x <= n*n); // これが満たされないと正しく計算されない可能性がある。

        vector<ll> res;
        if (x <= n) {
            while (x != 1) {
                res.push_back(f[x]);
                x /= f[x];
            }
        }
        else {
            for (ll i = 0; primes[i] * primes[i] <= x; i++) {
                while (x % primes[i] == 0) {
                    res.pb(primes[i]);
                    x /= primes[i];
                }
            }
            if (x != 1) res.pb(x);
        }

        return res;  // [2, 3, 3, 5, 5, 5.....]
    }                /*}}}*/

    vector<pair<ll, ll>> prime_factor(ll x) { /*{{{*/
        // just change fl vector to map form
        vector<ll> fl = factor_list(x);
        if (fl.size() == 0) return {};
        vector<pair<ll, ll>> res = {mp(fl[0], 0)};
        for (ll p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;  // [(2,1), (3,2), (5,3), .....]
    }                /*}}}*/
};/*}}}*/
Sieve sv(1e6);
// How to use
    // sv.primes            // 素数のリスト
    // sv.prime_factor(x);  // 素因数分解

//%snippet.end()%
#line 3 "library/cpp/math/sieve.test.cpp"

bool is_prime_naive(ll n) { /*{{{*/
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
} /*}}}*/

uint64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<uint64_t>(0, sv.n * 2)(x);
}

void test(ll m){
    // dump(m);

    auto ps = sv.prime_factor(m);
    // dump(ps);

    ll restore = 1;
    each(p, ps){
        if (is_prime_naive(p.first)==false) assert(false);
        rep(i, p.second) restore *= p.first;
    }
    assert(restore == m);
}

int main(){
    assert(sz(sv.prime_factor(1))==0);
    // test(sv.n * sv.n + 1);  // make sure that this will fail

    int num = 100000;
    while(num--){
        ll m = rng();
        test(m);
    }

    cout << "Hello World" << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

