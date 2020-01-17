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


# :warning: codes/cpp/graph/gridgraph.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/gridgraph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-13 16:10:40+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('dijkstra')%

  // grid graphを通常のグラフに格納する。
  // (i, j) -> i*w + j
  // u -> (u/w, u%w)

  int h,w;cin>>h>>w;
  int n = h*w;
  vvi block(h, vi(w));
  rep(i, h){
    string s;cin>>s;
    rep(j, w){
      block[i][j] = (s[j]=='.'?0:1);
    }
  }

  vvi g(n);
  // Graph G;

  int di[]={1, -1, 0, 0};
  int dj[]={0, 0, 1, -1};
  rep(i, h)rep(j, w){
    if (block[i][j]) continue;  // blockから出る辺はない
    int u = i*w+j;

    rep(k, 4){
      int ni = i+di[k];
      int nj = j+dj[k];
      int v = ni*w + nj;
      if (is_in(ni, 0, h) && is_in(nj, 0, w)){
        if (block[ni][nj]) continue;  // blockに入る辺はない
        g[u].pb(v);
        // G.add_edge(u, v, 1);
        // 自分から生える辺だけでよい。そうしないと二重辺になってしまう。
      }
    }
  }

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/graph/gridgraph.cpp"
//%snippet.set('dijkstra')%

  // grid graphを通常のグラフに格納する。
  // (i, j) -> i*w + j
  // u -> (u/w, u%w)

  int h,w;cin>>h>>w;
  int n = h*w;
  vvi block(h, vi(w));
  rep(i, h){
    string s;cin>>s;
    rep(j, w){
      block[i][j] = (s[j]=='.'?0:1);
    }
  }

  vvi g(n);
  // Graph G;

  int di[]={1, -1, 0, 0};
  int dj[]={0, 0, 1, -1};
  rep(i, h)rep(j, w){
    if (block[i][j]) continue;  // blockから出る辺はない
    int u = i*w+j;

    rep(k, 4){
      int ni = i+di[k];
      int nj = j+dj[k];
      int v = ni*w + nj;
      if (is_in(ni, 0, h) && is_in(nj, 0, w)){
        if (block[ni][nj]) continue;  // blockに入る辺はない
        g[u].pb(v);
        // G.add_edge(u, v, 1);
        // 自分から生える辺だけでよい。そうしないと二重辺になってしまう。
      }
    }
  }

//%snippet.end()%

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

