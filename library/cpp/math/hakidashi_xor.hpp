#pragma once
#include "../header.hpp"

//%snippet.set('hakidasi_xor')%
const int D = 64;
using B = bitset<D>;
void hakidasi_xor(vector<B>& a){
    int r = 0;
    int n = sz(a);
    rep(d, 0, D){
        int p = -1;
        rep(i, r, n) if(a[i][d]) p = i;
        if (p == -1) continue;

        swap(a[r], a[p]);
        rep(i, n) if(a[i][d] && i!=r) a[i] ^= a[r];
        r++;
    }
}
//%snippet.end()%

// verified by https://atcoder.jp/contests/agc045/tasks/agc045_a
