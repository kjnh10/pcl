#pragma once
#include "../header.hpp"
#include "unionfind.hpp"
#include "tree.lib/tree.hpp"

//%snippet.set('Graph')%
//%snippet.include('UnionFind')%
//%snippet.include('tree')%

template<class Pos=int, class Cost=ll, Cost zerocost=0LL, Cost infcost=INF>
struct Graph{
    struct Edge {
        Pos to;
        Cost cost;
        Edge(Pos to, Cost cost): to(to), cost(cost) {
        }
        friend ostream& operator<<(ostream &os, const Edge& e){
            os << e.to << " " << e.cost;
            return os;
        }
    };

    int n;  // 頂点数
    // unordered_map<Pos, vector<Edge>> adj_list;//Posがpiiでなくintならunordredの方が早い
    vector<vector<Edge>> adj_list;
    UnionFind buf;
    tree tr;
    Pos root;
    vector<int> _used_in_dfs;
    vector<int> lowlink;

    Graph(){ }
    Graph(int _n): n(_n), adj_list(_n), tr(n), _used_in_dfs(n){
    }


    void add_edge(Pos from, Pos to, Cost cost){
        adj_list[from].emplace_back(to, cost);
    }

    void build_tree(int _root){
        root = _root;
        _dfs_tree(root);
        tr.build(root);
        _make_lowlink();
    }

    auto operator[](Pos pos) {
        return adj_list[pos];
    }

    vector<int> make_bipartite(){
        buf = UnionFind(2*n);
        rep(u, n){
            each(e, adj_list[u]){
                buf.merge(u, e.to+n);
                buf.merge(e.to, u+n);
            }
        }

        vector<int> res(n, -1);
        rep(u, n){
            if(buf.same(u, u+n)){
                return res;
            }
        }
        rep(u, n){
            if (buf.same(0, u)) res[u] = 0;
            else res[u] = 1;
        }
        return res;
    }

    void _dfs_tree(int u){
        _used_in_dfs[u] = 1;
        each(el, adj_list[u]){
            auto [v, cost] = el;
            if (_used_in_dfs[v]) continue;
            tr.add_edge(u, v, cost);
            _dfs_tree(v);
        }
    }
    // lolinkを構築

    void _make_lowlink(){
        lowlink = vector<int>(n, INF);
        r_rep(i, n){
            int u = tr.dfstrv[i];
            chmin(lowlink[u], tr.ord[u]);

            each(el, adj_list[u]){
                auto [v, cost] = el;
                if (v==tr.par[u]) continue;
                else if (tr.ord[v]<tr.ord[u]){
                    chmin(lowlink[u], tr.ord[v]);
                }
                else{
                    chmin(lowlink[u], lowlink[v]);
                }
            }
        }
    }

    vector<Pos> get_articulation_points(){
        if (sz(lowlink)==0) throw("make_lowlik() beforehand");

        vector<Pos> res;
        dump(tr.children[root]);
        if (sz(tr.children[root])>1){
            res.push_back(root);
        }
        rep(u, 0, n){
            if (u==root) continue;
            bool is_kan = false;
            each(v, tr.children[u]){
                if (tr.ord[u] <= lowlink[v]){
                    is_kan = true;
                }
            }
            if (is_kan) res.push_back(u);
        }
        return res;
    }
};

//%snippet.end()%

