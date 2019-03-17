// http://codeforces.com/blog/entry/18051

#include <bits/stdc++.h>

template <typename monoid_trait> struct segment_tree {
  using M = monoid_trait;
  using T = typename M::value_type;

  // monoid m;
  std::size_t sz;
  std::vector<T> x;

  segment_tree(std::size_t n = 0) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    x.assign(sz * 2, M::id());
    initialize();
  }

  template <typename iterator>
    segment_tree(iterator first, iterator last) {
      sz = 1;
      std::size_t n = std::distance(first, last);
      while (sz < n)
        sz *= 2;
      x.assign(sz * 2, M::id());
      std::copy(first, last, x.begin() + sz);
      initialize();
    }

  void initialize() {
    for (int i = (int)sz - 1; i >= 1; --i) {
      x[i] = M::op(x[i * 2 + 0], x[i * 2 + 1]);
    }
  }

  T query(std::size_t l, std::size_t r) const {
    T res = M::id();
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        res = M::op(res, x[l++]);
      if (r & 1)
        res = M::op(res, x[--r]);
    }
    return res;
  }

  void update(std::size_t i, const T &val) {
    x[i += sz] = val;
    while (i > 1) {
      x[i / 2] = M::op(x[i], x[i ^ 1]);
      i /= 2;
    }
  }

  T operator[](std::size_t i) const { return x[sz + i]; }
};

template <typename T> struct zero_sum_monoid {
  using value_type = T;
  static constexpr T id() { return 0; }
  static T op(const T &a, const T &b) { return a + b; }
};

template <typename T> struct inf_min_monoid {
  using value_type = T;
  static constexpr T id() { return std::numeric_limits<T>::max(); }
  static T op(const T &a, const T &b) { return std::min(a, b); }
};

template <typename T> using rmq = segment_tree<inf_min_monoid<T>>;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)

template <typename T> void __dump__(std::ostream &os, const T &first) {
  os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
  os << first << ", ";
  __dump__(os, rest...);
}
#define dump(...)                                           \
  do {                                                    \
    std::ostringstream os;                              \
    os << __LINE__ << ":\t" << #__VA_ARGS__ << " = ";   \
    __dump__(os, __VA_ARGS__);                          \
    std::cerr << os.str() << std::endl;                 \
  } while (0)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, q;
  while (cin >> n >> q) {
    segment_tree<inf_min_monoid<int32_t>> st(n);
    rep(i, q) {
      int t;
      cin >> t;
      if (t == 0) {
        int k, x;
        cin >> k >> x;
        st.update(k, x);
      } else {
        int l, r;
        cin >> l >> r;
        ++r;
        cout << st.query(l, r) << '\n';
      }
    }
  }
}
