#include "../../header.hpp"

template<typename T>
struct SegmentTree { // {{{
  private:
    using F = function<T(T,T)>;
    int n;  // 元の配列のサイズ
    int N;  // n以上の最小の2冪
    vector<T> node;
    F merge;
    T identity;

  public:
    SegmentTree(){}
    SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
      n = a.size();
      N = 1; while(N < n) N *= 2;
      node.resize(2*N-1, identity);
      for(int i=0; i<n; i++) node[i+N-1] = a[i];
      for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
    }
    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

    T& operator[](int i) { return node[i+N-1]; }

    void update(int x, T val) {
      x += (N - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    void add(int x, T val) {
      x += (N - 1);
      node[x] += val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    // query for [l, r)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}

class segment_tree_beats {
    // MEMO: values for queries (max, min, lazy_add, and lazy_update) already apply to the current node; but not for children
    typedef struct {
        int64_t max;
        int64_t max_second;
        int max_count;
        int64_t min;
        int64_t min_second;
        int min_count;
        int64_t lazy_add;
        int64_t lazy_update;
        int64_t sum;
    } value_type;

    int n;
    std::vector<value_type> a;

public:
    segment_tree_beats() = default;
    segment_tree_beats(int n_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1);
        tag<UPDATE>(0, 0);
    }
    template <class InputIterator>
    segment_tree_beats(InputIterator first, InputIterator last) {
        int n_ = std::distance(first, last);
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1);
        rep (i, n_) {
            tag<UPDATE>(n - 1 + i, *(first + i));
        }
        rep (i, n_, n) {
            tag<UPDATE>(n - 1 + i, 0);
        }
        r_rep (i, n - 1) {
            update(i);
        }
    }

    void range_chmin(int l, int r, int64_t value) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply<CHMIN>(0, 0, n, l, r, value);
    }
    void range_chmax(int l, int r, int64_t value) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply<CHMAX>(0, 0, n, l, r, value);
    }
    void range_add(int l, int r, int64_t value) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply<ADD>(0, 0, n, l, r, value);
    }
    void range_update(int l, int r, int64_t value) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply<UPDATE>(0, 0, n, l, r, value);
    }

    int64_t range_min(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        return range_get<MIN>(0, 0, n, l, r);
    }
    int64_t range_max(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        return range_get<MAX>(0, 0, n, l, r);
    }
    int64_t range_sum(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        return range_get<SUM>(0, 0, n, l, r);
    }

private:
    static constexpr char CHMIN = 0;
    static constexpr char CHMAX = 1;
    static constexpr char ADD = 2;
    static constexpr char UPDATE = 3;
    static constexpr char MIN = 10;
    static constexpr char MAX = 11;
    static constexpr char SUM = 12;

    template <char TYPE>
    void range_apply(int i, int il, int ir, int l, int r, int64_t g) {
        if (ir <= l or r <= il or break_condition<TYPE>(i, g)) {
            // break
        } else if (l <= il and ir <= r and tag_condition<TYPE>(i, g)) {
            tag<TYPE>(i, g);
        } else {
            pushdown(i);
            range_apply<TYPE>(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_apply<TYPE>(2 * i + 2, (il + ir) / 2, ir, l, r, g);
            update(i);
        }
    }
    template <char TYPE>
    inline bool break_condition(int i, int64_t g) {
        switch (TYPE) {
            case CHMIN: return a[i].max <= g;
            case CHMAX: return g <= a[i].min;
            case ADD: return false;
            case UPDATE: return false;
            default: assert (false);
        }
    }
    template <char TYPE>
    inline bool tag_condition(int i, int64_t g) {
        switch (TYPE) {
            case CHMIN: return a[i].max_second < g and g < a[i].max;
            case CHMAX: return a[i].min < g and g < a[i].min_second;
            case ADD: return true;
            case UPDATE: return true;
            default: assert (false);
        }
    }
    template <char TYPE>
    inline void tag(int i, int64_t g) {
        int length = n >> (32 - __builtin_clz(i + 1) - 1);
        if (TYPE == CHMIN) {
            if (a[i].max == a[i].min or g <= a[i].min) {
                tag<UPDATE>(i, g);
                return;
            }
            if (a[i].max != INT64_MIN) {
                a[i].sum -= a[i].max * a[i].max_count;
            }
            a[i].max = g;
            a[i].min_second = std::min(a[i].min_second, g);
            if (a[i].lazy_update != INT64_MAX) {
                a[i].lazy_update = std::min(a[i].lazy_update, g);
            }
            a[i].sum += g * a[i].max_count;
        } else if (TYPE == CHMAX) {
            if (a[i].max == a[i].min or a[i].max <= g) {
                tag<UPDATE>(i, g);
                return;
            }
            if (a[i].min != INT64_MAX) {
                a[i].sum -= a[i].min * a[i].min_count;
            }
            a[i].min = g;
            a[i].max_second = std::max(a[i].max_second, g);
            if (a[i].lazy_update != INT64_MAX) {
                a[i].lazy_update = std::max(a[i].lazy_update, g);
            }
            a[i].sum += g * a[i].min_count;
        } else if (TYPE == ADD) {
            if (a[i].max != INT64_MAX) {
                a[i].max += g;
            }
            if (a[i].max_second != INT64_MIN) {
                a[i].max_second += g;
            }
            if (a[i].min != INT64_MIN) {
                a[i].min += g;
            }
            if (a[i].min_second != INT64_MAX) {
                a[i].min_second += g;
            }
            a[i].lazy_add += g;
            if (a[i].lazy_update != INT64_MAX) {
                a[i].lazy_update += g;
            }
            a[i].sum += g * length;
        } else if (TYPE == UPDATE) {
            a[i].max = g;
            a[i].max_second = INT64_MIN;
            a[i].max_count = length;
            a[i].min = g;
            a[i].min_second = INT64_MAX;
            a[i].min_count = length;
            a[i].lazy_add = 0;
            a[i].lazy_update = INT64_MAX;
            a[i].sum = g * length;
        } else {
            assert (false);
        }
    }
    void pushdown(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        // update
        if (a[i].lazy_update != INT64_MAX) {
            tag<UPDATE>(l, a[i].lazy_update);
            tag<UPDATE>(r, a[i].lazy_update);
            a[i].lazy_update = INT64_MAX;
            return;
        }
        // add
        if (a[i].lazy_add != 0) {
            tag<ADD>(l, a[i].lazy_add);
            tag<ADD>(r, a[i].lazy_add);
            a[i].lazy_add = 0;
        }
        // chmin
        if (a[i].max < a[l].max) {
            tag<CHMIN>(l, a[i].max);
        }
        if (a[i].max < a[r].max) {
            tag<CHMIN>(r, a[i].max);
        }
        // chmax
        if (a[l].min < a[i].min) {
            tag<CHMAX>(l, a[i].min);
        }
        if (a[r].min < a[i].min) {
            tag<CHMAX>(r, a[i].min);
        }
    }
    void update(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        // chmin
        std::vector<int64_t> b { a[l].max, a[l].max_second, a[r].max, a[r].max_second };
        std::sort(b.rbegin(), b.rend());
        b.erase(std::unique(all(b)), b.end());
        a[i].max = b[0];
        a[i].max_second = b[1];
        a[i].max_count = (b[0] == a[l].max ? a[l].max_count : 0) + (b[0] == a[r].max ? a[r].max_count : 0);
        // chmax
        std::vector<int64_t> c { a[l].min, a[l].min_second, a[r].min, a[r].min_second };
        std::sort(all(c));
        c.erase(std::unique(all(c)), c.end());
        a[i].min = c[0];
        a[i].min_second = c[1];
        a[i].min_count = (c[0] == a[l].min ? a[l].min_count : 0) + (c[0] == a[r].min ? a[r].min_count : 0);
        // add
        a[i].lazy_add = 0;
        // update
        a[i].lazy_update = INT64_MAX;
        // sum
        a[i].sum = a[l].sum + a[r].sum;
    }

    template <char TYPE>
    int64_t range_get(int i, int il, int ir, int l, int r) {
        if (ir <= l or r <= il) {
            switch (TYPE) {
                case MIN: return INT64_MAX;
                case MAX: return INT64_MIN;
                case SUM: return 0;
                default: assert (false);
            }
        } else if (l <= il and ir <= r) {
            // base
            switch (TYPE) {
                case MIN: return a[i].min;
                case MAX: return a[i].max;
                case SUM: return a[i].sum;
                default: assert (false);
            }
        } else {
            pushdown(i);
            int64_t value_l = range_get<TYPE>(2 * i + 1, il, (il + ir) / 2, l, r);
            int64_t value_r = range_get<TYPE>(2 * i + 2, (il + ir) / 2, ir, l, r);
            // mult
            switch (TYPE) {
                case MIN: return std::min(value_l, value_r);
                case MAX: return std::max(value_l, value_r);
                case SUM: return value_l + value_r;
                default: assert (false);
            }
        }
    }
};


signed main() {
    int n;cin>>n;
    vector<int> m(n);
    vector<pii> mi(n);
    int mv = -INF;
    rep(i, n) {
        cin>>m[i];
        chmax(mv, m[i]);
        mi[i] = mp(m[i], i);
    }
    dump(m);
    if (n>100000) return 0;

    vi L(n);
    {
        segment_tree_beats lseg(all(m));
        rep(i, 1, n){
            if (i>100000) return 0;
            cerrendl;
            lseg.range_chmin(0, i, m[i]);
            L[i] = lseg.range_sum(0, i);
        }
    }
    dump(L);

    vi R(n);
    {
        segment_tree_beats lseg2(all(m));
        r_rep(i, n-1){
            lseg2.range_chmin(i+1, n, m[i]);
            R[i] = lseg2.range_sum(i+1, n);
        }
    }
    dump(R);

    int max_score = -INF;
    int midx;
    rep(i, n){
        int score = m[i]+L[i]+R[i];
        dump(i, score);
        if (score>max_score){
            midx = i;
            max_score = score;
        }
    }
    dump(max_score, midx);

    vector<int> tmp(n);
    int x =  midx;
    tmp[x] = m[x];
    int cur;

    cur = m[x];
    r_rep(i, 0, x){
        if(m[i]>cur){
            tmp[i] = cur;
        }
        else{
            tmp[i] = m[i];
            cur = m[i];
        }
    }

    cur = m[x];
    rep(i, x+1, n){
        if(m[i]>cur){
            tmp[i] = cur;
        }
        else{
            tmp[i] = m[i];
            cur = m[i];
        }
    }
    int s = accumulate(all(tmp), 0LL);
    dump(s);

    rep(i, sz(tmp)) cout << tmp[i] << (i!=sz(tmp)-1 ? " " : "\n");

    return 0;
}

