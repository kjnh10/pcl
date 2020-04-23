//%snippet.set('template')%
// template version 1.11
using namespace std;
#include <bits/stdc++.h>

// varibable settings {{{
#define int long long
#define infile "../test/sample-1.in"
// }}}
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
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

#include "../mint.hpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b){ //{{{
  if (b>=mod) {
    return -1;
  }

  // find x s.t a^x = b in (mod)
  mint x;
  int sq = sqrt(mod);
  // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

  map<int, int> minr; // minr[v]: min(r s.t a^r=v)
  mint ar = 1;
  rep(r, 0, sq){
    if (minr.find(ar.x)==minr.end()) minr[ar.x] = r;
    ar *= a;
  }

  mint A = mint(a).pow(-sq);
  rep(p, 0, sq+1){
    int Ab = (A.pow(p)*b).x;
    if (minr.find(Ab)!=minr.end()){
      int r = minr[Ab];
      return p*sq + r;
    }
  }

  return -1;
} //}}}
// %snippet.end()%

signed main(){
  int a,b,p;cin>>a>>b>>p;
  mod = p;
  cout << bsgs(a, b) << endl;
  return 0;
}
