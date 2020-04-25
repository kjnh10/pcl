#include "../../../problem_template/codes/header.hpp"

//BEGIN CUT HERE
using value=int;
using mat=vector<vector<value>>;

mat mul(mat& A, mat& B){
  mat res(A.size(), vector<value>(B[0].size()));
  rep(i, A.size()){
    rep(j, B[0].size()){
      rep(k, B.size()){
        res[i][j] = (res[i][j]+A[i][k]*B[k][j])%MOD; // remove %MOD if not needed
      }
    }
  }
  return res;
}

mat pow(mat A, int n){
  mat B(A.size(), vector<value>(A.size()));
  rep(i, A.size()){
    B[i][i]=1;  // E
  }
  while (n>0) {
    if (n & 1) B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}
//END CUT HERE

int solve(){
  int n,m;cin>>n>>m;

  mat A(m, vi(m, 0)); // m==0だと落ちるので注意。
  A[0][0] = 1;
  A[0][m-1] = 1;
  rep(i, 1, m){
    A[i][i-1] = 1;
  }
  // dump(pow(A, n));

  cout << pow(A, n)[0][0] << endl;

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
