// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

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
#define mt(a, b, c) make_tuple(a, b, c)
#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
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
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

struct suffix_array{
  vector<int> a;
  vector<int> pos;  // pos[j]: j位のsumffixはどこから始まるか
  vector<int> rank;  // rank[i]: s[i:]は何位か
  // pos = rank^-1
  vector<int> lcp_array;  // lcp_arry[j]: s[j:]とs[j+1:]のlcp
  int n;

  suffix_array(){}
  suffix_array(vector<int>& a) : a(a), n(a.size()){}
  suffix_array(string& s){
    n = s.size();
    a.resize(n);
    rep(i, n) a[i] = s[i];
  }

  void build(){
    _build_order();
    _build_lcp_array();
  }

  void _build_order(){
    pos.resize(n);
    iota(all(pos), 0);
    rank = a;  // aでそのままスコア化

    for (int k=1; k<n; k*=2){
      // kでのrankが生成されている前提で2*kでのrankを生成する

      auto _comp = [&](int l, int r){
        auto left = mp(rank[l], (l+k<n ? rank[l+k] : -1));
        auto right = mp(rank[r], (r+k<n ? rank[r+k] : -1));
        return left < right;
      };
      sort(all(pos), _comp);

      vector<int> next_rank(n);
      next_rank[pos[0]] = 0;
      int r = 0;
      rep(i, 1, n){
        if (_comp(pos[i-1], pos[i])) r++;
        next_rank[pos[i]] = r;
      }
      rank = next_rank;
    }
  }

  void _build_lcp_array(){
    lcp_array.resize(n);
    // vector<int> pos;  // pos[j]: j位のsumffixはどこから始まるか
    // vector<int> rank;  // rank[i]: s[i:]は何位か
    // vector<int> lcp_array;  // lcp_arry[j]: s[j:]とs[j+1:]のlcp

    // rank[0], rank[0]+1の間のlcp, lcp_array[rank[0]]についてまずやる。
    int con = 1;
    rep(l, 0, n){
      if (rank[l]+1==n){
        lcp_array[rank[l]] = -1;
        con = 1;
        continue;
      }

      if (con>0) con--;
      int r = pos[rank[l]+1];
      while(l+con<n && r+con<n && a[l+con]==a[r+con]){
        con++;
      }
      lcp_array[rank[l]] = con;
    }
  }

  int lcp(int i, int j){ // longest cummon prefix 
    int res = 0;
    // TODO: implement
    return res;
  }
};

signed main() {
  string s = "adcdacbdcab";
  // string s = "aaaaa";
  // string s;cin>>s;

  dump(s);
  suffix_array sa(s);
  sa.build();
  dump(sa.pos);
  dump(sa.rank);
  dump(sa.lcp_array);

  rep(i, sz(sa.pos)) cout << sa.pos[i] << (i!=sz(sa.pos)-1 ? " " : "\n");
  return 0;
}
