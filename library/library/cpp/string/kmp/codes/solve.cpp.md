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
<script type="text/javascript" src="../../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/string/kmp/codes/solve.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#c4edc97866360646965a77b5500cc883">library/cpp/string/kmp/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/string/kmp/codes/solve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:20:30+09:00




## Depends on

* :heavy_check_mark: <a href="../../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../../header.hpp"

//%snippet.set('kmp')%

// Morris-Pratt
template <typename T>
struct KMP {
    int n;
    T pattern;
    vector<int> a;
    KMP() {} /*{{{*/
    KMP(const T& pattern) : pattern(pattern) {
        n = pattern.size();
        a = vector<int>(n + 1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && pattern[j] != pattern[i]) j = a[j];
            j++;
            a[i + 1] = j;
        }
    } /*}}}*/
    int operator[](int i) { return a[i]; }
    vector<int> findAll(const T& s) { /*{{{*/
        vector<int> res;
        int j = 0;
        for (int i = 0; i < sz(s); ++i) {
            while (j != -1 && pattern[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i - j + 1);
                j = a[j];
            }
        }
        return res;
    } /*}}}*/
};

// KMP<vector<int>> kmp({1,2,3});
// KMP<string> kmp("abc");

//%snippet.end()%

vector<int> f(vector<int>& a) {
    int n = a.size();
    vector<int> res(n);
    rep(i, n) res[i] = a[i] ^ a[(i + 1) % n];
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> xa = f(a);
    vector<int> xb = f(b);
    dump(xa);
    dump(xb);

    KMP<vector<int>> kmp(xa);
    dump("hello");
    vi wxb;
    wxb.insert(wxb.end(), xb.begin(), xb.end());
    wxb.insert(wxb.end(), xb.begin(), xb.end());

    vector<int> res = kmp.findAll(wxb);
    vector<int> ks;
    for (int p : res) ks.push_back(n - p);
    sort(ks.begin(), ks.end());
    for (int k : ks) {
        if (k >= n) continue;
        int x = a[k] ^ b[0];
        cout << k << " " << x << endl;
    }
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> iii;

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
#line 2 "library/cpp/string/kmp/codes/solve.cpp"

//%snippet.set('kmp')%

// Morris-Pratt
template <typename T>
struct KMP {
    int n;
    T pattern;
    vector<int> a;
    KMP() {} /*{{{*/
    KMP(const T& pattern) : pattern(pattern) {
        n = pattern.size();
        a = vector<int>(n + 1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && pattern[j] != pattern[i]) j = a[j];
            j++;
            a[i + 1] = j;
        }
    } /*}}}*/
    int operator[](int i) { return a[i]; }
    vector<int> findAll(const T& s) { /*{{{*/
        vector<int> res;
        int j = 0;
        for (int i = 0; i < sz(s); ++i) {
            while (j != -1 && pattern[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i - j + 1);
                j = a[j];
            }
        }
        return res;
    } /*}}}*/
};

// KMP<vector<int>> kmp({1,2,3});
// KMP<string> kmp("abc");

//%snippet.end()%

vector<int> f(vector<int>& a) {
    int n = a.size();
    vector<int> res(n);
    rep(i, n) res[i] = a[i] ^ a[(i + 1) % n];
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> xa = f(a);
    vector<int> xb = f(b);
    dump(xa);
    dump(xb);

    KMP<vector<int>> kmp(xa);
    dump("hello");
    vi wxb;
    wxb.insert(wxb.end(), xb.begin(), xb.end());
    wxb.insert(wxb.end(), xb.begin(), xb.end());

    vector<int> res = kmp.findAll(wxb);
    vector<int> ks;
    for (int p : res) ks.push_back(n - p);
    sort(ks.begin(), ks.end());
    for (int k : ks) {
        if (k >= n) continue;
        int x = a[k] ^ b[0];
        cout << k << " " << x << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

