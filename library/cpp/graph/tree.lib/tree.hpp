#pragma once
#include "../../../../problem_template/codes/header.hpp"
#include "../../array/segtree/segment_tree.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree')%
//%snippet.include('segment_tree')%
struct tree{/*{{{*/
    int n;
    vector<int> par;  // par[i]: dfs木における親
    vector<int> cost;  // par[i]: dfs木における親への辺のコスト
    vector<int> dfstrv; // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
    vector<int> ord;  // ord[u]: uのdfs木における訪問順
    vector<int> end;  // end[u]: uのdfs終了時のカウンター
    vector<int> psize; // psize[u]: uのpartial tree size
    // uの部分木は[ord[u], end[u])
    // ordとdfstrvは逆変換

    vector<int> depth;  // depth[i]: dfs木でのiの深さ
    vector<int> ldepth;  //  ldepth[i]: dfs木でのrootからの距離
    vector<vector<pair<int, int>>> g; // 辺(隣接リスト)
    vector<vector<int>> adj; // 辺(隣接リスト)
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;  // euler_tour first occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;

    int _counter = 0;

    tree(){};
    tree(int n): n(n),par(n),cost(n,1),ord(n),end(n),psize(n),depth(n),ldepth(n),g(n),adj(n),children(n),et_fpos(n),head_of_comp(n){};

    void add_edge(int u, int v, int cost){/*{{{*/
        g[u].emplace_back(v, cost);
        g[v].emplace_back(u, cost);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }/*}}}*/
    void add_edge(int u, int v){/*{{{*/
        g[u].emplace_back(v, 1);
        g[v].emplace_back(u, 1);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }/*}}}*/
    void build(int root){/*{{{*/
        _counter = 0;
        par[root] = -1;
        cost[root] = -1;
        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2*n-1); rep(i, 2*n-1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(ini, [](auto a, auto b){return min(a,b);}, 1e18);
    }/*}}}*/
    int _dfs_psize(int u, int pre){/*{{{*/
        psize[u] = 1;
        each(el, g[u]){
            int v = el.first;
            if (v==pre) continue;
            psize[u] += _dfs_psize(v, u);
        }
        return psize[u];
    }/*}}}*/
    void _dfs_tree(int u, int pre, int head_node){/*{{{*/
        dfstrv.pb(u);
        ord[u] = _counter;
        if (pre!=-1){
            depth[u] = depth[pre]+1; 
            ldepth[u] = ldepth[pre]+cost[u]; 
        }

        _counter++;
        {
            // set most heavy child to top
            int max_psize = 0;
            int most_heavy_i = -1;
            rep(i, sz(g[u])){
                if (g[u][i].first==pre) continue;
                if (psize[g[u][i].first] > max_psize){
                    most_heavy_i = i;
                    max_psize = psize[g[u][i].first];
                }
            }
            if (most_heavy_i!=-1) swap(g[u][most_heavy_i], g[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(g[u])){
            int v = g[u][i].first;
            if (v==pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = g[u][i].second;

            if (i==0) _dfs_tree(v, u, head_node); // continue components
            else      _dfs_tree(v, u, v);         // new
        }
        end[u] = _counter;
    }/*}}}*/
    void _dfs_et(int u){/*{{{*/
        et_fpos[u] = euler_tour.size();
        euler_tour.pb(u);
        each(v, children[u]){
            _dfs_et(v);
            euler_tour.pb(u);
        }
    }/*}}}*/
    int lca(int u, int v){/*{{{*/
        if (u==v) return u;
        if (et_fpos[u]>et_fpos[v]) swap(u, v);
        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
    }/*}}}*/
    int dist(int u, int v){/*{{{*/
        int p = lca(u, v);
        return depth[u] + depth[v] - 2*depth[p];
    }/*}}}*/
    int ldist(int u, int v){  // length dist{{{
        int p = lca(u, v);
        return ldepth[u] + ldepth[v] - 2*ldepth[p];
    }/*}}}*/
    pair<int, int> diameter(){/*{{{*/
        int u, v;
        int max_len = *max_element(all(ldepth));
        rep(i, n){
            if(ldepth[i]==max_len){
                u = i; break;
            }
        }
        int md = -1;
        rep(i, n){
            int d = ldist(u, i);
            if (d>md){ v = i; md = d; }
        }
        return mp(u, v);
    }/*}}}*/
    vector<pair<int, int>> hld_path(int u, int v){ //{{{
        // 閉区間をvectorで返す
        vector<pair<int,int>> res;
        while(head_of_comp[u] != head_of_comp[v]){
            if(depth[head_of_comp[u]] < depth[head_of_comp[v]]){
                res.push_back({ord[head_of_comp[v]], ord[v]});
                v = par[head_of_comp[v]];
            }
            else{
                res.push_back({ord[head_of_comp[u]], ord[u]});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u],ord[v]), max(ord[u], ord[v])});
        return res;
    } //}}}
#if defined(PCM) || defined(LOCAL)/*{{{*/
    friend ostream& operator<<(ostream& os, const tree& tr){
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
#endif/*}}}*/

};/*}}}*/

//%snippet.end()%

