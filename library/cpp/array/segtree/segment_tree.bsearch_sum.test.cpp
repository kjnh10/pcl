#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "segment_tree.hpp"

SegmentTree<ll> seg;
vector<ll> a;
int n;

int64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<int64_t>(0, 20)(x);
}

int target;

pair<int, int> naive(int i){
    int right = n;
    int sum = 0;
    rep(j, i, sz(a)){
        sum += a[j];
        if (sum >= target) {
            right = j;
            break;
        }
    }
    int left = -1;
    sum = 0;
    r_rep(j, 0, i+1){
        sum += a[j];
        if (sum >= target) {
            left = j;
            break;
        }
    }
    return {left, right};
}

pair<int, int> get_first_index_got_target(int i){
    auto left = seg.find_most_right(i, [&](auto x){return x >= target;});
    auto right = seg.find_most_left(i, [&](auto x){return x >= target;});
    return {left, right};
}

int test(int _n, bool compare = true){
    n = _n;
    a.clear();
    target = rng()%100000;
    rep(i, n){ a.pb(rng()%10); }
    dump(a);

    seg = SegmentTree<ll>(a, [](auto a, auto b){return a + b;}, 0);
    rep(i, sz(a)){
        auto res = get_first_index_got_target(i);
        if (compare){
            // dump(i, naive(i), res);
            assert(naive(i) == res);
        }
    }
    return 0;
}

int main(){
    int nums = 10;
    while(nums--){
        test(abs(rng())); 
        test(1000000, false); 
    }
    cout << "Hello World" << endl;
    return 0;
}
