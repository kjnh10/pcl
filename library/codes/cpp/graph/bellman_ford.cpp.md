---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: codes/cpp/graph/bellman_ford.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-14 21:41:36+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

//%snippet.set('bellman_ford')%
struct Edge {
  int to, cost;  // 辺の接続先頂点, 辺の重み
  Edge(int to, int cost) : to(to), cost(cost) {}
};

typedef vector<vector<Edge> > Graph;  // 隣接リストの型
Graph graph;  // グラフの辺を格納した構造体
// graph[v][i]は頂点vから出るi番目の辺Edge

const int INF = 100000000;

vector<int> dist; // 最短距離

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
  dist = vector<int>(n, INF);
  dist[s] = 0; // 開始点の距離は0
  for (int i = 0; i < n; i++) {
    for (int v = 0; v < n; v++) {
      for (int k = 0; k < (int)graph[v].size(); k++) {
        Edge e = graph[v][k];
        if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  return false;
}

// int main() {
//   int n, m;
//   cin >> n >> m;
//
//   graph = Graph(n);
//  
//   for (int i = 0; i < m; i++) {
//     int from, to, cost;
//     cin >> from >> to >> cost;
//     graph[from].push_back(Edge(to, cost));
//   }
//  
//   bellman_ford(n, 0);
//  
//   for (int i = 0; i < n; i++) {
//     if (dist[i] != INF)
//       cout << "0から" << i << "へのコスト: " << dist[i] << endl;
//   }
//  
//   return 0;
// }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/graph/bellman_ford.cpp"
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

//%snippet.set('bellman_ford')%
struct Edge {
  int to, cost;  // 辺の接続先頂点, 辺の重み
  Edge(int to, int cost) : to(to), cost(cost) {}
};

typedef vector<vector<Edge> > Graph;  // 隣接リストの型
Graph graph;  // グラフの辺を格納した構造体
// graph[v][i]は頂点vから出るi番目の辺Edge

const int INF = 100000000;

vector<int> dist; // 最短距離

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
  dist = vector<int>(n, INF);
  dist[s] = 0; // 開始点の距離は0
  for (int i = 0; i < n; i++) {
    for (int v = 0; v < n; v++) {
      for (int k = 0; k < (int)graph[v].size(); k++) {
        Edge e = graph[v][k];
        if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  return false;
}

// int main() {
//   int n, m;
//   cin >> n >> m;
//
//   graph = Graph(n);
//  
//   for (int i = 0; i < m; i++) {
//     int from, to, cost;
//     cin >> from >> to >> cost;
//     graph[from].push_back(Edge(to, cost));
//   }
//  
//   bellman_ford(n, 0);
//  
//   for (int i = 0; i < n; i++) {
//     if (dist[i] != INF)
//       cout << "0から" << i << "へのコスト: " << dist[i] << endl;
//   }
//  
//   return 0;
// }

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

