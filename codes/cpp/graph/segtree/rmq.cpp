// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

#include <bits/stdc++.h>
using namespace std;

int N, Q;
int const INF = INT_MAX;

//%snippet.set('SegmentTreeRMQ')%
//%snippet.config({'alias':'rmq'})%
struct SegmentTree {
  private:
    int n;
    vector<int> node;

  public:
    SegmentTree(vector<int> v) {
      int sz = v.size();
      n = 1; while(n < sz) n *= 2;
      node.resize(2*n-1, INF);
      for(int i=0; i<sz; i++) node[i+n-1] = v[i];
      for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
      x += (n - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1], node[2*x+2]);
      }
    }

    // get min of [l, r)
    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = n;
      if(r <= a || b <= l) return INF;
      if(a <= l && r <= b) return node[k];

      int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
      int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
      return min(vl, vr);
    }
};
//%snippet.end%

int main() {
  cin >> N >> Q;
  SegmentTree seg( vector<int>(N, INF) );
  for(int i=0; i<Q; i++) {
    int c, x, y; cin >> c >> x >> y;
    if(c == 0) seg.update(x, y);
    else cout << seg.getmin(x, y+1) << endl;
  }    
}
