#pragma once
#include "../../../../problem_template/codes/header.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%

template<typename T>
struct SegmentTree { // {{{
    private:
        using F = function<T(T,T)>;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<T> node;
        F merge;
        T identity;

    public:
        SegmentTree(){}
        SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
            n = a.size();
            N = 1; while(N < n) N *= 2;
            node.resize(2*N-1, identity);
            for(int i=0; i<n; i++) node[i+N-1] = a[i];
            for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
        }
        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

        T& operator[](int i) { return node[i+N-1]; }

        void update(int x, T val) {
            x += (N - 1);
            node[x] = val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = merge(node[2*x+1], node[2*x+2]);
            }
        }

        void add(int x, T val) {
            x += (N - 1);
            node[x] += val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = merge(node[2*x+1], node[2*x+2]);
            }
        }

        // query for [l, r)
        T query(int a, int b, int k=0, int l=0, int r=-1) {
            if(r < 0) r = N;
            if(r <= a || b <= l) return identity;
            if(a <= l && r <= b) return node[k];

            T vl = query(a, b, 2*k+1, l, (l+r)/2);
            T vr = query(a, b, 2*k+2, (l+r)/2, r);
            return merge(vl, vr);
        }

        #if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
            os << "[";
            for(int i=0; i<sg.n; i++){
                os << sg[i] << (i==sg.n-1?"]\n":", ");
            }
            return os;
        }
        #endif
};
// }}}
// Sample:
// -----------------------------------------------
    // auto mymin=[](auto a, auto b){return min(a,b);};
    // SegmentTree<int> seg(a, mymin, 1e18);

    // auto mymax=[](auto a, auto b){return max(a,b);};
    // SegmentTree<int> seg(a, mymax, -1e18);

    // auto add=[](auto a, auto b){return a+b;};
    // SegmentTree<int> seg(a, add, 0);
// -----------------------------------------------

//%snippet.end()%

