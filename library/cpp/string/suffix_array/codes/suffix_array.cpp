#include "../../../header.hpp"

//%snippet.set('suffix_array')%

template<typename T> struct SegmentTree { // {{{
  private:
    using F = function<T(T,T)>;
    int n;  // 元の配列のサイズ
    int N;  // n以上の最小の2冪
    vector<T> node;
    F merge;
    T identity;

  public:
    SegmentTree(){}
    SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
      n = a.size();
      N = 1; while(N < n) N *= 2;
      node.resize(2*N-1, identity);
      for(int i=0; i<n; i++) node[i+N-1] = a[i];
      for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
    }
    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

    T& operator[](int i) { return node[i+N-1]; }

    void update(int x, T val) {
      x += (N - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    void add(int x, T val) {
      x += (N - 1);
      node[x] += val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    // query for [l, r)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}
template<class MeetSemiLattice> struct SparseTable {/*{{{*/
  vector<vector<MeetSemiLattice> > dat;
  vector<int> height;
  
  SparseTable() { }
  SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
  void init(const vector<MeetSemiLattice> &vec) {
    int n = (int)vec.size(), h = 0;
    while ((1<<h) < n) ++h;
    dat.assign(h, vector<MeetSemiLattice>(1<<h));
    height.assign(n+1, 0);
    for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
    for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
    for (int i = 1; i < h; ++i)
      for (int j = 0; j < n; ++j)
        dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
  }
  
  MeetSemiLattice get(int a, int b) {
    if (a==b) return INF;
    return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
  }
};/*}}}*/
struct suffix_array{/*{{{*/
  vector<int> a;
  vector<int> pos;  // pos[j]: j位のsumffixはどこから始まるか
  vector<int> rank;  // rank[i]: s[i:]は何位か
  // pos = rank^-1
  vector<int> lcp_array;  // lcp_arry[j]: s[j:]とs[j+1:]のlcp
  SegmentTree<int> seg_lcp_array;  // lcp_arry[j]: s[j:]とs[j+1:]のlcp
  SparseTable<int> sparse_lcp_array;
  int n;

  // constructor{{{
  suffix_array(){}
  suffix_array(vector<int>& a) : a(a), n(a.size()){_build();}
  suffix_array(string& s){
    n = s.size();
    a.resize(n);
    rep(i, n) a[i] = s[i];
    _build();
  }/*}}}*/

  void _build(){/*{{{*/
    _build_order();
    _build_lcp_array();
  }/*}}}*/

  void _build_order(){/*{{{*/
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
  }/*}}}*/

  void _build_lcp_array(){/*{{{*/
    lcp_array.resize(n);
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

    auto mymin=[](auto a, auto b){return min(a,b);};
    seg_lcp_array = SegmentTree<int>(lcp_array, mymin, 1e18);
    sparse_lcp_array = SparseTable<int>(lcp_array);
  }/*}}}*/

  int lcp(int i, int j){ // longest cummon prefix length between s[i:] and s[j:]{{{
    // if (rank[i]<rank[j]) return seg_lcp_array.query(rank[i], rank[j]);
    // else                 return seg_lcp_array.query(rank[j], rank[i]);
    if (rank[i]<rank[j]) return sparse_lcp_array.get(rank[i], rank[j]);
    else                 return sparse_lcp_array.get(rank[j], rank[i]);
  }/*}}}*/
};/*}}}*/

// sample: abc141E
// int n;cin>>n;
// string s;cin>>s;
// suffix_array sa(s);
//
// int ans = 0;
// rep(i, n)rep(j, n){
//   chmax(ans, min(j-i, sa.lcp(i, j)));
// }
// cout << ans << endl;

//%snippet.end()%


void test_sa(){
  string s;cin>>s;
  suffix_array sa(s);
  
  rep(i, sz(sa.pos)) cout << sa.pos[i] << (i!=sz(sa.pos)-1 ? " " : "\n");
}

void test_lcp(){
  // abc141E
  int n;cin>>n;
  string s;cin>>s;
  suffix_array sa(s);

  int ans = 0;
  rep(i, n)rep(j, n){
    chmax(ans, min(j-i, sa.lcp(i, j)));
  }
  cout << ans << endl;
}

signed main() {
  // string s = "adcdacbdcab";
  // // string s = "aaaaa";
  // dump(s);
  // suffix_array sa(s);
  // sa.build();
  // dump(sa.pos);
  // dump(sa.rank);
  // dump(sa.lcp_array);
  // dump(sa.lcp(1, 7));
  test_lcp();

  return 0;
}
