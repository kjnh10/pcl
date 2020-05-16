#pragma once
#include "../header.hpp"

//%snippet.set('UnionFind')%
//%snippet.fold()%

struct UnionFind {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int count;         // count of groups

    UnionFind() {}
    UnionFind(int size) : par(size, -1), count(size) {}
    bool merge(int x, int y) { 
        x = root(x);
        y = root(y);
        if (x != y) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
            count--;
        }
        return x != y;
    } 
    int root(int x) {
        if (is_root(x)){
            return x;
        }
        else{
            return par[x] = root(par[x]);  // 経路圧縮
            // return root(par[x]);         // 経路圧縮なし
        }
    }
    bool is_root(int x) { return par[x] < 0; }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }

#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, UnionFind& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i); }
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
#endif  // }}}
};

//%snippet.end()%
