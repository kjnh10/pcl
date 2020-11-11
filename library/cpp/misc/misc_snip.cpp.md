---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/misc/misc_snip.cpp\"\n//%snippet.set('cout')%\n\
    cout << ${0} << endl;\n\n//%snippet.set('couts')%\nrep(i, sz(${1:x})) cout <<\
    \ $1[i] << (i!=sz($1)-1 ? \" \" : \"\\n\");\n\n//%snippet.set('?')%\n(${1} ? ${2}\
    \ : ${3})\n\n//%snippet.set('inv')%\nvector<ll> ${1}(n);\nrep(i, n) cin>>$1[i];\n\
    dump($1);${0}\n\n//%snippet.set('invv')%\nvector<vector<ll>> ${1}(h, vector<ll>(w));\n\
    rep(i, h){\n    rep(j,w){\n        cin>>$1[i][j];\n    }\n}\n\n//%snippet.set('invvs')%\n\
    vector<vector<ll>> ${1}(h, vector<ll>(w));\nrep(i, h){\n    string tmp;cin>>tmp;\n\
    \    rep(j,w){\n        if (tmp[j]=='#') $1[i][j]=1;\n        else           \
    \  $1[i][j]=0; \n    }\n}\n\n//%snippet.set('rep')%\nrep(${0}){\n}\n\n//%snippet.set('r_rep')%\n\
    r_rep(${0}){\n}\n\n//%snippet.set('for')%\nfor(ll i=0; i<n; i++){${0}\n}\n\n//%snippet.set('for_iter')%\n\
    for(auto iter=begin(${1}); iter!=end($1); ++iter){${0}\n}\n\n//%snippet.set('for_riter')%\n\
    for(auto riter=rbegin(${1}); riter!=rend($1); ++riter){${0}\n}\n\n//%snippet.set('if')%\n\
    if (${0}) {\n}\n\n//%snippet.set('else')%\nelse{${0}\n}\n\n//%snippet.set('elif')%\n\
    else if(${0}){\n}\n\n//%snippet.set('while')%\nwhile(${0}){\n}\n\n//%snippet.set('reprep')%\n\
    rep(${1}) rep(${2}){${0}\n}\n\n//%snippet.set('d')%\ndump(${0});\n\n//%snippet.set('af')%\n\
    assert(false);\n\n//%snippet.set('sortkey')%\nsort(all(${0}), [&](auto &l, auto\
    \ &r){return l.second < r.second;});\n\n//%snippet.set('perm')%\nvector<ll> p(n);\n\
    iota(all(p), 0LL);\ndo{\n    dump(p);\n    vector<ll> ma(a);\n    rep(i, n) ma[i]\
    \ = a[p[i]];\n    dump(ma);\n} while (next_permutation(all(p)));\n\n//%snippet.set('to_bin')%\n\
    //%snippet.fold()%\nstring to_bin(ll n, ll d = 10){\n    // n\u3092d\u6841\u306E\
    2\u9032\u6570\u3067\u8868\u793A\u3059\u308B\u3002\n    stringstream ss;\n    ss\
    \ << bitset<64>(n);\n    return ss.str().substr(64-d, d);\n}\n// ll d = (32 -\
    \ __builtin_clz(n));  // \u6700\u5927\u6841\u306Ed: (2^d)\n// ll f = N - d; to_bin()\u3067\
    \u8FD4\u3063\u3066\u304D\u305F\u6587\u5B57\u5217\u3067\u6700\u521D\u306B1\u304C\
    \u7ACB\u3063\u3066\u3044\u308Bindex\n\n//%snippet.set('warsharll')%\n// init\n\
    vector<vector<ll>> d(n, vector<ll>(n, inf<ll>));\nrep(i, n)rep(j, n){\n    if\
    \ (i==j) d[i][j] = 0;\n}\n\n// input\n${0};\n\n// calc\nrep(k, n){\n    rep(i,\
    \ n){\n        rep(j, n){\n            chmin(d[i][j], d[i][k]+d[k][j]);\n    \
    \    }\n    }\n}\ndump_2d(d, n, n);\n\n\n//%snippet.set('digitdp')%\nll n = sz(s);\n\
    vector<vector<ll>> dp(2, vector<ll>(n));\ndp[0][0] = 1;\nrep(i, 1, n+1){  //\u6841\
    \u6570\n    rep(leq, 2){  //\u672A\u6E80\u78BA\u5B9A\u30D5\u30E9\u30B0\n     \
    \   ll lim = leq ? 9 : s[i-1]-'0';\n        rep(d, lim+1){\n            dp[leq\
    \ || d<lim][i] += dp[leq][i-1];\n        }\n    }\n}\n\n\n//%snippet.set('remove_leading_zeros')%\n\
    str.erase(0, min(str.find_first_not_of('0'), str.size()-1));\n\n\n//%snippet.set('lambda')%\n\
    //%snippet.config({'alias':'f'})%\nauto f = [&](){\n};\n\n\n//%snippet.set('dfs_lambda_graph')%\n\
    vector<ll> used(n);\nauto dfs = [&](const auto& dfs, ll u) -> void {\n    used[u]\
    \ = 1;\n    each(e, g[u]){\n        if (used[e.to]) continue;\n        dfs(dfs,\
    \ e.to);\n    }\n};\ndfs(dfs, 0);\n\n\n//%snippet.set('dfs_lambda')%\nauto dfs\
    \ = [&](const auto& dfs, ll u) -> ll {\n};\n\n\n//%snippet.set('dxdy')%\nll dx[]={1,\
    \ -1, 0, 0};\nll dy[]={0, 0, 1, -1};\n\n\n//%snippet.set('ostream')%\nostream&\
    \ operator<<(ostream& os, const ${1:type}& ${2}){\n    os << ${3};\n    return\
    \ os;\n}\n\n//%snippet.set('query')%\nint query(){\n    cerrendl;\n\n    return\
    \ 0;\n}\n\nint main(){/*{{{*/\n    ll Q;cin>>Q;\n    rep(_, Q){\n        query();\n\
    \    }\n    check_input();\n    return 0;\n}/*}}}*/\n\n\n//%snippet.set('random_generator')%\n\
    uint64_t rng() {\n    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<uint64_t>(0, -1)(x);\n}\n\n\n//%snippet.set('bitall')%\n\
    rep(s, 1<<n){\n    rep(i, n){\n        if(s>>i&1){\n        }\n        else{\n\
    \        }\n    }\n}\n\n\n//%snippet.set('print_float')%\nprintf(\"%.12f\\n\"\
    , ${1});\n\n\n//%snippet.set('sep')%\n//%snippet.config({'alias':'<<'})%\n<< \"\
    \ \" << ${1}\n\n\n//%snippet.set('interactive')%\nll counter = 0;\nll query(ll\
    \ u, ll v){/*{{{*/\n    dump('q', u+1, v+1);\n    counter++;\n    if (counter>n/2)\
    \ assert(false);\n\n    cout << \"?\" << \" \" << u << \" \" << v << endl;\n \
    \   fflush(stdout);\n\n    // ll res = tr.lca(u, v);\n    ll res; cin>>res;\n\n\
    \    return res;\n}/*}}}*/\n\nvoid ans(ll u){/*{{{*/\n    cout << \"!\" << \"\
    \ \" << u+1 << endl;\n}/*}}}*/\n\n\n//%snippet.set('pairsort')%\n//%snippet.fold()%\n\
    template<class T>\nvoid pairsort(vector<T>& x, vector<T>& y){\n    ll n = sz(x);\n\
    \    vector<tuple<T, T>> t(n);\n    rep(i, n){\n        t[i] = make_tuple(x[i],\
    \ y[i]);\n    }\n    sort(all(t));\n    rep(i, n){\n        x[i] = get<0>(t[i]);\n\
    \        y[i] = get<1>(t[i]);\n    }\n}\n\n\n//%snippet.set('make_vector')%\n\
    template<class T> vector<vector<vector<T>>> make_vector_2d(ll n1, ll n2, T init_value){\n\
    \    return vector<vector<T>>(n1, vector<T>(n2, init_value));\n}\n\n\ntemplate<class\
    \ T> vector<vector<vector<T>>> make_vector_3d(ll n1, ll n2, ll n3, T init_value){\n\
    \    return vector<vector<vector<T>>>(n1, vector<vector<T>>(n2, vector<T>(n3,\
    \ init_value)));\n}\n// auto dp = make_vector_2d<mint>(n, k, 0);  // like ll dp[n][k];\n\
    // auto dp = make_vector_3d<mint>(n, k, m, 0);  // like ll dp[n][k][m];\n\n\n\
    //%snippet.set('erase_loop')%\nfor(auto iter=begin(s); iter!=end(s);){\n    //\
    \ \u51E6\u7406\n\n    // \u7D42\u4E86\u51E6\u7406\n    if (*iter%3==0 || *iter==1)\
    \ {  // delete\n        iter = s.erase(iter);\n    }\n    else{  // non-delete\n\
    \        ++iter;\n    }\n}\n\n\n//%snippet.set('erase_loop_reverse')%\nfor(auto\
    \ riter=rbegin(s); riter!=rend(s);){\n    // \u51E6\u7406\n\n    // \u7D42\u4E86\
    \u51E6\u7406\n    if (*riter%3==0 || *riter==1) {\n        auto iter = riter.base();\
    \ --iter; // iter\u306B\u5909\u63DB\n        iter = s.erase(iter); // \u8981\u7D20\
    \u3092\u524A\u9664\u3002\u3053\u308C\u304C\u7D42\u4E86\u3057\u305F\u6642\u70B9\
    \u3067\u306Fiter\u306F\u524A\u9664\u8981\u7D20\u306E\u53F3\u3092\u6307\u3057\u3066\
    \u3044\u308B\u3002\n        riter = reverse_iterator(iter); // reverse\u3059\u308B\
    \u3068\u5DE6\u306B\uFF11\u500B\u9032\u3080\u306E\u3067\u3061\u3087\u3046\u3069\
    \u3088\u3044\u3002\n    }\n    else{\n        riter++;\n    }\n}\n\n\n//%snippet.set('get_rank')%\n\
    //%snippet.config({'alias':'rank'})%\nvector<ll> get_rank(vector<ll>& score){\n\
    \    ll n = sz(score);\n    vector<pair<ll, ll>> tmp(n);\n    rep(i, n) tmp[i]\
    \ = mp(score[i], i);\n    sort(all(tmp));\n\n    vector<ll> rank(n);\n    ll now\
    \ = -1, last = -1;\n    rep(i, n){\n        auto [dist, idx] = tmp[i];\n     \
    \   if (last < dist) now = i;\n        rank[idx] = now;\n        last = dist;\n\
    \    }\n    return rank;\n}\n\n\n//%snippet.set('encode')%\n//%snippet.config({'alias':'id'})%\n\
    //%snippet.config({'alias':'nid'})%\nauto nid = [&](int i, int j){return (i*w\
    \ + j);}; // int u = nid(i, j);\nauto pos = [&](int idx) -> pair<int, int> { return\
    \ {idx/w, idx%w}; }; // auto [i,j] = pos(u);\n// auto nid = [&](int i, int j,\
    \ int k){return (i*(y*z) + j*(z) + k);};\n// auto pos = [&](int idx) -> pair<int,\
    \ int> { return {idx/(y*z), (idx/z)%y, idx%z}; };\n\n\n//%snippet.set('atcoder')%\n\
    //%snippet.config({'alias':'acl'})%\n// {{{ include acl-library\n// #include <atcoder/fenwicktree>\n\
    // #include <atcoder/segtree>\n// #include <atcoder/lazysegtree>\n// #include\
    \ <atcoder/string>\n// #include <atcoder/math>\n// #include <atcoder/convolution>\n\
    // #include <atcoder/modint>\n// #include <atcoder/dsu>\n// #include <atcoder/maxflow>\n\
    // #include <atcoder/mincostflow>\n// #include <atcoder/scc>\n// #include <atcoder/twosat>\n\
    // using namespace atcoder;\n// }}}\n"
  code: "//%snippet.set('cout')%\ncout << ${0} << endl;\n\n//%snippet.set('couts')%\n\
    rep(i, sz(${1:x})) cout << $1[i] << (i!=sz($1)-1 ? \" \" : \"\\n\");\n\n//%snippet.set('?')%\n\
    (${1} ? ${2} : ${3})\n\n//%snippet.set('inv')%\nvector<ll> ${1}(n);\nrep(i, n)\
    \ cin>>$1[i];\ndump($1);${0}\n\n//%snippet.set('invv')%\nvector<vector<ll>> ${1}(h,\
    \ vector<ll>(w));\nrep(i, h){\n    rep(j,w){\n        cin>>$1[i][j];\n    }\n\
    }\n\n//%snippet.set('invvs')%\nvector<vector<ll>> ${1}(h, vector<ll>(w));\nrep(i,\
    \ h){\n    string tmp;cin>>tmp;\n    rep(j,w){\n        if (tmp[j]=='#') $1[i][j]=1;\n\
    \        else             $1[i][j]=0; \n    }\n}\n\n//%snippet.set('rep')%\nrep(${0}){\n\
    }\n\n//%snippet.set('r_rep')%\nr_rep(${0}){\n}\n\n//%snippet.set('for')%\nfor(ll\
    \ i=0; i<n; i++){${0}\n}\n\n//%snippet.set('for_iter')%\nfor(auto iter=begin(${1});\
    \ iter!=end($1); ++iter){${0}\n}\n\n//%snippet.set('for_riter')%\nfor(auto riter=rbegin(${1});\
    \ riter!=rend($1); ++riter){${0}\n}\n\n//%snippet.set('if')%\nif (${0}) {\n}\n\
    \n//%snippet.set('else')%\nelse{${0}\n}\n\n//%snippet.set('elif')%\nelse if(${0}){\n\
    }\n\n//%snippet.set('while')%\nwhile(${0}){\n}\n\n//%snippet.set('reprep')%\n\
    rep(${1}) rep(${2}){${0}\n}\n\n//%snippet.set('d')%\ndump(${0});\n\n//%snippet.set('af')%\n\
    assert(false);\n\n//%snippet.set('sortkey')%\nsort(all(${0}), [&](auto &l, auto\
    \ &r){return l.second < r.second;});\n\n//%snippet.set('perm')%\nvector<ll> p(n);\n\
    iota(all(p), 0LL);\ndo{\n    dump(p);\n    vector<ll> ma(a);\n    rep(i, n) ma[i]\
    \ = a[p[i]];\n    dump(ma);\n} while (next_permutation(all(p)));\n\n//%snippet.set('to_bin')%\n\
    //%snippet.fold()%\nstring to_bin(ll n, ll d = 10){\n    // n\u3092d\u6841\u306E\
    2\u9032\u6570\u3067\u8868\u793A\u3059\u308B\u3002\n    stringstream ss;\n    ss\
    \ << bitset<64>(n);\n    return ss.str().substr(64-d, d);\n}\n// ll d = (32 -\
    \ __builtin_clz(n));  // \u6700\u5927\u6841\u306Ed: (2^d)\n// ll f = N - d; to_bin()\u3067\
    \u8FD4\u3063\u3066\u304D\u305F\u6587\u5B57\u5217\u3067\u6700\u521D\u306B1\u304C\
    \u7ACB\u3063\u3066\u3044\u308Bindex\n\n//%snippet.set('warsharll')%\n// init\n\
    vector<vector<ll>> d(n, vector<ll>(n, inf<ll>));\nrep(i, n)rep(j, n){\n    if\
    \ (i==j) d[i][j] = 0;\n}\n\n// input\n${0};\n\n// calc\nrep(k, n){\n    rep(i,\
    \ n){\n        rep(j, n){\n            chmin(d[i][j], d[i][k]+d[k][j]);\n    \
    \    }\n    }\n}\ndump_2d(d, n, n);\n\n\n//%snippet.set('digitdp')%\nll n = sz(s);\n\
    vector<vector<ll>> dp(2, vector<ll>(n));\ndp[0][0] = 1;\nrep(i, 1, n+1){  //\u6841\
    \u6570\n    rep(leq, 2){  //\u672A\u6E80\u78BA\u5B9A\u30D5\u30E9\u30B0\n     \
    \   ll lim = leq ? 9 : s[i-1]-'0';\n        rep(d, lim+1){\n            dp[leq\
    \ || d<lim][i] += dp[leq][i-1];\n        }\n    }\n}\n\n\n//%snippet.set('remove_leading_zeros')%\n\
    str.erase(0, min(str.find_first_not_of('0'), str.size()-1));\n\n\n//%snippet.set('lambda')%\n\
    //%snippet.config({'alias':'f'})%\nauto f = [&](){\n};\n\n\n//%snippet.set('dfs_lambda_graph')%\n\
    vector<ll> used(n);\nauto dfs = [&](const auto& dfs, ll u) -> void {\n    used[u]\
    \ = 1;\n    each(e, g[u]){\n        if (used[e.to]) continue;\n        dfs(dfs,\
    \ e.to);\n    }\n};\ndfs(dfs, 0);\n\n\n//%snippet.set('dfs_lambda')%\nauto dfs\
    \ = [&](const auto& dfs, ll u) -> ll {\n};\n\n\n//%snippet.set('dxdy')%\nll dx[]={1,\
    \ -1, 0, 0};\nll dy[]={0, 0, 1, -1};\n\n\n//%snippet.set('ostream')%\nostream&\
    \ operator<<(ostream& os, const ${1:type}& ${2}){\n    os << ${3};\n    return\
    \ os;\n}\n\n//%snippet.set('query')%\nint query(){\n    cerrendl;\n\n    return\
    \ 0;\n}\n\nint main(){/*{{{*/\n    ll Q;cin>>Q;\n    rep(_, Q){\n        query();\n\
    \    }\n    check_input();\n    return 0;\n}/*}}}*/\n\n\n//%snippet.set('random_generator')%\n\
    uint64_t rng() {\n    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<uint64_t>(0, -1)(x);\n}\n\n\n//%snippet.set('bitall')%\n\
    rep(s, 1<<n){\n    rep(i, n){\n        if(s>>i&1){\n        }\n        else{\n\
    \        }\n    }\n}\n\n\n//%snippet.set('print_float')%\nprintf(\"%.12f\\n\"\
    , ${1});\n\n\n//%snippet.set('sep')%\n//%snippet.config({'alias':'<<'})%\n<< \"\
    \ \" << ${1}\n\n\n//%snippet.set('interactive')%\nll counter = 0;\nll query(ll\
    \ u, ll v){/*{{{*/\n    dump('q', u+1, v+1);\n    counter++;\n    if (counter>n/2)\
    \ assert(false);\n\n    cout << \"?\" << \" \" << u << \" \" << v << endl;\n \
    \   fflush(stdout);\n\n    // ll res = tr.lca(u, v);\n    ll res; cin>>res;\n\n\
    \    return res;\n}/*}}}*/\n\nvoid ans(ll u){/*{{{*/\n    cout << \"!\" << \"\
    \ \" << u+1 << endl;\n}/*}}}*/\n\n\n//%snippet.set('pairsort')%\n//%snippet.fold()%\n\
    template<class T>\nvoid pairsort(vector<T>& x, vector<T>& y){\n    ll n = sz(x);\n\
    \    vector<tuple<T, T>> t(n);\n    rep(i, n){\n        t[i] = make_tuple(x[i],\
    \ y[i]);\n    }\n    sort(all(t));\n    rep(i, n){\n        x[i] = get<0>(t[i]);\n\
    \        y[i] = get<1>(t[i]);\n    }\n}\n\n\n//%snippet.set('make_vector')%\n\
    template<class T> vector<vector<vector<T>>> make_vector_2d(ll n1, ll n2, T init_value){\n\
    \    return vector<vector<T>>(n1, vector<T>(n2, init_value));\n}\n\n\ntemplate<class\
    \ T> vector<vector<vector<T>>> make_vector_3d(ll n1, ll n2, ll n3, T init_value){\n\
    \    return vector<vector<vector<T>>>(n1, vector<vector<T>>(n2, vector<T>(n3,\
    \ init_value)));\n}\n// auto dp = make_vector_2d<mint>(n, k, 0);  // like ll dp[n][k];\n\
    // auto dp = make_vector_3d<mint>(n, k, m, 0);  // like ll dp[n][k][m];\n\n\n\
    //%snippet.set('erase_loop')%\nfor(auto iter=begin(s); iter!=end(s);){\n    //\
    \ \u51E6\u7406\n\n    // \u7D42\u4E86\u51E6\u7406\n    if (*iter%3==0 || *iter==1)\
    \ {  // delete\n        iter = s.erase(iter);\n    }\n    else{  // non-delete\n\
    \        ++iter;\n    }\n}\n\n\n//%snippet.set('erase_loop_reverse')%\nfor(auto\
    \ riter=rbegin(s); riter!=rend(s);){\n    // \u51E6\u7406\n\n    // \u7D42\u4E86\
    \u51E6\u7406\n    if (*riter%3==0 || *riter==1) {\n        auto iter = riter.base();\
    \ --iter; // iter\u306B\u5909\u63DB\n        iter = s.erase(iter); // \u8981\u7D20\
    \u3092\u524A\u9664\u3002\u3053\u308C\u304C\u7D42\u4E86\u3057\u305F\u6642\u70B9\
    \u3067\u306Fiter\u306F\u524A\u9664\u8981\u7D20\u306E\u53F3\u3092\u6307\u3057\u3066\
    \u3044\u308B\u3002\n        riter = reverse_iterator(iter); // reverse\u3059\u308B\
    \u3068\u5DE6\u306B\uFF11\u500B\u9032\u3080\u306E\u3067\u3061\u3087\u3046\u3069\
    \u3088\u3044\u3002\n    }\n    else{\n        riter++;\n    }\n}\n\n\n//%snippet.set('get_rank')%\n\
    //%snippet.config({'alias':'rank'})%\nvector<ll> get_rank(vector<ll>& score){\n\
    \    ll n = sz(score);\n    vector<pair<ll, ll>> tmp(n);\n    rep(i, n) tmp[i]\
    \ = mp(score[i], i);\n    sort(all(tmp));\n\n    vector<ll> rank(n);\n    ll now\
    \ = -1, last = -1;\n    rep(i, n){\n        auto [dist, idx] = tmp[i];\n     \
    \   if (last < dist) now = i;\n        rank[idx] = now;\n        last = dist;\n\
    \    }\n    return rank;\n}\n\n\n//%snippet.set('encode')%\n//%snippet.config({'alias':'id'})%\n\
    //%snippet.config({'alias':'nid'})%\nauto nid = [&](int i, int j){return (i*w\
    \ + j);}; // int u = nid(i, j);\nauto pos = [&](int idx) -> pair<int, int> { return\
    \ {idx/w, idx%w}; }; // auto [i,j] = pos(u);\n// auto nid = [&](int i, int j,\
    \ int k){return (i*(y*z) + j*(z) + k);};\n// auto pos = [&](int idx) -> pair<int,\
    \ int> { return {idx/(y*z), (idx/z)%y, idx%z}; };\n\n\n//%snippet.set('atcoder')%\n\
    //%snippet.config({'alias':'acl'})%\n// {{{ include acl-library\n// #include <atcoder/fenwicktree>\n\
    // #include <atcoder/segtree>\n// #include <atcoder/lazysegtree>\n// #include\
    \ <atcoder/string>\n// #include <atcoder/math>\n// #include <atcoder/convolution>\n\
    // #include <atcoder/modint>\n// #include <atcoder/dsu>\n// #include <atcoder/maxflow>\n\
    // #include <atcoder/mincostflow>\n// #include <atcoder/scc>\n// #include <atcoder/twosat>\n\
    // using namespace atcoder;\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/misc/misc_snip.cpp
  requiredBy: []
  timestamp: '2020-11-11 19:32:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/misc/misc_snip.cpp
layout: document
redirect_from:
- /library/library/cpp/misc/misc_snip.cpp
- /library/library/cpp/misc/misc_snip.cpp.html
title: library/cpp/misc/misc_snip.cpp
---
