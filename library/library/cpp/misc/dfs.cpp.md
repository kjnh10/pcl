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


# :warning: library/cpp/misc/dfs.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b4c52cffc478acefbc1ee6a9d0578055">library/cpp/misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/misc/dfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 09:08:25+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp


//%snippet.set('dfs')%

stack<int> st;
vector<int> used(n);

st.push(0);
while (!st.empty()) {
    auto u = st.top();
    st.pop();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        if (used[v]) continue;
        // if (d[u]+cost>=d[v]) continue;
        // d[v] = d[u]+cost;
        st.push(v);
    }
}

//%snippet.end()%

//%snippet.set('bfs')%

queue<int> q;
vector<int> used(n);

q.push(0);
while (!q.empty()) {
    auto u = q.front();
    q.pop();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        // process
        q.push(v);
    }
}

//%snippet.end()%

//%snippet.set('01bfs')%

deque<int> dq;
vector<int> used(n);

dq.push_back(0);
while (!dq.empty()) {
    auto u = dq.front();
    dq.pop_front();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        // process
        q.push_back(v);
    }
}

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/misc/dfs.cpp"


//%snippet.set('dfs')%

stack<int> st;
vector<int> used(n);

st.push(0);
while (!st.empty()) {
    auto u = st.top();
    st.pop();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        if (used[v]) continue;
        // if (d[u]+cost>=d[v]) continue;
        // d[v] = d[u]+cost;
        st.push(v);
    }
}

//%snippet.end()%

//%snippet.set('bfs')%

queue<int> q;
vector<int> used(n);

q.push(0);
while (!q.empty()) {
    auto u = q.front();
    q.pop();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        // process
        q.push(v);
    }
}

//%snippet.end()%

//%snippet.set('01bfs')%

deque<int> dq;
vector<int> used(n);

dq.push_back(0);
while (!dq.empty()) {
    auto u = dq.front();
    dq.pop_front();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        // process
        q.push_back(v);
    }
}

//%snippet.end()%

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

