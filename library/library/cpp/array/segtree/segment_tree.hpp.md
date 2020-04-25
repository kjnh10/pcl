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


# :heavy_check_mark: library/cpp/array/segtree/segment_tree.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#ebc279bbe94c10384fe9898d1a2c958d">library/cpp/array/segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/array/segtree/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 20:58:40+09:00




## Depends on

* :heavy_check_mark: <a href="../../../../problem_template/codes/header.hpp.html">problem_template/codes/header.hpp</a>


## Required by

* :warning: <a href="../../graph/tree.lib/reroot.cpp.html">library/cpp/graph/tree.lib/reroot.cpp</a>
* :heavy_check_mark: <a href="../../graph/tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/library/cpp/array/segtree/segment_tree.test.cpp.html">library/cpp/array/segtree/segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/hld.test.cpp.html">library/cpp/graph/tree.lib/hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/lca.test.cpp.html">library/cpp/graph/tree.lib/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../../../../problem_template/codes/header.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%

template<typename T>
struct SegmentTree { // {{{
    private:
        using F = function<T(T,T)>;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<T> node;
        F merge;
        T identity;

    public:
        SegmentTree(){}
        SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
            n = a.size();
            N = 1; while(N < n) N *= 2;
            node.resize(2*N-1, identity);
            for(int i=0; i<n; i++) node[i+N-1] = a[i];
            for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
        }
        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

        T& operator[](int i) { return node[i+N-1]; }

        void update(int x, T val) {
            x += (N - 1);
            node[x] = val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = merge(node[2*x+1], node[2*x+2]);
            }
        }

        void add(int x, T val) {
            x += (N - 1);
            node[x] += val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = merge(node[2*x+1], node[2*x+2]);
            }
        }

        // query for [l, r)
        T query(int a, int b, int k=0, int l=0, int r=-1) {
            if(r < 0) r = N;
            if(r <= a || b <= l) return identity;
            if(a <= l && r <= b) return node[k];

            T vl = query(a, b, 2*k+1, l, (l+r)/2);
            T vr = query(a, b, 2*k+2, (l+r)/2, r);
            return merge(vl, vr);
        }

        #if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
            os << "[";
            for(int i=0; i<sg.n; i++){
                os << sg[i] << (i==sg.n-1?"]\n":", ");
            }
            return os;
        }
        #endif
};
// }}}
// Sample:
// -----------------------------------------------
// auto mymin=[](auto a, auto b){return min(a,b);};
// SegmentTree<int> seg(a, mymin, 1e18);

// auto mymax=[](auto a, auto b){return max(a,b);};
// SegmentTree<int> seg(a, mymax, -1e18);

// auto add=[](auto a, auto b){return a+b;};
// SegmentTree<int> seg(a, add, 0);
// -----------------------------------------------

//%snippet.end()%


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

#line 3 "library/cpp/array/segtree/segment_tree.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%

template<typename T>
struct SegmentTree { // {{{
    private:
        using F = function<T(T,T)>;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<T> node;
        F merge;
        T identity;

    public:
        SegmentTree(){}
        SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
            n = a.size();
            N = 1; while(N < n) N *= 2;
            node.resize(2*N-1, identity);
            for(int i=0; i<n; i++) node[i+N-1] = a[i];
            for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
        }
        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

        T& operator[](int i) { return node[i+N-1]; }

        void update(int x, T val) {
            x += (N - 1);
            node[x] = val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = merge(node[2*x+1], node[2*x+2]);
            }
        }

        void add(int x, T val) {
            x += (N - 1);
            node[x] += val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = merge(node[2*x+1], node[2*x+2]);
            }
        }

        // query for [l, r)
        T query(int a, int b, int k=0, int l=0, int r=-1) {
            if(r < 0) r = N;
            if(r <= a || b <= l) return identity;
            if(a <= l && r <= b) return node[k];

            T vl = query(a, b, 2*k+1, l, (l+r)/2);
            T vr = query(a, b, 2*k+2, (l+r)/2, r);
            return merge(vl, vr);
        }

        #if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
            os << "[";
            for(int i=0; i<sg.n; i++){
                os << sg[i] << (i==sg.n-1?"]\n":", ");
            }
            return os;
        }
        #endif
};
// }}}
// Sample:
// -----------------------------------------------
// auto mymin=[](auto a, auto b){return min(a,b);};
// SegmentTree<int> seg(a, mymin, 1e18);

// auto mymax=[](auto a, auto b){return max(a,b);};
// SegmentTree<int> seg(a, mymax, -1e18);

// auto add=[](auto a, auto b){return a+b;};
// SegmentTree<int> seg(a, add, 0);
// -----------------------------------------------

//%snippet.end()%


```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

