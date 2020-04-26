#pragma once
#include "../header.hpp"
#include "tree.lib/tree.hpp"
#include "unionfind.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%
//%snippet.include('tree')%

template <class Pos = int, class Cost = ll, Cost zerocost = 0LL,
          Cost infcost = INF>
struct Graph {
    struct Edge {
        Pos from, to;
        Cost cost;
        int idx;
        Edge(){};
        Edge(Pos from, Pos to, Cost cost, int idx)
            : from(from), to(to), cost(cost), idx(idx) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {
            os << e.from << " " << e.to << " " << e.cost << " " << e.idx;
            return os;
        }
    };

    int n;  // 頂点数
    // unordered_map<Pos, vector<Edge>>
    // adj_list;//Posがpiiでなくintならunordredの方が早い
    vector<vector<Edge>> adj_list;
    vector<Edge> edges;
    UnionFind buf;
    tree tr;
    Pos root;
    vector<int> _used_in_dfs;
    vector<int> lowlink;

    Graph() {}
    Graph(int _n) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n) {}

    void add_edge(Pos from, Pos to, Cost cost, int idx) {
        adj_list[from].emplace_back(from, to, cost, idx);
        edges.emplace_back(from, to, cost, idx);
    }

    void build_tree(int _root) {
        root = _root;
        _dfs_tree(root);
        tr.build(root);
        _make_lowlink();
    }

    auto operator[](Pos pos) { return adj_list[pos]; }

    vector<int> make_bipartite() {
        buf = UnionFind(2 * n);
        rep(u, n) {
            each(e, adj_list[u]) {
                buf.merge(u, e.to + n);
                buf.merge(e.to, u + n);
            }
        }

        vector<int> res(n, -1);
        rep(u, n) {
            if (buf.same(u, u + n)) {
                return res;
            }
        }
        rep(u, n) {
            if (buf.same(0, u))
                res[u] = 0;
            else
                res[u] = 1;
        }
        return res;
    }

    void _dfs_tree(int u) {
        _used_in_dfs[u] = 1;
        each(e, adj_list[u]) {
            if (_used_in_dfs[e.to]) continue;
            tr.add_edge(u, e.to, e.cost);
            _dfs_tree(e.to);
        }
    }

    void _make_lowlink() {
        lowlink = vector<int>(n, INF);
        r_rep(i, n) {
            int u = tr.dfstrv[i];
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
    }

    vector<Pos> get_articulation_points() {
        if (sz(lowlink) == 0) throw("make_lowlik() beforehand");

        vector<Pos> res;
        dump(tr.children[root]);
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
    }

    vector<Edge> kruskal_tree() {
        // 使用される辺のindexのvectorを返す
        vector<Edge> res(n - 1);
        sort(all(edges), [&](auto l, auto r) { return l.cost < r.cost; });
        UnionFind uf(n);

        int total_cost = 0;
        int i = 0;
        each(e, edges) {
            if (uf.same(e.from, e.to)) continue;
            uf.merge(e.from, e.to);
            total_cost += e.cost;
            res[i] = e;
            i++;
        }
        assert(i == n - 1);

        return res;
    }
};

//%snippet.end()%
