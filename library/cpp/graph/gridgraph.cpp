#include "../header.hpp"

signed main(){
//%snippet.set('gridgraph')%

    // grid graphを通常のグラフに格納する。
    // (i, j) -> i*w + j
    // u -> (u/w, u%w)

    int h, w;
    cin >> h >> w;
    int n = h * w;
    vvi block(h, vi(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) { block[i][j] = (s[j] == '.' ? 0 : 1); }
    }

    vvi g(n);
    // Graph G;

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    rep(i, h) rep(j, w) {
        if (block[i][j]) continue;  // blockから出る辺はない
        int u = i * w + j;

        rep(k, 4) {
            int ni = i + di[k];
            int nj = j + dj[k];
            int v = ni * w + nj;
            if (is_in(ni, 0, h) && is_in(nj, 0, w)) {
                if (block[ni][nj]) continue;  // blockに入る辺はない
                g[u].pb(v);
                // G.add_edge(u, v, 1);
                // 自分から生える辺だけでよい。そうしないと二重辺になってしまう。
            }
        }
    }

//%snippet.end()%
}
