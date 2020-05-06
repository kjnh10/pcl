#include "../header.hpp"
#include "graph.hpp"

signed main() {
    //%snippet.set('gridgraph')%

    // grid graphを通常のグラフに格納する。
    int h, w;
    cin >> h >> w;
    int n = h * w;  // 頂点数
    vvi block(h, vi(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) { block[i][j] = (s[j] == '#' ? 1 : 0); }
    }

    Graph g(n);

    auto nid = [&](int i, int j){return (i*w + j);};
    auto pos = [&](int u) -> pair<int, int> { return {u/w, u%w}; };
    // int u = nid(i, j);
    // auto [i,j] = pos(u);

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    // 下と右のみ. rep(k, 4)をrep(k, 2)に変更するのも忘れない。
    // int di[] = {1, 0};
    // int dj[] = {0, 1};
    rep(i, h) rep(j, w) {
        if (block[i][j]) continue;  // blockから出る辺はない
        rep(k, 4) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (is_in(ni, 0, h) && is_in(nj, 0, w)) {
                if (block[ni][nj]) continue;  // blockに入る辺はない
                g.add_edge(nid(i, j), nid(ni, nj));
                // 自分から生える辺だけでよい。そうしないと二重辺になってしまう。
            }
        }
    }
    //%snippet.end()%

    // https://atcoder.jp/contests/abc151/submissions/12467532
    // (language updateが終わるまでは未veriyf)
    int ans = 0;
    rep(s, n){
        auto d = g.dijkstra(s);
        rep(i, sz(d)) if (d[i]<INF) chmax(ans, d[i]);
    }
    cout << ans << endl;

}