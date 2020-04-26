#include "../header.hpp"
#include "../math/mint.hpp"

template <typename T, T MOD, T B>
struct rolling_hash {
    using ll = long long;
    vector<T> hash, bpow;  // 1-index
    rolling_hash() {}
    rolling_hash(vector<T> vs) { init(vs); }
    rolling_hash(string &s) {
        vector<T> vs;
        for (char c : s) vs.emplace_back(c);
        init(vs);
    }

    void init(vector<T> vs) {
        int n = vs.size();
        hash.assign(n + 1, 0);
        bpow.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = ((ll)hash[i] * B + vs[i]) % MOD;
            bpow[i + 1] = (ll)bpow[i] * B % MOD;
        }
    }

    // S[l, r)
    T find(int l, int r) {
        T res = (ll)hash[r] + MOD - (ll)hash[l] * bpow[r - l] % MOD;
        return res >= MOD ? res - MOD : res;
    }
};

signed main() {
    // https://atcoder.jp/contests/abc150/tasks/abc150_f
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }
    vector<int> b(n);
    rep(i, n) { cin >> b[i]; }

    vi c(n), d(n);
    rep(i, n) {
        c[i] = a[i] ^ a[(i + 1) % n];
        d[i] = b[i] ^ b[(i + 1) % n];
    }

    const int B = 1e9 + 9;  // random if codeforces
    rolling_hash<int, mod, B> arh(c);
    rolling_hash<int, mod, B> brh(d);
    mint x = arh.find(0, n);
    mint y = brh.find(0, n);

    vi ans;
    rep(k, n) {
        x -= c[k] * arh.bpow[n - 1];
        x *= B;
        x += c[k];
        if (x == y) ans.pb((k + 1) % n);
    }

    sort(all(ans));
    each(k, ans) {
        int x = a[n - 1] ^ b[n - 1 - k];
        cout << k << " " << x << endl;
    }

    return 0;
}
