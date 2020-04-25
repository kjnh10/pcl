#include "../../../../problem_template/codes/header.hpp"

int solve(){
  int a,b,p;cin>>a>>b>>p;
  int v = 1;
  int res = INF;
  rep(x, 0, p){
    // dump(x, v);
    if (v==b){
      cout << x << endl;
      return 0;
    }
    v *= a;
    v %= p;
  }
  cout << -1 << endl;
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
