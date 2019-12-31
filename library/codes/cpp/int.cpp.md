---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: codes/cpp/int.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/int.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 15:20:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

// {{{ gcd, lcm
// %snippet.set('gcd')%
// %snippet.config({'abbr':'great common divisor', 'indent':True})%
int gcd(int a, int b){
  if (b>a) swap(a,b);
  if (b==0) return a;
  return gcd(b, a%b);
}
// %snippet.end()%  明示的に終了したい場合


// %snippet.set('lcm')%
// %snippet.include('gcd')%
int lcm(int a, int b){
  return (a/gcd(a,b))*b;  // overflowしにくいように最初に割り算をする。
}
// %snippet.end()%

//}}}

//%snippet.set('reverse_int')%
//%snippet.include('lcm')%  //再帰のテスト {{{
int reverse_int(int number) {
  int reverse=0;
  while (number > 0) {
    reverse = reverse * 10 + number % 10;
    number /= 10;
  }
  return reverse;
}
// %snippet.end()% }}}

//%snippet.set('digitSum')%
int digitSum(int x){/*{{{*/
  int res = 0;
  while (true) {
    res += x%10;
    x /= 10;
    if (x==0) { break; }
  }
  return res;
}/*}}}*/

//%snippet.set('sieve')%
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
}//}}}

//%snippet.set('is_prime')%
bool is_prime(int n) {/*{{{*/
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return n != 1;
}/*}}}*/

//%snippet.set('prime_factor')%
map<int, int> prime_factor(int n) { // 素因数分解 (o(√N)){{{
  map<int, int> res;  // vectorで持つことも考えられる。
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
//}}}

//%snippet.set('divisor')%
vi divisor(int n){  // 約数全列挙{{{
  vi p,q;
  for(int i=1; i*i<=n; i++){
    if (n%i==0){
      p.pb(i);
      if (i*i!=n) q.pb(n/i);
    }
  }
  reverse(all(q));
  p.insert(p.end(), all(q));
  return p;
}//}}}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/int.cpp"
#include <bits/stdc++.h>
using namespace std;

// {{{ gcd, lcm
// %snippet.set('gcd')%
// %snippet.config({'abbr':'great common divisor', 'indent':True})%
int gcd(int a, int b){
  if (b>a) swap(a,b);
  if (b==0) return a;
  return gcd(b, a%b);
}
// %snippet.end()%  明示的に終了したい場合


// %snippet.set('lcm')%
// %snippet.include('gcd')%
int lcm(int a, int b){
  return (a/gcd(a,b))*b;  // overflowしにくいように最初に割り算をする。
}
// %snippet.end()%

//}}}

//%snippet.set('reverse_int')%
//%snippet.include('lcm')%  //再帰のテスト {{{
int reverse_int(int number) {
  int reverse=0;
  while (number > 0) {
    reverse = reverse * 10 + number % 10;
    number /= 10;
  }
  return reverse;
}
// %snippet.end()% }}}

//%snippet.set('digitSum')%
int digitSum(int x){/*{{{*/
  int res = 0;
  while (true) {
    res += x%10;
    x /= 10;
    if (x==0) { break; }
  }
  return res;
}/*}}}*/

//%snippet.set('sieve')%
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
}//}}}

//%snippet.set('is_prime')%
bool is_prime(int n) {/*{{{*/
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return n != 1;
}/*}}}*/

//%snippet.set('prime_factor')%
map<int, int> prime_factor(int n) { // 素因数分解 (o(√N)){{{
  map<int, int> res;  // vectorで持つことも考えられる。
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
//}}}

//%snippet.set('divisor')%
vi divisor(int n){  // 約数全列挙{{{
  vi p,q;
  for(int i=1; i*i<=n; i++){
    if (n%i==0){
      p.pb(i);
      if (i*i!=n) q.pb(n/i);
    }
  }
  reverse(all(q));
  p.insert(p.end(), all(q));
  return p;
}//}}}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

