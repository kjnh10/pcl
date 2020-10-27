#pragma once
#include "../header.hpp"
#include "graph.hpp"

//%snippet.set('topological_sort')%
//%snippet.include('Graph')%
//%snippet.config({'alias':'tps'})%
//%snippet.fold()%

using Pos = int;
tuple<bool, vector<Pos>, int> topological_sort(const Graph<>& g) {
    vector<Pos> res;  // sort後の結果を格納
    vector<int> h(g.n);  // 頂点ごとの入次数
    stack<Pos> st;    // 入次数が0になっている頂点の集合
    int max_len = 0;   // 最長経路の長さ

    // 入次数を計算する。
    rep(u, g.n) {
        for (const auto& edge : g[u]) {
            h[edge.to]++;
        }
    }

    // 最初に入次数0になっている頂点を集める。
    rep(u, g.n) {
        if (h[u] == 0) {
            st.push(u);
            res.push_back(u);
        }
    }

    // 入次数0の頂点をresに追加しそこから出て行く辺は削除していく。O(g.n+E)
    while (!st.empty()) {
        stack<Pos> nex_st;
        while (!st.empty()) {
            Pos u = st.top(); st.pop();
            for (const auto& edge : g[u]) {
                h[edge.to]--;
                if (h[edge.to] == 0) {
                    res.push_back(edge.to);
                    nex_st.push(edge.to);
                }
            }
        }
        max_len++;
        st = nex_st;
    }
    
    bool is_valid = (sz(res)==g.n ? true : false);
    return {is_valid, res, max_len};  // res.size()<g.nなら閉路がありDAGではない。閉路内の頂点はstに入り得ないので。
}
//%snippet.end()%

