#include "../header.hpp"

template<class Z> Z rng(Z a, Z b) {
    auto tmp = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<Z>(a, b - 1)(tmp);
}

//%snippet.set('rolling_hash')%

struct rolling_hash {
    // static constexpr uint64_t P0 = 4111144441, P1 = 4111444111;
    static constexpr uint64_t P0 = 1e9+7, P1 = 998244353;
    static uint64_t B0, B1;
    vector<ll> hash0, hash1, _bpow0, _bpow1;  // 1-index
    rolling_hash() {}
    rolling_hash(vector<ll> &vs) {
        init(vs, hash0, B0, P0, _bpow0); 
        init(vs, hash1, B1, P1, _bpow1); 
    }
    rolling_hash(string &s) {
        vector<ll> vs;
        for (char c : s) vs.emplace_back(c);
        init(vs, hash0, B0, P0, _bpow0); 
        init(vs, hash1, B1, P1, _bpow1); 
    }

    void init(vector<ll>& vs, vector<ll>& hash, ll B, ll P, vector<ll>& _bpow) {
        int n = vs.size();
        hash.assign(n + 1, 0);
        _bpow.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * B + vs[i]) % P;
            _bpow[i + 1] = _bpow[i] * B % P;
        }
    }

    pair<ll, ll> get_hash(int l, int r) {
        ll h0 = _get_hash(l, r, hash0, B0, P0, _bpow0);
        ll h1 = _get_hash(l, r, hash1, B1, P1, _bpow1);
        return {h0, h1};
    }
    ll _get_hash(int l, int r,  const vector<ll>& hash, ll B, ll P, const vector<ll>& _bpow) {
        ll res = (hash[r] - hash[l]*_bpow[r - l]) % P;
        res = (res < 0 ? res + P : res);
        assert(res>=0);
        return res;
    }
};
uint64_t rolling_hash::B0 = rng<ll>(1000000, rolling_hash::P0);
uint64_t rolling_hash::B1 = rng<ll>(1000000, rolling_hash::P1);


