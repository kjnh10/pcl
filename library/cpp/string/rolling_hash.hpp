#include "../header.hpp"

//%snippet.set('rolling_hash')%

template <ll mod, ll B>
struct rolling_hash {
    vector<ll> hash, _bpow;  // 1-index
    rolling_hash() {}
    rolling_hash(vector<ll> vs) { init(vs); }
    rolling_hash(string &s) {
        vector<ll> vs;
        for (char c : s) vs.emplace_back(c);
        init(vs);
    }

    void init(vector<ll> vs) {
        int n = vs.size();
        hash.assign(n + 1, 0);
        _bpow.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * B + vs[i]) % mod;
            _bpow[i + 1] = _bpow[i] * B % mod;
        }
    }

    // S[l, r)
    ll get_hash(int l, int r) {
        ll res = hash[r] + mod - hash[l] * _bpow[r - l] % mod;
        return res >= mod ? res - mod : res;
    }
};

//%snippet.end()%

