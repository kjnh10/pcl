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


# :warning: library/cpp/misc/misc_snip.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b4c52cffc478acefbc1ee6a9d0578055">library/cpp/misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/misc/misc_snip.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-27 03:29:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('cout')%
cout << ${0:TARGET} << endl;

//%snippet.set('couts')%
rep(i, sz(${1:x})) cout << $1[i] << (i!=sz($1)-1 ? " " : "\n");

//%snippet.set('?')%
(${1} ? ${2} : ${3})

//%snippet.set('inv')%
vector<ll> ${1}(n);
rep(i, n) {
    cin>>$1[i];
}
dump($1);${0}

//%snippet.set('invv')%
vector<vector<ll>> ${1}(h, vector<ll>(w));
rep(i, h){
    rep(j,w){
        cin>>$1[i][j];
    }
}

//%snippet.set('invvs')%
vector<vector<ll>> ${1}(h, vector<ll>(w));
rep(i, h){
    string tmp;cin>>tmp;
    rep(j,w){
        if (tmp[j]=='#') $1[i][j]=1;
        else             $1[i][j]=0; 
    }
}

//%snippet.set('rep')%
rep(${0}){
}

//%snippet.set('r_rep')%
r_rep(${0}){
}

//%snippet.set('for')%
for(ll i=0; i<n; i++){${0}
}

//%snippet.set('for_iter')%
for(auto iter=begin(${1}); iter!=end($1); ++iter){${0}
}

//%snippet.set('for_riter')%
for(auto riter=rbegin(${1}); riter!=rend($1); ++riter){${0}
}

//%snippet.set('if')%
if (${0}) {
}

//%snippet.set('else')%
else{${0}
}

//%snippet.set('elif')%
else if(${0}){
}

//%snippet.set('while')%
while(${0}){
}

//%snippet.set('reprep')%
rep(${1}) rep(${2}){${0}
}

//%snippet.set('d')%
dump(${0});

//%snippet.set('af')%
assert(false);

//%snippet.set('sortkey')%
sort(all(${0}), [&](auto &l, auto &r){return l.second < r.second;});

//%snippet.set('perm')%
vector<ll> p(n);
iota(all(p), 0LL);
do{
    dump(p);
    vector<ll> ma(a);
    rep(i, n) ma[i] = a[p[i]];
    dump(ma);
} while (next_permutation(all(p)));

//%snippet.set('to_bin')%
//%snippet.fold()%
string to_bin(ll n, ll d = 10){
    // nをd桁の2進数で表示する。
    stringstream ss;
    ss << bitset<64>(n);
    return ss.str().substr(64-d, d);
}
// ll d = (32 - __builtin_clz(n));  // 最大桁のd: (2^d)
// ll f = N - d; to_bin()で返ってきた文字列で最初に1が立っているindex

//%snippet.set('warsharll')%
// init
vector<vector<ll>> d(n, vector<ll>(n, INF));
rep(i, n)rep(j, n){
    if (i==j) d[i][j] = 0;
}

// input
${0};

// calc
rep(k, n){
    rep(i, n){
        rep(j, n){
            chmin(d[i][j], d[i][k]+d[k][j]);
        }
    }
}
dump_2d(d, n, n);


//%snippet.set('digitdp')%
ll n = sz(s);
vector<vector<ll>> dp(2, vector<ll>(n));
dp[0][0] = 1;
rep(i, 1, n+1){  //桁数
    rep(leq, 2){  //未満確定フラグ
        ll lim = leq ? 9 : s[i-1]-'0';
        rep(d, lim+1){
            dp[leq || d<lim][i] += dp[leq][i-1];
        }
    }
}


//%snippet.set('asv')%
// acumulative sum vector {{{
template<typename T>
struct asvector {
    vector<T> cum; //accumulative sum
    asvector(vector<T> a): cum(a){  // {{{  // constructor
        rep(i, 1, sz(a))  cum[i]+=cum[i-1];
    } // }}}

    T sum(ll l, ll r) {  // return sum of [l, r) of data.  {{{
        l = max(0LL, l);
        r = min(r, sz(cum));
        if (l<r){
            return cum[r-1] - (l-1>=0 ? cum[l-1] : 0);
        }
        else{
            return 0;
        }
    } // }}}

    T& operator[](ll i) { // {{{
        return cum[i]; 
    } // }}}

    friend ostream& operator<<(ostream &os, asvector<T>& as){//{{{
        os << as.cum; return os;
    } //}}}
};
//}}}


//%snippet.set('remove_leading_zeros')%
str.erase(0, min(str.find_first_not_of('0'), str.size()-1));


//%snippet.set('lambda')%
//%snippet.config({'alias':'f'})%
auto f = [&](){
};


//%snippet.set('dfs_lambda_graph')%
vector<ll> used(n);
auto dfs = [&](const auto& dfs, ll u) -> void {
    used[u] = 1;
    each(e, g[u]){
        if (used[e.to]) continue;
        dfs(dfs, e.to);
    }
};
dfs(dfs, 0);


//%snippet.set('dfs_lambda')%
auto dfs = [&](const auto& dfs, ll u) -> ll {
};


//%snippet.set('dxdy')%
ll dx[]={1, -1, 0, 0};
ll dy[]={0, 0, 1, -1};


//%snippet.set('ostream')%
ostream& operator<<(ostream& os, const ${1:type}& ${2}){
    os << ${3};
    return os;
}

//%snippet.set('query')%
ll query(){
    cerrendl;

    return 0;
}

signed main(){/*{{{*/
    ll Q;cin>>Q;
    rep(_, Q){
        query();
    }
    check_input();
    return 0;
}/*}}}*/


//%snippet.set('random_generator')%
uint64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<uint64_t>(0, -1)(x);
}


//%snippet.set('bitall')%
rep(s, 1<<n){
    rep(i, n){
        if(s>>i&1){
        }
        else{
        }
    }
}


//%snippet.set('print_float')%
printf("%.12f\n", ${1});


//%snippet.set('sep')%
//%snippet.config({'alias':'<<'})%
<< " " << ${1}


//%snippet.set('interactive')%
ll counter = 0;
ll query(ll u, ll v){/*{{{*/
    dump('q', u+1, v+1);
    counter++;
    if (counter>n/2) assert(false);

    cout << "?" << " " << u << " " << v << endl;
    fflush(stdout);

    // ll res = tr.lca(u, v);
    ll res; cin>>res;

    return res;
}/*}}}*/

void ans(ll u){/*{{{*/
    cout << "!" << " " << u+1 << endl;
}/*}}}*/


//%snippet.set('pairsort')%
template<class T>
void pairsort(vector<T>& x, vector<T>& y){
    ll n = sz(x);
    vector<tuple<T, T>> t(n);
    rep(i, n){
        t[i] = make_tuple(x[i], y[i]);
    }
    sort(all(t));
    rep(i, n){
        x[i] = get<0>(t[i]);
        y[i] = get<1>(t[i]);
    }
}


//%snippet.set('make_vector')%
template<class T> vector<vector<vector<T>>> make_vector_2d(ll n1, ll n2, T init_value){
    return vector<vector<T>>(n1, vector<T>(n2, init_value));
}


template<class T> vector<vector<vector<T>>> make_vector_3d(ll n1, ll n2, ll n3, T init_value){
    return vector<vector<vector<T>>>(n1, vector<vector<T>>(n2, vector<T>(n3, init_value)));
}
// auto dp = make_vector_2d<mint>(n, k, 0);  // like ll dp[n][k];
// auto dp = make_vector_3d<mint>(n, k, m, 0);  // like ll dp[n][k][m];


//%snippet.set('erase_loop')%
for(auto iter=begin(s); iter!=end(s);){
    // 処理

    // 終了処理
    if (*iter%3==0 || *iter==1) {  // delete
        iter = s.erase(iter);
    }
    else{  // non-delete
        ++iter;
    }
}


//%snippet.set('erase_loop_reverse')%
for(auto riter=rbegin(s); riter!=rend(s);){
    // 処理

    // 終了処理
    if (*riter%3==0 || *riter==1) {
        auto iter = riter.base(); --iter; // iterに変換
        iter = s.erase(iter); // 要素を削除。これが終了した時点ではiterは削除要素の右を指している。
        riter = reverse_iterator(iter); // reverseすると左に１個進むのでちょうどよい。
    }
    else{
        riter++;
    }
}


//%snippet.set('get_rank')%
//%snippet.config({'alias':'rank'})%
vector<ll> get_rank(vector<ll>& score){
    ll n = sz(score);
    vector<pair<ll, ll>> tmp(n);
    rep(i, n) tmp[i] = mp(score[i], i);
    sort(all(tmp));

    vector<ll> rank(n);
    ll now = -1, last = -1;
    rep(i, n){
        auto [dist, idx] = tmp[i];
        if (last < dist) now = i;
        rank[idx] = now;
        last = dist;
    }
    return rank;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/misc/misc_snip.cpp"
//%snippet.set('cout')%
cout << ${0:TARGET} << endl;

//%snippet.set('couts')%
rep(i, sz(${1:x})) cout << $1[i] << (i!=sz($1)-1 ? " " : "\n");

//%snippet.set('?')%
(${1} ? ${2} : ${3})

//%snippet.set('inv')%
vector<ll> ${1}(n);
rep(i, n) {
    cin>>$1[i];
}
dump($1);${0}

//%snippet.set('invv')%
vector<vector<ll>> ${1}(h, vector<ll>(w));
rep(i, h){
    rep(j,w){
        cin>>$1[i][j];
    }
}

//%snippet.set('invvs')%
vector<vector<ll>> ${1}(h, vector<ll>(w));
rep(i, h){
    string tmp;cin>>tmp;
    rep(j,w){
        if (tmp[j]=='#') $1[i][j]=1;
        else             $1[i][j]=0; 
    }
}

//%snippet.set('rep')%
rep(${0}){
}

//%snippet.set('r_rep')%
r_rep(${0}){
}

//%snippet.set('for')%
for(ll i=0; i<n; i++){${0}
}

//%snippet.set('for_iter')%
for(auto iter=begin(${1}); iter!=end($1); ++iter){${0}
}

//%snippet.set('for_riter')%
for(auto riter=rbegin(${1}); riter!=rend($1); ++riter){${0}
}

//%snippet.set('if')%
if (${0}) {
}

//%snippet.set('else')%
else{${0}
}

//%snippet.set('elif')%
else if(${0}){
}

//%snippet.set('while')%
while(${0}){
}

//%snippet.set('reprep')%
rep(${1}) rep(${2}){${0}
}

//%snippet.set('d')%
dump(${0});

//%snippet.set('af')%
assert(false);

//%snippet.set('sortkey')%
sort(all(${0}), [&](auto &l, auto &r){return l.second < r.second;});

//%snippet.set('perm')%
vector<ll> p(n);
iota(all(p), 0LL);
do{
    dump(p);
    vector<ll> ma(a);
    rep(i, n) ma[i] = a[p[i]];
    dump(ma);
} while (next_permutation(all(p)));

//%snippet.set('to_bin')%
//%snippet.fold()%
string to_bin(ll n, ll d = 10){
    // nをd桁の2進数で表示する。
    stringstream ss;
    ss << bitset<64>(n);
    return ss.str().substr(64-d, d);
}
// ll d = (32 - __builtin_clz(n));  // 最大桁のd: (2^d)
// ll f = N - d; to_bin()で返ってきた文字列で最初に1が立っているindex

//%snippet.set('warsharll')%
// init
vector<vector<ll>> d(n, vector<ll>(n, INF));
rep(i, n)rep(j, n){
    if (i==j) d[i][j] = 0;
}

// input
${0};

// calc
rep(k, n){
    rep(i, n){
        rep(j, n){
            chmin(d[i][j], d[i][k]+d[k][j]);
        }
    }
}
dump_2d(d, n, n);


//%snippet.set('digitdp')%
ll n = sz(s);
vector<vector<ll>> dp(2, vector<ll>(n));
dp[0][0] = 1;
rep(i, 1, n+1){  //桁数
    rep(leq, 2){  //未満確定フラグ
        ll lim = leq ? 9 : s[i-1]-'0';
        rep(d, lim+1){
            dp[leq || d<lim][i] += dp[leq][i-1];
        }
    }
}


//%snippet.set('asv')%
// acumulative sum vector {{{
template<typename T>
struct asvector {
    vector<T> cum; //accumulative sum
    asvector(vector<T> a): cum(a){  // {{{  // constructor
        rep(i, 1, sz(a))  cum[i]+=cum[i-1];
    } // }}}

    T sum(ll l, ll r) {  // return sum of [l, r) of data.  {{{
        l = max(0LL, l);
        r = min(r, sz(cum));
        if (l<r){
            return cum[r-1] - (l-1>=0 ? cum[l-1] : 0);
        }
        else{
            return 0;
        }
    } // }}}

    T& operator[](ll i) { // {{{
        return cum[i]; 
    } // }}}

    friend ostream& operator<<(ostream &os, asvector<T>& as){//{{{
        os << as.cum; return os;
    } //}}}
};
//}}}


//%snippet.set('remove_leading_zeros')%
str.erase(0, min(str.find_first_not_of('0'), str.size()-1));


//%snippet.set('lambda')%
//%snippet.config({'alias':'f'})%
auto f = [&](){
};


//%snippet.set('dfs_lambda_graph')%
vector<ll> used(n);
auto dfs = [&](const auto& dfs, ll u) -> void {
    used[u] = 1;
    each(e, g[u]){
        if (used[e.to]) continue;
        dfs(dfs, e.to);
    }
};
dfs(dfs, 0);


//%snippet.set('dfs_lambda')%
auto dfs = [&](const auto& dfs, ll u) -> ll {
};


//%snippet.set('dxdy')%
ll dx[]={1, -1, 0, 0};
ll dy[]={0, 0, 1, -1};


//%snippet.set('ostream')%
ostream& operator<<(ostream& os, const ${1:type}& ${2}){
    os << ${3};
    return os;
}

//%snippet.set('query')%
ll query(){
    cerrendl;

    return 0;
}

signed main(){/*{{{*/
    ll Q;cin>>Q;
    rep(_, Q){
        query();
    }
    check_input();
    return 0;
}/*}}}*/


//%snippet.set('random_generator')%
uint64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<uint64_t>(0, -1)(x);
}


//%snippet.set('bitall')%
rep(s, 1<<n){
    rep(i, n){
        if(s>>i&1){
        }
        else{
        }
    }
}


//%snippet.set('print_float')%
printf("%.12f\n", ${1});


//%snippet.set('sep')%
//%snippet.config({'alias':'<<'})%
<< " " << ${1}


//%snippet.set('interactive')%
ll counter = 0;
ll query(ll u, ll v){/*{{{*/
    dump('q', u+1, v+1);
    counter++;
    if (counter>n/2) assert(false);

    cout << "?" << " " << u << " " << v << endl;
    fflush(stdout);

    // ll res = tr.lca(u, v);
    ll res; cin>>res;

    return res;
}/*}}}*/

void ans(ll u){/*{{{*/
    cout << "!" << " " << u+1 << endl;
}/*}}}*/


//%snippet.set('pairsort')%
template<class T>
void pairsort(vector<T>& x, vector<T>& y){
    ll n = sz(x);
    vector<tuple<T, T>> t(n);
    rep(i, n){
        t[i] = make_tuple(x[i], y[i]);
    }
    sort(all(t));
    rep(i, n){
        x[i] = get<0>(t[i]);
        y[i] = get<1>(t[i]);
    }
}


//%snippet.set('make_vector')%
template<class T> vector<vector<vector<T>>> make_vector_2d(ll n1, ll n2, T init_value){
    return vector<vector<T>>(n1, vector<T>(n2, init_value));
}


template<class T> vector<vector<vector<T>>> make_vector_3d(ll n1, ll n2, ll n3, T init_value){
    return vector<vector<vector<T>>>(n1, vector<vector<T>>(n2, vector<T>(n3, init_value)));
}
// auto dp = make_vector_2d<mint>(n, k, 0);  // like ll dp[n][k];
// auto dp = make_vector_3d<mint>(n, k, m, 0);  // like ll dp[n][k][m];


//%snippet.set('erase_loop')%
for(auto iter=begin(s); iter!=end(s);){
    // 処理

    // 終了処理
    if (*iter%3==0 || *iter==1) {  // delete
        iter = s.erase(iter);
    }
    else{  // non-delete
        ++iter;
    }
}


//%snippet.set('erase_loop_reverse')%
for(auto riter=rbegin(s); riter!=rend(s);){
    // 処理

    // 終了処理
    if (*riter%3==0 || *riter==1) {
        auto iter = riter.base(); --iter; // iterに変換
        iter = s.erase(iter); // 要素を削除。これが終了した時点ではiterは削除要素の右を指している。
        riter = reverse_iterator(iter); // reverseすると左に１個進むのでちょうどよい。
    }
    else{
        riter++;
    }
}


//%snippet.set('get_rank')%
//%snippet.config({'alias':'rank'})%
vector<ll> get_rank(vector<ll>& score){
    ll n = sz(score);
    vector<pair<ll, ll>> tmp(n);
    rep(i, n) tmp[i] = mp(score[i], i);
    sort(all(tmp));

    vector<ll> rank(n);
    ll now = -1, last = -1;
    rep(i, n){
        auto [dist, idx] = tmp[i];
        if (last < dist) now = i;
        rank[idx] = now;
        last = dist;
    }
    return rank;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

