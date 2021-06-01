#include "tree.hpp"

class kth_root {
public:
    int N; // 2**N >= max_depthとなる最小のべき + 1
    const tree<>& tr;
    vector<vector<int>> db;
    kth_root(tree<>& _tr) : tr(_tr) {
        int max_depth = *max_element(all(tr.depth));
        N = 0;
        int mul = 1;
        while(mul < max_depth){
            mul <<= 1;
            N++;
        }
        N++;

        db = mv(N, tr.n, -1);
        db[0] = tr.par; db[0][tr.root] = -1;
        rep(d, 1, N){
            rep(j, tr.n){
                if (db[d-1][j] == -1) db[d][j] = -1;
                else db[d][j] = db[d-1][db[d-1][j]];
            }
        }
    }
    
    int query(int node, int k) {
        int cur = node;
        for(int d = 0; d < N ; d++) {
            if (k>>d&1) {
                if (db[d][cur]==-1) return -1;
                else cur = db[d][cur];
            }
        }
        return cur;
    }

    int lca(int u, int v) {
        if (tr.depth[u] > tr.depth[v]) swap(u, v);
        v = query(v, tr.depth[v] - tr.depth[u]);
        if (u==v) return u;

        for (int d = N-1; d >= 0; d--) {
            if (db[d][u] != db[d][v]) {
                u = db[d][u];
                v = db[d][v];
            }
        }
        return tr.par[u];
    }
};
