// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

#include <bits/stdc++.h>
using namespace std;

//%snippet.set('SegmentTree')%
//%snippet.config({'alias':'rmq'})%

template<typename T, typename F>
struct SegmentTree { // {{{
  private:
    int n; 
    int N;  // 
    vector<int> node;
    F merge;
    T identity;

  public:
    SegmentTree(vector<int> a, F f, T id):merge(f), identity(id) {
      n = a.size();
      N = 1; while(N < n) N *= 2;
      node.resize(2*N-1, identity);
      for(int i=0; i<n; i++) node[i+N-1] = a[i];
      for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
    }
    SegmentTree(int n, F f, T id) : SegmentTree(vector<int>(n, id), f, id) {}

    T& operator[](int i) { return node[i+N-1]; }

    void update(int x, int val) {
      x += (N - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    // query for [l, r)
    int query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      int vl = query(a, b, 2*k+1, l, (l+r)/2);
      int vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T, F>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}
// Sample:
  // -----------------------------------------------
  // auto mymin=[&](int a,int b){return min(a,b);};
  // SegmentTree<int, decltype(mymin)> seg(a, mymin, INF);

  // auto mymax=[&](int a,int b){return max(a,b);};
  // SegmentTree<int, decltype(mymax)> seg(a, mymax, -INF);

  // auto add=[&](int a,int b){return a+b;};
  // SegmentTree<int, decltype(add)> seg(a, add, 0);
  // -----------------------------------------------

//%snippet.end()%

int main() {
  int N = 6;
  vector<int> a = {1, 4, -2, 3, 6, 7};
  auto f=[&](int a,int b){return max(a,b);};
  SegmentTree<int, decltype(f)> seg(a, f, -1e9);

  assert(seg.query(0, 8)==7);
  cout << seg.query(0, 8) << endl;
  cout << seg.query(0, 10) << endl;
  cout << seg.query(-3, 10) << endl;
  cout << seg[0] << endl;
  cout << seg[1] << endl;
  cout << seg[2] << endl;
  cout << seg << endl;
  seg.update(2, 10);
  cout << seg.query(0, 8) << endl;

}
