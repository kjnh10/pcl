#pragma once
#include "../header.hpp"
#include "edge.hpp"
#include "tree.lib/tree.hpp"
#include "union_find.hpp"

//%snippet.set('Graph')%
//%snippet.include('union_find')%
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
        union_find buf(2 * n);
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
        union_find uf(n);

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
