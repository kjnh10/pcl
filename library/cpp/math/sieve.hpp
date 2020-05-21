
//%snippet.set('sieve')%
//%snippet.config({'alias':'prime_factor_by_sieve'})%
//%snippet.fold()%

struct Sieve {/*{{{*/
    // エラトステネスのふるい O(NloglogN)
    int n;                              // n
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
    bool is_prime(int x) { return f[x] == x; }

    vector<int> factor_list(int x) { /*{{{*/
        // n**2くらいまでは計算できるはず
        vector<int> res;
        if (x < n) {
            while (x != 1) {
                res.push_back(f[x]);
                x /= f[x];
            }
        }
        else {
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
};/*}}}*/
Sieve sv(1e6);
// How to use
    // sv.primes      // 素数のリスト
    // sv.factor(x);  // 素因数分解

//%snippet.end()%
