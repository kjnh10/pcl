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
    int right = n;
    rep(j, i+1, sz(a)){
        if (a[j] < a[i]) {
            right = j;
            break;
        }
    }
    int left = -1;
    r_rep(j, 0, i){
        if (a[j] < a[i]) {
            left = j;
            break;
        }
    }
    return {left, right};
}

pair<int, int> get_nearest_index_of_smaller_element(int i){
    auto left = seg.find_most_right(i, [&](auto x){return x < a[i];});
    auto right = seg.find_most_left(i, [&](auto x){return x < a[i];});
    return {left, right};
}

int test(int _n, bool compare = true){
    n = _n;
    a.clear();
    rep(i, n){ a.pb(rng()%10); }
    dump(a);

    seg = SegmentTree<ll>(a, [](auto a, auto b){return min(a,b);}, 1e18);
    rep(i, sz(a)){
        auto res = get_nearest_index_of_smaller_element(i);
        if (compare){
            // dump(naive(i), res);
            assert(naive(i) == res);
        }
    }
    return 0;
}

int main(){
    int nums = 10;
    while(nums--){
        test(abs(rng())); 
        // test(1000000, false); 
    }
    cout << "Hello World" << endl;
    return 0;
}
