#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "segment_tree.hpp"

SegmentTree<ll> seg;
vector<ll> a;
int n;

int64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<int64_t>(-100, 100)(x);
}

pair<int, int> naive(int i){
    int nr = -1;
    rep(j, i+1, sz(a)){
        if (a[j] < a[i]) {
            nr = j;
            break;
        }
    }
    int nl = -1;
    r_rep(j, 0, i){
        if (a[j] < a[i]) {
            nl = j;
            break;
        }
    }
    return {nl, nr};
}

pair<int, int> by_seg_find(int i){
    // a[i]より小さくて左側で一番近いもののindex
    auto nl = seg.find_mr(0, i, [&](auto x){return x < a[i];});
    auto nr = seg.find_ml(i, n, [&](auto x){return x < a[i];});
    return {nl, nr};
}

int test(){
    n = abs(rng());
    a.clear();
    rep(i, n){ a.pb(rng()%10); }
    dump(a);

    seg = SegmentTree<ll>(a, [](auto a, auto b){return min(a,b);}, 1e18);
    rep(i, sz(a)){
        assert(naive(i) == by_seg_find(i));
    }
    return 0;
}

int main(){
    int nums = 100;
    while(nums--){ test(); }
    // test();
    return 0;
}
