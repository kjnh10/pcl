#include "../header.hpp"

//%snippet.set('lis')%

template<class T>
int lis(const vector<T>& x, bool strict=true) { /*{{{*/
    int n = sz(x);
    vector<T> dp(n+1, numeric_limits<T>().max());
    vector<pair<int, T>> update_info(n);
    dp[0] = numeric_limits<T>().min();
    int res = 0;
    rep(i, n) {
        int j;
        if (strict) j = lb(all(dp), x[i]) - dp.begin();
        else        j = ub(all(dp), x[i]) - dp.begin();
        chmax(res, j);
        update_info[i] = make_pair(j, dp[j]);
        dp[j] = x[i];
    }
    dump(dp);

    // 復元
    int now_len = res;
    vector<ll> lis;
    r_rep(i, n){
        auto [j, pre] = update_info[i];
        if (j==now_len) {
            now_len--;
            lis.push_back(x[i]);
        }
        dp[j] = pre;
    }
    assert(now_len==0);
    reverse(all(lis));
    dump(lis);

    return res;
} /*}}}*/


//%snippet.end()%

// lisにはBITを使ったmethodもある。
// signed main() {
//     vi x({1, 5, 4, 2, 3, 3, 7});
//     auto res = lis(x);
//     auto res_not_strict = lis(x, false);
//     dump(res);
//     dump(res_not_strict);
//     return 0;
// }
