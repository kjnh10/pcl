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


# :x: library/cpp/graph/tests/two_sat.test.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#5cfe5baf3670d8b3119d43c381f15ee8">library/cpp/graph/tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/tests/two_sat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-05 21:34:55+09:00


* see: <a href="https://yukicoder.me/problems/no/274">https://yukicoder.me/problems/no/274</a>


## Depends on

* :x: <a href="../../../../../library/library/cpp/array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/edge.hpp.html">library/cpp/graph/edge.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/scc.hpp.html">library/cpp/graph/scc.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/topological_sort.hpp.html">library/cpp/graph/topological_sort.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/two_sat.hpp.html">library/cpp/graph/two_sat.hpp</a>
* :x: <a href="../../../../../library/library/cpp/graph/unionfind.hpp.html">library/cpp/graph/unionfind.hpp</a>
* :question: <a href="../../../../../library/library/cpp/header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/274"
#include "../two_sat.hpp"

int main() {
    int n,m;cin>>n>>m;
    vector<int> l(n), r(n);
    rep(i, n){
        cin>>l[i]>>r[i];
    }

    two_sat ts(n);

    rep(i, n){
        rep(j, i+1, n){
            if (r[j] < l[i] || r[i] < l[j]) {
            }
            else{
                ts.add_condition(i, 0, j, 0);
                ts.add_condition(i, 1, j, 1);
            }

            if (r[j] < m-1-r[i] || m-1-l[i] < l[j]) {
            }
            else{
                ts.add_condition(i, 0, j, 1);
                ts.add_condition(i, 1, j, 0);
            }
        }
    }
    auto valid = ts.build();
    cout << (valid ? "YES" : "NO") << endl;

    return 0; 
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/graph/tests/two_sat.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/274"
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
#line 3 "library/cpp/graph/edge.hpp"

//%snippet.set('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct Edge {
    int from, to;
    Cost cost;
    int idx;
    Edge(){};
    Edge(int from, int to, Cost cost, int idx)
        : from(from), to(to), cost(cost), idx(idx) {}

    friend ostream& operator<<(ostream& os, const Edge& e) {
        // os << "(f:" << e.from << ", t:" << e.to << ", c:" << e.cost << ", i" << e.idx << ")";  // detailed
        os << "(" << e.from << "," << e.to << ")";
        return os;
    }
};
//%snippet.end()%
#line 3 "library/cpp/array/segtree/segment_tree.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%
//%snippet.fold()%

template <typename T> struct SegmentTree {  // {{{
    private:
        using F = function<T(T, T)>;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<T> node;
        F merge;
        T identity;

    public:
        SegmentTree() {}
        SegmentTree(vector<T> a, F f, T id) : merge(f), identity(id) {
            n = a.size();
            N = 1;
            while (N < n) N *= 2;
            node.resize(2 * N - 1, identity);
            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];
            for (int i = N - 2; i >= 0; i--)
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
        }
        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

        T& operator[](int i) { return node[i + N - 1]; }

        void update(int i, T val) {
            i += (N - 1);
            node[i] = val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        void add(int i, T val) {
            i += (N - 1);
            node[i] += val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        // query for [a, b)
        T query(int a, int b, int k = 0, int l = 0, int r = -1) {
            if (r < 0) r = N;
            if (r <= a || b <= l) return identity;
            if (a <= l && r <= b) return node[k];

            T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }

        // find most right element for [a, b)
        int find_mr(int a, int b, function<bool(T)> is_ok, int k = 0, int l = 0, int r = -1){
            if (r < 0) r = N;
            if (r <= a || b <= l || !is_ok(node[k])) return a-1;
            if (k >= N-1) return k - (N-1);  // leaf

            T vr = find_mr(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);
            if (vr != a-1) return vr;

            T vl = find_mr(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);
            return vl;
        }

        // find most left element for [a, b)
        int find_ml(int a, int b, function<bool(T)> is_ok, int k = 0, int l = 0, int r = -1){
            // find most left
            if (r < 0) r = N;
            if (r <= a || b <= l || !is_ok(node[k])) return b;
            if (k >= N-1) return k - (N-1);  // leaf

            T vl = find_ml(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) return vl;

            T vr = find_ml(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);
            return vr;
        }

        #if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //
            os << "[";
            for (int i = 0; i < sg.n; i++) {
                os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
            }
            return os;
        }
        #endif
};/*}}}*/
// sample of initialize SegmentTree:
// -----------------------------------------------
// auto mymin=[](auto a, auto b){return min(a,b);};
// SegmentTree<ll> seg(a, mymin, 1e18);

// auto mymax=[](auto a, auto b){return max(a,b);};
// SegmentTree<ll> seg(a, mymax, -1e18);

// auto add=[](auto a, auto b){return a+b;};
// SegmentTree<ll> seg(a, add, 0);
// -----------------------------------------------

//%snippet.end()%
#line 5 "library/cpp/graph/tree.lib/tree.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree')%
//%snippet.include('segment_tree')%
//%snippet.include('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct tree { 
    int n;
    int root;
    vector<int> par;   // par[i]: dfs木における親
    vector<Cost> cost;  // par[i]: dfs木における親への辺のコスト
    vector<int> dfstrv;  // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
    vector<int> ord;    // ord[u]: uのdfs木における訪問順
    vector<int> end;    // end[u]: uのdfs終了時のカウンター
    vector<int> psize;  // psize[u]: uのpartial tree size
    // uの部分木は[ord[u], end[u])
    // ordとdfstrvは逆変換
    vector<int> depth;   // depth[i]: dfs木でのiの深さ
    vector<Cost> ldepth;  //  ldepth[i]: dfs木でのrootからの距離
    vector<vector<Edge<Cost>>> adj_list;       // 辺(隣接リスト)
    auto operator[](int pos) const { return adj_list[pos]; }
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;    // euler_tour first occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;
    int _counter = 0;

    tree(){};/*{{{*/
    tree(int n)
        : n(n),
          par(n),
          cost(n),
          ord(n),
          end(n),
          psize(n),
          depth(n),
          ldepth(n),
          adj_list(n),
          children(n),
          et_fpos(n),
          head_of_comp(n){};/*}}}*/
    void add_edge(int u, int v, Cost cost, int idx=-1) { /*{{{*/
        adj_list[u].emplace_back(u, v, cost, idx);
        adj_list[v].emplace_back(v, u, cost, idx);
    }                             /*}}}*/
    void add_edge(int u, int v) { /*{{{*/
        adj_list[u].emplace_back(u, v, 1, -1);
        adj_list[v].emplace_back(v, u, 1, -1);
    }                      /*}}}*/
    void build(int _root) { /*{{{*/
        root = _root;
        _counter = 0;
        par[root] = -1;
        // cost[root] = -1;
        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
            ini, [](auto a, auto b) { return min(a, b); }, numeric_limits<int>().max());
    }                                /*}}}*/
    int _dfs_psize(int u, int pre) { /*{{{*/
        psize[u] = 1;
        each(edge, adj_list[u]) {
            if (edge.to == pre) continue;
            psize[u] += _dfs_psize(edge.to, u);
        }
        return psize[u];
    }                                               /*}}}*/
    void _dfs_tree(int u, int pre, int head_node) { /*{{{*/
        dfstrv.pb(u);
        ord[u] = _counter;
        if (pre != -1) {
            depth[u] = depth[pre] + 1;
            ldepth[u] = ldepth[pre] + cost[u];
        }

        _counter++;
        {
            // set most heavy child to top
            int max_psize = 0;
            int most_heavy_i = -1;
            rep(i, sz(adj_list[u])) {
                if (adj_list[u][i].to == pre) continue;
                if (psize[adj_list[u][i].to] > max_psize) {
                    most_heavy_i = i;
                    max_psize = psize[adj_list[u][i].to];
                }
            }
            if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(adj_list[u])) {
            int v = adj_list[u][i].to;
            if (v == pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = adj_list[u][i].cost;

            if (i == 0)
                _dfs_tree(v, u, head_node);  // continue components
            else
                _dfs_tree(v, u, v);  // new
        }
        end[u] = _counter;
    }                     /*}}}*/
    void _dfs_et(int u) { /*{{{*/
        et_fpos[u] = euler_tour.size();
        euler_tour.pb(u);
        each(v, children[u]) {
            _dfs_et(v);
            euler_tour.pb(u);
        }
    }                       /*}}}*/
    int lca(int u, int v) { /*{{{*/
        if (u == v) return u;
        if (et_fpos[u] > et_fpos[v]) swap(u, v);
        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
    }                        /*}}}*/
    int dist(int u, int v) { /*{{{*/
        int p = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[p];
    }                          /*}}}*/
    Cost ldist(int u, int v) {  // length dist{{{
        int p = lca(u, v);
        return ldepth[u] + ldepth[v] - 2 * ldepth[p];
    }                           /*}}}*/
    pair<int, int> diameter() { /*{{{*/
        int u, v;
        Cost max_len = *max_element(all(ldepth));
        rep(i, n) {
            if (ldepth[i] == max_len) {
                u = i;
                break;
            }
        }
        Cost md = -1;
        rep(i, n) {
            Cost d = ldist(u, i);
            if (d > md) {
                v = i;
                md = d;
            }
        }
        return mp(u, v);
    }                                                /*}}}*/
    vector<pair<int, int>> hld_path(int u, int v, bool for_edge=true) {  //{{{
        // 閉区間をvectorで返す。for_edge=trueでlcaは除いて返すことに注意。
        vector<pair<int, int>> res;
        while (head_of_comp[u] != head_of_comp[v]) {
            if (depth[head_of_comp[u]] < depth[head_of_comp[v]]) {
                res.push_back({ord[head_of_comp[v]], ord[v]});
                v = par[head_of_comp[v]];
            } else {
                res.push_back({ord[head_of_comp[u]], ord[u]});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u], ord[v])});
        return res;
    }                              //}}}
#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const tree& tr) {
        os << endl;
        os << "par:         " << tr.par << endl;
        os << "cost:        " << tr.cost << endl;
        os << "dfstrv:      " << tr.dfstrv << endl;
        os << "ord:         " << tr.ord << endl;
        os << "end:         " << tr.end << endl;
        os << "depth:       " << tr.depth << endl;
        os << "children:    " << tr.children << endl;
        os << "euler_tour:  " << tr.euler_tour << endl;
        os << "et_fpos:     " << tr.et_fpos << endl;
        os << "head_of_comp:" << tr.head_of_comp << endl;
        return os;
    }
#endif /*}}}*/
}; 
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
#line 6 "library/cpp/graph/graph.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%
//%snippet.include('tree')%
//%snippet.fold()%

template<class Cost=ll>
struct Graph {
    using Pos = int;  // int以外には対応しない。

    int n;  // 頂点数
    vector<vector<Edge<Cost>>> adj_list;
    auto operator[](Pos pos) const { return adj_list[pos]; }
    vector<Edge<Cost>> edges;
    tree<Cost> tr;
    Pos root;
    vector<int> _used_in_dfs;
    vector<int> lowlink;
    Cost zerocost;
    Cost infcost;

    Graph() {}
    Graph(int _n) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n), zerocost(0LL), infcost(INF) { }
    Graph(int _n, Cost zc, Cost ic) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n), zerocost(zc), infcost(ic) { }

    void add_edge(Pos from, Pos to, Cost cost, int idx=-1) {/*{{{*/
        adj_list[from].emplace_back(from, to, cost, idx);
        edges.emplace_back(from, to, cost, idx);
    }
    void add_edge(Pos from, Pos to) {  // for ll
        adj_list[from].emplace_back(from, to, 1, -1);
        edges.emplace_back(from, to, 1, -1);
    }/*}}}*/

    void build_tree(Pos _root) {/*{{{*/
        root = _root;
        _dfs_tree(root);
        tr.build(root);
        _make_lowlink();
    }/*}}}*/

    vector<int> make_bipartite() {/*{{{*/
        UnionFind buf(2 * n);
        rep(u, n) {
            each(e, adj_list[u]) {
                buf.merge(u, e.to + n);
                buf.merge(e.to, u + n);
            }
        }

        vector<int> res(n, -1);
        rep(u, n) {
            if (buf.same(u, u + n)) return res;
        }
        rep(u, n) {
            if (buf.same(0, u)) res[u] = 0;
            else res[u] = 1;
        }
        return res;
    }/*}}}*/

    void _dfs_tree(Pos u) {/*{{{*/
        _used_in_dfs[u] = 1;
        each(e, adj_list[u]) {
            if (_used_in_dfs[e.to]) continue;
            tr.add_edge(u, e.to, e.cost);
            _dfs_tree(e.to);
        }
    }/*}}}*/

    void _make_lowlink() {/*{{{*/
        lowlink = vector<Pos>(n, numeric_limits<Pos>().max());
        r_rep(i, n) {
            Pos u = tr.dfstrv[i];
            chmin(lowlink[u], tr.ord[u]);

            each(e, adj_list[u]) {
                if (e.to == tr.par[u])
                    continue;
                else if (tr.ord[e.to] < tr.ord[u]) {
                    chmin(lowlink[u], tr.ord[e.to]);
                } else {
                    chmin(lowlink[u], lowlink[e.to]);
                }
            }
        }
    }/*}}}*/

    vector<Pos> get_articulation_points() {/*{{{*/
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");

        vector<Pos> res;
        if (sz(tr.children[root]) > 1) {
            res.push_back(root);
        }
        rep(u, 0, n) {
            if (u == root) continue;
            bool is_kan = false;
            each(v, tr.children[u]) {
                if (tr.ord[u] <= lowlink[v]) {
                    is_kan = true;
                }
            }
            if (is_kan) res.push_back(u);
        }
        return res;
    }/*}}}*/

    vector<Edge<Cost>> get_bridges() {/*{{{*/
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");
        vector<Edge<Cost>> res;
        each(edge, edges){
            if (tr.ord[edge.from] < lowlink[edge.to]) res.push_back(edge);
        }
        return res;
    }/*}}}*/

    vector<Edge<Cost>> kruskal_tree() {/*{{{*/
        // 使用される辺のvectorを返す
        vector<Edge<Cost>> res(n - 1);
        sort(all(edges), [&](auto l, auto r) { return l.cost < r.cost; });
        UnionFind uf(n);

        Cost total_cost = zerocost;
        int idx = 0;
        each(e, edges) {
            if (uf.same(e.from, e.to)) continue;
            uf.merge(e.from, e.to);
            total_cost = total_cost + e.cost;
            res[idx] = e;
            idx++;
        }
        assert(idx == n - 1);

        return res;
    }/*}}}*/

    vector<Cost> dijkstra(vector<Pos> starts) {  // 多点スタート{{{
        vector<Cost> dist(n, infcost);           // 最短距離
        PQ<pair<Cost, Pos>> pq;
        each(start, starts) {
            dist[start] = zerocost;
            pq.push(make_pair(zerocost, start));
        }
        while (!pq.empty()) {
            auto cp = pq.top();
            pq.pop();
            auto [cost, u] = cp;
            for (const auto& edge : adj_list[u]) {
                Cost new_cost = cost + edge.cost;  // TODO: 問題によってはここが変更の必要あり
                if (new_cost < dist[edge.to]) {
                    dist[edge.to] = new_cost;
                    pq.push(make_pair(new_cost, edge.to));
                }
            }
        }
        return dist;
    };/*}}}*/

    vector<Cost> dijkstra(Pos start) {  // 1点スタート{{{
        vector<Pos> starts = {start};
        return dijkstra(starts);
    };/*}}}*/
};

//%snippet.end()%
#line 3 "library/cpp/graph/scc.hpp"

//%snippet.set('scc')%
//%snippet.config({'alias':'StronglyConnectedComponents'})%
//%snippet.include('Graph')%
//%snippet.fold()%

template<class T = ll>
struct StronglyConnectedComponents {
    const Graph<T> &g;  //{{{
    vector<int> comp;  // comp[i]: iが属する強連結成分が何番目の成分か
    Graph<> dag;  // 縮約されたDAG graph. sizeをとれば強連結成分の個数が分かる。
    Graph<> _rg;  // reversed graph
    vector<int> _order;  // order[i]: 帰りがけ順
    vector<int> _used;

    StronglyConnectedComponents(Graph<T> &_g)
        : g(_g), comp(_g.n, -1), _rg(_g.n), _used(_g.n) {
        for (int i = 0; i < g.n; i++) {
            for (auto e : g[i]) {
                _rg.add_edge(e.to, e.from);
            }
        }
        _build();
    }

    int operator[](int k) { return comp[k]; }

    void _build() {
        for (int i = 0; i < g.n; i++) _dfs(i);
        reverse(begin(_order), end(_order));
        int cnt = 0;
        for (int u : _order)
            if (comp[u] == -1) _rdfs(u, cnt), cnt++;

        dag = Graph(cnt);
        for (int u = 0; u < g.n; u++) {
            for (auto &e : g[u]) {
                if (comp[u] == comp[e.to]) continue;
                dag.add_edge(comp[u], comp[e.to]);
            }
        }
    }

    void _dfs(int idx) {
        if (_used[idx]) return;
        _used[idx] = true;
        for (auto &e : g[idx]) _dfs(e.to);
        _order.push_back(idx);
    }

    void _rdfs(int idx, int cnt) {
        if (comp[idx] != -1) return;
        comp[idx] = cnt;
        for (auto e : _rg[idx]) _rdfs(e.to, cnt);
    }  //}}}
};
// how to use
// StronglyConnectedComponents scc(g); // g: Graph
// dump(scc.comp, scc.dag.adj_list);

//%snippet.end()%


#line 3 "library/cpp/graph/topological_sort.hpp"

//%snippet.set('topological_sort')%
//%snippet.include('Graph')%
//%snippet.config({'alias':'tps'})%
//%snippet.fold()%

using Pos = int;
tuple<bool, vector<Pos>, int> topological_sort(const Graph<>& g) {
    vector<Pos> res;  // sort後の結果を格納
    vector<int> h(g.n);  // 頂点ごとの入次数
    stack<Pos> st;    // 入次数が0になっている頂点の集合
    int max_len = 0;   // 最長経路の長さ

    // 入次数を計算する。
    rep(u, g.n) {
        for (const auto& edge : g[u]) {
            h[edge.to]++;
        }
    }

    // 最初に入次数0になっている頂点を集める。
    rep(u, g.n) {
        if (h[u] == 0) {
            st.push(u);
            res.push_back(u);
        }
    }

    // 入次数0の頂点をresに追加しそこから出て行く辺は削除していく。O(g.n+E)
    while (!st.empty()) {
        stack<Pos> nex_st;
        while (!st.empty()) {
            Pos u = st.top(); st.pop();
            for (const auto& edge : g[u]) {
                h[edge.to]--;
                if (h[edge.to] == 0) {
                    res.push_back(edge.to);
                    nex_st.push(edge.to);
                }
            }
        }
        max_len++;
        st = nex_st;
    }
    
    bool is_valid = (sz(res)==g.n ? true : false);
    return {is_valid, res, max_len};  // res.size()<g.nなら閉路がありDAGではない。閉路内の頂点はstに入り得ないので。
}
//%snippet.end()%

#line 3 "library/cpp/graph/two_sat.hpp"

//%snippet.set('two_sat')%
//%snippet.include('scc')%
//%snippet.include('topological_sort')%
//%snippet.fold()%

struct two_sat{
    using Pos = int;
    using Size = int;
    Size orig_n;
    Graph<bool> g;
    vector<int> assigned;

    two_sat(Size _orig_n): orig_n(_orig_n){
        g = Graph<bool>(orig_n * 2);  // 頂点倍加
    };

    Pos toid(Pos u, bool is_u) {
        return u * 2 + is_u;
    }

    void add_condition(Pos u, bool is_u, Pos v, bool is_v) {
        // add condition (u == is_u or v == is_v)
        g.add_edge(toid(u, is_u^1), toid(v, is_v));
        g.add_edge(toid(v, is_v^1), toid(u, is_u));
    }

    bool build(){
        // if successed to assigne valiables, return true, else return false。
        StronglyConnectedComponents scc(g);
        auto ts = get<1>(topological_sort(scc.dag));
        vector<Size> ord(sz(ts));
        rep(i, sz(ts)) ord[ts[i]] = i;

        // check valid
        rep(u, orig_n){
            if (scc.comp[toid(u, 0)] == scc.comp[toid(u, 1)]) {
                return false;
            }
        }

        assigned = vector<int>(orig_n, -1);
        rep(u, orig_n){
            assigned[u] = (ord[scc.comp[toid(u, 0)]] < ord[scc.comp[toid(u, 1)]] ? 1 : 0);
        }
        return true;
    }
};
// how to use
// two_sat ts(n); // n変数
// ts.add_condition(x, 1, y, 0);  // represents (x==1 or y==0)
// ......
// ......
// auto valid = ts.build();
// if (valid) dump(ts.assigned);

//%snippet.end()%
#line 3 "library/cpp/graph/tests/two_sat.test.cpp"

int main() {
    int n,m;cin>>n>>m;
    vector<int> l(n), r(n);
    rep(i, n){
        cin>>l[i]>>r[i];
    }

    two_sat ts(n);

    rep(i, n){
        rep(j, i+1, n){
            if (r[j] < l[i] || r[i] < l[j]) {
            }
            else{
                ts.add_condition(i, 0, j, 0);
                ts.add_condition(i, 1, j, 1);
            }

            if (r[j] < m-1-r[i] || m-1-l[i] < l[j]) {
            }
            else{
                ts.add_condition(i, 0, j, 1);
                ts.add_condition(i, 1, j, 0);
            }
        }
    }
    auto valid = ts.build();
    cout << (valid ? "YES" : "NO") << endl;

    return 0; 
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

