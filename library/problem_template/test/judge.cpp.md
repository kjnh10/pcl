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


# :warning: problem_template/test/judge.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76c92c32675513a9b45b3a525f3ad871">problem_template/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/problem_template/test/judge.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-20 00:15:11+09:00




## Depends on

* :question: <a href="../../library/cpp/header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../codes/header.hpp"

enum JudgeResult {/*{{{*/
    AC = 0,
    WA = 1,
    RE = 2,
    CE = 3,
    TLE = -2,
    MLE = 4,
    QLE = 5,  // Query limit exceeded
    AIE = 6,  // Additional input error
    NOEXP = 98,
    TLENAIVE = 99,
    YET = 100,
};/*}}}*/

template <class T>/*{{{*/
void tell(T x) {
    cout << x << endl;
    fflush(stdout);
}/*}}}*/

bool check_AIE(){/*{{{*/
    ll tmp;cin>>tmp;
    if (cin.eof()==0) exit(AIE);  // check needles user-output does not exist
}/*}}}*/

int judge_case(ll x) {
    ll num = 22;  // TODO: update query number limit
    while(num--){
        string query;
        cin >> query;
        if (query=="?"){ // query
            ll solver_ans;cin>>solver_ans;
            tell(gcd(solver_ans, x));
        }
        if (query=="!"){ // ans
            ll solver_ans;cin>>solver_ans;
            if (abs(solver_ans-x)<=7 || (solver_ans<=2*x && x<=2*solver_ans)){
                return 0;
            }
            else{
                cerr << "WA: ";
                dump(x, solver_ans);
                exit(WA);
            }
        }
    }
    exit(QLE);
}

int main() {
    // input case
    int Q;
    cin >> Q;
    // Q = 1; if single case
    vector<ll> x(Q);
    rep(q, Q){ cin>>x[q]; }

    // judge
    tell(Q);  // off if single case
    rep(q, Q) {
        cerr << "start judge for: " << x[q] << " [judge]" << endl;;
        judge_case(x[q]); 
    }

    // check_AIE(); // これは何故か動かない。無限待機になってしまう。
    exit(AC);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "library/cpp/header.hpp"

//%snippet.set('header')%
//%snippet.fold()%
#ifndef HEADER_H
#define HEADER_H

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
const long long INF = 1e18;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)
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
template <class T> inline void chmax(T &a, const T &b) { if ((a) < (b)) (a) = (b); }
template <class T> inline void chmin(T &a, const T &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define divceil(a, b) ((a) + (b)-1) / (b)
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif /* HEADER_H */
//%snippet.end()%
#line 2 "problem_template/test/judge.cpp"

enum JudgeResult {/*{{{*/
    AC = 0,
    WA = 1,
    RE = 2,
    CE = 3,
    TLE = -2,
    MLE = 4,
    QLE = 5,  // Query limit exceeded
    AIE = 6,  // Additional input error
    NOEXP = 98,
    TLENAIVE = 99,
    YET = 100,
};/*}}}*/

template <class T>/*{{{*/
void tell(T x) {
    cout << x << endl;
    fflush(stdout);
}/*}}}*/

bool check_AIE(){/*{{{*/
    ll tmp;cin>>tmp;
    if (cin.eof()==0) exit(AIE);  // check needles user-output does not exist
}/*}}}*/

int judge_case(ll x) {
    ll num = 22;  // TODO: update query number limit
    while(num--){
        string query;
        cin >> query;
        if (query=="?"){ // query
            ll solver_ans;cin>>solver_ans;
            tell(gcd(solver_ans, x));
        }
        if (query=="!"){ // ans
            ll solver_ans;cin>>solver_ans;
            if (abs(solver_ans-x)<=7 || (solver_ans<=2*x && x<=2*solver_ans)){
                return 0;
            }
            else{
                cerr << "WA: ";
                dump(x, solver_ans);
                exit(WA);
            }
        }
    }
    exit(QLE);
}

int main() {
    // input case
    int Q;
    cin >> Q;
    // Q = 1; if single case
    vector<ll> x(Q);
    rep(q, Q){ cin>>x[q]; }

    // judge
    tell(Q);  // off if single case
    rep(q, Q) {
        cerr << "start judge for: " << x[q] << " [judge]" << endl;;
        judge_case(x[q]); 
    }

    // check_AIE(); // これは何故か動かない。無限待機になってしまう。
    exit(AC);
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

