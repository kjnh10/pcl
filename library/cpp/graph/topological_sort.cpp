#include "../header.hpp"

//%snippet.set('topological_sort')%
//%snippet.config({'alias':'tps'})%
template <class node>
using graph = vector<vector<node>>;

template <class node>
pair<vector<node>, int> topological_sort(const graph<node>& G) {
    int V = sz(G);     // node数
    vector<node> ans;  // sort後の結果を格納
    vector<int> h(V);  // 頂点ごとの入次数
    stack<node> st;    // 入次数が0になっている頂点の集合
    int max_len = 0;   // 最長経路の長さ
                       /*{{{*/
    // 入次数を計算する。
    rep(v, V) {
        for (auto to : G[v]) {
            h[to]++;
        }
    }

    // 最初に入次数0になっている頂点を集める。
    rep(v, V) {
        if (h[v] == 0) {
            st.push(v);
            ans.push_back(v);
        }
    }

    // 入次数0の頂点をansに追加しそこから出て行く辺は削除していく。O(V+E)
    while (!st.empty()) {
        stack<node> nex_st;
        while (!st.empty()) {
            node v = st.top();
            st.pop();
            for (auto to : G[v]) {
                h[to]--;
                if (h[to] == 0) {
                    ans.push_back(to);
                    nex_st.push(to);
                }
            }
        }
        max_len++;
        st = nex_st;
    }
    /*}}}*/
    return make_pair(
        ans,
        max_len);  // ans.size()<Vなら閉路がありDAGではない。閉路内の頂点はstに入り得ないので。
}
//%snippet.end()%

int solve() {  // ABC139 E:https://atcoder.jp/contests/abc139
               // input
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;

    vvi M(n);
    rep(i, n) {
        rep(j, n - 1) {
            int a;
            cin >> a;
            a--;
            M[i].pb(a);
        }
    }
    dump_2d(M, n, n - 1);

    // encode pair<int, int> -> int
    int id = 0;
    vvi idtable(n, vi(n));
    rep(i, n) rep(j, i + 1, n) { idtable[i][j] = id++; }
    auto toid = [&](int i, int j) {
        if (i > j) swap(i, j);
        return idtable[i][j];
    };

    // generate graph
    graph<int> g(m + 2);
    vi h(m + 2);
    rep(i, n) {
        rep(j, 1, n - 1) {
            int pre = M[i][j - 1];
            int to = M[i][j];
            g[toid(i, pre)].pb(toid(i, to));
            h[toid(i, to)]++;
        }
    }
    dump(g);

    // answer
    auto ans = topological_sort(g);
    cout << ((sz(ans.first) < m) ? -1 : ans.second) << endl;
    return 0;
}

signed main() {  //{{{
#ifdef INPUT_FROM_FILE
    std::ifstream in(infile);
    std::cin.rdbuf(in.rdbuf());
#endif
    solve();
    return 0;
}  //}}}
