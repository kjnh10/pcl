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
            n = a.size();
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

            X vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            X vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }

        // find most right element for [a, b)
        index find_mr(index a, index b, const function<bool(X)>& is_ok, int k = 0, index l = 0, index r = -1){
            if (r < 0) r = N;
            if (r <= a || b <= l || !is_ok(node[k])) return a-1;
            if (k >= N-1) return k - (N-1);  // leaf

            index vr = find_mr(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);
            if (vr != a-1) return vr;

            index vl = find_mr(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);
            return vl;
        }

        // find most left element for [a, b)
        index find_ml(index a, index b, const function<bool(X)>& is_ok, int k = 0, index l = 0, index r = -1){
            // find most left
            if (r < 0) r = N;
            if (r <= a || b <= l || !is_ok(node[k])) return b;
            if (k >= N-1) return k - (N-1);  // leaf

            index vl = find_ml(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) return vl;

            index vr = find_ml(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);
            return vr;
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
// SegmentTree<ll> seg(a, mymin, 1e18);

// auto mymax=[](auto a, auto b){return max(a,b);};
// SegmentTree<ll> seg(a, mymax, -1e18);

// auto add=[](auto a, auto b){return a+b;};
// SegmentTree<ll> seg(a, add, 0);
// -----------------------------------------------

//%snippet.end()%
