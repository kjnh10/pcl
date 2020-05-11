#define PROBLEM "https://yukicoder.me/problems/no/1035"

#include "combination.hpp"

int main(){
    int n,m;cin>>n>>m;

    mint ans = mint(m).pow(n);

    rep(x, 1, m){  // x: 使わない色の数
        ans += mint(-1).pow(x) * com(m, x) * mint(m-x).pow(n);
    }

    cout << ans << endl;
}
