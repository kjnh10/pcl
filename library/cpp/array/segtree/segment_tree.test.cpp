#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "segment_tree.hpp"

signed main() {
    vector<int> a = {1, 4, -2, 3, 6, 7};
    auto f = [&](auto a, auto b) { return max(a, b); };
    SegmentTree<int> seg(a, f, -1e9);

    assert(seg.query(0, 8) == 7);
    dump(seg.query(0, 8));
    dump(seg.query(0, 10));
    dump(seg.query(-3, 10));
    dump(seg[0]);
    dump(seg[1]);
    dump(seg[2]);
    dump(seg);
    seg.set(2, 10);
    dump(seg.query(0, 8));

    // doubleなど他の型でも動くかチェック
    auto mymax = [&](auto a, auto b) { return max(a, b); };
    vector<double> p(6);
    SegmentTree<double> segd(p, mymax, -1e18);
    segd.set(0, 1.2);
    segd.set(1, 1.4);
    segd.set(2, 1.6);
    double v = segd.query(0, 6);
    dump(v);

    cout << "Hello World" << endl;
}
