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


# :heavy_check_mark: library/cpp/graph/unionfind.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/unionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-31 23:26:41+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :heavy_check_mark: <a href="bellman_ford.hpp.html">library/cpp/graph/bellman_ford.hpp</a>
* :heavy_check_mark: <a href="graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="gridgraph.cpp.html">library/cpp/graph/gridgraph.cpp</a>
* :heavy_check_mark: <a href="scc.hpp.html">library/cpp/graph/scc.hpp</a>
* :heavy_check_mark: <a href="topological_sort.hpp.html">library/cpp/graph/topological_sort.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/bellman_ford.test.cpp.html">library/cpp/graph/tests/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.2dcost.test.cpp.html">library/cpp/graph/tests/graph.2dcost.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.bridge.test.cpp.html">library/cpp/graph/tests/graph.bridge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.dijkstra.test.cpp.html">library/cpp/graph/tests/graph.dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.kruskal.test.cpp.html">library/cpp/graph/tests/graph.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.lowlink.test.cpp.html">library/cpp/graph/tests/graph.lowlink.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/scc.test.cpp.html">library/cpp/graph/tests/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/topological_sort.test.cpp.html">library/cpp/graph/tests/topological_sort.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../header.hpp"

//%snippet.set('UnionFind')%
//%snippet.fold()%

struct UnionFind {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int gcount;         // count of groups

    UnionFind() {}
    UnionFind(int _n) : par(_n, -1), gcount(_n) {}
    bool merge(int x, int y) { 
        x = root(x);
        y = root(y);
        if (x != y) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
            gcount--;
        }
        return x != y;
    } 
    int root(int x) {
        if (is_root(x)){
            return x;
        }
        else{
            return par[x] = root(par[x]);  // 経路圧縮
            // return root(par[x]);         // 経路圧縮なし
        }
    }
    bool is_root(int x) { return par[x] < 0; }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }

#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i); }
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
#endif  // }}}
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
#line 3 "library/cpp/graph/unionfind.hpp"

//%snippet.set('UnionFind')%
//%snippet.fold()%

struct UnionFind {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int gcount;         // count of groups

    UnionFind() {}
    UnionFind(int _n) : par(_n, -1), gcount(_n) {}
    bool merge(int x, int y) { 
        x = root(x);
        y = root(y);
        if (x != y) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
            gcount--;
        }
        return x != y;
    } 
    int root(int x) {
        if (is_root(x)){
            return x;
        }
        else{
            return par[x] = root(par[x]);  // 経路圧縮
            // return root(par[x]);         // 経路圧縮なし
        }
    }
    bool is_root(int x) { return par[x] < 0; }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }

#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i); }
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
#endif  // }}}
};

//%snippet.end()%

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

