//%snippet.set('cout')%
cout << ${0} << endl;

//%snippet.set('couts')%
rep(j, sz(${1:x})) cout << $1[j] << (j!=sz($1)-1 ? " " : "\n");

//%snippet.set('?')%
(${1} ? ${2} : ${3})

//%snippet.set('inv')%
vector<ll> ${1}(n);
rep(i, n) cin>>$1[i];
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
vector<vector<ll>> d(n, vector<ll>(n, inf<ll>));
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
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
int ni = i + dx[dir];
int nj = j + dy[dir];
if (0 <= ni && ni < h && 0 <= nj && nj < w) {
}


//%snippet.set('ostream')%
ostream& operator<<(ostream& os, const ${1:type}& ${2}){
    os << ${3};
    return os;
}

//%snippet.set('query')%
int query(){
    cerrendl;

    return 0;
}

int main(){/*{{{*/
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
rep(bit, 1<<n){
    rep(i, n){
        if(bit>>i&1){
        }
    }
}


//%snippet.set('subsum')%
//%snippet.config({'alias':'bit_subsum'})%
template<class T>
vector<T> subsum(const vector<T>& v) {
    // O(2^N) faster than naive bit all search
    // return sorted vector
    int n = v.size();
    vector<T> ret;
    vector<T> t1, t2;
    ret.emplace_back(0);
    for (auto e : v) {
        t1.clear();
        for (auto p : ret) {
            t1.emplace_back(e + p);
        }
        t2 = ret;
        ret.clear();
        merge(t1.begin(), t1.end(), t2.begin(), t2.end(), back_inserter(ret));
    }
    return ret;
};


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
//%snippet.fold()%
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


//%snippet.set('encode')%
//%snippet.config({'alias':'id'})%
//%snippet.config({'alias':'nid'})%
auto nid = [&](int i, int j){return (i*w + j);}; // int u = nid(i, j);
auto pos = [&](int idx) -> pair<int, int> { return {idx/w, idx%w}; }; // auto [i,j] = pos(u);
// auto nid = [&](int i, int j, int k){return (i*(y*z) + j*(z) + k);};
// auto pos = [&](int idx) -> tuple<int, int, int> { return {idx/(y*z), (idx/z)%y, idx%z}; };


//%snippet.set('atcoder')%
//%snippet.config({'alias':'acl'})%
// {{{ include acl-library
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>
// using namespace atcoder;
// }}}


//%snippet.set('syuuki')%
ll P = 100000; // mod
auto nxt = [&](ll x){
    return (x + digitSum(x))%P;
};

vec<ll> last(P, -1);
last[n] = 0;
ll d; // 周期
ll x = n;
rep(i, 1, P+1){
    x = nxt(x);
    if (last[x]==-1) last[x] = i;
    else {
        d = i - last[x];  // 周期
        if (k>i) k = i+(k-i)%d;
        break;
    }
}
while(k--) n = nxt(n);

