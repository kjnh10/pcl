#pragma once
#include "../header.hpp"

//%snippet.set('union_find')%
//%snippet.fold()%

struct union_find {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int gcount;         // count of groups

    union_find() {}
    union_find(int _n) : par(_n, -1), gcount(_n) {}
    bool merge(int x, int y) { // -> return new_root
        x = root(x);
        y = root(y);
        if (x != y) {
            if (par[y] < par[x]) swap(x, y);
            // y -> x : 大きい方にmergeする。
            par[x] += par[y];
            par[y] = x;
            gcount--;
        }
        return (x != y ? x : -1);
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

    map<int, vector<int>> group(){
        map<int, vector<int>> res;
        rep(i, sz(this->par)) { res[this->root(i)].pb(i); }
        return res;
    }

    #if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, union_find& uf) {
        auto group = uf.group();
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
    #endif  // }}}
};

//%snippet.end()%
