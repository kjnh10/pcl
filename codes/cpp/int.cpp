#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if (b>a) swap(a,b);
  if (b==0) return a;
  return gcd(b, a%b);
}

int lcd(int a, int b){
  return (a/gcd(a,b))*b;  // overflowしにくいように最初に割り算をする。
}

int rev(int number) {
  int reverse=0;
  while (number > 0) {
    reverse = reverse * 10 + number % 10;
    number /= 10;
  }
  return reverse;
}

int digitSum(int x){/*{{{*/
  int res = 0;
  while (true) {
    res += x%10;
    x /= 10;
    if (x==0) { break; }
  }
  return res;
}/*}}}*/

// Combination Table by パスカルの三角形 {{{
#define MAX_N 50
int C[MAX_N+1][MAX_N+1]; // C[n][k] -> nCk
void comb_table(int N){
  for(int i=1;i<=N;++i){
    for(int j=0;j<=N;++j){
      if(j==0 or j==i){
        C[i][j]=1LL;
      }else{
        C[i][j]=(C[i-1][j-1]+C[i-1][j]);
      }
    }
  }
}  // }}}

vector<int> sieve(int n) {  // エラトステネスのふるい O(NloglogN){{{
  // 素数の集合を得たい場合はsort, uniqueをすればよい。
  vector<int> primes(n);
  for (int i = 2; i < n; ++i)
    primes[i] = i;
  for (int i = 2; i*i < n; ++i)
    if (primes[i])
      for (int j = i*i; j < n; j+=i)
        primes[j] = 0;
  return primes;
}/*}}}*/

bool is_prime(int n) {/*{{{*/
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}/*}}}*/

map<int, int> prime_factor(int n) { // 素因数分解 (o(√N)){{{
    map<int, int> res;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}
// (参考)http://pakapa104.hatenablog.com/entry/2016/02/09/230443
/*}}}*/

// my mod calc{{{
void add(int& x, int y){
  x+=y; x%=MOD;
}

int mod(int x){
  int res = x%MOD;
  return res<0?res+MOD:res;
}
// }}}

// tourist mod calc{{{
const int md = (int) 1e9 + 7;
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
//}}}
