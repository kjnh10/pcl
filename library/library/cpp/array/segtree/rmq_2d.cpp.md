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


# :warning: library/cpp/array/segtree/rmq_2d.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#ebc279bbe94c10384fe9898d1a2c958d">library/cpp/array/segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/segtree/rmq_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 10:29:48+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"

//%snippet.set('SegmentTree2DRMQ')%
//%snippet.config({'alias':'2drmq'})%
struct segtree {
    int H, W;
    vector<vector<int>> dat;
    segtree() {}
    segtree(vector<vector<int>> &f) {
        H = W = 1;
        while (H < (int)f.size()) H <<= 1;
        while (W < (int)f[0].size()) W <<= 1;
        dat.assign(2 * H - 1, vector<int>(2 * W - 1, INF));
        init(f);
    }
    void init(vector<vector<int>> &f) {
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i + H - 1][j + W - 1] = f[i][j];
        dump("hello");
        for (int i = 2 * H - 2; i > H - 2; i--)
            for (int j = W - 2; j >= 0; j--)
                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2 * j + 2]);
        dump("hello1");
        for (int i = H - 2; i >= 0; i--)
            for (int j = 0; j < 2 * W - 1; j++)
                dat[i][j] = min(dat[2 * i + 1][j], dat[2 * i + 2][j]);
        dump("hello2");
    }
    int minimum(int li, int lj, int ri, int rj) {
        return minimum_h(li, lj, ri, rj, 0, H, 0);
    }
    int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if (ri <= si or ti <= li) return INF;
        if (li <= si and ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);
        const int mi = (si + ti) / 2;
        return min(minimum_h(li, lj, ri, rj, si, mi, 2 * k + 1),
                   minimum_h(li, lj, ri, rj, mi, ti, 2 * k + 2));
    }
    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
        if (rj <= sj or tj <= lj) return INF;
        if (lj <= sj and tj <= rj) return dat[i][k];
        const int mj = (sj + tj) / 2;
        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),
                   minimum_w(lj, rj, mj, tj, i, 2 * k + 2));
    }
};
//%snippet.end()%

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
#line 2 "library/cpp/array/segtree/rmq_2d.cpp"

//%snippet.set('SegmentTree2DRMQ')%
//%snippet.config({'alias':'2drmq'})%
struct segtree {
    int H, W;
    vector<vector<int>> dat;
    segtree() {}
    segtree(vector<vector<int>> &f) {
        H = W = 1;
        while (H < (int)f.size()) H <<= 1;
        while (W < (int)f[0].size()) W <<= 1;
        dat.assign(2 * H - 1, vector<int>(2 * W - 1, INF));
        init(f);
    }
    void init(vector<vector<int>> &f) {
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i + H - 1][j + W - 1] = f[i][j];
        dump("hello");
        for (int i = 2 * H - 2; i > H - 2; i--)
            for (int j = W - 2; j >= 0; j--)
                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2 * j + 2]);
        dump("hello1");
        for (int i = H - 2; i >= 0; i--)
            for (int j = 0; j < 2 * W - 1; j++)
                dat[i][j] = min(dat[2 * i + 1][j], dat[2 * i + 2][j]);
        dump("hello2");
    }
    int minimum(int li, int lj, int ri, int rj) {
        return minimum_h(li, lj, ri, rj, 0, H, 0);
    }
    int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if (ri <= si or ti <= li) return INF;
        if (li <= si and ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);
        const int mi = (si + ti) / 2;
        return min(minimum_h(li, lj, ri, rj, si, mi, 2 * k + 1),
                   minimum_h(li, lj, ri, rj, mi, ti, 2 * k + 2));
    }
    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
        if (rj <= sj or tj <= lj) return INF;
        if (lj <= sj and tj <= rj) return dat[i][k];
        const int mj = (sj + tj) / 2;
        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),
                   minimum_w(lj, rj, mj, tj, i, 2 * k + 2));
    }
};
//%snippet.end()%

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

