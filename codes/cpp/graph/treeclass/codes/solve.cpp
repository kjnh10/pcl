// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
  #define cerrendl 42
#endif
//}}}

struct tree{
  int n;
  vector<pair<int, int>> par;  // par[i]: dfs木における親
  vector<int> dfstrv;
  vector<int> ord;  // ord[i]: iのdfs木における訪問順
  vector<int> pos;  // pos[i]: dfs終了時のカウンター
  vector<int> depth;  // depth[i]: dfs木でのiの深さ
  // vの部分木は[ord[v], pos[v])

  vector<vector<pair<int, int>>> g; // 隣接リスト
  vector<vector<int>> children;
  int counter = 0;

  tree(int n): n(n), par(n), ord(n), pos(n), g(n), children(n) {};

  void add_edge(int u, int v, int cost){
    g[u].emplace_back(v, cost);
    g[v].emplace_back(u, cost);
  }

  void build(int root){
    counter = 0;
    par[0] = mp(-1, INF);
    dfs_tree(root, -1);
  }

  void dfs_tree(int u, int pre){
    dfstrv.pb(u);
    ord[u] = counter;

    counter++;
    each(el, g[u]){
      int v = el.first;
      int cost = el.second;
      if (v==pre) continue;

      children[u].pb(v);
      par[v] = mp(counter+1, cost);
      dfs_tree(v, u);
    }
    pos[u] = counter;
  }
};


signed main() {
  tree tr(8);
  tr.add_edge(0, 1, 1);
  tr.add_edge(0, 2, 1);
  tr.add_edge(1, 3, 1);
  tr.add_edge(1, 4, 1);
  tr.add_edge(4, 6, 1);
  tr.add_edge(4, 7, 1);
  tr.add_edge(2, 5, 1);

  tr.build(0);
  dump(tr.par);
  dump(tr.dfstrv);
  dump(tr.ord);
  dump(tr.pos);
  dump(tr.children);
}
