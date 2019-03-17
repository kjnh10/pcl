// 動的
#define MAX_H 50
#define MAX_W 50
int M[MAX_H][MAX_W];
int d[MAX_H][MAX_W];
int solve(){
  int h,w;cin>>h>>w;
  int bcnt = 0;
  rep(i, h) rep(j, w){
    char c;cin>>c;
    M[i][j] = c;
    if (c=='#') bcnt++;
  }

  auto s = mp(0,0);  // TODO startの設定

  rep(i, h) rep(j, w){ d[i][j]=INF; }
  typedef pair<int, pii> CP; // (cost, pos)
  PQ<CP> q;
  q.push(CP(0LL, pii(s.first, s.second)));
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
  dump_2d(d, h, w);

  return 0;
}
