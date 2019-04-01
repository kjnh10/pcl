#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct ModComb { // {{{
#define MAX_P 200005
  ll fact[MAX_P]; // fact[n]: n!
  ll inv[MAX_P];  // inv[n]: n^(-1)
  ll finv[MAX_P]; // finv[n]: (n!)^(-1)
  ll mod;

  ModComb(ll mod){  // 階乗関連テーブルの初期化 O(n)
    this->mod = mod;
    fact[0]=1;
    for(ll i=1;i<MAX_P;i++)
      fact[i]=(fact[i-1]*i)%mod;

    inv[1]=1;
    for(ll i=2;i<MAX_P;i++)
      inv[i]=inv[mod%i]*(mod-mod/i)%mod;

    finv[0]=1;  //　高速(10倍程度)な逆元階乗テーブルの作成。
    for(ll i=1;i<MAX_P;i++)
      finv[i]=finv[i-1]*inv[i]%mod;
  }

  ll C(ll n, ll k){  // Combination
    if(k<0||k>n)
      return 0;
    else {
      return fact[n]*finv[k]%mod*finv[n-k]%mod;
    }
  }
};
// }}}

int main(){
  auto mc = ModComb(1e9+7);
  cout << mc.C(6, 2) << endl;
  assert(mc.C(5, 2) == 10);
}

