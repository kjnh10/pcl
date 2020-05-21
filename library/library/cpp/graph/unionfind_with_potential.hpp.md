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


# :warning: library/cpp/graph/unionfind_with_potential.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/unionfind_with_potential.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-22 02:09:00+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//%snippet.set('unionfind_with_potential')%
//%snippet.fold()%

template<class Pot = ll>  // Pot: Abel
struct UnionFind {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int gcount;         // count of groups
    vector<Pot>  diff;

    UnionFind() {}
    UnionFind(int _n, Pot SUM_UNITY = 0) : par(_n, -1), gcount(_n), diff(_n, SUM_UNITY) {}

    bool merge(int x, int y, Pot d) { 
        // d:= y - x
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            if (par[ry] >= par[rx]) {
                par[rx] += par[ry];
                par[ry] = rx;
                diff[ry] = diff[x] + d + (-diff[y]);
            }
            else{
                par[ry] += par[rx];
                par[rx] = ry;
                diff[rx] = (-diff[x]) + (-d) + diff[y];
            }
            gcount--;
        }
        return rx != ry;
    } 

    int root(int x) {
        if (is_root(x)){
            return x;
        }
        else{
            int r = root(par[x]);
            par[x] = r;
            diff[x] += diff[r];
            return par[x];
        }
    }

    Pot weight(int x){
        root(x); // 経路圧縮
        return diff[x];
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
#line 1 "library/cpp/graph/unionfind_with_potential.hpp"

//%snippet.set('unionfind_with_potential')%
//%snippet.fold()%

template<class Pot = ll>  // Pot: Abel
struct UnionFind {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int gcount;         // count of groups
    vector<Pot>  diff;

    UnionFind() {}
    UnionFind(int _n, Pot SUM_UNITY = 0) : par(_n, -1), gcount(_n), diff(_n, SUM_UNITY) {}

    bool merge(int x, int y, Pot d) { 
        // d:= y - x
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            if (par[ry] >= par[rx]) {
                par[rx] += par[ry];
                par[ry] = rx;
                diff[ry] = diff[x] + d + (-diff[y]);
            }
            else{
                par[ry] += par[rx];
                par[rx] = ry;
                diff[rx] = (-diff[x]) + (-d) + diff[y];
            }
            gcount--;
        }
        return rx != ry;
    } 

    int root(int x) {
        if (is_root(x)){
            return x;
        }
        else{
            int r = root(par[x]);
            par[x] = r;
            diff[x] += diff[r];
            return par[x];
        }
    }

    Pot weight(int x){
        root(x); // 経路圧縮
        return diff[x];
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

