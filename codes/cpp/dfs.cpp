

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
