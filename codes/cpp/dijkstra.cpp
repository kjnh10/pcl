// template version 1.8

// varibable settings {{{
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define int long long
const int INF=1e18;
const int MOD=1e9+7;
#define infile "../test/sample-1.in"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define fi first
#define se second

// }}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;

// dump macro
#ifdef PCM
  #include "dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

//%snippet.set('dijkstra')%

using COST = int;  // update
using POS = tuple<int, int>;  // TODO: update
using EDGE = pair<POS, COST>;
struct GRAPH{
  map<POS, vector<EDGE>> all_edges;
  void add_edge(POS from, POS to, COST cost){
    all_edges[from].emplace_back(mp(to, cost));
  }

  auto operator[](POS pos){
    return all_edges[pos];
  }
};

map<POS, COST> dijkstra(GRAPH& G){
  map<POS, COST> d;  // 最短距離
  // TODO: vectorの場合はd[*]=INFにしておく。

  PQ<pair<COST, POS>> q;
  q.push(mp(0LL, mp(0,0))); // putting start node TODO: update
  while (!q.empty()){
    auto cp = q.top(); q.pop();
    auto cost = cp.first;
    auto pos = cp.second;

    if (d.find(pos)==d.end() || cost < d[pos]) {
      d[pos] = cost;
      for (const auto &el:G[pos]){
        auto ncost = cost + el.second;
        auto npos = el.first;
        q.push(mp(ncost, npos));
      }
    }
  }
  return d;
}

// int sample(){
//   // init and build G
//   GRAPH G;
//
//   int n;cin>>n;
//   rep(i, n){
//     POS from, to;
//     COST cost;
//     cin>>from>>to>>cost;
//     pos--;from--;
//     G.add_edge(from, to, cost);
//   }
//
//   // calc min distance by G
//   auto d = dijkstra(G);
//   cout << d[n-1] << endl;
//   return 0;
// }

//%snippet.end()%

int solve(){
  int N,M,K;cin>>N>>M>>K;

  // build G
  GRAPH G;
  rep(i, M){
    int a,b,c;
    cin>>a>>b>>c;a--;b--;
    rep(k, K+1){
      G.add_edge(mp(a, k), mp(b, k), c);
      G.add_edge(mp(b, k), mp(a, k), c);
    }
  }
  rep(i, N){
    int x,y;cin>>x>>y;
    if (x==0) continue;
    rep(j, K) G.add_edge(mp(i, j), mp(i, min(j+x, K)), y);
  }

  // call dijkstra with G
  auto d = dijkstra(G);
  if (d.find(mp(N-1, K))!=d.end()){
    cout << d[mp(N-1, K)] << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
