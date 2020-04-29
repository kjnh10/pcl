#include "../header.hpp"
#include "graph.hpp"

//%snippet.set('bellman_ford')%
//%snippet.include('Graph')%
//%snippet.fold()%

auto bellman_ford(const Graph<>& g, int start) { // 負閉路検出
    vector<decltype(g.infcost)> dist(g.n, g.infcost);  // 最短距離
    dist[start] = g.zerocost;
    for (int i = 0; i < g.n; i++) {
        each(edge, g.edges){
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.cost) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                if (i == g.n - 1)
                    return make_pair(true, dist);  // n回目にも更新があるなら負の閉路が存在
            }
        }
    }
    return make_pair(false, dist);
}

//%snippet.end()%
