#include "./template.hpp"

//%snippet.set('lis')%

int lis(vector<int>& x){/*{{{*/
    int n = sz(x);
    vector<int> dp(n, INF);
    int res = 0;
    rep(i, n){
        int j = lb(all(dp), x[i]) - dp.begin();
        chmax(res, j+1);
        dp[j] = x[i];
    }
    // dump(dp);
    return res;
}/*}}}*/

//%snippet.end()%

signed main(){
    vi x({1, 5, 4, 2, 3, 7});
    auto res = lis(x);
    dump(res);
    return 0;
}
