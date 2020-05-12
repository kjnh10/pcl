#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "rolling_hash.hpp"

int main() {
    string t, p;
    using RH = rolling_hash;

    cin >> t;
    cin >> p;
    RH rh(t), rh2(p);
    for(int i = 0; i + p.size() <= t.size(); i++) {
        if(rh.get_hash(i, i + p.size()) == rh2.get_hash(0, p.size())) {
            cout << i << endl;
        }
    }
}
