using namespace std;
#include <bits/stdc++.h>
#include <iostream>

// varibable settings {{{
#define infile "../test/sample-1.in"
#define int long long
const int INF=1e18;
const int MOD=1e9+7;
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
// }}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
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
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
//}}}

//%snippet.set('bit')%

template<typename T=int> struct bit {//{{{
  int n;
  vector<T> dat;
  vector<T> raw;

  bit(int _n=0){ //{{{
    n = _n;
    dat = vector<T>(n);
    raw = vector<T>(n);
  } //}}}

  bit(vector<T> a){ // {{{
    n = (int)a.size();
    dat = vector<T>(n);
    raw = vector<T>(n);
    for(int i = 0; i<n; i++){
      add(i, a[i]);
      raw[i] = a[i];
    }
  } //}}}

  T _rsum(int i){ //{{{ [0, i]
    T s = 0;
    while(i >= 0){
      s += dat[i];
      i = (i & (i+1)) - 1;
    }
    return s;
  } //}}}

  T sum(int l, int r){ //{{{  [l, r)
    if(l > r-1) return 0;
    return _rsum(r-1) - _rsum(l-1);
  } //}}}

  void add(int i, T x){ //{{{
    raw[i] += x;
    while(i < n){
      dat[i] += x;
      i |= i+1;
    }
  } //}}}

  int lower_bound(T x){ // a[0]+...+a[ret] >= x{{{
    int ret = -1;
    int k = 1;
    while(2*k <= n) k <<= 1;
    for( ;k>0; k>>=1){
      if(ret+k < n && dat[ret+k] < x){
        x -= dat[ret+k];
        ret += k;
      }
    }
    return ret + 1;
  } //}}}

  friend ostream& operator<<(ostream &os, bit<T>& b){ //{{{
    os << endl << "  raw:" << b.raw << endl;
    vector<T> acum;
    rep(i, b.n){
      acum.pb(b.sum(i));
    }
    os << "  acm:" << acum << endl;
    return os;
  } //}}}
}; //}}}

//%snippet.end()%

signed main(){
  // vi x = {1, 2, 3, 4, 5};
  // bit<int> b(x);
  bit<int> b(5);
  b.add(0, 1);
  b.add(1, 2);
  b.add(2, 4);
  b.add(3, 8);
  b.add(4, 16);
  rep(i, 5){
    cout << b.raw[i] << (i!=5-1?" ":"\n");
  }
  // cout << b << endl;  // dump.hppをimportしないと使えない。
  cout << b._rsum(0) << endl;  //1
  cout << b._rsum(1) << endl;  //3
  cout << b._rsum(2) << endl;  //7
  cout << b._rsum(3) << endl;  //15
  cout << b._rsum(4) << endl;  //31
  cout << b.sum(2, 4) << endl;  // 12

  return 0;
}
