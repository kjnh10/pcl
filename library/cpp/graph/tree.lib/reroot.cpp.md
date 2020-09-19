---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':question:'
    path: library/cpp/graph/tree.lib/tree.hpp
    title: library/cpp/graph/tree.lib/tree.hpp
  - icon: ':question:'
    path: library/cpp/array/segtree/segment_tree.hpp
    title: library/cpp/array/segtree/segment_tree.hpp
  - icon: ':question:'
    path: library/cpp/graph/edge.hpp
    title: library/cpp/graph/edge.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://codeforces.com/contest/1324/problem/F
  bundledCode: "#line 1 \"library/cpp/graph/tree.lib/reroot.cpp\"\n// %test('http://codeforces.com/contest/1324/problem/F')%\n\
    #line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
    #ifndef HEADER_H\n#define HEADER_H\n\n// template version 2.0\nusing namespace\
    \ std;\n#include <bits/stdc++.h>\n\n// varibable settings\nconst long long INF\
    \ = 1e18;\ntemplate <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i,\
    \ 0, n)\n#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n\
    #define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)\n#define\
    \ each(i, a) for (auto &&i : a)\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b) make_pair(a,\
    \ b)\n#define mt(...) make_tuple(__VA_ARGS__)\n#define ub upper_bound\n#define\
    \ lb lower_bound\n#define lpos(A, x) (lower_bound(all(A), x) - A.begin())\n#define\
    \ upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate <class T, class U>\
    \ inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }\ntemplate\
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
    #line 3 \"library/cpp/array/segtree/segment_tree.hpp\"\n// http://tsutaj.hatenablog.com/entry/2017/03/29/204841\n\
    \n//%snippet.set('segment_tree')%\n//%snippet.config({'alias':'rmq'})%\n//%snippet.fold()%\n\
    \ntemplate <typename T> struct SegmentTree {  // {{{\n    private:\n        using\
    \ F = function<T(T, T)>;\n        int n;  // \u5143\u306E\u914D\u5217\u306E\u30B5\
    \u30A4\u30BA\n        int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n\
    \        vector<T> node;\n        F merge;\n        T identity;\n\n    public:\n\
    \        SegmentTree() {}\n        SegmentTree(vector<T> a, F f, T id) : merge(f),\
    \ identity(id) {\n            n = a.size();\n            N = 1;\n            while\
    \ (N < n) N *= 2;\n            node.resize(2 * N - 1, identity);\n           \
    \ for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n            for (int i\
    \ = N - 2; i >= 0; i--)\n                node[i] = merge(node[2 * i + 1], node[2\
    \ * i + 2]);\n        }\n        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n,\
    \ id), f, id) {}\n\n        T& operator[](int i) { return node[i + N - 1]; }\n\
    \n        void update(int i, T val) {\n            i += (N - 1);\n           \
    \ node[i] = val;\n            while (i > 0) {\n                i = (i - 1) / 2;\n\
    \                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);\n        \
    \    }\n        }\n\n        void add(int i, T val) {\n            i += (N - 1);\n\
    \            node[i] += val;\n            while (i > 0) {\n                i =\
    \ (i - 1) / 2;\n                node[i] = merge(node[2 * i + 1], node[2 * i +\
    \ 2]);\n            }\n        }\n\n        // query for [a, b)\n        T query(int\
    \ a, int b, int k = 0, int l = 0, int r = -1) {\n            if (r < 0) r = N;\n\
    \            if (r <= a || b <= l) return identity;\n            if (a <= l &&\
    \ r <= b) return node[k];\n\n            T vl = query(a, b, 2 * k + 1, l, (l +\
    \ r) / 2);\n            T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n     \
    \       return merge(vl, vr);\n        }\n\n        // find most right element\
    \ for [a, b)\n        int find_mr(int a, int b, function<bool(T)> is_ok, int k\
    \ = 0, int l = 0, int r = -1){\n            if (r < 0) r = N;\n            if\
    \ (r <= a || b <= l || !is_ok(node[k])) return a-1;\n            if (k >= N-1)\
    \ return k - (N-1);  // leaf\n\n            T vr = find_mr(a, b, is_ok, 2 * k\
    \ + 2, (l + r) / 2, r);\n            if (vr != a-1) return vr;\n\n           \
    \ T vl = find_mr(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);\n            return\
    \ vl;\n        }\n\n        // find most left element for [a, b)\n        int\
    \ find_ml(int a, int b, function<bool(T)> is_ok, int k = 0, int l = 0, int r =\
    \ -1){\n            // find most left\n            if (r < 0) r = N;\n       \
    \     if (r <= a || b <= l || !is_ok(node[k])) return b;\n            if (k >=\
    \ N-1) return k - (N-1);  // leaf\n\n            T vl = find_ml(a, b, is_ok, 2\
    \ * k + 1, l, (l + r) / 2);\n            if (vl != b) return vl;\n\n         \
    \   T vr = find_ml(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);\n            return\
    \ vr;\n        }\n\n        #if defined(PCM) || defined(LOCAL)\n        friend\
    \ ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //\n            os <<\
    \ \"[\";\n            for (int i = 0; i < sg.n; i++) {\n                os <<\
    \ sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n            }\n            return\
    \ os;\n        }\n        #endif\n};/*}}}*/\n// sample of initialize SegmentTree:\n\
    // -----------------------------------------------\n// auto mymin=[](auto a, auto\
    \ b){return min(a,b);};\n// SegmentTree<ll> seg(a, mymin, 1e18);\n\n// auto mymax=[](auto\
    \ a, auto b){return max(a,b);};\n// SegmentTree<ll> seg(a, mymax, -1e18);\n\n\
    // auto add=[](auto a, auto b){return a+b;};\n// SegmentTree<ll> seg(a, add, 0);\n\
    // -----------------------------------------------\n\n//%snippet.end()%\n#line\
    \ 3 \"library/cpp/graph/edge.hpp\"\n\n//%snippet.set('edge')%\n//%snippet.fold()%\n\
    template<class Cost=ll>\nstruct Edge {\n    int from, to;\n    Cost cost;\n  \
    \  int idx;\n    Edge(){};\n    Edge(int from, int to, Cost cost, int idx)\n \
    \       : from(from), to(to), cost(cost), idx(idx) {}\n\n    friend ostream& operator<<(ostream&\
    \ os, const Edge& e) {\n        // os << \"(f:\" << e.from << \", t:\" << e.to\
    \ << \", c:\" << e.cost << \", i\" << e.idx << \")\";  // detailed\n        os\
    \ << \"(\" << e.from << \",\" << e.to << \")\";\n        return os;\n    }\n};\n\
    //%snippet.end()%\n#line 5 \"library/cpp/graph/tree.lib/tree.hpp\"\n// (ref) https://www.slideshare.net/Proktmr/ss-138534092\n\
    // (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3\n\
    \n//%snippet.set('tree')%\n//%snippet.include('segment_tree')%\n//%snippet.include('edge')%\n\
    //%snippet.fold()%\ntemplate<class Cost=ll>\nstruct tree { \n    int n;\n    int\
    \ root;\n    vector<int> par;   // par[i]: dfs\u6728\u306B\u304A\u3051\u308B\u89AA\
    \n    vector<Cost> cost;  // par[i]: dfs\u6728\u306B\u304A\u3051\u308B\u89AA\u3078\
    \u306E\u8FBA\u306E\u30B3\u30B9\u30C8\n    vector<int> dfstrv;  // dfstrv[i]: dfs\u6728\
    \u3067i\u756A\u76EE\u306B\u8A2A\u308C\u308B\u30CE\u30FC\u30C9\u3002dp\u306F\u3053\
    \u308C\u3092\u9006\u9806\u306B\u56DE\u3059\n    vector<int> ord;    // ord[u]:\
    \ u\u306Edfs\u6728\u306B\u304A\u3051\u308B\u8A2A\u554F\u9806\n    vector<int>\
    \ end;    // end[u]: u\u306Edfs\u7D42\u4E86\u6642\u306E\u30AB\u30A6\u30F3\u30BF\
    \u30FC\n    vector<int> psize;  // psize[u]: u\u306Epartial tree size\n    //\
    \ u\u306E\u90E8\u5206\u6728\u306F[ord[u], end[u])\n    // ord\u3068dfstrv\u306F\
    \u9006\u5909\u63DB\n    vector<int> depth;   // depth[i]: dfs\u6728\u3067\u306E\
    i\u306E\u6DF1\u3055\n    vector<Cost> ldepth;  //  ldepth[i]: dfs\u6728\u3067\u306E\
    root\u304B\u3089\u306E\u8DDD\u96E2\n    vector<vector<Edge<Cost>>> adj_list; \
    \      // \u8FBA(\u96A3\u63A5\u30EA\u30B9\u30C8)\n    auto operator[](int pos)\
    \ const { return adj_list[pos]; }\n    vector<vector<int>> children;\n    vector<int>\
    \ euler_tour;\n    vector<int> et_fpos;    // euler_tour first occurence position\n\
    \    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)\n    vector<int>\
    \ head_of_comp;\n    int _counter = 0;\n\n    tree(){};/*{{{*/\n    tree(int n)\n\
    \        : n(n),\n          par(n),\n          cost(n),\n          ord(n),\n \
    \         end(n),\n          psize(n),\n          depth(n),\n          ldepth(n),\n\
    \          adj_list(n),\n          children(n),\n          et_fpos(n),\n     \
    \     head_of_comp(n){};/*}}}*/\n    void add_edge(int u, int v, Cost cost, int\
    \ idx=-1) { /*{{{*/\n        adj_list[u].emplace_back(u, v, cost, idx);\n    \
    \    adj_list[v].emplace_back(v, u, cost, idx);\n    }                       \
    \      /*}}}*/\n    void add_edge(int u, int v) { /*{{{*/\n        adj_list[u].emplace_back(u,\
    \ v, 1, -1);\n        adj_list[v].emplace_back(v, u, 1, -1);\n    }          \
    \            /*}}}*/\n    void build(int _root) { /*{{{*/\n        root = _root;\n\
    \        _counter = 0;\n        par[root] = -1;\n        // cost[root] = -1;\n\
    \        _dfs_psize(root, -1);\n        _dfs_tree(root, -1, root);\n        _dfs_et(root);\n\
    \        vector<int> ini(2 * n - 1);\n        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];\n\
    \        _seg = SegmentTree<int>(\n            ini, [](auto a, auto b) { return\
    \ min(a, b); }, numeric_limits<int>().max());\n    }                         \
    \       /*}}}*/\n    int _dfs_psize(int u, int pre) { /*{{{*/\n        psize[u]\
    \ = 1;\n        each(edge, adj_list[u]) {\n            if (edge.to == pre) continue;\n\
    \            psize[u] += _dfs_psize(edge.to, u);\n        }\n        return psize[u];\n\
    \    }                                               /*}}}*/\n    void _dfs_tree(int\
    \ u, int pre, int head_node) { /*{{{*/\n        dfstrv.pb(u);\n        ord[u]\
    \ = _counter;\n        if (pre != -1) {\n            depth[u] = depth[pre] + 1;\n\
    \            ldepth[u] = ldepth[pre] + cost[u];\n        }\n\n        _counter++;\n\
    \        {\n            // set most heavy child to top\n            int max_psize\
    \ = 0;\n            int most_heavy_i = -1;\n            rep(i, sz(adj_list[u]))\
    \ {\n                if (adj_list[u][i].to == pre) continue;\n               \
    \ if (psize[adj_list[u][i].to] > max_psize) {\n                    most_heavy_i\
    \ = i;\n                    max_psize = psize[adj_list[u][i].to];\n          \
    \      }\n            }\n            if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i],\
    \ adj_list[u][0]);\n        }\n\n        head_of_comp[u] = head_node;\n      \
    \  rep(i, sz(adj_list[u])) {\n            int v = adj_list[u][i].to;\n       \
    \     if (v == pre) continue;\n\n            children[u].pb(v);\n            par[v]\
    \ = u;\n            cost[v] = adj_list[u][i].cost;\n\n            if (i == 0)\n\
    \                _dfs_tree(v, u, head_node);  // continue components\n       \
    \     else\n                _dfs_tree(v, u, v);  // new\n        }\n        end[u]\
    \ = _counter;\n    }                     /*}}}*/\n    void _dfs_et(int u) { /*{{{*/\n\
    \        et_fpos[u] = euler_tour.size();\n        euler_tour.pb(u);\n        each(v,\
    \ children[u]) {\n            _dfs_et(v);\n            euler_tour.pb(u);\n   \
    \     }\n    }                       /*}}}*/\n    int lca(int u, int v) { /*{{{*/\n\
    \        if (u == v) return u;\n        if (et_fpos[u] > et_fpos[v]) swap(u, v);\n\
    \        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];\n    }           \
    \             /*}}}*/\n    int dist(int u, int v) { /*{{{*/\n        int p = lca(u,\
    \ v);\n        return depth[u] + depth[v] - 2 * depth[p];\n    }             \
    \             /*}}}*/\n    Cost ldist(int u, int v) {  // length dist{{{\n   \
    \     int p = lca(u, v);\n        return ldepth[u] + ldepth[v] - 2 * ldepth[p];\n\
    \    }                           /*}}}*/\n    pair<int, int> diameter() { /*{{{*/\n\
    \        int u, v;\n        Cost max_len = *max_element(all(ldepth));\n      \
    \  rep(i, n) {\n            if (ldepth[i] == max_len) {\n                u = i;\n\
    \                break;\n            }\n        }\n        Cost md = -1;\n   \
    \     rep(i, n) {\n            Cost d = ldist(u, i);\n            if (d > md)\
    \ {\n                v = i;\n                md = d;\n            }\n        }\n\
    \        return mp(u, v);\n    }                                             \
    \   /*}}}*/\n    vector<pair<int, int>> hld_path(int u, int v, bool for_edge=true)\
    \ {  //{{{\n        // \u9589\u533A\u9593\u3092vector\u3067\u8FD4\u3059\u3002\
    for_edge=true\u3067lca\u306F\u9664\u3044\u3066\u8FD4\u3059\u3053\u3068\u306B\u6CE8\
    \u610F\u3002\n        vector<pair<int, int>> res;\n        while (head_of_comp[u]\
    \ != head_of_comp[v]) {\n            if (depth[head_of_comp[u]] < depth[head_of_comp[v]])\
    \ {\n                res.push_back({ord[head_of_comp[v]], ord[v]});\n        \
    \        v = par[head_of_comp[v]];\n            } else {\n                res.push_back({ord[head_of_comp[u]],\
    \ ord[u]});\n                u = par[head_of_comp[u]];\n            }\n      \
    \  }\n        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u],\
    \ ord[v])});\n        return res;\n    }                              //}}}\n\
    #if defined(PCM) || defined(LOCAL) /*{{{*/\n    friend ostream& operator<<(ostream&\
    \ os, const tree& tr) {\n        os << endl;\n        os << \"par:         \"\
    \ << tr.par << endl;\n        os << \"cost:        \" << tr.cost << endl;\n  \
    \      os << \"dfstrv:      \" << tr.dfstrv << endl;\n        os << \"ord:   \
    \      \" << tr.ord << endl;\n        os << \"end:         \" << tr.end << endl;\n\
    \        os << \"depth:       \" << tr.depth << endl;\n        os << \"children:\
    \    \" << tr.children << endl;\n        os << \"euler_tour:  \" << tr.euler_tour\
    \ << endl;\n        os << \"et_fpos:     \" << tr.et_fpos << endl;\n        os\
    \ << \"head_of_comp:\" << tr.head_of_comp << endl;\n        return os;\n    }\n\
    #endif /*}}}*/\n}; \n//%snippet.end()%\n#line 4 \"library/cpp/graph/tree.lib/reroot.cpp\"\
    \n\nsigned main() {\n    int n;\n    cin >> n;\n    vector<int> col(n);\n    rep(i,\
    \ n) {\n        cin >> col[i];\n        if (col[i] == 0) col[i] = -1;\n    }\n\
    \n    //%snippet.set('reroot')%\n    tree tr(n);\n    rep(i, n - 1) {\n      \
    \  int u, v;\n        cin >> u >> v;\n        u--;\n        v--;\n        tr.add_edge(u,\
    \ v);\n    }\n    tr.build(0);\n\n    vector<map<int, int>> dp(n);\n    // dp[u][v]:\
    \ u\u306E\u89AA\u3092v\u3068\u3059\u308B\u3088\u3046\u306A\u5411\u304D\u3067\u6728\
    \u3092\u898B\u305F\u6642\u306Eu\u3092\u9802\u70B9\u3068\u3059\u308B\u90E8\u5206\
    \u6728\u306E\u60C5\u5831\n\n    // first dfs\n    r_rep(i, 1, n) {\n        //\
    \ \u8449\u304B\u3089dp\n        int u = tr.dfstrv[i];\n        dp[u][tr.par[u]]\
    \ = col[u];  // TODO: update: \u5B50\u4F9B\u304C\u3044\u306A\u3044\u5834\u5408\
    \n        each(ch, tr.children[u]) {\n            dp[u][tr.par[u]] += max(0LL,\
    \ dp[ch][u]);  // TODO: update\n        }\n    }\n    dump_2d(dp, n, n);\n\n \
    \   // second dfs\n    rep(i, 0, n) {\n        cerrendl;\n        // u\u3092\u9802\
    \u70B9\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u60C5\u5831dp[u][*]\u3092\u914D\
    \u308B\u3002\n        int u = tr.dfstrv[i];\n        int m = sz(tr.adj[u]);\n\n\
    \        vector<int> lcum(m + 2);\n        vector<int> rcum(m + 2);\n        {\
    \  // \u524D\u51E6\u7406\n            vector<int> child_info(m + 2);\n       \
    \     rep(j, 1, m + 1) {\n                int v = tr.adj[u][j - 1];\n        \
    \        child_info[j] = max(dp[v][u], 0LL);  // TODO: update\n            }\n\
    \            lcum[0] = 0;\n            lcum[m + 1] = 0;  // \u5358\u4F4D\u5143\
    \u3092\u756A\u5175\u306B  // TODO: update\n            rcum[0] = 0;\n        \
    \    rcum[m + 1] = 0;  // \u5358\u4F4D\u5143\u3092\u756A\u5175\u306B  // TODO:\
    \ update\n            rep(j, 1, m + 1) {\n                lcum[j] = lcum[j - 1]\
    \ + child_info[j];  // TODO: update\n            }\n            r_rep(j, 1, m\
    \ + 1) {\n                rcum[j] = rcum[j + 1] + child_info[j];  // TODO: update\n\
    \            }\n            dump(child_info);\n        }\n\n        dump(lcum);\n\
    \        dump(rcum);\n        rep(j, 1, m + 1) {\n            int v = tr.adj[u][j\
    \ - 1];\n            dp[u][v] = lcum[j - 1] + rcum[j + 1];  // TODO: update\n\
    \            dp[u][v] += col[u];  // \u8FFD\u52A0\u6761\u4EF6  // TODO: update\n\
    \            dump(u, v, j, dp[u][v], lcum[j - 1], rcum[j + 1], col[u]);\n    \
    \    }\n    }\n    dump_2d(dp, n, n);\n\n    // answer\n    vector<int> ans;\n\
    \    rep(u, n) {\n        int res = col[u];  // TODO: update\n        each(v,\
    \ tr.adj[u]) {\n            res += max(0LL, dp[v][u]);  // TODO: update\n    \
    \    }\n        ans.push_back(res);\n    }\n    rep(i, sz(ans)) cout << ans[i]\
    \ << (i != sz(ans) - 1 ? \" \" : \"\\n\");\n\n    //%snippet.end()%\n\n    return\
    \ 0;\n}\n"
  code: "// %test('http://codeforces.com/contest/1324/problem/F')%\n#include \"../../header.hpp\"\
    \n#include \"tree.hpp\"\n\nsigned main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ col(n);\n    rep(i, n) {\n        cin >> col[i];\n        if (col[i] == 0) col[i]\
    \ = -1;\n    }\n\n    //%snippet.set('reroot')%\n    tree tr(n);\n    rep(i, n\
    \ - 1) {\n        int u, v;\n        cin >> u >> v;\n        u--;\n        v--;\n\
    \        tr.add_edge(u, v);\n    }\n    tr.build(0);\n\n    vector<map<int, int>>\
    \ dp(n);\n    // dp[u][v]: u\u306E\u89AA\u3092v\u3068\u3059\u308B\u3088\u3046\u306A\
    \u5411\u304D\u3067\u6728\u3092\u898B\u305F\u6642\u306Eu\u3092\u9802\u70B9\u3068\
    \u3059\u308B\u90E8\u5206\u6728\u306E\u60C5\u5831\n\n    // first dfs\n    r_rep(i,\
    \ 1, n) {\n        // \u8449\u304B\u3089dp\n        int u = tr.dfstrv[i];\n  \
    \      dp[u][tr.par[u]] = col[u];  // TODO: update: \u5B50\u4F9B\u304C\u3044\u306A\
    \u3044\u5834\u5408\n        each(ch, tr.children[u]) {\n            dp[u][tr.par[u]]\
    \ += max(0LL, dp[ch][u]);  // TODO: update\n        }\n    }\n    dump_2d(dp,\
    \ n, n);\n\n    // second dfs\n    rep(i, 0, n) {\n        cerrendl;\n       \
    \ // u\u3092\u9802\u70B9\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u60C5\u5831\
    dp[u][*]\u3092\u914D\u308B\u3002\n        int u = tr.dfstrv[i];\n        int m\
    \ = sz(tr.adj[u]);\n\n        vector<int> lcum(m + 2);\n        vector<int> rcum(m\
    \ + 2);\n        {  // \u524D\u51E6\u7406\n            vector<int> child_info(m\
    \ + 2);\n            rep(j, 1, m + 1) {\n                int v = tr.adj[u][j -\
    \ 1];\n                child_info[j] = max(dp[v][u], 0LL);  // TODO: update\n\
    \            }\n            lcum[0] = 0;\n            lcum[m + 1] = 0;  // \u5358\
    \u4F4D\u5143\u3092\u756A\u5175\u306B  // TODO: update\n            rcum[0] = 0;\n\
    \            rcum[m + 1] = 0;  // \u5358\u4F4D\u5143\u3092\u756A\u5175\u306B \
    \ // TODO: update\n            rep(j, 1, m + 1) {\n                lcum[j] = lcum[j\
    \ - 1] + child_info[j];  // TODO: update\n            }\n            r_rep(j,\
    \ 1, m + 1) {\n                rcum[j] = rcum[j + 1] + child_info[j];  // TODO:\
    \ update\n            }\n            dump(child_info);\n        }\n\n        dump(lcum);\n\
    \        dump(rcum);\n        rep(j, 1, m + 1) {\n            int v = tr.adj[u][j\
    \ - 1];\n            dp[u][v] = lcum[j - 1] + rcum[j + 1];  // TODO: update\n\
    \            dp[u][v] += col[u];  // \u8FFD\u52A0\u6761\u4EF6  // TODO: update\n\
    \            dump(u, v, j, dp[u][v], lcum[j - 1], rcum[j + 1], col[u]);\n    \
    \    }\n    }\n    dump_2d(dp, n, n);\n\n    // answer\n    vector<int> ans;\n\
    \    rep(u, n) {\n        int res = col[u];  // TODO: update\n        each(v,\
    \ tr.adj[u]) {\n            res += max(0LL, dp[v][u]);  // TODO: update\n    \
    \    }\n        ans.push_back(res);\n    }\n    rep(i, sz(ans)) cout << ans[i]\
    \ << (i != sz(ans) - 1 ? \" \" : \"\\n\");\n\n    //%snippet.end()%\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - library/cpp/header.hpp
  - library/cpp/graph/tree.lib/tree.hpp
  - library/cpp/array/segtree/segment_tree.hpp
  - library/cpp/graph/edge.hpp
  isVerificationFile: false
  path: library/cpp/graph/tree.lib/reroot.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/tree.lib/reroot.cpp
layout: document
redirect_from:
- /library/library/cpp/graph/tree.lib/reroot.cpp
- /library/library/cpp/graph/tree.lib/reroot.cpp.html
title: library/cpp/graph/tree.lib/reroot.cpp
---
