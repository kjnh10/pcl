#pragma once
#include "../header.hpp"

//%snippet.set('union_find_with_potential')%
//%snippet.fold()%

template<class Pot = ll>  // Pot: Abel
struct union_find {
    vector<int> par;   // par[x]: parent of x. if root, -size.
    int gcount;         // count of groups
    vector<Pot>  diff;
    union_find() {}
    union_find(int _n, Pot SUM_UNITY = 0) : par(_n, -1), gcount(_n), diff(_n, SUM_UNITY) {}
    bool merge(int x, int y, Pot d) { /*{{{*/
        // d:= wight(y) - weight(x)
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            if (par[ry] >= par[rx]) {
                par[rx] += par[ry];
                par[ry] = rx;
                diff[ry] = diff[x] + d + (-diff[y]);
            }
            else{
                par[ry] += par[rx];
                par[rx] = ry;
                diff[rx] = (-diff[x]) + (-d) + diff[y];
            }
            gcount--;
        }
        else{
            if (weight(y) + (-weight(x)) != d){
                throw runtime_error("contradiction exist");
            }
        }
        return rx != ry;
    } /*}}}*/
    int root(int x) {/*{{{*/
        if (is_root(x)){
            return x;
        }
        else{
            int r = root(par[x]);
            diff[x] += diff[par[x]];
            par[x] = r;
            return par[x];
        }
    }/*}}}*/
    Pot weight(int x){/*{{{*/
        root(x); // 経路圧縮
        return diff[x];
    }/*}}}*/
    Pot diff(int x, int y){/*{{{*/
        if (!same(x, y)){
            string s = to_string(x) + " and " + to_string(y) + " are not in the same group.";
            throw invalid_argument(s);
        }
        else{
            return weight(y) + (-weight(x));
        }
    }/*}}}*/
    bool is_root(int x) { return par[x] < 0; }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }
#if defined(PCM) || defined(LOCAL)  // {{{
    friend ostream& operator<<(ostream& os, union_find& uf) {
        map<int, vector<int>> group;
        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i); }
        os << endl;
        each(g, group) { os << g << endl; }
        return os;
    }
#endif  // }}}
};

//%snippet.end()%
