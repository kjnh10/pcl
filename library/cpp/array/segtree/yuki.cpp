#include <bits/stdc++.h>
#define rep(i, a, b) for (ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for (ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

const ll MOD = 1000000007;
const int MAX_N = 1 << 17;  // nの2倍くらい
const ll INF = (1LL << 31) - 1;
// RSQ&RAQ
/*
struct LazySegmentTree{
    ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:nを２べきにしたもの

    //初期化
    void init(int n_){
        //要素数を2べきに
        SIZE=1;
        while(SIZE<n_) SIZE*=2;

        //全ての値をI_MAXに
        rep(i,0,2*SIZE-1) node[i]=0;
    }

    //k番目のノードについて遅延評価を行う
    void eval(int k, int l, int r){
        // 遅延配列が空でない場合、自ノード及び子ノードへの値の伝播が起こる
        if(lazy[k]!=0){
            node[k]+=lazy[k];
            // 最下段かどうかのチェックをしよう
            if(r-l>1){
                lazy[2*k+1]+=lazy[k]/2;
                lazy[2*k+2]+=lazy[k]/2;
            }
            // 伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k]=node[2*k+1]+node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        if(b <= l || r <= a) return 0;
        eval(k,l,r);
        if(a <= l && r <= b) return node[k];
        ll vl=getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr=getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl+vr;
    }
};
*/

// RMQ&RUQ
/*
struct LazySegmentTree{
    ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:nを２べきにしたもの
    bool lazyflag[2*MAX_N-1];

    //初期化
    void init(int n_){
        //要素数を2べきに
        SIZE=1;
        while(SIZE<n_) SIZE*=2;

        //全ての値をI_MAXに
        rep(i,0,2*SIZE-1) node[i]=INF;
    }

    //k番目のノードについて遅延評価を行う
    void eval(int k, int l, int r){
        // 遅延配列が空でない場合、自ノード及び子ノードへの値の伝播が起こる
        if(lazyflag[k]){
            node[k]=lazy[k];
            // 最下段かどうかのチェックをしよう
            if(r-l>1){
                lazy[k*2+1] = lazy[k*2+2] = lazy[k];
                lazyflag[k*2+1] = lazyflag[k*2+2] = true;
            }
            lazyflag[k] = false;
        }
    }

    void update(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyflag[k]=true;
            eval(k, l, r);
        }
        else{
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k]=min(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl=getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr=getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};*/

// RMQ&RAQ
/*
struct LazySegmentTree{
    ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:nを２べきにしたもの
    bool lazyflag[2*MAX_N-1];
    //初期化
    void init(int n_){
        //要素数を2べきに
        SIZE=1;
        while(SIZE<n_) SIZE*=2;

        //全ての値をI_MAXに
        rep(i,0,2*SIZE-1) node[i]=0;
    }

    //k番目のノードについて遅延評価を行う
    void eval(int k, int l, int r){
        // 遅延配列が空でない場合、自ノード及び子ノードへの値の伝播が起こる
        if(lazyflag[k]){
            node[k]+=lazy[k];
            // 最下段かどうかのチェックをしよう
            if(r-l>1){
                lazy[k*2+1] += lazy[k];
                lazy[k*2+2] += lazy[k];
                lazyflag[k*2+1] = lazyflag[k*2+2] = true;
            }
            lazyflag[k] = false;
            lazy[k]=0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            lazyflag[k]=true;
            eval(k, l, r);
        }
        else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k]=min(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl=getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr=getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};*/

// RSQ&RUQ
struct LazySegmentTree {
    ll node[2 * MAX_N - 1], lazy[2 * MAX_N - 1],
        SIZE;  // SIZE:nを２べきにしたもの
    bool lazyflag[2 * MAX_N - 1];

    //初期化
    void init(int n_) {
        //要素数を2べきに
        SIZE = 1;
        while (SIZE < n_) SIZE *= 2;

        //全ての値をI_MAXに
        rep(i, 0, 2 * SIZE - 1) node[i] = 0;
    }

    // k番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {
        // 遅延配列が空でない場合、自ノード及び子ノードへの値の伝播が起こる
        if (lazyflag[k]) {
            node[k] = (r - l) * lazy[k];
            // 最下段かどうかのチェックをしよう
            if (r - l > 1) {
                lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
                lazyflag[k * 2 + 1] = lazyflag[k * 2 + 2] = true;
            }
            lazyflag[k] = false;
        }
    }

    void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = SIZE;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            lazyflag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = SIZE;
        eval(k, l, r);
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

LazySegmentTree S;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    S.init(n);
    rep(i, 0, q) {
        int b;
        cin >> b;
        if (b) {
            int s, t;
            cin >> s >> t;
            cout << S.getsum(s, t + 1) << "\n";
        } else {
            int s, t;
            cin >> s >> t;
            ll x;
            cin >> x;
            S.update(s, t + 1, x);
        }
    }
}
