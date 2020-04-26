#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "zipper.hpp"

signed main() {
    vector<int> x({3, 10, 5, (int)1e12});
    auto z1 = zipper(x);  // x: vector<long long>;
    dump(z1);
    auto z2 = zipper(x, INF + 5);
    dump(z2);

    auto z3 = zipper();
    z3.add_value(3);
    z3.add_value(5);
    z3.add_value(10);
    z3.add_value((int)1e12);
    z3.build();
    dump(z3);

    dump(z1(5));
    assert(z1(5) == 2);
    assert(z1.unzip(4) == (int)1e12);
    dump(z1.get_zipped(x));
    assert(z1.get_zipped(x) == vector<int>({1, 3, 2, 4}));

    cout << "Hello World" << endl;
    return 0;
}
