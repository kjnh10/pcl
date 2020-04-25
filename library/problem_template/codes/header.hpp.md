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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: problem_template/codes/header.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dd26a324a0aa66900316935adc80e31b">problem_template/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/problem_template/codes/header.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 20:58:40+09:00




## Required by

* :warning: <a href="../../library/cpp/array/bit.cpp.html">library/cpp/array/bit.cpp</a>
* :warning: <a href="../../library/cpp/array/lis.cpp.html">library/cpp/array/lis.cpp</a>
* :warning: <a href="../../library/cpp/array/segtree/rmq_2d.cpp.html">library/cpp/array/segtree/rmq_2d.cpp</a>
* :heavy_check_mark: <a href="../../library/cpp/array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :warning: <a href="../../library/cpp/array/segtree/segment_tree_beats.cpp.html">library/cpp/array/segtree/segment_tree_beats.cpp</a>
* :warning: <a href="../../library/cpp/array/slide_min.cpp.html">library/cpp/array/slide_min.cpp</a>
* :warning: <a href="../../library/cpp/debug/dump.hpp.html">library/cpp/debug/dump.hpp</a>
* :warning: <a href="../../library/cpp/graph/bridge/codes/naive.cpp.html">library/cpp/graph/bridge/codes/naive.cpp</a>
* :warning: <a href="../../library/cpp/graph/bridge/codes/solve.cpp.html">library/cpp/graph/bridge/codes/solve.cpp</a>
* :warning: <a href="../../library/cpp/graph/dijkstra.cpp.html">library/cpp/graph/dijkstra.cpp</a>
* :warning: <a href="../../library/cpp/graph/flow/dinic.cpp.html">library/cpp/graph/flow/dinic.cpp</a>
* :warning: <a href="../../library/cpp/graph/graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="../../library/cpp/graph/scc.cpp.html">library/cpp/graph/scc.cpp</a>
* :warning: <a href="../../library/cpp/graph/test.make_bipartie/codes/solve.cpp.html">library/cpp/graph/test.make_bipartie/codes/solve.cpp</a>
* :warning: <a href="../../library/cpp/graph/topological_sort.cpp.html">library/cpp/graph/topological_sort.cpp</a>
* :warning: <a href="../../library/cpp/graph/tree.lib/reroot.cpp.html">library/cpp/graph/tree.lib/reroot.cpp</a>
* :heavy_check_mark: <a href="../../library/cpp/graph/tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>
* :warning: <a href="../../library/cpp/graph/unionfind.hpp.html">library/cpp/graph/unionfind.hpp</a>
* :warning: <a href="../../library/cpp/math/bsgs/bsgs.cpp.html">library/cpp/math/bsgs/bsgs.cpp</a>
* :warning: <a href="../../library/cpp/math/bsgs/naive.cpp.html">library/cpp/math/bsgs/naive.cpp</a>
* :warning: <a href="../../library/cpp/math/combination.hpp.html">library/cpp/math/combination.hpp</a>
* :warning: <a href="../../library/cpp/math/gbsgs/gbsgs.cpp.html">library/cpp/math/gbsgs/gbsgs.cpp</a>
* :warning: <a href="../../library/cpp/math/gbsgs/naive.cpp.html">library/cpp/math/gbsgs/naive.cpp</a>
* :warning: <a href="../../library/cpp/math/geoemtry/geometry.cpp.html">library/cpp/math/geoemtry/geometry.cpp</a>
* :warning: <a href="../../library/cpp/math/matrix.cpp.html">library/cpp/math/matrix.cpp</a>
* :warning: <a href="../../library/cpp/math/mint.hpp.html">library/cpp/math/mint.hpp</a>
* :warning: <a href="../../library/cpp/math/pascal.cpp.html">library/cpp/math/pascal.cpp</a>
* :warning: <a href="../../library/cpp/misc/napsack.cpp.html">library/cpp/misc/napsack.cpp</a>
* :heavy_check_mark: <a href="../../library/cpp/misc/zipper.lib/zipper.hpp.html">library/cpp/misc/zipper.lib/zipper.hpp</a>
* :warning: <a href="../../library/cpp/string/kmp/codes/naive.cpp.html">library/cpp/string/kmp/codes/naive.cpp</a>
* :warning: <a href="../../library/cpp/string/kmp/codes/solve.cpp.html">library/cpp/string/kmp/codes/solve.cpp</a>
* :warning: <a href="../../library/cpp/string/lcs.cpp.html">library/cpp/string/lcs.cpp</a>
* :warning: <a href="../../library/cpp/string/rollinghash.cpp.html">library/cpp/string/rollinghash.cpp</a>
* :warning: <a href="../../library/cpp/string/suffix_array/codes/suffix_array.cpp.html">library/cpp/string/suffix_array/codes/suffix_array.cpp</a>
* :warning: <a href="solve.cpp.html">problem_template/codes/solve.cpp</a>
* :warning: <a href="../test/judge.cpp.html">problem_template/test/judge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/library/cpp/array/segtree/segment_tree.test.cpp.html">library/cpp/array/segtree/segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/library/cpp/graph/tree.lib/hld.test.cpp.html">library/cpp/graph/tree.lib/hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/library/cpp/graph/tree.lib/lca.test.cpp.html">library/cpp/graph/tree.lib/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/library/cpp/misc/zipper.lib/zipper.test.cpp.html">library/cpp/misc/zipper.lib/zipper.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define r_rep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x)-A.begin())
#define upos(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
#else
  #define dump(...) ;
  #define dump_1d(...) ;
  #define dump_2d(...) ;
  #define cerrendl ;
#endif


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "problem_template/codes/header.hpp"

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define r_rep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x)-A.begin())
#define upos(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
#else
  #define dump(...) ;
  #define dump_1d(...) ;
  #define dump_2d(...) ;
  #define cerrendl ;
#endif


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

