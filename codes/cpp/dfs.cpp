

//%snippet.set('dfs')%

stack<int> st;
vector<int> used(n);

st.push(0);
used[0] = 1;
while (!st.empty()){
  auto v = st.top();st.pop();

  if (!used[v]) continue;
  each(u, used[v]){
    used[u] = 1;
    // process
    q.push(u);
  }
}

//%snippet.end()%


//%snippet.set('bfs')%

queue<int> q;
vector<int> used(n);

st.push(0);
used[0] = 1;
while (!st.empty()){
  auto v = q.front();q.pop();

  if (!used[v]) continue;
  each(u, used[v]){
    used[u] = 1;
    // process
    q.push(u);
  }
}

//%snippet.end()%


//%snippet.set('01bfs')%

deque<int> dq;
vector<int> used(n);

st.push(0);
used[0] = 1;
while (!st.empty()){
  auto v = dq.front();dq.pop_front();

  if (!used[v]) continue;
  each(u, used[v]){
    used[u] = 1;
    // process
    q.push_back(u);
  }
}

//%snippet.end()%
