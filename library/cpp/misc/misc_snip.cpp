//%snippet.set('cout')%
cout << ${0:TARGET} << endl;

//%snippet.set('couts')%
rep(i, sz(${1:x})) cout << $1[i] << (i!=sz($1)-1 ? " " : "\n");

//%snippet.set('?')%
(${1} ? ${2} : ${3})

//%snippet.set('inv')%
vector<int> ${1}(n);
rep(i, n) {
    cin>>$1[i];
}
dump($1);${0}

//%snippet.set('invv')%
vector<vector<int>> ${1}(h, vector<int>(w));
rep(i, h){
    rep(j,w){
        cin>>$1[i][j];
    }
}

//%snippet.set('invvs')%
vector<vector<int>> ${1}(h, vector<int>(w));
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
for(int i=0; i<n; i++){${0}
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
vi p(n);
iota(all(p), 0LL);
do{
    dump(p);
    vi ma(a);
    rep(i, n) ma[i] = a[p[i]];
    dump(ma);
} while (next_permutation(all(p)));

//%snippet.set('to_bin')%
#define N 61
string to_bin(int n, int d){
    // nをd桁の2進数で表示する。
    stringstream ss;
    ss << bitset<N>(n);
    return ss.str().substr(N-d, d);
}
// int d = (32 - __builtin_clz(n));  // 最大桁のd: (2^d)
// int f = N - d; to_bin()で返ってきた文字列で最初に1が立っているindex

//%snippet.set('warsharll')%
// init
vector<vector<int>> d(n, vector<int>(n, INF));
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
int n = sz(s);
vector<vector<int>> dp(2, vector<int>(n));
dp[0][0] = 1;
rep(i, 1, n+1){  //桁数
    rep(leq, 2){  //未満確定フラグ
        int lim = leq ? 9 : s[i-1]-'0';
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

    T sum(int l, int r) {  // return sum of [l, r) of data.  {{{
        l = max(0LL, l);
        r = min(r, sz(cum));
        if (l<r){
            return cum[r-1] - (l-1>=0 ? cum[l-1] : 0);
        }
        else{
            return 0;
        }
    } // }}}

    T& operator[](int i) { // {{{
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
vector<int> used(n);
auto dfs = [&](const auto& dfs, int u) -> void {
    used[u] = 1;
    each(e, g[u]){
        if (used[e.to]) continue;
        dfs(dfs, e.to);
    }
};
dfs(dfs, 0);


//%snippet.set('dfs_lambda')%
auto dfs = [&](const auto& dfs, int u) -> int {
};


//%snippet.set('dxdy')%
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};


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

signed main(){
    int Q;cin>>Q;
    rep(_, Q){
        query();
    }
    check_input();
    return 0;
}


//%snippet.set('random_generator')%
uint64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<uint64_t>(0, -1)(x);
}


//%snippet.set('bitall')%
rep(mask, 1<<n){
    cerrendl;
    vi vmask(n); rep(i, n){ if (mask&(1<<i)) vmask[i] = 1; } dump(vmask);
    rep(i, n){
        if (vmask[i]){
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
int counter = 0;
int query(int u, int v){/*{{{*/
    dump('q', u+1, v+1);
    counter++;
    if (counter>n/2) assert(false);

    cout << "?" << " " << u << " " << v << endl;
    fflush(stdout);

    // int res = tr.lca(u, v);
    int res; cin>>res;

    return res;
}/*}}}*/

void ans(int u){/*{{{*/
    cout << "!" << " " << u+1 << endl;
}/*}}}*/


//%snippet.set('pairsort')%
template<class T>
void pairsort(vector<T>& x, vector<T>& y){
    int n = sz(x);
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
template<class T> vector<vector<vector<T>>> make_vector_2d(int n1, int n2, T init_value){
    return vector<vector<T>>(n1, vector<T>(n2, init_value));
}


template<class T> vector<vector<vector<T>>> make_vector_3d(int n1, int n2, int n3, T init_value){
    return vector<vector<vector<T>>>(n1, vector<vector<T>>(n2, vector<T>(n3, init_value)));
}
// auto dp = make_vector_2d<mint>(n, k, 0);  // like int dp[n][k];
// auto dp = make_vector_3d<mint>(n, k, m, 0);  // like int dp[n][k][m];


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