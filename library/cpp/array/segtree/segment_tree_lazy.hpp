#pragma once
#include "../../header.hpp"

//%snippet.set('segment_tree_lazy')%
//%snippet.config({'alias':'lazy'})%
//%snippet.fold()%

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

/* SegTreeLazyProportional<X,M>(n,fx,fa,fm,ex,em): モノイド(集合X, 二項演算fx,fa,fm,p 単位元ex,em)についてサイズnで構築
    set(index i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(index a, index b, M m): [a, b)の要素にmをapply。O(log(n))
    query(index a, index b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/

//%snippet.end()%

