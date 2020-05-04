#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A&lang=ja"
#include "zipper.hpp"

signed main() {
    int n;cin>>n;

    vector<ll> x1(n), x2(n), y1(n), y2(n);
    zipper zx, zy;
    rep(i, n){
        cin>>x1[i]>>y1[i];
        cin>>x2[i]>>y2[i];
        zx.add_value(x1[i]);
        zx.add_value(x2[i]);
        zy.add_value(y1[i]);
        zy.add_value(y2[i]);
    }
    zx.build();
    zy.build();
    vvi e(sz(zx), vi(sz(zy)));
    rep(i, n){
        e[zx(x1[i])][zy(y1[i])]++;
        e[zx(x1[i])][zy(y2[i])]--;
        e[zx(x2[i])][zy(y1[i])]--;
        e[zx(x2[i])][zy(y2[i])]++;
    }

    rep(i, 0, sz(zx)){
        rep(j, 1, sz(zy)){
            e[i][j] += e[i][j-1];
        }
    }
    rep(j, 0, sz(zy)){
        rep(i, 1, sz(zx)){
            e[i][j] += e[i-1][j];
        }
    }

    ll ans = 0;
    rep(i, 1, sz(zx)-2){
        rep(j, 1, sz(zy)-2){
            ll dx = (zx.unzip(i+1) - zx.unzip(i));
            ll dy = (zy.unzip(j+1) - zy.unzip(j));
            if (e[i][j]>0 )ans += dx*dy;
        }
    }
    cout << ans << endl;

    return 0;
}
