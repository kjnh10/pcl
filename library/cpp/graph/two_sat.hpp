#include "scc.hpp"
#include "topological_sort.hpp"

//%snippet.set('two_sat')%
//%snippet.include('scc')%
//%snippet.include('topological_sort')%
//%snippet.fold()%

struct two_sat{
    using Pos = ll;
    using Size = ll;
    Size orig_n;
    Graph<> g;
    vector<int> assigned;

    two_sat(Size _orig_n): orig_n(_orig_n){
        g = Graph<>(orig_n * 2);  // 頂点倍加
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
