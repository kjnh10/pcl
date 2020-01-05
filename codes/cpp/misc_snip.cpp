//%snippet.set('cout')%
cout << ${0:TARGET} << endl;

//%snippet.set('couts')%
rep(i, sz(${1:x})) cout << $1[i] << (i!=sz($1)-1 ? " " : "\n");

//%snippet.set('?')%
  (${1} ? ${2} : ${3})

//%snippet.set('inv')%
vector<int> ${1}(n);
rep(i, n) {
  cin>>$1[i];
}
dump($1);${0}

//%snippet.set('invv')%
vector<vector<int>> ${1}(h, vector<int>(w));
rep(i, h){
  rep(j,w){
    cin>>$1[i][j];
  }
}

//%snippet.set('invvs')%
vector<vector<int>> ${1}(h, vector<int>(w));
rep(i, h){
  string tmp;cin>>tmp;
  rep(j,w){
    if (tmp[j]=='#') $1[i][j]=1;
    else             $1[i][j]=0; 
  }
}

//%snippet.set('rep')%
rep(${0}){
}

//%snippet.set('rrep')%
rrep(${0}){
}

//%snippet.set('for')%
for(int i=0; i<n; i++){${0}
}

//%snippet.set('if')%
if (${0}) {
}

//%snippet.set('else')%
else{${0}
}

//%snippet.set('elif')%
else if(${0}){
}

//%snippet.set('while')%
while (${0}){
}

//%snippet.set('reprep')%
rep(${1}) rep(${2}){${0}
}

//%snippet.set('d')%
dump(${0});

//%snippet.set('af')%
assert(false);

//%snippet.set('sortkey')%
sort(all(${0}), [&](auto &left, auto &right){return left.second < right.second;});

//%snippet.set('perm')%
do{
  ${0};
} while (next_permutation(all(x)));

//%snippet.set('to_bin')%
#define N 61
string to_bin(int n, int d){
  // nをd桁の2進数で表示する。
  stringstream ss;
  ss << bitset<N>(n);
  return ss.str().substr(N-d, d);
}
// int d = (32 - __builtin_clz(n));  // 桁数
// int f = N - d; to_bin()で返ってきた文字列で最初に1が立っているindex

//%snippet.set('warsharll')%
// init
int d[N][N]={};  // 必要があればglobalに
rep(i, N)rep(j, N){
  d[i][j] = (i==j ? 0 : INF);
}

// input
${0};

// calc
rep(k, N){
  rep(i, N){
    rep(j, N){
      chmin(d[i][j], d[i][k]+d[k][j]);
    }
  }
}
dump_2d(d, N, N);


//%snippet.set('digitdp')%
rep(i, sz(S)){  //桁数
  rep(leq, 2){  //未満確定フラグ
    int lim = leq ? 9 : S[i]-'0';
    rep(d, lim+1){
      dp[leq || d<lim][i] += dp[leq][i-1];
    }
  }
}


//%snippet.set('rangesum')%
int rangesum(int l, int r){
  // a[]: accumulative sum
  l = max(0, l);
  // r = min(0, n-1);
  if (l > r) return 0;
  return a[r] - (l-1>=0 ? a[l-1] : 0);
}


//%snippet.set('asv')%
// acumulative sum vector {{{
template<typename T>
struct asvector {
  vector<T> cum; //accumulative sum
  asvector(vector<T> a): cum(a){  // {{{  // constructor
    rep(i, 1, sz(a))  cum[i]+=cum[i-1];
  } // }}}

  T rsum(int l, int r) {  // return sum of [l, r) of data.  {{{
    l = max(0LL, l);
    r = min(r, sz(cum));
    if (l<=r){
      return cum[r-1] - (l-1>=0 ? cum[l-1] : 0);
    }
    else{
      return 0;
    }
  } // }}}

  T& operator[](int i) { // {{{
    return cum[i]; 
  } // }}}

  friend ostream& operator<<(ostream &os, asvector<T>& as){//{{{
    os << as.cum; return os;
  } //}}}
};
//}}}


//%snippet.set('sandbox')%
using namespace std;
#include <bits/stdc++.h>
#include <iostream>

int main(){
  return 0;
}


//%snippet.set('remove_leading_zeros')%
str.erase(0, min(str.find_first_not_of('0'), str.size()-1));


operator//%snippet.set('pow2')%
int p[500001];  // power of 2 {{{
p[0] = 1;
rep(i, 1, 500002){
  p[i] = p[i-1]*2;
  p[i] %= MOD;
}
// }}}

//%snippet.set('pow')%
int pow_(int b, int x){ //{{{
  if (x==1) return b%M;
  if (x%2==0){
    int t = pow_(b, x/2);
    return (t*t)%M;
  }
  else{
    return pow_(b, x-1)*b%M;
  }
} //}}}


//%snippet.set('lambda')%
//%snippet.config({'alias':'f'})%
auto f = [&](){
};


//%snippet.set('dfs_lambda')%
auto dfs = [&](const auto& dfs, int x, int v) -> void {
  // 処理
  dfs(dfs, nx, nv);
};


//%snippet.set('dxdy')%
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};


//%snippet.set('ostream')%
//%snippet.config({'alias':'<<'})%
ostream& operator<<(ostream& os, const ${1:type}& ${2}){
  os << ${3};
  return os;
}

//%snippet.set('query')%
int query(){

  cerr << endl;
  return 0;
}

signed main(){
  int Q;cin>>Q;
  rep(_, Q){
    query();
  }
  return 0;
}


//%snippet.set('random_generator')%
uint64_t rng() {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<uint64_t>(0, -1)(mt);
}
