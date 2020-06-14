#include "graph.hpp"

// verified by https://codeforces.com/contest/1364/problem/D

// 無向グラフにしか対応していないので有向グラフの場合は以下
// 有向グラフの極小閉路の見つけ方（線形✕logくらい）
// ・dfsでひとつ閉路をみつける（けんちょんさんのdfsの記事）
// ・全辺を走査してショートカットの辺があれば不要なノードを削除していく。サイクルは(index, node-num)のsetで管理しておくと各ノードの削除はlog
// でできるかな？

//%snippet.set('local_min_cycle')%
//%snippet.config({'alias':'cycle'})%
//%snippet.include('Graph')%
//%snippet.fold()%

template<class T>
vector<int> local_min_cycle(Graph<T>& g){
    // 無向グラフにしか対応していないので注意
    pair<int, int> loop = mp(-1, -1);  // start, end
    vector<int> loop_path;
    vector<bool> used(g.n);
    bool loop_found = false;
    auto dfs = [&](const auto& dfs, int u, int pre) -> int {
        used[u] = 1;
        int max_depth = -1;
        each(e, g.adj_list[u]){
            if (e.to == pre) continue;
            else if (used[e.to]){  // back-track-edge
                loop_found = true;
                if (g.tr.depth[e.to] > max_depth) {
                    max_depth = g.tr.depth[e.to];
                    loop = mp(e.to, u);
                }
            }
        }
        if (loop_found){
            // generate path
            loop_path.pb(loop.first);
            int cur = loop.second;
            while(cur != loop.first){
                loop_path.pb(cur);
                cur = g.tr.par[cur];
            }
            // loop_path.pb(loop.first);
        }

        // if no back-tarck edge exists, the continue to dfs
        each(e, g.tr.adj_list[u]){
            if (e.to == pre) continue;
            if (!loop_found) dfs(dfs, e.to, u);
        }

        return 0;
    };

    dfs(dfs, 0, -1);
    return loop_path;  // if tree, loop_path = {};
}

//%snippet.end()%
