#include "../../../problem_template/codes/header.hpp"

//%snippet.set('lcs')%
#define MAX_N 5000
#define MAX_M 5000
int lcs(string s, string t){
  int n = sz(s);
  int m = sz(t);
  int dp[MAX_N+1][MAX_M+1]={};  // 1-index

  rep(i, n){
    rep(j, m){
      if (s[i]==t[j])
        chmax(dp[i+1][j+1], dp[i][j]+1);
      else{
        chmax(dp[i+1][j+1], dp[i][j+1]);
        chmax(dp[i+1][j+1], dp[i+1][j]);
      }
    }
  }
  return dp[n][m];
}
// %snippet.end()%

int solve(){/*{{{*/
  string s,t;cin>>s>>t;
  cout << lcs(s, t)+1 << endl;

  return 0;
}/*}}}*/

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
