// %test('http://codeforces.com/contest/1324/problem/F')%
#include "../../../template.hpp"
#include "./tree.hpp"

signed main() {
    int n; cin>>n;
    vector<int> col(n);
    rep(i, n){
        cin>>col[i];
        if (col[i]==0) col[i] = -1;
    }

    //%snippet.set('reroot')%
    tree tr(n);
    rep(i, n-1){
        int u, v;cin>>u>>v;
        u--;v--;
        tr.add_edge(u, v);
    }
    tr.build(0);

    vector<map<int, int>> dp(n);
    // dp[u][v]: uの親をvとするような向きで木を見た時のuを頂点とする部分木の情報

    // first dfs
    rrep(i, 1, n){
        // 葉からdp
        int u = tr.dfstrv[i];
        dp[u][tr.par[u]] = col[u];  // TODO: update: 子供がいない場合
        each(ch, tr.children[u]){
            dp[u][tr.par[u]] += max(0LL, dp[ch][u]);  // TODO: update
        }
    }
    dump_2d(dp, n, n);

    // second dfs
    rep(i, 0, n){
        cerrendl;
        // uを頂点とする部分木の情報dp[u][*]を配る。
        int u = tr.dfstrv[i];
        int m = sz(tr.adj[u]);

        vector<int> lcum(m+2);
        vector<int> rcum(m+2);
        { // 前処理
            vector<int> child_info(m+2);
            rep(j, 1, m+1){
                int v = tr.adj[u][j-1];
                child_info[j] = max(dp[v][u], 0LL);  // TODO: update
            }
            lcum[0] = 0; lcum[m+1] = 0;  // 単位元を番兵に  // TODO: update
            rcum[0] = 0; rcum[m+1] = 0;  // 単位元を番兵に  // TODO: update
            rep(j, 1, m+1){
                lcum[j] = lcum[j-1] + child_info[j];  // TODO: update
            }
            rrep(j, 1, m+1){
                rcum[j] = rcum[j+1] + child_info[j];  // TODO: update
            }
            dump(child_info);
        }

        dump(lcum);
        dump(rcum);
        rep(j, 1, m+1){
            int v = tr.adj[u][j-1];
            dp[u][v] = lcum[j-1] + rcum[j+1];  // TODO: update
            dp[u][v] += col[u];  // 追加条件  // TODO: update
            dump(u, v, j, dp[u][v], lcum[j-1], rcum[j+1], col[u]);
        }
    }
    dump_2d(dp, n, n);

    // answer
    vector<int> ans;
    rep(u, n){
        int res = col[u];  // TODO: update
        each(v, tr.adj[u]){
            res += max(0LL, dp[v][u]);  // TODO: update
        }
        ans.push_back(res);
    }
    rep(i, sz(ans)) cout << ans[i] << (i!=sz(ans)-1 ? " " : "\n");

    //%snippet.end()%

    return 0;
}
