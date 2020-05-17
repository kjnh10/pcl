#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "p2.hpp"

#define myassert(x, y) dump(x); assert(x==y);

signed main() {
    P2 p1(1, 15);
    P2 p2(3, 6);
    myassert(p1+p2, P2(4, 21));
    myassert(p1*3, P2(3, 45));
    myassert(p1/3, P2(0, 5));
    myassert(p1-p2, P2(-2, 9));
    myassert(-p1, P2(-1, -15));
    myassert(-p1-p2, P2(-4, -21));
    myassert(-p1+p2, P2(2, -9));

    cout << "Hello World" << endl;
    return 0;
}
