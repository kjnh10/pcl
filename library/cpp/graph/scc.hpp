#include "../header.hpp"
#include "graph.hpp"

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


