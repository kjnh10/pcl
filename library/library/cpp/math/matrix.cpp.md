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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: library/cpp/math/matrix.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#38e8a99339d0d505d14feb619e0537d8">library/cpp/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 09:08:25+09:00




## Depends on

* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../header.hpp"

// BEGIN CUT HERE
using value = int;
using mat = vector<vector<value>>;

mat mul(mat& A, mat& B) {
    mat res(A.size(), vector<value>(B[0].size()));
    rep(i, A.size()) {
        rep(j, B[0].size()) {
            rep(k, B.size()) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) %
                            MOD;  // remove %MOD if not needed
            }
        }
    }
    return res;
}

mat pow(mat A, int n) {
    mat B(A.size(), vector<value>(A.size()));
    rep(i, A.size()) {
        B[i][i] = 1;  // E
    }
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
// END CUT HERE

int solve() {
    int n, m;
    cin >> n >> m;

    mat A(m, vi(m, 0));  // m==0だと落ちるので注意。
    A[0][0] = 1;
    A[0][m - 1] = 1;
    rep(i, 1, m) { A[i][i - 1] = 1; }
    // dump(pow(A, n));

    cout << pow(A, n)[0][0] << endl;

    return 0;
}

signed main() {  //{{{
#ifdef INPUT_FROM_FILE
    std::ifstream in(infile);
    std::cin.rdbuf(in.rdbuf());
#endif
    solve();
    return 0;
}  //}}}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "library/cpp/header.hpp"

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF = 1e18;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (int i = (int)((b)-1); i >= (int)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T>
inline void chmax(T &a, const T &b) {
    if ((a) < (b)) (a) = (b);
}
template <class T>
inline void chmin(T &a, const T &b) {
    if ((a) > (b)) (a) = (b);
}

#define divceil(a, b) ((a) + (b)-1) / (b)
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x)    \
    sort(all(x)); \
    x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast {
    Fast() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
    }
} fast;

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif
#line 2 "library/cpp/math/matrix.cpp"

// BEGIN CUT HERE
using value = int;
using mat = vector<vector<value>>;

mat mul(mat& A, mat& B) {
    mat res(A.size(), vector<value>(B[0].size()));
    rep(i, A.size()) {
        rep(j, B[0].size()) {
            rep(k, B.size()) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) %
                            MOD;  // remove %MOD if not needed
            }
        }
    }
    return res;
}

mat pow(mat A, int n) {
    mat B(A.size(), vector<value>(A.size()));
    rep(i, A.size()) {
        B[i][i] = 1;  // E
    }
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
// END CUT HERE

int solve() {
    int n, m;
    cin >> n >> m;

    mat A(m, vi(m, 0));  // m==0だと落ちるので注意。
    A[0][0] = 1;
    A[0][m - 1] = 1;
    rep(i, 1, m) { A[i][i - 1] = 1; }
    // dump(pow(A, n));

    cout << pow(A, n)[0][0] << endl;

    return 0;
}

signed main() {  //{{{
#ifdef INPUT_FROM_FILE
    std::ifstream in(infile);
    std::cin.rdbuf(in.rdbuf());
#endif
    solve();
    return 0;
}  //}}}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
