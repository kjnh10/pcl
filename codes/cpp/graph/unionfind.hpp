#pragma once
#include "template.hpp"

//%snippet.set('UnionFind')%
struct UnionFind {
  vector<int> data;  // size defined only for root node
  int count;  // count of groups

  UnionFind(){}
  UnionFind(int size) : data(size, -1), count(size){}
  bool merge(int x, int y) {/*{{{*/
    x=root(x); y=root(y);
    if (x!=y) {
      if (data[y]<data[x]) swap(x, y);
      data[x]+=data[y]; data[y]=x;
      count--;
    }
    return x != y;
  }/*}}}*/
  int root(int x) { return (data[x]<0 ? x : data[x]=root(data[x])); }
  bool same(int x,int y){ return root(x)==root(y); }
  int size(int x) { return -data[root(x)]; }

  friend auto& operator<<(auto &os, UnionFind& uf){ //{{{
    map<int, vector<int>> group;
    rep(i, sz(uf.data)){ group[uf.root(i)].pb(i); }
    os << endl; each(g, group){ os << g << endl; }
    return os;
  } //}}}
};
//%snippet.end()%
