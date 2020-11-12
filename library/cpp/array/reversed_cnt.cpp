#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include "../misc/zipper.lib/zipper.hpp"
#include "segtree/segment_tree.hpp"

//%snippet.set('reversed_cnt')%
//%snippet.config({'alias':'tentousu'})%
//%snippet.config({'alias':'cnt_reversed'})%
//%snippet.include('zipper')%
//%snippet.include('segment_tree')%
//%snippet.fold()%
template<class T>
ll reversed_cnt(const vector<T>& v){
    int n = sz(v);
    if (n == 0) return 0;
    ll max_v = *max_element(all(v));
    ll min_v = *min_element(all(v));

    zipper z;
    bool zipped = false;
    if (max_v > n-1 || min_v < 0) {
        z = zipper(v);
        max_v = z.n - 1;
        zipped = true;
    }

    auto add=[](auto a, auto b){return a+b;};
    ll e = 0;
    SegmentTree<ll> seg(max_v + 1, add, e);

    ll res = 0;
    rep(i, n){
        ll w = (zipped ? z(v[i]) : v[i]);
        res += seg.query(w+1, max_v+1);
        seg.add(w, 1);
    }
    return res;
}

template<class T>
ll reversed_dist(const vector<T>& a, const vector<T>& b){
    // assume a and b are permutaion of same size
    int n = sz(a);
    vector<int> d(n+1);
    rep(i, n){ d[a[i]] = i; }
    vector<T> c(n);
    rep(i, n){ c[i] = d[b[i]]; }
    return reversed_cnt(c);
}
//%snippet.end()%

int main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i, n) cin>>a[i];
    cout << reversed_cnt(a) << endl;
}
