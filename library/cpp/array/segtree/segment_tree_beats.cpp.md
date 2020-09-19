---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n// varibable settings\n\
    const long long INF = 1e18;\ntemplate <class T> constexpr T inf = numeric_limits<T>::max()\
    \ / 2.1;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n)\
    \ repi(i, 0, n)\n#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n\
    #define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define _rrep(i,\
    \ n) rrepi(i, 0, n)\n#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a);\
    \ --i)\n#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)\n\
    #define each(i, a) for (auto &&i : a)\n#define all(x) (x).begin(), (x).end()\n\
    #define sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b)\
    \ make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n#define ub upper_bound\n\
    #define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A), x) - A.begin())\n\
    #define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate <class T, class\
    \ U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }\ntemplate\
    \ <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b)) (a)\
    \ = (b); }\ntemplate <typename X, typename T> auto make_table(X x, T a) { return\
    \ vector<T>(x, a); }\ntemplate <typename X, typename Y, typename Z, typename...\
    \ Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z,\
    \ zs...); return vector<decltype(cont)>(x, cont); }\n\n#define cdiv(a, b) (((a)\
    \ + (b)-1) / (b))\n#define is_in(x, a, b) ((a) <= (x) && (x) < (b))\n#define uni(x)\
    \ sort(all(x)); x.erase(unique(all(x)), x.end())\n#define slice(l, r) substr(l,\
    \ r - l)\n\ntypedef long long ll;\ntypedef long double ld;\nusing vl = vector<ll>;\n\
    using vvl = vector<vl>;\nusing pll = pair<ll, ll>;\n\ntemplate <typename T>\n\
    using PQ = priority_queue<T, vector<T>, greater<T>>;\nvoid check_input() { assert(cin.eof()\
    \ == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }\n\n#if defined(PCM) ||\
    \ defined(LOCAL)\n#else\n#define dump(...) ;\n#define dump_1d(...) ;\n#define\
    \ dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n\
    #line 2 \"library/cpp/array/segtree/segment_tree_beats.cpp\"\n\ntemplate <typename\
    \ T>\nstruct SegmentTree {  // {{{\n   private:\n    using F = function<T(T, T)>;\n\
    \    int n;  // \u5143\u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    int N; \
    \ // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n    vector<T> node;\n    F\
    \ merge;\n    T identity;\n\n   public:\n    SegmentTree() {}\n    SegmentTree(vector<T>\
    \ a, F f, T id) : merge(f), identity(id) {\n        n = a.size();\n        N =\
    \ 1;\n        while (N < n) N *= 2;\n        node.resize(2 * N - 1, identity);\n\
    \        for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n        for (int\
    \ i = N - 2; i >= 0; i--)\n            node[i] = merge(node[2 * i + 1], node[2\
    \ * i + 2]);\n    }\n    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n,\
    \ id), f, id) {}\n\n    T& operator[](int i) { return node[i + N - 1]; }\n\n \
    \   void update(int x, T val) {\n        x += (N - 1);\n        node[x] = val;\n\
    \        while (x > 0) {\n            x = (x - 1) / 2;\n            node[x] =\
    \ merge(node[2 * x + 1], node[2 * x + 2]);\n        }\n    }\n\n    void add(int\
    \ x, T val) {\n        x += (N - 1);\n        node[x] += val;\n        while (x\
    \ > 0) {\n            x = (x - 1) / 2;\n            node[x] = merge(node[2 * x\
    \ + 1], node[2 * x + 2]);\n        }\n    }\n\n    // query for [l, r)\n    T\
    \ query(int a, int b, int k = 0, int l = 0, int r = -1) {\n        if (r < 0)\
    \ r = N;\n        if (r <= a || b <= l) return identity;\n        if (a <= l &&\
    \ r <= b) return node[k];\n\n        T vl = query(a, b, 2 * k + 1, l, (l + r)\
    \ / 2);\n        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n        return\
    \ merge(vl, vr);\n    }\n\n    friend ostream& operator<<(ostream& os, SegmentTree<T>&\
    \ sg) {  //\n        os << \"[\";\n        for (int i = 0; i < sg.n; i++) {\n\
    \            os << sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n        }\n\
    \        return os;\n    }\n};\n// }}}\n\nclass segment_tree_beats {\n    // MEMO:\
    \ values for queries (max, min, lazy_add, and lazy_update) already\n    // apply\
    \ to the current node; but not for children\n    typedef struct {\n        int64_t\
    \ max;\n        int64_t max_second;\n        int max_count;\n        int64_t min;\n\
    \        int64_t min_second;\n        int min_count;\n        int64_t lazy_add;\n\
    \        int64_t lazy_update;\n        int64_t sum;\n    } value_type;\n\n   \
    \ int n;\n    std::vector<value_type> a;\n\n   public:\n    segment_tree_beats()\
    \ = default;\n    segment_tree_beats(int n_) {\n        n = 1;\n        while\
    \ (n < n_) n *= 2;\n        a.resize(2 * n - 1);\n        tag<UPDATE>(0, 0);\n\
    \    }\n    template <class InputIterator>\n    segment_tree_beats(InputIterator\
    \ first, InputIterator last) {\n        int n_ = std::distance(first, last);\n\
    \        n = 1;\n        while (n < n_) n *= 2;\n        a.resize(2 * n - 1);\n\
    \        rep(i, n_) { tag<UPDATE>(n - 1 + i, *(first + i)); }\n        rep(i,\
    \ n_, n) { tag<UPDATE>(n - 1 + i, 0); }\n        r_rep(i, n - 1) { update(i);\
    \ }\n    }\n\n    void range_chmin(int l, int r, int64_t value) {  // 0-based,\
    \ [l, r)\n        assert(0 <= l and l <= r and r <= n);\n        range_apply<CHMIN>(0,\
    \ 0, n, l, r, value);\n    }\n    void range_chmax(int l, int r, int64_t value)\
    \ {  // 0-based, [l, r)\n        assert(0 <= l and l <= r and r <= n);\n     \
    \   range_apply<CHMAX>(0, 0, n, l, r, value);\n    }\n    void range_add(int l,\
    \ int r, int64_t value) {  // 0-based, [l, r)\n        assert(0 <= l and l <=\
    \ r and r <= n);\n        range_apply<ADD>(0, 0, n, l, r, value);\n    }\n   \
    \ void range_update(int l, int r, int64_t value) {  // 0-based, [l, r)\n     \
    \   assert(0 <= l and l <= r and r <= n);\n        range_apply<UPDATE>(0, 0, n,\
    \ l, r, value);\n    }\n\n    int64_t range_min(int l, int r) {  // 0-based, [l,\
    \ r)\n        assert(0 <= l and l <= r and r <= n);\n        return range_get<MIN>(0,\
    \ 0, n, l, r);\n    }\n    int64_t range_max(int l, int r) {  // 0-based, [l,\
    \ r)\n        assert(0 <= l and l <= r and r <= n);\n        return range_get<MAX>(0,\
    \ 0, n, l, r);\n    }\n    int64_t range_sum(int l, int r) {  // 0-based, [l,\
    \ r)\n        assert(0 <= l and l <= r and r <= n);\n        return range_get<SUM>(0,\
    \ 0, n, l, r);\n    }\n\n   private:\n    static constexpr char CHMIN = 0;\n \
    \   static constexpr char CHMAX = 1;\n    static constexpr char ADD = 2;\n   \
    \ static constexpr char UPDATE = 3;\n    static constexpr char MIN = 10;\n   \
    \ static constexpr char MAX = 11;\n    static constexpr char SUM = 12;\n\n   \
    \ template <char TYPE>\n    void range_apply(int i, int il, int ir, int l, int\
    \ r, int64_t g) {\n        if (ir <= l or r <= il or break_condition<TYPE>(i,\
    \ g)) {\n            // break\n        } else if (l <= il and ir <= r and tag_condition<TYPE>(i,\
    \ g)) {\n            tag<TYPE>(i, g);\n        } else {\n            pushdown(i);\n\
    \            range_apply<TYPE>(2 * i + 1, il, (il + ir) / 2, l, r, g);\n     \
    \       range_apply<TYPE>(2 * i + 2, (il + ir) / 2, ir, l, r, g);\n          \
    \  update(i);\n        }\n    }\n    template <char TYPE>\n    inline bool break_condition(int\
    \ i, int64_t g) {\n        switch (TYPE) {\n            case CHMIN:\n        \
    \        return a[i].max <= g;\n            case CHMAX:\n                return\
    \ g <= a[i].min;\n            case ADD:\n                return false;\n     \
    \       case UPDATE:\n                return false;\n            default:\n  \
    \              assert(false);\n        }\n    }\n    template <char TYPE>\n  \
    \  inline bool tag_condition(int i, int64_t g) {\n        switch (TYPE) {\n  \
    \          case CHMIN:\n                return a[i].max_second < g and g < a[i].max;\n\
    \            case CHMAX:\n                return a[i].min < g and g < a[i].min_second;\n\
    \            case ADD:\n                return true;\n            case UPDATE:\n\
    \                return true;\n            default:\n                assert(false);\n\
    \        }\n    }\n    template <char TYPE>\n    inline void tag(int i, int64_t\
    \ g) {\n        int length = n >> (32 - __builtin_clz(i + 1) - 1);\n        if\
    \ (TYPE == CHMIN) {\n            if (a[i].max == a[i].min or g <= a[i].min) {\n\
    \                tag<UPDATE>(i, g);\n                return;\n            }\n\
    \            if (a[i].max != INT64_MIN) {\n                a[i].sum -= a[i].max\
    \ * a[i].max_count;\n            }\n            a[i].max = g;\n            a[i].min_second\
    \ = std::min(a[i].min_second, g);\n            if (a[i].lazy_update != INT64_MAX)\
    \ {\n                a[i].lazy_update = std::min(a[i].lazy_update, g);\n     \
    \       }\n            a[i].sum += g * a[i].max_count;\n        } else if (TYPE\
    \ == CHMAX) {\n            if (a[i].max == a[i].min or a[i].max <= g) {\n    \
    \            tag<UPDATE>(i, g);\n                return;\n            }\n    \
    \        if (a[i].min != INT64_MAX) {\n                a[i].sum -= a[i].min *\
    \ a[i].min_count;\n            }\n            a[i].min = g;\n            a[i].max_second\
    \ = std::max(a[i].max_second, g);\n            if (a[i].lazy_update != INT64_MAX)\
    \ {\n                a[i].lazy_update = std::max(a[i].lazy_update, g);\n     \
    \       }\n            a[i].sum += g * a[i].min_count;\n        } else if (TYPE\
    \ == ADD) {\n            if (a[i].max != INT64_MAX) {\n                a[i].max\
    \ += g;\n            }\n            if (a[i].max_second != INT64_MIN) {\n    \
    \            a[i].max_second += g;\n            }\n            if (a[i].min !=\
    \ INT64_MIN) {\n                a[i].min += g;\n            }\n            if\
    \ (a[i].min_second != INT64_MAX) {\n                a[i].min_second += g;\n  \
    \          }\n            a[i].lazy_add += g;\n            if (a[i].lazy_update\
    \ != INT64_MAX) {\n                a[i].lazy_update += g;\n            }\n   \
    \         a[i].sum += g * length;\n        } else if (TYPE == UPDATE) {\n    \
    \        a[i].max = g;\n            a[i].max_second = INT64_MIN;\n           \
    \ a[i].max_count = length;\n            a[i].min = g;\n            a[i].min_second\
    \ = INT64_MAX;\n            a[i].min_count = length;\n            a[i].lazy_add\
    \ = 0;\n            a[i].lazy_update = INT64_MAX;\n            a[i].sum = g *\
    \ length;\n        } else {\n            assert(false);\n        }\n    }\n  \
    \  void pushdown(int i) {\n        int l = 2 * i + 1;\n        int r = 2 * i +\
    \ 2;\n        // update\n        if (a[i].lazy_update != INT64_MAX) {\n      \
    \      tag<UPDATE>(l, a[i].lazy_update);\n            tag<UPDATE>(r, a[i].lazy_update);\n\
    \            a[i].lazy_update = INT64_MAX;\n            return;\n        }\n \
    \       // add\n        if (a[i].lazy_add != 0) {\n            tag<ADD>(l, a[i].lazy_add);\n\
    \            tag<ADD>(r, a[i].lazy_add);\n            a[i].lazy_add = 0;\n   \
    \     }\n        // chmin\n        if (a[i].max < a[l].max) {\n            tag<CHMIN>(l,\
    \ a[i].max);\n        }\n        if (a[i].max < a[r].max) {\n            tag<CHMIN>(r,\
    \ a[i].max);\n        }\n        // chmax\n        if (a[l].min < a[i].min) {\n\
    \            tag<CHMAX>(l, a[i].min);\n        }\n        if (a[r].min < a[i].min)\
    \ {\n            tag<CHMAX>(r, a[i].min);\n        }\n    }\n    void update(int\
    \ i) {\n        int l = 2 * i + 1;\n        int r = 2 * i + 2;\n        // chmin\n\
    \        std::vector<int64_t> b{a[l].max, a[l].max_second, a[r].max,\n       \
    \                        a[r].max_second};\n        std::sort(b.rbegin(), b.rend());\n\
    \        b.erase(std::unique(all(b)), b.end());\n        a[i].max = b[0];\n  \
    \      a[i].max_second = b[1];\n        a[i].max_count = (b[0] == a[l].max ? a[l].max_count\
    \ : 0) +\n                         (b[0] == a[r].max ? a[r].max_count : 0);\n\
    \        // chmax\n        std::vector<int64_t> c{a[l].min, a[l].min_second, a[r].min,\n\
    \                               a[r].min_second};\n        std::sort(all(c));\n\
    \        c.erase(std::unique(all(c)), c.end());\n        a[i].min = c[0];\n  \
    \      a[i].min_second = c[1];\n        a[i].min_count = (c[0] == a[l].min ? a[l].min_count\
    \ : 0) +\n                         (c[0] == a[r].min ? a[r].min_count : 0);\n\
    \        // add\n        a[i].lazy_add = 0;\n        // update\n        a[i].lazy_update\
    \ = INT64_MAX;\n        // sum\n        a[i].sum = a[l].sum + a[r].sum;\n    }\n\
    \n    template <char TYPE>\n    int64_t range_get(int i, int il, int ir, int l,\
    \ int r) {\n        if (ir <= l or r <= il) {\n            switch (TYPE) {\n \
    \               case MIN:\n                    return INT64_MAX;\n           \
    \     case MAX:\n                    return INT64_MIN;\n                case SUM:\n\
    \                    return 0;\n                default:\n                   \
    \ assert(false);\n            }\n        } else if (l <= il and ir <= r) {\n \
    \           // base\n            switch (TYPE) {\n                case MIN:\n\
    \                    return a[i].min;\n                case MAX:\n           \
    \         return a[i].max;\n                case SUM:\n                    return\
    \ a[i].sum;\n                default:\n                    assert(false);\n  \
    \          }\n        } else {\n            pushdown(i);\n            int64_t\
    \ value_l =\n                range_get<TYPE>(2 * i + 1, il, (il + ir) / 2, l,\
    \ r);\n            int64_t value_r =\n                range_get<TYPE>(2 * i +\
    \ 2, (il + ir) / 2, ir, l, r);\n            // mult\n            switch (TYPE)\
    \ {\n                case MIN:\n                    return std::min(value_l, value_r);\n\
    \                case MAX:\n                    return std::max(value_l, value_r);\n\
    \                case SUM:\n                    return value_l + value_r;\n  \
    \              default:\n                    assert(false);\n            }\n \
    \       }\n    }\n};\n\nsigned main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ m(n);\n    vector<pair<int, int>> mi(n);\n    int mv = -INF;\n    rep(i, n)\
    \ {\n        cin >> m[i];\n        chmax(mv, m[i]);\n        mi[i] = mp(m[i],\
    \ i);\n    }\n    dump(m);\n    if (n > 100000) return 0;\n\n    vi L(n);\n  \
    \  {\n        segment_tree_beats lseg(all(m));\n        rep(i, 1, n) {\n     \
    \       if (i > 100000) return 0;\n            cerrendl;\n            lseg.range_chmin(0,\
    \ i, m[i]);\n            L[i] = lseg.range_sum(0, i);\n        }\n    }\n    dump(L);\n\
    \n    vi R(n);\n    {\n        segment_tree_beats lseg2(all(m));\n        r_rep(i,\
    \ n - 1) {\n            lseg2.range_chmin(i + 1, n, m[i]);\n            R[i] =\
    \ lseg2.range_sum(i + 1, n);\n        }\n    }\n    dump(R);\n\n    int max_score\
    \ = -INF;\n    int midx;\n    rep(i, n) {\n        int score = m[i] + L[i] + R[i];\n\
    \        dump(i, score);\n        if (score > max_score) {\n            midx =\
    \ i;\n            max_score = score;\n        }\n    }\n    dump(max_score, midx);\n\
    \n    vector<int> tmp(n);\n    int x = midx;\n    tmp[x] = m[x];\n    int cur;\n\
    \n    cur = m[x];\n    r_rep(i, 0, x) {\n        if (m[i] > cur) {\n         \
    \   tmp[i] = cur;\n        } else {\n            tmp[i] = m[i];\n            cur\
    \ = m[i];\n        }\n    }\n\n    cur = m[x];\n    rep(i, x + 1, n) {\n     \
    \   if (m[i] > cur) {\n            tmp[i] = cur;\n        } else {\n         \
    \   tmp[i] = m[i];\n            cur = m[i];\n        }\n    }\n    int s = accumulate(all(tmp),\
    \ 0LL);\n    dump(s);\n\n    rep(i, sz(tmp)) cout << tmp[i] << (i != sz(tmp) -\
    \ 1 ? \" \" : \"\\n\");\n\n    return 0;\n}\n"
  code: "#include \"../../header.hpp\"\n\ntemplate <typename T>\nstruct SegmentTree\
    \ {  // {{{\n   private:\n    using F = function<T(T, T)>;\n    int n;  // \u5143\
    \u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    int N;  // n\u4EE5\u4E0A\u306E\
    \u6700\u5C0F\u306E2\u51AA\n    vector<T> node;\n    F merge;\n    T identity;\n\
    \n   public:\n    SegmentTree() {}\n    SegmentTree(vector<T> a, F f, T id) :\
    \ merge(f), identity(id) {\n        n = a.size();\n        N = 1;\n        while\
    \ (N < n) N *= 2;\n        node.resize(2 * N - 1, identity);\n        for (int\
    \ i = 0; i < n; i++) node[i + N - 1] = a[i];\n        for (int i = N - 2; i >=\
    \ 0; i--)\n            node[i] = merge(node[2 * i + 1], node[2 * i + 2]);\n  \
    \  }\n    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id)\
    \ {}\n\n    T& operator[](int i) { return node[i + N - 1]; }\n\n    void update(int\
    \ x, T val) {\n        x += (N - 1);\n        node[x] = val;\n        while (x\
    \ > 0) {\n            x = (x - 1) / 2;\n            node[x] = merge(node[2 * x\
    \ + 1], node[2 * x + 2]);\n        }\n    }\n\n    void add(int x, T val) {\n\
    \        x += (N - 1);\n        node[x] += val;\n        while (x > 0) {\n   \
    \         x = (x - 1) / 2;\n            node[x] = merge(node[2 * x + 1], node[2\
    \ * x + 2]);\n        }\n    }\n\n    // query for [l, r)\n    T query(int a,\
    \ int b, int k = 0, int l = 0, int r = -1) {\n        if (r < 0) r = N;\n    \
    \    if (r <= a || b <= l) return identity;\n        if (a <= l && r <= b) return\
    \ node[k];\n\n        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);\n       \
    \ T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n        return merge(vl, vr);\n\
    \    }\n\n    friend ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //\n\
    \        os << \"[\";\n        for (int i = 0; i < sg.n; i++) {\n            os\
    \ << sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n        }\n        return\
    \ os;\n    }\n};\n// }}}\n\nclass segment_tree_beats {\n    // MEMO: values for\
    \ queries (max, min, lazy_add, and lazy_update) already\n    // apply to the current\
    \ node; but not for children\n    typedef struct {\n        int64_t max;\n   \
    \     int64_t max_second;\n        int max_count;\n        int64_t min;\n    \
    \    int64_t min_second;\n        int min_count;\n        int64_t lazy_add;\n\
    \        int64_t lazy_update;\n        int64_t sum;\n    } value_type;\n\n   \
    \ int n;\n    std::vector<value_type> a;\n\n   public:\n    segment_tree_beats()\
    \ = default;\n    segment_tree_beats(int n_) {\n        n = 1;\n        while\
    \ (n < n_) n *= 2;\n        a.resize(2 * n - 1);\n        tag<UPDATE>(0, 0);\n\
    \    }\n    template <class InputIterator>\n    segment_tree_beats(InputIterator\
    \ first, InputIterator last) {\n        int n_ = std::distance(first, last);\n\
    \        n = 1;\n        while (n < n_) n *= 2;\n        a.resize(2 * n - 1);\n\
    \        rep(i, n_) { tag<UPDATE>(n - 1 + i, *(first + i)); }\n        rep(i,\
    \ n_, n) { tag<UPDATE>(n - 1 + i, 0); }\n        r_rep(i, n - 1) { update(i);\
    \ }\n    }\n\n    void range_chmin(int l, int r, int64_t value) {  // 0-based,\
    \ [l, r)\n        assert(0 <= l and l <= r and r <= n);\n        range_apply<CHMIN>(0,\
    \ 0, n, l, r, value);\n    }\n    void range_chmax(int l, int r, int64_t value)\
    \ {  // 0-based, [l, r)\n        assert(0 <= l and l <= r and r <= n);\n     \
    \   range_apply<CHMAX>(0, 0, n, l, r, value);\n    }\n    void range_add(int l,\
    \ int r, int64_t value) {  // 0-based, [l, r)\n        assert(0 <= l and l <=\
    \ r and r <= n);\n        range_apply<ADD>(0, 0, n, l, r, value);\n    }\n   \
    \ void range_update(int l, int r, int64_t value) {  // 0-based, [l, r)\n     \
    \   assert(0 <= l and l <= r and r <= n);\n        range_apply<UPDATE>(0, 0, n,\
    \ l, r, value);\n    }\n\n    int64_t range_min(int l, int r) {  // 0-based, [l,\
    \ r)\n        assert(0 <= l and l <= r and r <= n);\n        return range_get<MIN>(0,\
    \ 0, n, l, r);\n    }\n    int64_t range_max(int l, int r) {  // 0-based, [l,\
    \ r)\n        assert(0 <= l and l <= r and r <= n);\n        return range_get<MAX>(0,\
    \ 0, n, l, r);\n    }\n    int64_t range_sum(int l, int r) {  // 0-based, [l,\
    \ r)\n        assert(0 <= l and l <= r and r <= n);\n        return range_get<SUM>(0,\
    \ 0, n, l, r);\n    }\n\n   private:\n    static constexpr char CHMIN = 0;\n \
    \   static constexpr char CHMAX = 1;\n    static constexpr char ADD = 2;\n   \
    \ static constexpr char UPDATE = 3;\n    static constexpr char MIN = 10;\n   \
    \ static constexpr char MAX = 11;\n    static constexpr char SUM = 12;\n\n   \
    \ template <char TYPE>\n    void range_apply(int i, int il, int ir, int l, int\
    \ r, int64_t g) {\n        if (ir <= l or r <= il or break_condition<TYPE>(i,\
    \ g)) {\n            // break\n        } else if (l <= il and ir <= r and tag_condition<TYPE>(i,\
    \ g)) {\n            tag<TYPE>(i, g);\n        } else {\n            pushdown(i);\n\
    \            range_apply<TYPE>(2 * i + 1, il, (il + ir) / 2, l, r, g);\n     \
    \       range_apply<TYPE>(2 * i + 2, (il + ir) / 2, ir, l, r, g);\n          \
    \  update(i);\n        }\n    }\n    template <char TYPE>\n    inline bool break_condition(int\
    \ i, int64_t g) {\n        switch (TYPE) {\n            case CHMIN:\n        \
    \        return a[i].max <= g;\n            case CHMAX:\n                return\
    \ g <= a[i].min;\n            case ADD:\n                return false;\n     \
    \       case UPDATE:\n                return false;\n            default:\n  \
    \              assert(false);\n        }\n    }\n    template <char TYPE>\n  \
    \  inline bool tag_condition(int i, int64_t g) {\n        switch (TYPE) {\n  \
    \          case CHMIN:\n                return a[i].max_second < g and g < a[i].max;\n\
    \            case CHMAX:\n                return a[i].min < g and g < a[i].min_second;\n\
    \            case ADD:\n                return true;\n            case UPDATE:\n\
    \                return true;\n            default:\n                assert(false);\n\
    \        }\n    }\n    template <char TYPE>\n    inline void tag(int i, int64_t\
    \ g) {\n        int length = n >> (32 - __builtin_clz(i + 1) - 1);\n        if\
    \ (TYPE == CHMIN) {\n            if (a[i].max == a[i].min or g <= a[i].min) {\n\
    \                tag<UPDATE>(i, g);\n                return;\n            }\n\
    \            if (a[i].max != INT64_MIN) {\n                a[i].sum -= a[i].max\
    \ * a[i].max_count;\n            }\n            a[i].max = g;\n            a[i].min_second\
    \ = std::min(a[i].min_second, g);\n            if (a[i].lazy_update != INT64_MAX)\
    \ {\n                a[i].lazy_update = std::min(a[i].lazy_update, g);\n     \
    \       }\n            a[i].sum += g * a[i].max_count;\n        } else if (TYPE\
    \ == CHMAX) {\n            if (a[i].max == a[i].min or a[i].max <= g) {\n    \
    \            tag<UPDATE>(i, g);\n                return;\n            }\n    \
    \        if (a[i].min != INT64_MAX) {\n                a[i].sum -= a[i].min *\
    \ a[i].min_count;\n            }\n            a[i].min = g;\n            a[i].max_second\
    \ = std::max(a[i].max_second, g);\n            if (a[i].lazy_update != INT64_MAX)\
    \ {\n                a[i].lazy_update = std::max(a[i].lazy_update, g);\n     \
    \       }\n            a[i].sum += g * a[i].min_count;\n        } else if (TYPE\
    \ == ADD) {\n            if (a[i].max != INT64_MAX) {\n                a[i].max\
    \ += g;\n            }\n            if (a[i].max_second != INT64_MIN) {\n    \
    \            a[i].max_second += g;\n            }\n            if (a[i].min !=\
    \ INT64_MIN) {\n                a[i].min += g;\n            }\n            if\
    \ (a[i].min_second != INT64_MAX) {\n                a[i].min_second += g;\n  \
    \          }\n            a[i].lazy_add += g;\n            if (a[i].lazy_update\
    \ != INT64_MAX) {\n                a[i].lazy_update += g;\n            }\n   \
    \         a[i].sum += g * length;\n        } else if (TYPE == UPDATE) {\n    \
    \        a[i].max = g;\n            a[i].max_second = INT64_MIN;\n           \
    \ a[i].max_count = length;\n            a[i].min = g;\n            a[i].min_second\
    \ = INT64_MAX;\n            a[i].min_count = length;\n            a[i].lazy_add\
    \ = 0;\n            a[i].lazy_update = INT64_MAX;\n            a[i].sum = g *\
    \ length;\n        } else {\n            assert(false);\n        }\n    }\n  \
    \  void pushdown(int i) {\n        int l = 2 * i + 1;\n        int r = 2 * i +\
    \ 2;\n        // update\n        if (a[i].lazy_update != INT64_MAX) {\n      \
    \      tag<UPDATE>(l, a[i].lazy_update);\n            tag<UPDATE>(r, a[i].lazy_update);\n\
    \            a[i].lazy_update = INT64_MAX;\n            return;\n        }\n \
    \       // add\n        if (a[i].lazy_add != 0) {\n            tag<ADD>(l, a[i].lazy_add);\n\
    \            tag<ADD>(r, a[i].lazy_add);\n            a[i].lazy_add = 0;\n   \
    \     }\n        // chmin\n        if (a[i].max < a[l].max) {\n            tag<CHMIN>(l,\
    \ a[i].max);\n        }\n        if (a[i].max < a[r].max) {\n            tag<CHMIN>(r,\
    \ a[i].max);\n        }\n        // chmax\n        if (a[l].min < a[i].min) {\n\
    \            tag<CHMAX>(l, a[i].min);\n        }\n        if (a[r].min < a[i].min)\
    \ {\n            tag<CHMAX>(r, a[i].min);\n        }\n    }\n    void update(int\
    \ i) {\n        int l = 2 * i + 1;\n        int r = 2 * i + 2;\n        // chmin\n\
    \        std::vector<int64_t> b{a[l].max, a[l].max_second, a[r].max,\n       \
    \                        a[r].max_second};\n        std::sort(b.rbegin(), b.rend());\n\
    \        b.erase(std::unique(all(b)), b.end());\n        a[i].max = b[0];\n  \
    \      a[i].max_second = b[1];\n        a[i].max_count = (b[0] == a[l].max ? a[l].max_count\
    \ : 0) +\n                         (b[0] == a[r].max ? a[r].max_count : 0);\n\
    \        // chmax\n        std::vector<int64_t> c{a[l].min, a[l].min_second, a[r].min,\n\
    \                               a[r].min_second};\n        std::sort(all(c));\n\
    \        c.erase(std::unique(all(c)), c.end());\n        a[i].min = c[0];\n  \
    \      a[i].min_second = c[1];\n        a[i].min_count = (c[0] == a[l].min ? a[l].min_count\
    \ : 0) +\n                         (c[0] == a[r].min ? a[r].min_count : 0);\n\
    \        // add\n        a[i].lazy_add = 0;\n        // update\n        a[i].lazy_update\
    \ = INT64_MAX;\n        // sum\n        a[i].sum = a[l].sum + a[r].sum;\n    }\n\
    \n    template <char TYPE>\n    int64_t range_get(int i, int il, int ir, int l,\
    \ int r) {\n        if (ir <= l or r <= il) {\n            switch (TYPE) {\n \
    \               case MIN:\n                    return INT64_MAX;\n           \
    \     case MAX:\n                    return INT64_MIN;\n                case SUM:\n\
    \                    return 0;\n                default:\n                   \
    \ assert(false);\n            }\n        } else if (l <= il and ir <= r) {\n \
    \           // base\n            switch (TYPE) {\n                case MIN:\n\
    \                    return a[i].min;\n                case MAX:\n           \
    \         return a[i].max;\n                case SUM:\n                    return\
    \ a[i].sum;\n                default:\n                    assert(false);\n  \
    \          }\n        } else {\n            pushdown(i);\n            int64_t\
    \ value_l =\n                range_get<TYPE>(2 * i + 1, il, (il + ir) / 2, l,\
    \ r);\n            int64_t value_r =\n                range_get<TYPE>(2 * i +\
    \ 2, (il + ir) / 2, ir, l, r);\n            // mult\n            switch (TYPE)\
    \ {\n                case MIN:\n                    return std::min(value_l, value_r);\n\
    \                case MAX:\n                    return std::max(value_l, value_r);\n\
    \                case SUM:\n                    return value_l + value_r;\n  \
    \              default:\n                    assert(false);\n            }\n \
    \       }\n    }\n};\n\nsigned main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ m(n);\n    vector<pair<int, int>> mi(n);\n    int mv = -INF;\n    rep(i, n)\
    \ {\n        cin >> m[i];\n        chmax(mv, m[i]);\n        mi[i] = mp(m[i],\
    \ i);\n    }\n    dump(m);\n    if (n > 100000) return 0;\n\n    vi L(n);\n  \
    \  {\n        segment_tree_beats lseg(all(m));\n        rep(i, 1, n) {\n     \
    \       if (i > 100000) return 0;\n            cerrendl;\n            lseg.range_chmin(0,\
    \ i, m[i]);\n            L[i] = lseg.range_sum(0, i);\n        }\n    }\n    dump(L);\n\
    \n    vi R(n);\n    {\n        segment_tree_beats lseg2(all(m));\n        r_rep(i,\
    \ n - 1) {\n            lseg2.range_chmin(i + 1, n, m[i]);\n            R[i] =\
    \ lseg2.range_sum(i + 1, n);\n        }\n    }\n    dump(R);\n\n    int max_score\
    \ = -INF;\n    int midx;\n    rep(i, n) {\n        int score = m[i] + L[i] + R[i];\n\
    \        dump(i, score);\n        if (score > max_score) {\n            midx =\
    \ i;\n            max_score = score;\n        }\n    }\n    dump(max_score, midx);\n\
    \n    vector<int> tmp(n);\n    int x = midx;\n    tmp[x] = m[x];\n    int cur;\n\
    \n    cur = m[x];\n    r_rep(i, 0, x) {\n        if (m[i] > cur) {\n         \
    \   tmp[i] = cur;\n        } else {\n            tmp[i] = m[i];\n            cur\
    \ = m[i];\n        }\n    }\n\n    cur = m[x];\n    rep(i, x + 1, n) {\n     \
    \   if (m[i] > cur) {\n            tmp[i] = cur;\n        } else {\n         \
    \   tmp[i] = m[i];\n            cur = m[i];\n        }\n    }\n    int s = accumulate(all(tmp),\
    \ 0LL);\n    dump(s);\n\n    rep(i, sz(tmp)) cout << tmp[i] << (i != sz(tmp) -\
    \ 1 ? \" \" : \"\\n\");\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/array/segtree/segment_tree_beats.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/segtree/segment_tree_beats.cpp
layout: document
redirect_from:
- /library/library/cpp/array/segtree/segment_tree_beats.cpp
- /library/library/cpp/array/segtree/segment_tree_beats.cpp.html
title: library/cpp/array/segtree/segment_tree_beats.cpp
---
