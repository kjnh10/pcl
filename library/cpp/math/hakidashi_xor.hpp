#pragma once
#include "../header.hpp"

//%snippet.set('hakidasi_xor')%
vector<ll> hakidasi_xor(vector<ll>& a){
    int r = 0;
    int n = sz(a);
    r_rep(d, 0, 64){
        int p = -1;
        rep(i, r, n) {
            if (a[i]>>d&1) {
                p = i;
            }
        }
        if (p == -1) continue;

        swap(a[r], a[p]);
        rep(i, n){
            if (a[i]>>d&1 && i!=r) a[i] ^= a[r];
        }
        r++;
    }
    vector<ll> res;
    rep(i, r) res.pb(a[i]);
    return res;
}
//%snippet.end()%

// verified by https://atcoder.jp/contests/agc045/tasks/agc045_a
