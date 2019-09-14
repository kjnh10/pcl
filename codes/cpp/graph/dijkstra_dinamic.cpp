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
        if (M[nx][ny]=='.') q.push(mp(cost+1, mp(nx, ny)));
      }
    }
  }
}
