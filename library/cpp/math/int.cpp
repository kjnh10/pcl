#include <bits/stdc++.h>
using namespace std;

// {{{ gcd, lcm
// %snippet.set('gcd')%
// %snippet.config({'abbr':'great common divisor', 'indent':True})%
int gcd(int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}
// %snippet.end()%  明示的に終了したい場合

// %snippet.set('lcm')%
// %snippet.include('gcd')%
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // overflowしにくいように最初に割り算をする。
}
// %snippet.end()%

//}}}

//%snippet.set('reverse_int')%
//%snippet.include('lcm')%  //再帰のテスト {{{
int reverse_int(int number) {
    int reverse = 0;
    while (number > 0) {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
    return reverse;
}
// %snippet.end()% }}}

//%snippet.set('digitSum')%
int digitSum(int x) { /*{{{*/
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
bool is_prime(int n) { /*{{{*/
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
} /*}}}*/

//%snippet.set('prime_factor')%
map<int, int> prime_factor(int n) {  // 素因数分解 (o(√N)){{{
    map<int, int> res;  // vectorで持つことも考えられる。
    for (int i = 2; i * i <= n; i++) {
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
vi divisor(int n) {  // 約数全列挙{{{
    vi p, q;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            p.pb(i);
            if (i * i != n) q.pb(n / i);
        }
    }
    reverse(all(q));
    p.insert(p.end(), all(q));
    return p;
}  //}}}

//%snippet.set('sieve')%

struct Sieve {
    // エラトステネスのふるい O(NloglogN)
    int n;                              // n]
    vector<int> f;                      // [1, 2, 3, 2, 5, 2, 7, 2, 3, ....]
    vector<int> primes;                 // [2, 3, 5, .......]
    Sieve(int n = 1) : n(n), f(n + 1) { /*{{{*/
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    } /*}}}*/
    bool isPrime(int x) { return f[x] == x; }

    vector<int> factor_list(int x) { /*{{{*/
        vector<int> res;
        if (x < n) {
            while (x != 1) {
                res.push_back(f[x]);
                x /= f[x];
            }
        } else {
            for (int i = 0; primes[i] * primes[i] <= x; i++) {
                while (x % primes[i] == 0) {
                    res.pb(primes[i]);
                    x /= primes[i];
                }
            }
            if (x != 1) res.pb(x);
        }

        return res;  // [2, 3, 3, 5, 5, 5.....]
    }                /*}}}*/

    vector<pair<int, int>> factor(int x) { /*{{{*/
        vector<int> fl = factor_list(x);
        if (fl.size() == 0) return {};
        vector<pair<int, int>> res(1, mp(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;  // [(2,1), (3,2), (5,3), .....]
    }                /*}}}*/
};

// Sieve sv(1e6);
// sv.factor(x);  // 素因数分解
