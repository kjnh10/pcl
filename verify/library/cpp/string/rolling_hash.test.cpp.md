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
    - Last commit date: 2020-05-12 10:29:48+09:00


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
  string T, P;
  using RH = rolling_hash<1000000009, 10007>;

  cin >> T;
  cin >> P;
  RH rh(T), rh2(P);
  for(int i = 0; i + P.size() <= T.size(); i++) {
    if(rh.get_hash(i, i + P.size()) == rh2.get_hash(0, P.size())) {
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
template <class T>
inline void chmax(T &a, const T &b) {
    if ((a) < (b)) (a) = (b);
}
template <class T>
inline void chmin(T &a, const T &b) {
    if ((a) > (b)) (a) = (b);
}

#define divceil(a, b) ((a) + (b)-1) / (b)
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x)    \
    sort(all(x)); \
    x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast {
    Fast() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
    }
} fast;
void check_input() {
    assert(cin.eof() == 0);
    int tmp;
    cin >> tmp;
    assert(cin.eof() == 1);
}

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

template <ll mod, ll B>
struct rolling_hash {
    vector<ll> hash, _bpow;  // 1-index
    rolling_hash() {}
    rolling_hash(vector<ll> vs) { init(vs); }
    rolling_hash(string &s) {
        vector<ll> vs;
        for (char c : s) vs.emplace_back(c);
        init(vs);
    }

    void init(vector<ll> vs) {
        int n = vs.size();
        hash.assign(n + 1, 0);
        _bpow.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * B + vs[i]) % mod;
            _bpow[i + 1] = _bpow[i] * B % mod;
        }
    }

    // S[l, r)
    ll get_hash(int l, int r) {
        ll res = hash[r] + mod - hash[l] * _bpow[r - l] % mod;
        return res >= mod ? res - mod : res;
    }
};

//%snippet.end()%

#line 4 "library/cpp/string/rolling_hash.test.cpp"

int main() {
  string T, P;
  using RH = rolling_hash<1000000009, 10007>;

  cin >> T;
  cin >> P;
  RH rh(T), rh2(P);
  for(int i = 0; i + P.size() <= T.size(); i++) {
    if(rh.get_hash(i, i + P.size()) == rh2.get_hash(0, P.size())) {
      cout << i << endl;
    }
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

