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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: codes/cpp/dfs.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/dfs.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-31 17:03:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp


//%snippet.set('dfs')%

stack<int> st;
vector<int> used(n);

st.push(0);
while (!st.empty()){
  auto v = st.top();st.pop();
  if (used[v]) continue;

  each(u, g[v]){
    if (used[u]) continue;
    // process
    st.push(u);
  }
  used[v] = 1;
}

//%snippet.end()%


//%snippet.set('bfs')%

queue<int> q;
vector<int> used(n);

q.push(0);
while (!st.empty()){
  auto v = q.front();q.pop();
  if (used[v]) continue;

  each(u, g[v]){
    // process
    q.push(u);
  }
  used[v] = 1;
}

//%snippet.end()%


//%snippet.set('01bfs')%

deque<int> dq;
vector<int> used(n);

dq.push_back(0);
while (!dq.empty()){
  auto v = dq.front();dq.pop_front();
  if (used[v]) continue;

  each(u, g[v]){
    // process
    q.push_back(u);
  }
  used[v] = 1;
}

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/dfs.cpp"


//%snippet.set('dfs')%

stack<int> st;
vector<int> used(n);

st.push(0);
while (!st.empty()){
  auto v = st.top();st.pop();
  if (used[v]) continue;

  each(u, g[v]){
    if (used[u]) continue;
    // process
    st.push(u);
  }
  used[v] = 1;
}

//%snippet.end()%


//%snippet.set('bfs')%

queue<int> q;
vector<int> used(n);

q.push(0);
while (!st.empty()){
  auto v = q.front();q.pop();
  if (used[v]) continue;

  each(u, g[v]){
    // process
    q.push(u);
  }
  used[v] = 1;
}

//%snippet.end()%


//%snippet.set('01bfs')%

deque<int> dq;
vector<int> used(n);

dq.push_back(0);
while (!dq.empty()){
  auto v = dq.front();dq.pop_front();
  if (used[v]) continue;

  each(u, g[v]){
    // process
    q.push_back(u);
  }
  used[v] = 1;
}

//%snippet.end()%

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

