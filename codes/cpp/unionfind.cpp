//%snippet.set('unionfind')%
struct UnionFind {
  vector<int> data;  // size defined only for root node
  UnionFind(int size) : data(size, -1) { }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
  int size(int x) {
    return -data[root(x)];
  }
};
