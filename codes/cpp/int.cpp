#include <bits/stdc++.h>
using namespace std;

// {{{ gcd, lcd
//%snippet.set('gcd')%
//%snippet.config({'abbr':'great common divisor', 'indent':True})%
int gcd(int a, int b){
  if (b>a) swap(a,b);
  if (b==0) return a;
  return gcd(b, a%b);
}
//%snippet.end()%

//%snippet.set('lcd')%
//%snippet.include('gcd')%
int lcd(int a, int b){
  return (a/gcd(a,b))*b;  // overflowしにくいように最初に割り算をする。
}
//%snippet.end()%


//%snippet.set('rev')%
//%snippet.include('lcd')%
int rev(int number) {
  int reverse=0;
  while (number > 0) {
    reverse = reverse * 10 + number % 10;
    number /= 10;
  }
  return reverse;
}
//%snippet.end()%
// }}}

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
    if (n != 1) res[n] += 1;
    return res;
}
// (参考)http://pakapa104.hatenablog.com/entry/2016/02/09/230443
/*}}}*/

