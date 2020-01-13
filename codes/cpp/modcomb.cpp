#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//%snippet.set('com')%
const int MAX = 510000;
// Calculate COM(MAX, k) for k<=MAX by O(1) after COMinit() by O(MAX)
// {{{
ll fac[MAX], finv[MAX], inv[MAX];

// 前処理
void COMinit() {
    fac[0] = fac[1] = 1;  // 階乗
    finv[0] = finv[1] = 1; // 階乗の逆元
    inv[1] = 1;  // 逆元
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
//}}}
//%snippet.end()%

int main() {
    // 前処理
    COMinit();

    // 計算例
    assert(COM(5, 2) == 10);
    cout << COM(10, 3) << endl;  // 120
}

// ref: [http://drken1215.hatenablog.com/entry/2018/06/08/210000]
