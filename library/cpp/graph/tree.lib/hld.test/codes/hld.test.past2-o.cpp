#define IGNORE
#define PCMTEST
#include "../../../unionfind.hpp"
#include "../../../../array/segtree/segment_tree.hpp"
#include "../../tree.hpp"

template<class T>
void pairsort(vector<T>& x, vector<T>& y, vector<T>& z, vector<T>& p){
    int n = sz(x);
    vector<tuple<T, T, T, T>> t(n);
    rep(i, n){
        t[i] = make_tuple(x[i], y[i], z[i], p[i]);
    }
    sort(all(t));
    rep(i, n){
        x[i] = get<0>(t[i]);
        y[i] = get<1>(t[i]);
        z[i] = get<2>(t[i]);
        p[i] = get<3>(t[i]);
    }
}

signed main() {
    int n,m;cin>>n>>m;

    vi a(m), b(m), c(m), idx(m);
    rep(i, m){
        cin>>a[i]>>b[i]>>c[i];
        idx[i] = i;
        a[i]--;b[i]--;
    }
    pairsort(c, a, b, idx);
    dump(c);
    dump(a);
    dump(b);
    dump(idx);  // idxを使うのは最後の最後にする

    UnionFind uf(n);
    int cost = 0;
    vector<int> used(m);
    rep(i, m){
        if (!uf.same(a[i], b[i])){
            used[i] = 1;
            uf.merge(a[i], b[i]);
            cost += c[i];
        }
    }
    dump(used);
    dump(cost);

    tree tr(n);
    rep(i, m){
        if (used[i]){
            tr.add_edge(a[i], b[i], c[i]);
        }
    }
    tr.build(0);
    dump(tr);

    vi ans(m);
    auto mymax=[](auto a, auto b){return max(a,b);};
    SegmentTree<int> seg(n, mymax, -1e18);
    rep(i, n) seg.update(i, tr.cost[tr.dfstrv[i]]);

    rep(i, m){
        if (used[i]){
            ans[idx[i]] = cost;
        }
        else{
            int max_cost = -INF;
            each(p, tr.hld_path(a[i], b[i])){
                dump(idx[i], p);
                chmax(max_cost, seg.query(p.first, p.second+1));
            }
            dump(idx[i], c[i], max_cost);
            ans[idx[i]] = cost + c[i] - max_cost;
        }
    }
    rep(i, m){
        cout << ans[i] << endl;
    }

    return 0;
}
