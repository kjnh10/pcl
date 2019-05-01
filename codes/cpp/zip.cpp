using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// define basic macro {{{
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
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;

// dump macro
#ifdef PCM
  #include "dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

//%snippet.set('zip')%
vector<int> unzipper;
map<int, int> zipper;
vector<int> zipped;
// a = [3, 10, 5, 5, 2]
// unzipper = [2, 3, 5, 10]
// zipper = {2:0, 3:2, 5:3, 10:4}
// zipped = [2, 4, 3, 3, 0]

int zip(vector<int> a){
  int n = sz(a);
  unzipper = vector<int>(n);
  zipped = vector<int>(n);
  rep(i, n) {
    cin>>a[i];
    unzipper[i]=a[i];
  }
  uni(unzipper);

  rep(i, sz(unzipper)){
    zipper[unzipper[i]] = i;
  }

  rep(i, n){
    zipped[i] = zipper[a[i]];
  }
  return 0;
}
