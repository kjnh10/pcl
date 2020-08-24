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
<script type="text/javascript" src="../../../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/graph/tree.lib/hld.test/test/judge.cpp

<a href="../../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../../index.html#6625f7d848c2ba1574f90ce7248a2c37">library/cpp/graph/tree.lib/hld.test/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/tree.lib/hld.test/test/judge.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-11 21:04:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
// struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
    #include "../codes/lib/dump.hpp"
#else
    #define dump(...) 42
    #define dump_1d(...) 42
    #define dump_2d(...) 42
    #define cerrendl 42
#endif
//}}}

int T;
int b;

template<class T>
void tell(T x){
    dump(x);
    cout << x << endl;
    fflush(stdout);
}

int judge_case(string a){
    dump(a);
    for(int cnt=1; cnt<=150; cnt++){
        if (cnt%10==1){ reverse(all(a)); }

        string query;cin>>query;
        if (sz(query)!=b){ tell(a[stoi(query)-1]); }
        else{
            if (query==a){
                tell("Y");
                return 0;
            }
            else{
                tell("N");
                dump("judge-ans", a);
                dump("contestant-ans", query);
                throw("WA");
            }
        }
        cnt += 1;
    }
    throw("query's limit exceeded");
}

signed main(){
    // input case
    cin>>T>>b;
    tell(T);
    tell(b);
    vector<string> A(T);
    rep(t, T){ cin>>A[t]; }

    // judge
    rep(i, T){
        judge_case(A[i]);
    }

    // TODO: check contestant code is continuing to needles queries.
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/cpp/graph/tree.lib/hld.test/test/judge.cpp: line 47: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../../../../index.html">Back to top page</a>

