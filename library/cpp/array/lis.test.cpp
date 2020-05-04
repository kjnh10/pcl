#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp"
#include "lis.hpp"

signed main(){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i, n) {
        cin>>a[i];
    }
    dump(a);

    cout << lis(a) << endl;
    return 0;
}
