#include "../../../header.hpp"

//%snippet.set('kmp')%

// Morris-Pratt
template <typename T>
struct KMP {
    int n;
    T pattern;
    vector<int> a;
    KMP() {} /*{{{*/
    KMP(const T& pattern) : pattern(pattern) {
        n = pattern.size();
        a = vector<int>(n + 1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && pattern[j] != pattern[i]) j = a[j];
            j++;
            a[i + 1] = j;
        }
    } /*}}}*/
    int operator[](int i) { return a[i]; }
    vector<int> findAll(const T& s) { /*{{{*/
        vector<int> res;
        int j = 0;
        for (int i = 0; i < sz(s); ++i) {
            while (j != -1 && pattern[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i - j + 1);
                j = a[j];
            }
        }
        return res;
    } /*}}}*/
};

// KMP<vector<int>> kmp({1,2,3});
// KMP<string> kmp("abc");

//%snippet.end()%

vector<int> f(vector<int>& a) {
    int n = a.size();
    vector<int> res(n);
    rep(i, n) res[i] = a[i] ^ a[(i + 1) % n];
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> xa = f(a);
    vector<int> xb = f(b);
    dump(xa);
    dump(xb);

    KMP<vector<int>> kmp(xa);
    dump("hello");
    vector<ll> wxb;
    wxb.insert(wxb.end(), xb.begin(), xb.end());
    wxb.insert(wxb.end(), xb.begin(), xb.end());

    vector<int> res = kmp.findAll(wxb);
    vector<int> ks;
    for (int p : res) ks.push_back(n - p);
    sort(ks.begin(), ks.end());
    for (int k : ks) {
        if (k >= n) continue;
        int x = a[k] ^ b[0];
        cout << k << " " << x << endl;
    }
    return 0;
}
