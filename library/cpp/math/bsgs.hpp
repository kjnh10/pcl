#include "../header.hpp"
#include "modint.hpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('modint')%

int bsgs(int a, int b) {  //{{{
    if (b >= mod) return -1;

    // find x s.t a^x = b in (mod)
    int h = sqrt(mod);
    // x = p*h + r  (0<=r<h and 0<=p<=h)

    unordered_map<int, int> minr;  // minr[v]: min(r s.t a^r=v)
    mint ar = 1;  // a^r
    rep(r, 0, h) {
        if (minr.find(ar.x) == minr.end()) minr[ar.x] = r;
        ar *= a;
    }

    mint A = mint(a).pow(-h);
    rep(p, 0, h + 1) {
        int Ab = (A.pow(p) * b).x;
        if (minr.find(Ab) != minr.end()) {
            int r = minr[Ab];
            return p * h + r;
        }
    }

    return -1;
}  //}}}

// %snippet.end()%


// %snippet.set('generalized_baybe_step_giant_step')%
// %snippet.config({'alias':'gbsgs'})%
// %snippet.include('modint')%

int gbsgs(int a, int b) {  //{{{
    // find x s.t a^x = b in (mod: primeである必要はない)

    if (b >= mod) return -1;
    if (1 % mod == b) return 0;

    int h = (int)sqrt(mod) + 1;  // h s.t x = p*h-r (0<=r<h and 0<=p<=h)

    unordered_map<int, vector<int>> rs;  // rs[v]: vector of r s.t b*a^r==v
    mint bar = b;  // b*a^r
    rep(r, 0, h) {
        rs[bar.x].pb(r);
        bar *= a;
    }
    bool looped = false;
    each(el, rs) if (sz(el.second) > 1) looped = true;

    mint ah = mint(a).pow(h);
    rep(p, 1, h + 1) {
        int aph = ah.pow(p).x;
        if (rs.find(aph) != rs.end()) {
            reverse(all(rs[aph]));
            each(r, rs[aph]) {
                if (mint(a).pow(p * h - r) == b){
                    // a^(p*h-r) == b in (mod) => a^(ph) == b*a^rだが逆は成り立たないのでこの確認が必要
                    return p * h - r;
                }
            }
        }
        // sz(rs[aph]) > 0の場合はbreakするので計算量も大丈夫
        if (looped) return -1;
    }

    return -1;
}  //}}}

// %snippet.end()%
