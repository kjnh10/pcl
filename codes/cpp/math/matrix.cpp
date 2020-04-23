// template version 1.6
// {{{ define basic macro
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// varibable settings
#define int long long
#define INF 1000000000000000000LL
// #define INF 2147483647
#define MOD 1000000007LL
// #define MOD 998244353LL
#define infile "../test/sample-1.in"

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
#define ten(n) ((int)1e##n)
template<class T, size_t N> size_t sza(const T (&array)[N]) { return N; }
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }
template<class T=int> T in() {T x; cin>>x; return (x);}
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

// dump macro
#ifdef PCM
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define fi first
#define se second

// }}}

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
