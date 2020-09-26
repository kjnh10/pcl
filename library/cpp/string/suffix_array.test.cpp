#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "suffix_array.hpp"

int main() {
  string s;cin>>s;
  suffix_array sa(s);
  rep(i, sz(sa.order)) cout << sa.order[i] << (i!=sz(sa.order)-1 ? " " : "\n");
  return 0;
}
