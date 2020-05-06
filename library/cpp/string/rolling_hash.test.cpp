#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "rolling_hash.hpp"

int main() {
  string T, P;
  using RH = rolling_hash<1000000009, 10007>;

  cin >> T;
  cin >> P;
  RH rh(T), rh2(P);
  for(int i = 0; i + P.size() <= T.size(); i++) {
    if(rh.get_hash(i, i + P.size()) == rh2.get_hash(0, P.size())) {
      cout << i << endl;
    }
  }
}
