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

//%snippet.set('bit1')%
template<typename T=int>
struct BIT {
  public:
    vector<T> data;  // 1-indexed

    // constructor
    BIT(vector<T> v){  // v: 0-index vector
      data = vector<T>(sz(v)+1);
      rep(i, 1, sz(v)) add(i+1, v[i]);
    }
    BIT(int n){
      data = vector<T>(n+1);
    }
    //------------

    T sum(int idx){  // return sum of [1, r]
      T res = 0;
      for (int i = idx; i > 0; i -= i&-i) res += data[i];
      return res;
    }

    void add(int idx, T x){
      for (int i = idx; i <= (int)data.size(); i += i&-i){
        data[i] += x;
      }
    }

  private:
};

ostream& operator<<(ostream& stream, BIT<int> bit){
  int n = sz(bit.data);
  stream << "bit[";
  rep(i, 1, n){
    stream << bit.sum(i) << (i==n-1 ? "" : ", ");
  }
  stream << "]";
  return stream;
}
//%snippet.end()%

signed main(){
  BIT<int> bit(5);
  bit.add(1, 1);
  bit.add(2, 2);
  bit.add(3, 4);
  bit.add(4, 8);
  bit.add(5, 16);
  cout << bit << endl;

  return 0;
}
