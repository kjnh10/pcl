#include "../header.hpp"

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
    rep(i, n) r_rep(j, MW){
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
    rep(i,n) r_rep(j, V){ // 01 napsack
      chmin(dp[min(j+v[i], V-1)], dp[j]+w[i]);  // jから配る
    }
    r_rep(j, V){
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
  // rep(i,n) r_rep(j,h+1){ // 01 napsack
    chmin(dp[min(j+v[i], h)], dp[j]+w[i]);  // jから配る
  }
  cout<<dp[h]<<endl;
  //%snippet.end()%

  return 0;
}

