#pragma once
#include "graph.hpp"

//%snippet.set('local_min_cycle_undirected')%
//%snippet.config({'alias':'cycle'})%
//%snippet.include('Graph')%
//%snippet.fold()%

// verified by https://codeforces.com/contest/1364/problem/D

template<class T>
vector<int> local_min_cycle_undirected(Graph<T>& g){
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


//%snippet.set('local_min_cycle_directed')%
//%snippet.include('Graph')%
//%snippet.fold()%

// verified by https://atcoder.jp/contests/abc142/tasks/abc142_f
// 有向グラフの極小閉路の見つけ方（線形✕logくらい）
// ・dfsでひとつ閉路をみつける（けんちょんさんのdfsの記事）
// ・全辺を走査してショートカットの辺があれば不要なノードを削除していく。サイクルは(index, node-num)のsetで管理しておくと各ノードの削除はlog

template<class T>
vec<int> local_min_cycle_directed(Graph<T>& g){
    int n = g.n;
    vec<bool> seen(n);
    vec<bool> finished(n);
    vec<int> hist;
    bool exist_loop = false;
    int starting_point = -1;
    auto dfs = [&](const auto& dfs, int u, int pre) -> void {
        seen[u] = true;
        hist.push_back(u);
        each(e, g[u]){
            if (e.to == pre) continue;
            else if (finished[e.to]) continue;
            else if (seen[e.to]){
                starting_point = e.to;
                exist_loop = true;
                return;
            }
            else{
                dfs(dfs, e.to, u);
            }
            if (exist_loop) return;
        }
        hist.pop_back();
        finished[u] = true;
        return;
    };

    rep(u, n){
        if (finished[u]) continue;
        dfs(dfs, u, -1);
        if (exist_loop){
            vec<int> loop;
            r_rep(i, sz(hist)){
                loop.pb(hist[i]);
                if (hist[i] == starting_point) break;
            }
            reverse(all(loop));
            int m = sz(loop);

            // find short cut
            map<int, int> pos;
            rep(i, m) pos[loop[i]] = i;
            vec<int> ans;
            int next_right = -1;
            int next_left = -1;
            rep(i, m) {
                if (next_right == -1 || next_right == i){
                    ans.pb(loop[i]);
                    next_right = -1;
                    each(e, g[loop[i]]){
                        if (e.to != loop[(i+1)%m] && pos.find(e.to) != pos.end()) {
                            if (pos[e.to] < i)
                                chmax(next_left, pos[e.to]); // back-edge
                            else
                                chmax(next_right, pos[e.to]); // to-edge
                        }
                    }
                    if (next_left != -1){
                        ans.clear();
                        rep(j, next_left, i+1){
                            if (pos.find(loop[j]) != pos.end()) ans.pb(loop[j]);
                        }
                        return ans;
                    }
                }
                else{
                    pos.erase(loop[i]);
                }
            }
            return ans;
        }
    }
    return {};
}

//%snippet.end()%
