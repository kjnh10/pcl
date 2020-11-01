#include "../../header.hpp"
#include "../modint.hpp"

// %snippet.set('baybe_step_giant_step')%
// %snippet.config({'alias':'bsgs'})%
// %snippet.include('modint')%

int bsgs(int a, int b) {  //{{{
    if (b >= mod) {
        return -1;
    }

    // find x s.t a^x = b in (mod)
    mint x;
    int sq = sqrt(mod);
    // x = p*sq + r  (0<=r<sq and 0<=p<=sq)

    map<int, int> minr;  // minr[v]: min(r s.t a^r=v)
    mint ar = 1;
    rep(r, 0, sq) {
        if (minr.find(ar.x) == minr.end()) minr[ar.x] = r;
        ar *= a;
    }

    mint A = mint(a).pow(-sq);
    rep(p, 0, sq + 1) {
        int Ab = (A.pow(p) * b).x;
        if (minr.find(Ab) != minr.end()) {
            int r = minr[Ab];
            return p * sq + r;
        }
    }

    return -1;
}  //}}}
// %snippet.end()%

signed main() {
    int a, b, p;
    cin >> a >> b >> p;
    mod = p;
    cout << bsgs(a, b) << endl;
    return 0;
}
