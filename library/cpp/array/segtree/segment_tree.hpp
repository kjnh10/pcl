#pragma once
#include "../../header.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%
//%snippet.fold()%

template <typename X> struct SegmentTree {  // {{{
    private:
        using F = function<X(X, X)>;
        using index = int;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<X> node;
        F merge;
        X identity;

    public:
        SegmentTree() {}
        SegmentTree(vector<X> a, F f, X id) : merge(f), identity(id) {
            n = (int)a.size();
            N = 1;
            while (N < n) N *= 2;
            node.resize(2 * N - 1, identity);
            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];
            for (int i = N - 2; i >= 0; i--)
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
        }
        SegmentTree(int sz, F f, X id) : SegmentTree(vector<X>(sz, id), f, id) {}

        X& operator[](index i) { return node[i + N - 1]; }

        void set(index i, X val) {
            i += (N - 1);
            node[i] = val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        void add(index i, X val) {
            i += (N - 1);
            node[i] += val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        // query for [a, b)
        X query(index a, index b, int k = 0, index l = 0, index r = -1) {
            if (r < 0) r = N;
            if (r <= a || b <= l) return identity;
            if (a <= l && r <= b) return node[k];

            X lv = query(a, b, 2 * k + 1, l, (l + r) / 2);
            X rv = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(lv, rv);
        }

        index find_most_left(index l, const function<bool(X)>& is_ok){
            // lから右に探していってis_okが初めて成り立つようなindexを返す。
            // assume query(l, *) has monotonity
            // return index i s.t is_ok(query(l, i)) does not holds, but is_ok(query(l, i+1)) does.
            // if such i does not exist, return n
            index res = _find_most_left(l, is_ok, 0, 0, N, identity).first;
            assert(l <= res);
            return res;
        }
        pair<index, X> _find_most_left(index a, const function<bool(X)>& is_ok, int k, index l, index r, X left_value){
            // params:
                // left_value = (a < l ? query(a, l) : ex)
            // return (index i, X v)
                // i is the index in [a, n)^[l, r) s.t query(a, i+1) is ok but query(a, i) isn't ok. if such i does not exist, i = n
                // v is the value s.t query(a, r)

            if (r <= a) return {n, identity};  // 区間が全く被っていない
            else if (a <= l && !is_ok(merge(left_value, node[k]))) return {n, merge(left_value, node[k])};
            else if (k >= N-1) return {k - (N-1), merge(left_value, node[k])};
            else{
                auto [lv, xl] = _find_most_left(a, is_ok, 2 * k + 1, l, (l + r) / 2, left_value);
                if (lv != n) return {lv, xl};
                auto [rv, xr] = _find_most_left(a, is_ok, 2 * k + 2, (l + r) / 2, r, xl);
                return {rv, xr};
            }
        }

        index find_most_right(index r, const function<bool(X)>& is_ok){
            // rから左に探していってis_okが初めて成り立つようなindexを返す。
            // assume query(*, r) has monotonity
            // return index i s.t is_ok(query(i+1, r+1)) does not holds, but is_ok(query(i, r+1)) does.
            // if such i does not exist, return -1
            index res = _find_most_right(r+1, is_ok, 0, 0, N, identity).first;
            assert(res <= r);
            return res;
        }
        pair<index, X> _find_most_right(index b, const function<bool(X)>& is_ok, int k, index l, index r, X right_value){
            if (b <= l) return {-1, identity};  // 区間が全く被っていない
            else if (r <= b && !is_ok(merge(node[k], right_value))) return {-1, merge(node[k], right_value)};
            else if (k >= N-1) return {k - (N-1), merge(node[k], right_value)};
            else{
                auto [rv, xr] = _find_most_right(b, is_ok, 2 * k + 2, (l + r) / 2, r, right_value);
                if (rv != -1) return {rv, xr};
                auto [lv, xl] = _find_most_right(b, is_ok, 2 * k + 1, l, (l + r) / 2, xr);
                return {lv, xl};
            }
        }

        #if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream& os, SegmentTree<X>& sg) {  //
            os << "[";
            for (int i = 0; i < sg.n; i++) {
                os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
            }
            return os;
        }
        #endif
};/*}}}*/
// sample of initialize SegmentTree:
// -----------------------------------------------
// auto mymin=[](auto a, auto b){return min(a,b);};
// ll e = 1e18;
// SegmentTree<ll> seg(a, mymin, e);

// auto mymax=[](auto a, auto b){return max(a,b);};
// ll e = -1e18;
// SegmentTree<ll> seg(a, mymax, e);

// auto add=[](auto a, auto b){return a+b;};
// ll e = 0;
// SegmentTree<ll> seg(a, add, e);

// pair<int, int> get_nearest_index_of_smaller_element(int i){
//     auto left = seg.find_most_right(i, [&](auto x){return x < a[i];});
//     auto right = seg.find_most_left(i, [&](auto x){return x < a[i];});
//     return {left, right};
// }
// -----------------------------------------------

//%snippet.end()%
