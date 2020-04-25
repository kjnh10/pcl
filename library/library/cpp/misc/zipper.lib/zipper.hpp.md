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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :heavy_check_mark: library/cpp/misc/zipper.lib/zipper.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#04045c664907c0ef027b886794febe26">library/cpp/misc/zipper.lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/misc/zipper.lib/zipper.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 02:21:57+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/library/cpp/misc/zipper.lib/zipper.test.cpp.html">library/cpp/misc/zipper.lib/zipper.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"

//%snippet.set('zip')%

struct zipper{/*{{{*/
    unordered_map<long long, int> zip_map; // [2:0, 3:1, 5:2, 10:3]
    vector<long long> _unzipper; // [2, 3, 5, 10]
    bool _is_build = false;

    zipper(long long inf_value = INF){/*{{{*/
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
    }/*}}}*/
    zipper(vector<long long> a, long long inf_value = INF){/*{{{*/
        int n = sz(a);
        _unzipper = vector<long long>(n);
        rep(i, n) { _unzipper[i]=a[i]; }
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
        build();
    }/*}}}*/
    void add_value(long long lv){/*{{{*/
        _unzipper.push_back(lv);
        _is_build = false;
    }/*}}}*/
    void build(){/*{{{*/
        uni(_unzipper);
        zip_map.clear();
        rep(i, sz(_unzipper)){ zip_map[_unzipper[i]] = i; }
        _is_build = true;
    }/*}}}*/
    int get_zipped(long long lv){/*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }/*}}}*/
    vector<int> get_zipped(vector<long long> lvs){/*{{{*/
        if (!_is_build) assert(false);
        int n = sz(lvs);
        vector<int> res(n);
        rep(i, n) res[i] = zip_map[lvs[i]];
        return res;
    }/*}}}*/
    int operator()(long long lv) {/*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }/*}}}*/
    long long unzip(int sv) {/*{{{*/
        if (!_is_build) assert(false);
        return _unzipper[sv];
    }/*}}}*/
#if defined(PCM) || defined(LOCAL)/*{{{*/
    friend ostream& operator<<(ostream& os, const zipper& zp){
        os << endl;
        os << "_is_build: " << zp._is_build << endl;
        os << "zip_map:   " << zp.zip_map << endl;
        return os;
    }
#endif/*}}}*/
};/*}}}*/
// How to use {{{
// construct
    // auto z = zipper(x); // x: vector<long long>;
    // auto z = zipper(x, 30*INF);

    // auto z = zipper();
    // auto z = zipper();
    // z.add_value(3);
    // z.add_value(5);
    // z.add_value(10);
    // z.add_value(100000000);
    // z.build();

// other method
    // z(x[i]); -> zipped x[i]
    // z.unzip(z(x[i])) -> x[i];
    // z.get_zipped(x) -> zipped x
// }}}

//%snippet.end()%


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
const int INF=1e18;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define r_rep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x)-A.begin())
#define upos(A, x) (upper_bound(all(A),x)-A.begin())
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
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
#else
  #define dump(...) ;
  #define dump_1d(...) ;
  #define dump_2d(...) ;
  #define cerrendl ;
#endif

#line 2 "library/cpp/misc/zipper.lib/zipper.hpp"

//%snippet.set('zip')%

struct zipper{/*{{{*/
    unordered_map<long long, int> zip_map; // [2:0, 3:1, 5:2, 10:3]
    vector<long long> _unzipper; // [2, 3, 5, 10]
    bool _is_build = false;

    zipper(long long inf_value = INF){/*{{{*/
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
    }/*}}}*/
    zipper(vector<long long> a, long long inf_value = INF){/*{{{*/
        int n = sz(a);
        _unzipper = vector<long long>(n);
        rep(i, n) { _unzipper[i]=a[i]; }
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
        build();
    }/*}}}*/
    void add_value(long long lv){/*{{{*/
        _unzipper.push_back(lv);
        _is_build = false;
    }/*}}}*/
    void build(){/*{{{*/
        uni(_unzipper);
        zip_map.clear();
        rep(i, sz(_unzipper)){ zip_map[_unzipper[i]] = i; }
        _is_build = true;
    }/*}}}*/
    int get_zipped(long long lv){/*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }/*}}}*/
    vector<int> get_zipped(vector<long long> lvs){/*{{{*/
        if (!_is_build) assert(false);
        int n = sz(lvs);
        vector<int> res(n);
        rep(i, n) res[i] = zip_map[lvs[i]];
        return res;
    }/*}}}*/
    int operator()(long long lv) {/*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }/*}}}*/
    long long unzip(int sv) {/*{{{*/
        if (!_is_build) assert(false);
        return _unzipper[sv];
    }/*}}}*/
#if defined(PCM) || defined(LOCAL)/*{{{*/
    friend ostream& operator<<(ostream& os, const zipper& zp){
        os << endl;
        os << "_is_build: " << zp._is_build << endl;
        os << "zip_map:   " << zp.zip_map << endl;
        return os;
    }
#endif/*}}}*/
};/*}}}*/
// How to use {{{
// construct
    // auto z = zipper(x); // x: vector<long long>;
    // auto z = zipper(x, 30*INF);

    // auto z = zipper();
    // auto z = zipper();
    // z.add_value(3);
    // z.add_value(5);
    // z.add_value(10);
    // z.add_value(100000000);
    // z.build();

// other method
    // z(x[i]); -> zipped x[i]
    // z.unzip(z(x[i])) -> x[i];
    // z.get_zipped(x) -> zipped x
// }}}

//%snippet.end()%


```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

