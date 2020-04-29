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


# :warning: library/cpp/graph/test.make_bipartie/codes/solve.cpp

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#705d3ed53d77dbb4f313b001665c2a66">library/cpp/graph/test.make_bipartie/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/test.make_bipartie/codes/solve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 14:52:46+09:00




## Depends on

* :heavy_check_mark: <a href="../../../array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :heavy_check_mark: <a href="../../tree.lib/tree.hpp.html">library/cpp/graph/tree.lib/tree.hpp</a>
* :heavy_check_mark: <a href="../../unionfind.hpp.html">library/cpp/graph/unionfind.hpp</a>
* :heavy_check_mark: <a href="../../../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../graph.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph<int, int> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b, 1);
    }

    auto res = g.make_bipartite();
    dump(res);
    if (res[0] == -1) {
        cout << n * (n - 1) / 2 - m << endl;
    } else {
        int c = accumulate(all(res), 0LL);
        cout << c * (n - c) - m << endl;
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
#line 3 "library/cpp/array/segtree/segment_tree.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%

template <typename T>
struct SegmentTree {  // {{{
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

    void update(int x, T val) {
        x += (N - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = merge(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    void add(int x, T val) {
        x += (N - 1);
        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = merge(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    // query for [l, r)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = N;
        if (r <= a || b <= l) return identity;
        if (a <= l && r <= b) return node[k];

        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return merge(vl, vr);
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
#line 4 "library/cpp/graph/tree.lib/tree.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree')%
//%snippet.include('segment_tree')%
template<class Cost=ll>
struct tree { /*{{{*/
    int n;
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
    vector<vector<pair<int, Cost>>> g;  // 辺(隣接リスト)
    vector<vector<int>> adj;           // 辺(隣接リスト)
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;    // euler_tour first occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;

    int _counter = 0;

    tree(){};
    tree(int n)
        : n(n),
          par(n),
          cost(n),
          ord(n),
          end(n),
          psize(n),
          depth(n),
          ldepth(n),
          g(n),
          adj(n),
          children(n),
          et_fpos(n),
          head_of_comp(n){};

    void add_edge(int u, int v, Cost cost) { /*{{{*/
        g[u].emplace_back(v, cost);
        g[v].emplace_back(u, cost);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }                             /*}}}*/
    void add_edge(int u, int v) { /*{{{*/
        g[u].emplace_back(v, 1);
        g[v].emplace_back(u, 1);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }                      /*}}}*/
    void build(int root) { /*{{{*/
        _counter = 0;
        // par[root] = -1;
        // cost[root] = -1;
        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
            ini, [](auto a, auto b) { return min(a, b); }, 1e18);
    }                                /*}}}*/
    int _dfs_psize(int u, int pre) { /*{{{*/
        psize[u] = 1;
        each(el, g[u]) {
            int v = el.first;
            if (v == pre) continue;
            psize[u] += _dfs_psize(v, u);
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
            rep(i, sz(g[u])) {
                if (g[u][i].first == pre) continue;
                if (psize[g[u][i].first] > max_psize) {
                    most_heavy_i = i;
                    max_psize = psize[g[u][i].first];
                }
            }
            if (most_heavy_i != -1) swap(g[u][most_heavy_i], g[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(g[u])) {
            int v = g[u][i].first;
            if (v == pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = g[u][i].second;

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
    vector<pair<int, int>> hld_path(int u, int v) {  //{{{
        // 閉区間をvectorで返す
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
        res.push_back({min(ord[u], ord[v]), max(ord[u], ord[v])});
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

}; /*}}}*/

//%snippet.end()%
#line 3 "library/cpp/graph/unionfind.hpp"

//%snippet.set('UnionFind')%
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
#line 5 "library/cpp/graph/graph.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%
//%snippet.include('tree')%

template<class Cost=ll> struct Graph {/*{{{*/
    using Pos = int;  // int以外には対応しない。
    struct Edge {/*{{{*/
        Pos from, to;
        Cost cost;
        int idx;
        Edge(){};
        Edge(Pos from, Pos to, Cost cost, int idx)
            : from(from), to(to), cost(cost), idx(idx) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {
            // os << "(f:" << e.from << ", t:" << e.to << ", c:" << e.cost << ", i" << e.idx << ")";  // detailed
            os << "(" << e.from << "," << e.to << ")";
            return os;
        }
    };/*}}}*/

    int n;  // 頂点数
    vector<vector<Edge>> adj_list;
    auto operator[](Pos pos) const { return adj_list[pos]; }
    vector<Edge> edges;
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
        lowlink = vector<Pos>(n, INF);
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

    vector<Edge> get_bridges() {/*{{{*/
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");
        vector<Edge> res;
        each(edge, edges){
            if (tr.ord[edge.from] < lowlink[edge.to]) res.push_back(edge);
        }
        return res;
    }/*}}}*/

    vector<Edge> kruskal_tree() {/*{{{*/
        // 使用される辺のvectorを返す
        vector<Edge> res(n - 1);
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
};/*}}}*/

//%snippet.end()%
#line 2 "library/cpp/graph/test.make_bipartie/codes/solve.cpp"

signed main() {
    int n, m;
    cin >> n >> m;
    Graph<int, int> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b, 1);
    }

    auto res = g.make_bipartite();
    dump(res);
    if (res[0] == -1) {
        cout << n * (n - 1) / 2 - m << endl;
    } else {
        int c = accumulate(all(res), 0LL);
        cout << c * (n - c) - m << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

