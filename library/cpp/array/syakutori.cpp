#include "../header.hpp"

vector<int> x;
int k;
int n;

signed main(){
//%snippet.set('syakutori')%
//%snippet.config({'abbr':'syakutori-hou-[l,r)', 'indent':True})%
    int sum = 0;

    auto isok = [&](int next_r) {  // check [l, next_r) is ok?
        if (sum + x[next_r - 1] <= k)
            return true;
        else
            return false;
    };

    int res = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        // [l, r)を限界まで広げる。
        while (r < n && isok(r + 1)) {
            sum += x[r];
            ++r;
        }
        chmax(res, (r - l));

        // leftをincrementする準備
        if (r == l)
            ++r;  // 空区間から空区間への変動なので何もしない。
        else
            sum -= x[l];
    }
//%snippet.end()%
}
