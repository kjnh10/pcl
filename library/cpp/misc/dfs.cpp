

//%snippet.set('dfs')%

stack<int> st;
vector<int> used(n);

st.push(0);
while (!st.empty()) {
    auto u = st.top(); st.pop();
    if (used[u]) continue; used[u] = 1;

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
    auto u = q.front(); q.pop();
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
    auto u = dq.front(); dq.pop_front();
    if (used[u]) continue;
    used[u] = 1;

    each(v, g[u]) {
        // process
        q.push_back(v);
    }
}

//%snippet.end()%
