#include "header.hpp"
template<class T=ll> using vec = vector<T>;
struct Fast { Fast() { std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

template <typename X, typename M>
struct segment_tree_lazy {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using index = int;
    int n;  // 元の配列のサイズ
    int N;  // n以上の最小の2冪
    FX merge;
    FA apply;
    FM composite;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    segment_tree_lazy(FX merge_, FA apply_, FM composite_, X ex_, M em_)
        : merge(merge_), apply(apply_), composite(composite_), ex(ex_), em(em_) {
    }

    void set(index i, X x) { dat[i + n - 1] = x; }
    void init(index n_) { 
        N = 1;
        n = n_;
        while (N < n_) N <<= 1;
        dat.assign(2 * N, ex);
        lazy.assign(2 * N, em);
    } 

    void build(const vector<X> &v) { 
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++) dat[i + N - 1] = v[i];
        for (int k = N - 2; k >= 0; k--) dat[k] = merge(dat[2 * k + 1], dat[2 * k + 2]);
    } 

    /* lazy propagate */
    void propagate(int k) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < N - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = composite(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = composite(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = apply(dat[k], lazy[k]);
        lazy[k] = em;
    }

    void update(index a, index b, M x) { update(a, b, x, 0, 0, N); }
    void update(index a, index b, M x, int k, index l, index r) {
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = composite(lazy[k], x);
            propagate(k);
        }
        else if (a < r && l < b) {                     // 一部区間が被る時
            propagate(k);
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
        else{
            propagate(k);
        }
    }

    X query(index a, index b) { return query_sub(a, b, 0, 0, N); }
    X query_sub(index a, index b, int k, index l, index r) {
        propagate(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        }
        else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        }
        else {  // 一部区間が被る時
            X lv = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X rv = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return merge(lv, rv);
        }
    }

    index find_most_left(index l, const function<bool(X)>& is_ok){
        // lから右に探していってis_okが初めて成り立つようなindexを返す。
        // assume query(l, *) has monotonity
        // return index i s.t is_ok(query(l, i)) does not holds, but is_ok(query(l, i+1)) does.
        // if such i does not exist, return n
        index res = _find_most_left(l, is_ok, 0, 0, N, ex).first;
        assert(l <= res);
        return res;
    }
    pair<index, X> _find_most_left(index a, const function<bool(X)>& is_ok, int k, index l, index r, X left_value){
        // params:
            // left_value = (a < l ? query(a, l) : ex)
        // return (index i, X v)
            // i is the index in [a, n)^[l, r) s.t query(a, i+1) is ok but query(a, i) isn't ok. if such i does not exist, i = n
            // v is the value s.t query(a, r)

        propagate(k);
        if (r <= a) return {n, ex};  // 区間が全く被っていない
        else if (a <= l && !is_ok(merge(left_value, dat[k]))) return {n, merge(left_value, dat[k])};
        else if (k >= N-1) return {k - (N-1), merge(left_value, dat[k])};
        else{
            auto [vl, xl] = _find_most_left(a, is_ok, 2 * k + 1, l, (l + r) / 2, left_value);
            if (vl != n) return {vl, xl};
            auto [vr, xr] = _find_most_left(a, is_ok, 2 * k + 2, (l + r) / 2, r, xl);
            return {vr, xr};
        }
    }

    index find_most_right(index r, const function<bool(X)>& is_ok){
        // rから左に探していってis_okが初めて成り立つようなindexを返す。
        // assume query(*, r) has monotonity
        // return index i s.t is_ok(query(i+1, r+1)) does not holds, but is_ok(query(i, r+1)) does.
        // if such i does not exist, return -1
        index res = _find_most_right(r+1, is_ok, 0, 0, N, ex).first;
        assert(res <= r);
        return res;
    }
    pair<index, X> _find_most_right(index b, const function<bool(X)>& is_ok, int k, index l, index r, X right_value){
        propagate(k);
        if (b <= l) return {-1, ex};  // 区間が全く被っていない
        else if (r <= b && !is_ok(merge(dat[k], right_value))) return {-1, merge(dat[k], right_value)};
        else if (k >= N-1) return {k - (N-1), merge(dat[k], right_value)};
        else{
            auto [vr, xr] = _find_most_right(b, is_ok, 2 * k + 2, (l + r) / 2, r, right_value);
            if (vr != -1) return {vr, xr};
            auto [vl, xl] = _find_most_right(b, is_ok, 2 * k + 1, l, (l + r) / 2, xr);
            return {vl, xl};
        }
    }

    /* debug */
    inline X operator[](int i) { return query(i, i + 1); }

    #if defined(PCM) || defined(LOCAL)
    friend ostream& operator<<(ostream& os, segment_tree_lazy& sg) {  //
        os << "[";
        for (int i = 0; i < sg.n; i++) {
            os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
        }
        return os;
    }
    #endif
};

// snippet:monoid_with_len {{{
template<class T>
struct monoid_with_len {
    T x;
    int len;
    monoid_with_len(): x(0), len(1){};
    monoid_with_len(T x_, ll len_) : x(x_), len(len_){};
};
template<class T>
monoid_with_len<T> operator+(monoid_with_len<T> a, monoid_with_len<T> b){
    return monoid_with_len<T>(a.x + b.x, a.len + b.len);
}
// snippet:monoid_with_len }}}

// snippet:make_lseg_rsq_raq {{{
using X = monoid_with_len<ll>; // (X, merge) is monoid
using M = ll; // (M, composition) is monoid
auto make_lseg_rsq_raq(){
    auto merge = [](X x1, X x2){return x1 + x2;};
    X ex = X(0, 0);
    M em = 0;
    auto composition = [](M m1, M m2){ return m1 + m2; };
    auto apply = [](X x, M m){return X(x.x + m*x.len, x.len);};
    return segment_tree_lazy<X, M>(merge, apply, composition, ex, em);
}
// snippet:make_lseg_rsq_raq }}}

int solve() {
    int n,q;cin>>n>>q;
    auto seg = make_lseg_rsq_raq();
    seg.build(vec<X>(n));
    rep(_, q){
        int ty;cin>>ty;
        if (ty == 1){
            int l,r,x;cin>>l>>r>>x;
            dump(l, r, x);
            // rep(i, l, r) a[i] += x;
            seg.update(l, r, x);
        }
        if (ty == 2){
            int l,r;cin>>l>>r;
            int res = 0;
            // rep(i, l, r) res += a[i];
            res = seg.query(l, r).x;
            cout << res << endl;
        }
        if (ty == 3){
            int l,target;cin>>l>>target;
            cout << seg.find_most_left(l, [=](X x){return x.x >= target;}) << endl;
        }
        if (ty == 4){
            int r,target;cin>>r>>target;
            cout << seg.find_most_right(r, [=](X x){return x.x >= target;}) << endl;
        }
    }

    return 0; 
}


int main(){/*{{{*/
    solve();
    check_input();
    return 0;
}/*}}}*/
