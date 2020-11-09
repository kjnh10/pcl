#include "../header.hpp"

int main(){
    //%snippet.set('range_dp')%
    //%snippet.config({'alias':'dp_range'})%
    //%snippet.fold()%
    auto dp = make_table(n, n+1, inf<int>);
    for (int len = 1; len <= n ; len++) {
        rep(l, 0, n-len+1){
            int r = l + len;
            // calc dp[l][r] : [l, r)
            chmin(dp[l][r], single(l, r));
            rep(mid, l+1, r) {
                chmin(dp[l][r], dp[l][mid]+dp[mid][r]);
            }
        }
    }
    //%snippet.end()%
}
