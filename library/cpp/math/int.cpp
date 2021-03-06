#include <bits/stdc++.h>
using namespace std;

// {{{ gcd, lcm
// %snippet.set('gcd')%
// %snippet.config({'abbr':'great common divisor', 'indent':True})%
ll gcd(ll a, ll b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}
// %snippet.end()%  明示的に終了したい場合

// %snippet.set('lcm')%
// %snippet.include('gcd')%
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;  // overflowしにくいように最初に割り算をする。
}
// %snippet.end()%

//}}}

//%snippet.set('reverse_int')%
//%snippet.include('lcm')%  //再帰のテスト {{{
ll reverse_int(ll number) {
    ll reverse = 0;
    while (number > 0) {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
    return reverse;
}
// %snippet.end()% }}}

//%snippet.set('digitSum')%
int digitSum(ll x) { /*{{{*/
    int res = 0;
    while (true) {
        res += x % 10;
        x /= 10;
        if (x == 0) {
            break;
        }
    }
    return res;
} /*}}}*/

//%snippet.set('is_prime')%
bool is_prime(ll n) { /*{{{*/
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
} /*}}}*/

//%snippet.set('prime_factor')%
map<ll, ll> prime_factor(ll n) {  // 素因数分解 (o(√N)){{{
    map<ll, ll> res;  // vectorで持つことも考えられる。
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
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
vector<ll> divisor(ll n) {  // 約数全列挙{{{
    vector<ll> p, q;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            p.pb(i);
            if (i * i != n) q.pb(n / i);
        }
    }
    reverse(all(q));
    p.insert(p.end(), all(q));
    return p;
}  //}}}

