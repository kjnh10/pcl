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


# :heavy_check_mark: library/cpp/string/rolling_hash.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6e84951d1d0c19ce3fef1705f200b877">library/cpp/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/string/rolling_hash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-05 21:34:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/library/cpp/header.hpp.html">library/cpp/header.hpp</a>
* :heavy_check_mark: <a href="../../../../library/library/cpp/string/rolling_hash.hpp.html">library/cpp/string/rolling_hash.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "rolling_hash.hpp"

int main() {
    string t, p;
    using RH = rolling_hash;

    cin >> t;
    cin >> p;
    RH rh(t), rh2(p);
    for(int i = 0; i + p.size() <= t.size(); i++) {
        if(rh.get_hash(i, i + p.size()) == rh2.get_hash(0, p.size())) {
            cout << i << endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/string/rolling_hash.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

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
#line 2 "library/cpp/string/rolling_hash.hpp"


//%snippet.set('rolling_hash')%
//%snippet.fold()%

template<class Z> Z rng(Z a, Z b) {
    auto tmp = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<Z>(a, b - 1)(tmp);
}

struct rolling_hash {
    // static constexpr uint64_t P0 = 4111144441, P1 = 4111444111;
    static constexpr uint64_t P0 = 1e9+7, P1 = 998244353;
    static uint64_t B0, B1;
    vector<ll> hash0, hash1, _bpow0, _bpow1;  // 1-index
    rolling_hash() {}

    template<class T = vector<int>>
    rolling_hash(T &vs) {
        init(vs, hash0, B0, P0, _bpow0); 
        init(vs, hash1, B1, P1, _bpow1); 
    }
    rolling_hash(string &s) {
        vector<int> vs;
        for (char c : s) vs.emplace_back(c);
        init(vs, hash0, B0, P0, _bpow0); 
        init(vs, hash1, B1, P1, _bpow1); 
    }

    template<class T>
    void init(T& vs, vector<ll>& hash, ll B, ll P, vector<ll>& _bpow) {
        int n = vs.size();
        hash.assign(n + 1, 0);
        _bpow.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * B + vs[i]) % P;
            _bpow[i + 1] = _bpow[i] * B % P;
        }
    }

    pair<ll, ll> get_hash(int l, int r) { // [l, r)
        ll h0 = _get_hash(l, r, hash0, B0, P0, _bpow0);
        ll h1 = _get_hash(l, r, hash1, B1, P1, _bpow1);
        return {h0, h1};
    }
    ll _get_hash(int l, int r,  const vector<ll>& hash, ll B, ll P, const vector<ll>& _bpow) {
        ll res = (hash[r] - hash[l]*_bpow[r - l]) % P;
        res = (res < 0 ? res + P : res);
        assert(res>=0);
        return res;
    }
};
uint64_t rolling_hash::B0 = rng<ll>(1000000, rolling_hash::P0);
uint64_t rolling_hash::B1 = rng<ll>(1000000, rolling_hash::P1);

//%snippet.end()%

#line 4 "library/cpp/string/rolling_hash.test.cpp"

int main() {
    string t, p;
    using RH = rolling_hash;

    cin >> t;
    cin >> p;
    RH rh(t), rh2(p);
    for(int i = 0; i + p.size() <= t.size(); i++) {
        if(rh.get_hash(i, i + p.size()) == rh2.get_hash(0, p.size())) {
            cout << i << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

