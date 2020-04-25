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


# :warning: library/cpp/graph/dijkstra_dinamic.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#df01edd2bf6d13defce1efe9440d670c">library/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/dijkstra_dinamic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 20:06:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
auto s = mp(0,0);  // TODO: startの設定
rep(x, h) rep(y, w){ d[x][y]=INF; }  // dの初期化
typedef pair<int, pii> CP; // (cost, pos)
PQ<CP> q;
q.push(CP(0LL, s));

while (!q.empty()){
  auto v = q.top(); q.pop();
  int cost = v.first;
  int x = v.second.first;
  int y = v.second.second;
  if (cost < d[x][y]){
    d[x][y] = cost;
    rep(i, 4){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (0<= nx && nx <= h-1 && 0<=ny && ny <= w-1){
        if (M[nx][ny]=='.' && cost+1<d[nx][ny]) q.push(mp(cost+1, mp(nx, ny)));
      }
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/graph/dijkstra_dinamic.cpp"
auto s = mp(0,0);  // TODO: startの設定
rep(x, h) rep(y, w){ d[x][y]=INF; }  // dの初期化
typedef pair<int, pii> CP; // (cost, pos)
PQ<CP> q;
q.push(CP(0LL, s));

while (!q.empty()){
  auto v = q.top(); q.pop();
  int cost = v.first;
  int x = v.second.first;
  int y = v.second.second;
  if (cost < d[x][y]){
    d[x][y] = cost;
    rep(i, 4){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (0<= nx && nx <= h-1 && 0<=ny && ny <= w-1){
        if (M[nx][ny]=='.' && cost+1<d[nx][ny]) q.push(mp(cost+1, mp(nx, ny)));
      }
    }
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

