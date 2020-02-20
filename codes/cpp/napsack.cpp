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
#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

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

int nampsack01all(int n, const vector<int>& v, const vector<int>& w){
  // abc032_d
  if (n<=30){
    dump("case 1");/*{{{*/

    int n1 = n/2;

    auto f = [&](int l, int r){
      vector<pii> res;
      int n = r-l;
      rep(mask, 1<<n){
        int sv = 0;
        int sw = 0;
        rep(i, n){
          if (mask&(1<<i)){
            sv += v[l+i]; sw += w[l+i];
          }
        }
        if (sw<=W) res.pb(mp(sw, sv));
      }
      return res;
    };

    auto r1 = f(0, n1);
    auto r2 = f(n1, n);
    sort(all(r1));
    sort(all(r2));
    int curmax = -1;
    each(el, r2){
      chmax(el.second, curmax);
      curmax = el.second;
    }

    int ans = -INF;
    each(el, r1){
      int res = 0;
      int sw = el.first;
      int sv = el.second;
      res += sv;

      int load = W - sw;
      auto i = ub(all(r2), mp(load, INF)) - r2.begin();
      if (i-1>=0) chmax(ans, res+r2[i-1].second);
    }
    return ans;/*}}}*/
  }
  else if(*max_element(all(w))<=1000){
    dump("case 2");/*{{{*/
    const int MW = 200002;
    vector<int> dp(MW, -INF);
    dp[0] = 0;
    rep(i, n) rrep(j, MW){
      chmax(dp[min(j+w[i], MW-1)], dp[j]+v[i]);
    }
    int ans = -INF;
    rep(wi, 0, W+1){
      chmax(ans, dp[wi]);
    }
    return ans;/*}}}*/
  }
  else if(*max_element(all(v))<=1000){
    dump("case 3");/*{{{*/
    const int V = 200002;
    vector<int> dp(V, INF);
    dp[0]=0;
    rep(i,n) rrep(j, V){ // 01 napsack
      chmin(dp[min(j+v[i], V-1)], dp[j]+w[i]);  // jから配る
    }
    rrep(j, V){
      if (dp[j]<=W){
        return j;
        return 0;
      }
    }/*}}}*/
  }
}

signed main(){

  //%snippet.set('napsack')%
  int n,h;
  cin>>h>>n;
  vector<int> v(n),w(n);
  rep(i,n) cin>>v[i]>>w[i];

  vector<int> dp(h+1, INF);
  dp[0]=0;
  rep(i,n) rep(j,h+1){ // 個数制限なし
  // rep(i,n) rrep(j,h+1){ // 01 napsack
    chmin(dp[min(j+v[i], h)], dp[j]+w[i]);  // jから配る
  }
  cout<<dp[h]<<endl;
  //%snippet.end()%

  return 0;
}

