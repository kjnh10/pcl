#pragma once
#include "../../header.hpp"
#include "../../array/segtree/segment_tree.hpp"
#include "../edge.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree_non_recursive')%
//%snippet.include('segment_tree')%
//%snippet.include('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct tree { 
    int n;
    int root;
    vector<int> par;   // par[i]: dfs木における親
    vector<Edge<Cost>*> edge;  // edge[i]: dfs木における親への辺のpointer
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
    vector<int> euler_tour;
    vector<int> et_fpos;    // euler_tour first occurence position
    vector<int> et_lpos;    // euler_tour last occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;

    tree(){};/*{{{*/
    tree(int n_)
        : n(n_),
          par(n_),
          edge(n_),
          ord(n_),
          end(n_),
          psize(n_),
          depth(n_),
          ldepth(n_),
          adj_list(n_),
          et_fpos(n_),
          et_lpos(n_),
          head_of_comp(n_){};/*}}}*/
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
        par[root] = -1;
        edge[root] = nullptr;
        _dfs_basic();
        _dfs_tree();
        _dfs_et();
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
            ini, [](auto a, auto b) { return min(a, b); }, numeric_limits<int>().max());
    }                                /*}}}*/
    void _dfs_basic() { /*{{{*/
        // HLDにpsizeが必要なのでまずpsizeだけ計算する。
        int counter = 0;
        vector<int> dfstrv;
        stack<pair<int, int>> st; st.push(make_pair(root, -1));
        while (sz(st) > 0){
            auto [u, pre] = st.top();st.pop();
            ord[u] = counter;
            counter++;
            par[u] = pre;
            dfstrv.pb(u);
            each(e, adj_list[u]) {
                if (e.to == pre) continue;
                st.push(make_pair(e.to, u));
            }
        }
        r_rep(i, sz(dfstrv)){
            int u = dfstrv[i];
            psize[u] = 1;
            end[u] = ord[u] + 1;
            for (auto& e : adj_list[u]) {
                if (e.to == par[u]) continue;
                psize[u] += psize[e.to];
                chmax(end[u], ord[u]);
            }
        }
    }                                               /*}}}*/
    void _dfs_tree() { /*{{{*/
        dfstrv.clear();
        dump(dfstrv);
        stack<tuple<int, int, int>> st; st.push(make_tuple(root, -1, root));
        int counter = 0;
        while(sz(st) > 0){
            auto [u, pre, head_node] = st.top(); st.pop();
            dfstrv.pb(u);
            dump(dfstrv);
            ord[u] = counter;
            counter++;
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
                dump(u, max_psize, most_heavy_i);
                if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);
            }
            head_of_comp[u] = head_node;
            r_rep(i, sz(adj_list[u])) {
                int v = adj_list[u][i].to;
                if (v == pre) continue;
                if (i == 0) st.push(make_tuple(v, u, head_node));  // continue components
                else        st.push(make_tuple(v, u, v)); // new
            }
        }

        r_rep(i, n){
            int u = dfstrv[i];
            end[u] = ord[u];
            each(e, adj_list[u]) {
                edge[e.to] = &e;
                if (e.to == par[u]) continue;
                chmax(end[u], end[e.to]);
            }
        }

        rep(i, sz(dfstrv)){
            int u = dfstrv[i];
            if (par[u] != -1){
                depth[u] = depth[par[u]] + 1;
                ldepth[u] = ldepth[par[u]] + edge[u]->cost;
            }
        }

    }                     /*}}}*/
    void _dfs_et() { /*{{{*/
        stack<int> st;
        st.push(~root);  // 帰りがけ処理用
        st.push(root);
        while(sz(st) > 0){
            int u = st.top();st.pop();
            if (u >= 0){  // 行きがけ順の処理
                et_fpos[u] = euler_tour.size();
                euler_tour.pb(u);
                r_rep(i, sz(adj_list[u])) {
                    int v = adj_list[u][i].to;
                    if (v == par[u]) continue;
                    st.push(~u);
                    st.push(v);
                }
            }
            else{  // 帰りがけ順の処理
                et_lpos[~u] = euler_tour.size();
                euler_tour.pb(~u);
            }
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
        vector<pair<int, int>> res;
        // return {[l0, r0), [l1, r1), ....} for_edge=trueでlcaは除いて返すことに注意。
        while (head_of_comp[u] != head_of_comp[v]) {
            if (depth[head_of_comp[u]] < depth[head_of_comp[v]]) {
                res.push_back({ord[head_of_comp[v]], ord[v]+1});
                v = par[head_of_comp[v]];
            } else {
                res.push_back({ord[head_of_comp[u]], ord[u]+1});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u], ord[v])+1});
        return res;
    }                              //}}}
#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const tree& tr) {
        os << endl;
        os << "psize:       " << tr.psize << endl;
        os << "par:         " << tr.par << endl;
        os << "dfstrv:      " << tr.dfstrv << endl;
        os << "ord:         " << tr.ord << endl;
        os << "end:         " << tr.end << endl;
        os << "depth:       " << tr.depth << endl;
        os << "euler_tour:  " << tr.euler_tour << endl;
        os << "et_fpos:     " << tr.et_fpos << endl;
        os << "head_of_comp:" << tr.head_of_comp << endl;
        return os;
    }
#endif /*}}}*/
}; 
//%snippet.end()%
