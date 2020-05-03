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


# :question: library/cpp/graph/unionfind.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/unionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 15:54:00+09:00




## Depends on

* :question: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :heavy_check_mark: <a href="bellman_ford.hpp.html">library/cpp/graph/bellman_ford.hpp</a>
* :question: <a href="graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="gridgraph.cpp.html">library/cpp/graph/gridgraph.cpp</a>
* :heavy_check_mark: <a href="scc.hpp.html">library/cpp/graph/scc.hpp</a>
* :x: <a href="topological_sort.hpp.html">library/cpp/graph/topological_sort.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/bellman_ford.test.cpp.html">library/cpp/graph/tests/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.2dcost.test.cpp.html">library/cpp/graph/tests/graph.2dcost.test.cpp</a>
* :x: <a href="../../../../verify/library/cpp/graph/tests/graph.bipartie.test.cpp.html">library/cpp/graph/tests/graph.bipartie.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.bridge.test.cpp.html">library/cpp/graph/tests/graph.bridge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.dijkstra.test.cpp.html">library/cpp/graph/tests/graph.dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.kruskal.test.cpp.html">library/cpp/graph/tests/graph.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/graph.lowlink.test.cpp.html">library/cpp/graph/tests/graph.lowlink.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/library/cpp/graph/tests/scc.test.cpp.html">library/cpp/graph/tests/scc.test.cpp</a>
* :x: <a href="../../../../verify/library/cpp/graph/tests/topological_sort.test.cpp.html">library/cpp/graph/tests/topological_sort.test.cpp</a>
* :x: <a href="../../../../verify/library/cpp/graph/tree.lib/hld.test.past2-o/codes/hld.test.past2-o.cpp.html">library/cpp/graph/tree.lib/hld.test.past2-o/codes/hld.test.past2-o.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../header.hpp"

//%snippet.set('UnionFind')%
//%snippet.fold()%

struct UnionFind {
    vector<int> data;  // size defined only for root node
    int count;         // count of groups

    UnionFind() {}
    UnionFind(int size) : data(size, -1), count(size) {}
    bool merge(int x, int y) { /*{{{*/
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
            count--;
        }
        return x != y;
    } /*}}}*/
    int root(int x) { return (data[x] < 0 ? x : data[x] = root(data[x])); }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -data[root(x)]; }

#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.data)) { group[uf.root(i)].pb(i); }
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
#define int long long
const int INF = 1e18;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (int i = (int)((b)-1); i >= (int)(a); --i)
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

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
#line 3 "library/cpp/graph/unionfind.hpp"

//%snippet.set('UnionFind')%
//%snippet.fold()%

struct UnionFind {
    vector<int> data;  // size defined only for root node
    int count;         // count of groups

    UnionFind() {}
    UnionFind(int size) : data(size, -1), count(size) {}
    bool merge(int x, int y) { /*{{{*/
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
            count--;
        }
        return x != y;
    } /*}}}*/
    int root(int x) { return (data[x] < 0 ? x : data[x] = root(data[x])); }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -data[root(x)]; }

#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.data)) { group[uf.root(i)].pb(i); }
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

