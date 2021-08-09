#pragma once
#include "../header.hpp"

//%snippet.set('sieve')%
//%snippet.config({'alias':'prime_factor_by_sieve'})%
//%snippet.fold()%

struct Sieve {/*{{{*/
    // エラトステネスのふるい O(NloglogN)
    ll n;                              // n: max number for defined minfactor and primes
    vector<ll> minfactor;              // [-1, 2, 3, 2, 5, 2, 7, 2, 3, ....]
    vector<ll> primes;                 // [2, 3, 5, .......]
    vector<int> mobius;                // メビウス関数値

    Sieve(ll n = 1) : n(n), minfactor(n + 1), mobius(n + 1, 1) { /*{{{*/
        minfactor[0] = minfactor[1] = -1;
        for (ll p = 2; p <= n; ++p) {
            if (minfactor[p]) continue;
            primes.push_back(p);
            minfactor[p] = p;
            mobius[p] = -1;
            for (ll x = p * p; x <= n; x += p) {
                if (!minfactor[x]) minfactor[x] = p;
                if ((x / p) % p == 0) mobius[x] = 0;
                else mobius[x] *= -1;
            }
        }
    } /*}}}*/

    bool is_prime(ll x) {/*{{{*/
        if (x <= n) return minfactor[x] == x; 
        return sz(factor_list(x)) == 1;
    }/*}}}*/

    vector<ll> factor_list(ll x) { /*{{{*/
        assert(0 < x && x <= n*n); // これが満たされないと正しく計算されない可能性がある。

        vector<ll> res;
        if (x <= n) {
            while (x != 1) {
                res.push_back(minfactor[x]);
                x /= minfactor[x];
            }
        }
        else {
            for (ll i = 0; primes[i] * primes[i] <= x; i++) {
                while (x % primes[i] == 0) {
                    res.pb(primes[i]);
                    x /= primes[i];
                }
            }
            if (x != 1) res.pb(x);
        }

        return res;  // [2, 3, 3, 5, 5, 5.....]
    }                /*}}}*/

    vector<pair<ll, ll>> prime_factor(ll x) { /*{{{*/
        // just change fl vector to map form
        vector<ll> fl = factor_list(x);
        if (fl.size() == 0) return {};
        vector<pair<ll, ll>> res = {mp(fl[0], 0)};
        for (ll p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;  // [(2,1), (3,2), (5,3), .....]
    }                /*}}}*/

    vector<ll> divisors(ll x) { // 高速約数列挙{{{
        vector<ll> res({1});
        auto ps = prime_factor(x);

        // 約数列挙
        for (auto p : ps) {
            ll s = (ll)res.size();
            for (ll i = 0; i < s; ++i) {
                ll v = 1;
                for (ll j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }/*}}}*/

};/*}}}*/
Sieve sv(1e6);
// How to use
    // sv.primes            // 素数のリスト
    // sv.prime_factor(x);  // 素因数分解

//%snippet.end()%
