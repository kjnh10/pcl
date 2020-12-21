---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/array/segtree/segment_tree.hpp
    title: library/cpp/array/segtree/segment_tree.hpp
  - icon: ':question:'
    path: library/cpp/graph/edge.hpp
    title: library/cpp/graph/edge.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/cpp/include/tree_non_recursive.hpp
    title: library/cpp/include/tree_non_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: library/cpp/graph/tree.lib/lca_non_recursive.test.cpp
    title: library/cpp/graph/tree.lib/lca_non_recursive.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3
    - https://www.slideshare.net/Proktmr/ss-138534092
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\n#include <bits/stdc++.h>\nusing namespace std;\n\n// varibable settings\n\
    template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;\n\n#define\
    \ _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define\
    \ repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
    \ repi, _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i, 0, n)\n#define rrepi(i,\
    \ a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n#define r_rep(...) _overload3(__VA_ARGS__,\
    \ rrepi, _rrep, )(__VA_ARGS__)\n#define each(i, a) for (auto &&i : a)\n#define\
    \ all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n#define pb(a)\
    \ push_back(a)\n#define mp(a, b) make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n\
    #define ub upper_bound\n#define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A),\
    \ x) - A.begin())\n#define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate\
    \ <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a)\
    \ = (b); }\ntemplate <class T, class U> inline void chmin(T &a, const U &b) {\
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto make_table(X\
    \ x, T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y,\
    \ z, zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T\
    \ cdiv(T a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x,\
    \ a, b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing pll\
    \ = pair<ll, ll>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/array/segtree/segment_tree.hpp\"\
    \n// http://tsutaj.hatenablog.com/entry/2017/03/29/204841\n\n//%snippet.set('segment_tree')%\n\
    //%snippet.config({'alias':'rmq'})%\n//%snippet.fold()%\n\ntemplate <typename\
    \ X> struct SegmentTree {  // {{{\n    private:\n        using F = function<X(X,\
    \ X)>;\n        using index = int;\n        int n;  // \u5143\u306E\u914D\u5217\
    \u306E\u30B5\u30A4\u30BA\n        int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    2\u51AA\n        vector<X> node;\n        F merge;\n        X identity;\n\n  \
    \  public:\n        SegmentTree() {}\n        SegmentTree(vector<X> a, F f, X\
    \ id) : merge(f), identity(id) {\n            n = (int)a.size();\n           \
    \ N = 1;\n            while (N < n) N *= 2;\n            node.resize(2 * N - 1,\
    \ identity);\n            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n\
    \            for (int i = N - 2; i >= 0; i--)\n                node[i] = merge(node[2\
    \ * i + 1], node[2 * i + 2]);\n        }\n        SegmentTree(int sz, F f, X id)\
    \ : SegmentTree(vector<X>(sz, id), f, id) {}\n\n        X& operator[](index i)\
    \ { return node[i + N - 1]; }\n\n        void set(index i, X val) {\n        \
    \    i += (N - 1);\n            node[i] = val;\n            while (i > 0) {\n\
    \                i = (i - 1) / 2;\n                node[i] = merge(node[2 * i\
    \ + 1], node[2 * i + 2]);\n            }\n        }\n\n        void add(index\
    \ i, X val) {\n            i += (N - 1);\n            node[i] += val;\n      \
    \      while (i > 0) {\n                i = (i - 1) / 2;\n                node[i]\
    \ = merge(node[2 * i + 1], node[2 * i + 2]);\n            }\n        }\n\n   \
    \     // query for [a, b)\n        X query(index a, index b, int k = 0, index\
    \ l = 0, index r = -1) {\n            if (r < 0) r = N;\n            if (r <=\
    \ a || b <= l) return identity;\n            if (a <= l && r <= b) return node[k];\n\
    \n            X lv = query(a, b, 2 * k + 1, l, (l + r) / 2);\n            X rv\
    \ = query(a, b, 2 * k + 2, (l + r) / 2, r);\n            return merge(lv, rv);\n\
    \        }\n\n        index find_most_left(index l, const function<bool(X)>& is_ok){\n\
    \            // l\u304B\u3089\u53F3\u306B\u63A2\u3057\u3066\u3044\u3063\u3066\
    is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\
    \u8FD4\u3059\u3002\n            // assume query(l, *) has monotonity\n       \
    \     // return index i s.t is_ok(query(l, i)) does not holds, but is_ok(query(l,\
    \ i+1)) does.\n            // if such i does not exist, return n\n           \
    \ index res = _find_most_left(l, is_ok, 0, 0, N, identity).first;\n          \
    \  assert(l <= res);\n            return res;\n        }\n        pair<index,\
    \ X> _find_most_left(index a, const function<bool(X)>& is_ok, int k, index l,\
    \ index r, X left_value){\n            // params:\n                // left_value\
    \ = (a < l ? query(a, l) : ex)\n            // return (index i, X v)\n       \
    \         // i is the index in [a, n)^[l, r) s.t query(a, i+1) is ok but query(a,\
    \ i) isn't ok. if such i does not exist, i = n\n                // v is the value\
    \ s.t query(a, r)\n\n            if (r <= a) return {n, identity};  // \u533A\u9593\
    \u304C\u5168\u304F\u88AB\u3063\u3066\u3044\u306A\u3044\n            else if (a\
    \ <= l && !is_ok(merge(left_value, node[k]))) return {n, merge(left_value, node[k])};\n\
    \            else if (k >= N-1) return {k - (N-1), merge(left_value, node[k])};\n\
    \            else{\n                auto [lv, xl] = _find_most_left(a, is_ok,\
    \ 2 * k + 1, l, (l + r) / 2, left_value);\n                if (lv != n) return\
    \ {lv, xl};\n                auto [rv, xr] = _find_most_left(a, is_ok, 2 * k +\
    \ 2, (l + r) / 2, r, xl);\n                return {rv, xr};\n            }\n \
    \       }\n\n        index find_most_right(index r, const function<bool(X)>& is_ok){\n\
    \            // r\u304B\u3089\u5DE6\u306B\u63A2\u3057\u3066\u3044\u3063\u3066\
    is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\
    \u8FD4\u3059\u3002\n            // assume query(*, r) has monotonity\n       \
    \     // return index i s.t is_ok(query(i+1, r+1)) does not holds, but is_ok(query(i,\
    \ r+1)) does.\n            // if such i does not exist, return -1\n          \
    \  index res = _find_most_right(r+1, is_ok, 0, 0, N, identity).first;\n      \
    \      assert(res <= r);\n            return res;\n        }\n        pair<index,\
    \ X> _find_most_right(index b, const function<bool(X)>& is_ok, int k, index l,\
    \ index r, X right_value){\n            if (b <= l) return {-1, identity};  //\
    \ \u533A\u9593\u304C\u5168\u304F\u88AB\u3063\u3066\u3044\u306A\u3044\n       \
    \     else if (r <= b && !is_ok(merge(node[k], right_value))) return {-1, merge(node[k],\
    \ right_value)};\n            else if (k >= N-1) return {k - (N-1), merge(node[k],\
    \ right_value)};\n            else{\n                auto [rv, xr] = _find_most_right(b,\
    \ is_ok, 2 * k + 2, (l + r) / 2, r, right_value);\n                if (rv != -1)\
    \ return {rv, xr};\n                auto [lv, xl] = _find_most_right(b, is_ok,\
    \ 2 * k + 1, l, (l + r) / 2, xr);\n                return {lv, xl};\n        \
    \    }\n        }\n\n        #if defined(PCM) || defined(LOCAL)\n        friend\
    \ ostream& operator<<(ostream& os, SegmentTree<X>& sg) {  //\n            os <<\
    \ \"[\";\n            for (int i = 0; i < sg.n; i++) {\n                os <<\
    \ sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n            }\n            return\
    \ os;\n        }\n        #endif\n};/*}}}*/\n// sample of initialize SegmentTree:\n\
    // -----------------------------------------------\n// auto mymin=[](auto a, auto\
    \ b){return min(a,b);};\n// ll e = 1e18;\n// SegmentTree<ll> seg(a, mymin, e);\n\
    \n// auto mymax=[](auto a, auto b){return max(a,b);};\n// ll e = -1e18;\n// SegmentTree<ll>\
    \ seg(a, mymax, e);\n\n// auto add=[](auto a, auto b){return a+b;};\n// ll e =\
    \ 0;\n// SegmentTree<ll> seg(a, add, e);\n\n// pair<int, int> get_nearest_index_of_smaller_element(int\
    \ i){\n//     auto left = seg.find_most_right(i, [&](auto x){return x < a[i];});\n\
    //     auto right = seg.find_most_left(i, [&](auto x){return x < a[i];});\n//\
    \     return {left, right};\n// }\n// -----------------------------------------------\n\
    \n//%snippet.end()%\n#line 3 \"library/cpp/graph/edge.hpp\"\n\n//%snippet.set('edge')%\n\
    //%snippet.fold()%\ntemplate<class Cost=ll>\nstruct Edge {\n    int from, to;\n\
    \    Cost cost;\n    int idx;\n    Edge(){};\n    Edge(int from_, int to_, Cost\
    \ cost_, int idx_)\n        : from(from_), to(to_), cost(cost_), idx(idx_) {}\n\
    \n    friend ostream& operator<<(ostream& os, const Edge& e) {\n        // os\
    \ << \"(f:\" << e.from << \", t:\" << e.to << \", c:\" << e.cost << \", i\" <<\
    \ e.idx << \")\";  // detailed\n        os << \"(\" << e.from << \",\" << e.to\
    \ << \")\";\n        return os;\n    }\n};\n//%snippet.end()%\n#line 5 \"library/cpp/graph/tree.lib/tree_non_recursive.hpp\"\
    \n// (ref) https://www.slideshare.net/Proktmr/ss-138534092\n// (ref:HL decomposition)\
    \ https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3\n\n//%snippet.set('tree_non_recursive')%\n\
    //%snippet.include('segment_tree')%\n//%snippet.include('edge')%\n//%snippet.fold()%\n\
    template<class Cost=ll>\nstruct tree { \n    int n;\n    int root;\n    vector<int>\
    \ par;   // par[i]: dfs\u6728\u306B\u304A\u3051\u308B\u89AA\n    vector<Edge<Cost>*>\
    \ edge;  // edge[i]: dfs\u6728\u306B\u304A\u3051\u308B\u89AA\u3078\u306E\u8FBA\
    \u306Epointer\n    vector<int> dfstrv;  // dfstrv[i]: dfs\u6728\u3067i\u756A\u76EE\
    \u306B\u8A2A\u308C\u308B\u30CE\u30FC\u30C9\u3002dp\u306F\u3053\u308C\u3092\u9006\
    \u9806\u306B\u56DE\u3059\n    vector<int> ord;    // ord[u]: u\u306Edfs\u6728\u306B\
    \u304A\u3051\u308B\u8A2A\u554F\u9806\n    vector<int> end;    // end[u]: u\u306E\
    dfs\u7D42\u4E86\u6642\u306E\u30AB\u30A6\u30F3\u30BF\u30FC\n    vector<int> psize;\
    \  // psize[u]: u\u306Epartial tree size\n    // u\u306E\u90E8\u5206\u6728\u306F\
    [ord[u], end[u])\n    // ord\u3068dfstrv\u306F\u9006\u5909\u63DB\n    vector<int>\
    \ depth;   // depth[i]: dfs\u6728\u3067\u306Ei\u306E\u6DF1\u3055\n    vector<Cost>\
    \ ldepth;  //  ldepth[i]: dfs\u6728\u3067\u306Eroot\u304B\u3089\u306E\u8DDD\u96E2\
    \n    vector<vector<Edge<Cost>>> adj_list;       // \u8FBA(\u96A3\u63A5\u30EA\u30B9\
    \u30C8)\n    auto operator[](int pos) const { return adj_list[pos]; }\n    vector<int>\
    \ euler_tour;\n    vector<int> et_fpos;    // euler_tour first occurence position\n\
    \    vector<int> et_lpos;    // euler_tour last occurence position\n    SegmentTree<int>\
    \ _seg;  // seg(map(ord, euler_tour), mymin, 1e18)\n    vector<int> head_of_comp;\n\
    \n    tree(){};/*{{{*/\n    tree(int n_)\n        : n(n_),\n          par(n_),\n\
    \          edge(n_),\n          ord(n_),\n          end(n_),\n          psize(n_),\n\
    \          depth(n_),\n          ldepth(n_),\n          adj_list(n_),\n      \
    \    et_fpos(n_),\n          et_lpos(n_),\n          head_of_comp(n_){};/*}}}*/\n\
    \    void add_edge(int u, int v, Cost cost, int idx=-1) { /*{{{*/\n        adj_list[u].emplace_back(u,\
    \ v, cost, idx);\n        adj_list[v].emplace_back(v, u, cost, idx);\n    }  \
    \                           /*}}}*/\n    void add_edge(int u, int v) { /*{{{*/\n\
    \        adj_list[u].emplace_back(u, v, 1, -1);\n        adj_list[v].emplace_back(v,\
    \ u, 1, -1);\n    }                      /*}}}*/\n    void build(int _root) {\
    \ /*{{{*/\n        root = _root;\n        par[root] = -1;\n        edge[root]\
    \ = nullptr;\n        _dfs_basic();\n        _dfs_tree();\n        _dfs_et();\n\
    \        vector<int> ini(2 * n - 1);\n        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];\n\
    \        _seg = SegmentTree<int>(\n            ini, [](auto a, auto b) { return\
    \ min(a, b); }, numeric_limits<int>().max());\n    }                         \
    \       /*}}}*/\n    void _dfs_basic() { /*{{{*/\n        // HLD\u306Bpsize\u304C\
    \u5FC5\u8981\u306A\u306E\u3067\u307E\u305Apsize\u3060\u3051\u8A08\u7B97\u3059\u308B\
    \u3002\n        int counter = 0;\n        vector<int> dfstrv;\n        stack<pair<int,\
    \ int>> st; st.push(make_pair(root, -1));\n        while (sz(st) > 0){\n     \
    \       auto [u, pre] = st.top();st.pop();\n            ord[u] = counter;\n  \
    \          counter++;\n            par[u] = pre;\n            dfstrv.pb(u);\n\
    \            each(e, adj_list[u]) {\n                if (e.to == pre) continue;\n\
    \                st.push(make_pair(e.to, u));\n            }\n        }\n    \
    \    r_rep(i, sz(dfstrv)){\n            int u = dfstrv[i];\n            psize[u]\
    \ = 1;\n            end[u] = ord[u] + 1;\n            for (auto& e : adj_list[u])\
    \ {\n                if (e.to == par[u]) continue;\n                psize[u] +=\
    \ psize[e.to];\n                chmax(end[u], ord[u]);\n            }\n      \
    \  }\n    }                                               /*}}}*/\n    void _dfs_tree()\
    \ { /*{{{*/\n        dfstrv.clear();\n        dump(dfstrv);\n        stack<tuple<int,\
    \ int, int>> st; st.push(make_tuple(root, -1, root));\n        int counter = 0;\n\
    \        while(sz(st) > 0){\n            auto [u, pre, head_node] = st.top();\
    \ st.pop();\n            dfstrv.pb(u);\n            dump(dfstrv);\n          \
    \  ord[u] = counter;\n            counter++;\n            {\n                //\
    \ set most heavy child to top\n                int max_psize = 0;\n          \
    \      int most_heavy_i = -1;\n                rep(i, sz(adj_list[u])) {\n   \
    \                 if (adj_list[u][i].to == pre) continue;\n                  \
    \  if (psize[adj_list[u][i].to] > max_psize) {\n                        most_heavy_i\
    \ = i;\n                        max_psize = psize[adj_list[u][i].to];\n      \
    \              }\n                }\n                dump(u, max_psize, most_heavy_i);\n\
    \                if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);\n\
    \            }\n            head_of_comp[u] = head_node;\n            r_rep(i,\
    \ sz(adj_list[u])) {\n                int v = adj_list[u][i].to;\n           \
    \     if (v == pre) continue;\n                if (i == 0) st.push(make_tuple(v,\
    \ u, head_node));  // continue components\n                else        st.push(make_tuple(v,\
    \ u, v)); // new\n            }\n        }\n\n        r_rep(i, n){\n         \
    \   int u = dfstrv[i];\n            end[u] = ord[u];\n            each(e, adj_list[u])\
    \ {\n                edge[e.to] = &e;\n                if (e.to == par[u]) continue;\n\
    \                chmax(end[u], end[e.to]);\n            }\n        }\n\n     \
    \   rep(i, sz(dfstrv)){\n            int u = dfstrv[i];\n            if (par[u]\
    \ != -1){\n                depth[u] = depth[par[u]] + 1;\n                ldepth[u]\
    \ = ldepth[par[u]] + edge[u]->cost;\n            }\n        }\n\n    }       \
    \              /*}}}*/\n    void _dfs_et() { /*{{{*/\n        stack<int> st;\n\
    \        st.push(~root);  // \u5E30\u308A\u304C\u3051\u51E6\u7406\u7528\n    \
    \    st.push(root);\n        while(sz(st) > 0){\n            int u = st.top();st.pop();\n\
    \            if (u >= 0){  // \u884C\u304D\u304C\u3051\u9806\u306E\u51E6\u7406\
    \n                et_fpos[u] = euler_tour.size();\n                euler_tour.pb(u);\n\
    \                r_rep(i, sz(adj_list[u])) {\n                    int v = adj_list[u][i].to;\n\
    \                    if (v == par[u]) continue;\n                    st.push(~u);\n\
    \                    st.push(v);\n                }\n            }\n         \
    \   else{  // \u5E30\u308A\u304C\u3051\u9806\u306E\u51E6\u7406\n             \
    \   et_lpos[~u] = euler_tour.size();\n                euler_tour.pb(~u);\n   \
    \         }\n        }\n    }                       /*}}}*/\n    int lca(int u,\
    \ int v) { /*{{{*/\n        if (u == v) return u;\n        if (et_fpos[u] > et_fpos[v])\
    \ swap(u, v);\n        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];\n  \
    \  }                        /*}}}*/\n    int dist(int u, int v) { /*{{{*/\n  \
    \      int p = lca(u, v);\n        return depth[u] + depth[v] - 2 * depth[p];\n\
    \    }                          /*}}}*/\n    Cost ldist(int u, int v) {  // length\
    \ dist{{{\n        int p = lca(u, v);\n        return ldepth[u] + ldepth[v] -\
    \ 2 * ldepth[p];\n    }                           /*}}}*/\n    pair<int, int>\
    \ diameter() { /*{{{*/\n        int u, v;\n        Cost max_len = *max_element(all(ldepth));\n\
    \        rep(i, n) {\n            if (ldepth[i] == max_len) {\n              \
    \  u = i;\n                break;\n            }\n        }\n        Cost md =\
    \ -1;\n        rep(i, n) {\n            Cost d = ldist(u, i);\n            if\
    \ (d > md) {\n                v = i;\n                md = d;\n            }\n\
    \        }\n        return mp(u, v);\n    }                                  \
    \              /*}}}*/\n    vector<pair<int, int>> hld_path(int u, int v, bool\
    \ for_edge=true) {  //{{{\n        vector<pair<int, int>> res;\n        // return\
    \ {[l0, r0), [l1, r1), ....} for_edge=true\u3067lca\u306F\u9664\u3044\u3066\u8FD4\
    \u3059\u3053\u3068\u306B\u6CE8\u610F\u3002\n        while (head_of_comp[u] !=\
    \ head_of_comp[v]) {\n            if (depth[head_of_comp[u]] < depth[head_of_comp[v]])\
    \ {\n                res.push_back({ord[head_of_comp[v]], ord[v]+1});\n      \
    \          v = par[head_of_comp[v]];\n            } else {\n                res.push_back({ord[head_of_comp[u]],\
    \ ord[u]+1});\n                u = par[head_of_comp[u]];\n            }\n    \
    \    }\n        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u],\
    \ ord[v])+1});\n        return res;\n    }                              //}}}\n\
    #if defined(PCM) || defined(LOCAL) /*{{{*/\n    friend ostream& operator<<(ostream&\
    \ os, const tree& tr) {\n        os << endl;\n        os << \"psize:       \"\
    \ << tr.psize << endl;\n        os << \"par:         \" << tr.par << endl;\n \
    \       os << \"dfstrv:      \" << tr.dfstrv << endl;\n        os << \"ord:  \
    \       \" << tr.ord << endl;\n        os << \"end:         \" << tr.end << endl;\n\
    \        os << \"depth:       \" << tr.depth << endl;\n        os << \"euler_tour:\
    \  \" << tr.euler_tour << endl;\n        os << \"et_fpos:     \" << tr.et_fpos\
    \ << endl;\n        os << \"head_of_comp:\" << tr.head_of_comp << endl;\n    \
    \    return os;\n    }\n#endif /*}}}*/\n}; \n//%snippet.end()%\n"
  code: "#pragma once\n#include \"../../header.hpp\"\n#include \"../../array/segtree/segment_tree.hpp\"\
    \n#include \"../edge.hpp\"\n// (ref) https://www.slideshare.net/Proktmr/ss-138534092\n\
    // (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3\n\
    \n//%snippet.set('tree_non_recursive')%\n//%snippet.include('segment_tree')%\n\
    //%snippet.include('edge')%\n//%snippet.fold()%\ntemplate<class Cost=ll>\nstruct\
    \ tree { \n    int n;\n    int root;\n    vector<int> par;   // par[i]: dfs\u6728\
    \u306B\u304A\u3051\u308B\u89AA\n    vector<Edge<Cost>*> edge;  // edge[i]: dfs\u6728\
    \u306B\u304A\u3051\u308B\u89AA\u3078\u306E\u8FBA\u306Epointer\n    vector<int>\
    \ dfstrv;  // dfstrv[i]: dfs\u6728\u3067i\u756A\u76EE\u306B\u8A2A\u308C\u308B\u30CE\
    \u30FC\u30C9\u3002dp\u306F\u3053\u308C\u3092\u9006\u9806\u306B\u56DE\u3059\n \
    \   vector<int> ord;    // ord[u]: u\u306Edfs\u6728\u306B\u304A\u3051\u308B\u8A2A\
    \u554F\u9806\n    vector<int> end;    // end[u]: u\u306Edfs\u7D42\u4E86\u6642\u306E\
    \u30AB\u30A6\u30F3\u30BF\u30FC\n    vector<int> psize;  // psize[u]: u\u306Epartial\
    \ tree size\n    // u\u306E\u90E8\u5206\u6728\u306F[ord[u], end[u])\n    // ord\u3068\
    dfstrv\u306F\u9006\u5909\u63DB\n    vector<int> depth;   // depth[i]: dfs\u6728\
    \u3067\u306Ei\u306E\u6DF1\u3055\n    vector<Cost> ldepth;  //  ldepth[i]: dfs\u6728\
    \u3067\u306Eroot\u304B\u3089\u306E\u8DDD\u96E2\n    vector<vector<Edge<Cost>>>\
    \ adj_list;       // \u8FBA(\u96A3\u63A5\u30EA\u30B9\u30C8)\n    auto operator[](int\
    \ pos) const { return adj_list[pos]; }\n    vector<int> euler_tour;\n    vector<int>\
    \ et_fpos;    // euler_tour first occurence position\n    vector<int> et_lpos;\
    \    // euler_tour last occurence position\n    SegmentTree<int> _seg;  // seg(map(ord,\
    \ euler_tour), mymin, 1e18)\n    vector<int> head_of_comp;\n\n    tree(){};/*{{{*/\n\
    \    tree(int n_)\n        : n(n_),\n          par(n_),\n          edge(n_),\n\
    \          ord(n_),\n          end(n_),\n          psize(n_),\n          depth(n_),\n\
    \          ldepth(n_),\n          adj_list(n_),\n          et_fpos(n_),\n    \
    \      et_lpos(n_),\n          head_of_comp(n_){};/*}}}*/\n    void add_edge(int\
    \ u, int v, Cost cost, int idx=-1) { /*{{{*/\n        adj_list[u].emplace_back(u,\
    \ v, cost, idx);\n        adj_list[v].emplace_back(v, u, cost, idx);\n    }  \
    \                           /*}}}*/\n    void add_edge(int u, int v) { /*{{{*/\n\
    \        adj_list[u].emplace_back(u, v, 1, -1);\n        adj_list[v].emplace_back(v,\
    \ u, 1, -1);\n    }                      /*}}}*/\n    void build(int _root) {\
    \ /*{{{*/\n        root = _root;\n        par[root] = -1;\n        edge[root]\
    \ = nullptr;\n        _dfs_basic();\n        _dfs_tree();\n        _dfs_et();\n\
    \        vector<int> ini(2 * n - 1);\n        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];\n\
    \        _seg = SegmentTree<int>(\n            ini, [](auto a, auto b) { return\
    \ min(a, b); }, numeric_limits<int>().max());\n    }                         \
    \       /*}}}*/\n    void _dfs_basic() { /*{{{*/\n        // HLD\u306Bpsize\u304C\
    \u5FC5\u8981\u306A\u306E\u3067\u307E\u305Apsize\u3060\u3051\u8A08\u7B97\u3059\u308B\
    \u3002\n        int counter = 0;\n        vector<int> dfstrv;\n        stack<pair<int,\
    \ int>> st; st.push(make_pair(root, -1));\n        while (sz(st) > 0){\n     \
    \       auto [u, pre] = st.top();st.pop();\n            ord[u] = counter;\n  \
    \          counter++;\n            par[u] = pre;\n            dfstrv.pb(u);\n\
    \            each(e, adj_list[u]) {\n                if (e.to == pre) continue;\n\
    \                st.push(make_pair(e.to, u));\n            }\n        }\n    \
    \    r_rep(i, sz(dfstrv)){\n            int u = dfstrv[i];\n            psize[u]\
    \ = 1;\n            end[u] = ord[u] + 1;\n            for (auto& e : adj_list[u])\
    \ {\n                if (e.to == par[u]) continue;\n                psize[u] +=\
    \ psize[e.to];\n                chmax(end[u], ord[u]);\n            }\n      \
    \  }\n    }                                               /*}}}*/\n    void _dfs_tree()\
    \ { /*{{{*/\n        dfstrv.clear();\n        dump(dfstrv);\n        stack<tuple<int,\
    \ int, int>> st; st.push(make_tuple(root, -1, root));\n        int counter = 0;\n\
    \        while(sz(st) > 0){\n            auto [u, pre, head_node] = st.top();\
    \ st.pop();\n            dfstrv.pb(u);\n            dump(dfstrv);\n          \
    \  ord[u] = counter;\n            counter++;\n            {\n                //\
    \ set most heavy child to top\n                int max_psize = 0;\n          \
    \      int most_heavy_i = -1;\n                rep(i, sz(adj_list[u])) {\n   \
    \                 if (adj_list[u][i].to == pre) continue;\n                  \
    \  if (psize[adj_list[u][i].to] > max_psize) {\n                        most_heavy_i\
    \ = i;\n                        max_psize = psize[adj_list[u][i].to];\n      \
    \              }\n                }\n                dump(u, max_psize, most_heavy_i);\n\
    \                if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);\n\
    \            }\n            head_of_comp[u] = head_node;\n            r_rep(i,\
    \ sz(adj_list[u])) {\n                int v = adj_list[u][i].to;\n           \
    \     if (v == pre) continue;\n                if (i == 0) st.push(make_tuple(v,\
    \ u, head_node));  // continue components\n                else        st.push(make_tuple(v,\
    \ u, v)); // new\n            }\n        }\n\n        r_rep(i, n){\n         \
    \   int u = dfstrv[i];\n            end[u] = ord[u];\n            each(e, adj_list[u])\
    \ {\n                edge[e.to] = &e;\n                if (e.to == par[u]) continue;\n\
    \                chmax(end[u], end[e.to]);\n            }\n        }\n\n     \
    \   rep(i, sz(dfstrv)){\n            int u = dfstrv[i];\n            if (par[u]\
    \ != -1){\n                depth[u] = depth[par[u]] + 1;\n                ldepth[u]\
    \ = ldepth[par[u]] + edge[u]->cost;\n            }\n        }\n\n    }       \
    \              /*}}}*/\n    void _dfs_et() { /*{{{*/\n        stack<int> st;\n\
    \        st.push(~root);  // \u5E30\u308A\u304C\u3051\u51E6\u7406\u7528\n    \
    \    st.push(root);\n        while(sz(st) > 0){\n            int u = st.top();st.pop();\n\
    \            if (u >= 0){  // \u884C\u304D\u304C\u3051\u9806\u306E\u51E6\u7406\
    \n                et_fpos[u] = euler_tour.size();\n                euler_tour.pb(u);\n\
    \                r_rep(i, sz(adj_list[u])) {\n                    int v = adj_list[u][i].to;\n\
    \                    if (v == par[u]) continue;\n                    st.push(~u);\n\
    \                    st.push(v);\n                }\n            }\n         \
    \   else{  // \u5E30\u308A\u304C\u3051\u9806\u306E\u51E6\u7406\n             \
    \   et_lpos[~u] = euler_tour.size();\n                euler_tour.pb(~u);\n   \
    \         }\n        }\n    }                       /*}}}*/\n    int lca(int u,\
    \ int v) { /*{{{*/\n        if (u == v) return u;\n        if (et_fpos[u] > et_fpos[v])\
    \ swap(u, v);\n        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];\n  \
    \  }                        /*}}}*/\n    int dist(int u, int v) { /*{{{*/\n  \
    \      int p = lca(u, v);\n        return depth[u] + depth[v] - 2 * depth[p];\n\
    \    }                          /*}}}*/\n    Cost ldist(int u, int v) {  // length\
    \ dist{{{\n        int p = lca(u, v);\n        return ldepth[u] + ldepth[v] -\
    \ 2 * ldepth[p];\n    }                           /*}}}*/\n    pair<int, int>\
    \ diameter() { /*{{{*/\n        int u, v;\n        Cost max_len = *max_element(all(ldepth));\n\
    \        rep(i, n) {\n            if (ldepth[i] == max_len) {\n              \
    \  u = i;\n                break;\n            }\n        }\n        Cost md =\
    \ -1;\n        rep(i, n) {\n            Cost d = ldist(u, i);\n            if\
    \ (d > md) {\n                v = i;\n                md = d;\n            }\n\
    \        }\n        return mp(u, v);\n    }                                  \
    \              /*}}}*/\n    vector<pair<int, int>> hld_path(int u, int v, bool\
    \ for_edge=true) {  //{{{\n        vector<pair<int, int>> res;\n        // return\
    \ {[l0, r0), [l1, r1), ....} for_edge=true\u3067lca\u306F\u9664\u3044\u3066\u8FD4\
    \u3059\u3053\u3068\u306B\u6CE8\u610F\u3002\n        while (head_of_comp[u] !=\
    \ head_of_comp[v]) {\n            if (depth[head_of_comp[u]] < depth[head_of_comp[v]])\
    \ {\n                res.push_back({ord[head_of_comp[v]], ord[v]+1});\n      \
    \          v = par[head_of_comp[v]];\n            } else {\n                res.push_back({ord[head_of_comp[u]],\
    \ ord[u]+1});\n                u = par[head_of_comp[u]];\n            }\n    \
    \    }\n        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u],\
    \ ord[v])+1});\n        return res;\n    }                              //}}}\n\
    #if defined(PCM) || defined(LOCAL) /*{{{*/\n    friend ostream& operator<<(ostream&\
    \ os, const tree& tr) {\n        os << endl;\n        os << \"psize:       \"\
    \ << tr.psize << endl;\n        os << \"par:         \" << tr.par << endl;\n \
    \       os << \"dfstrv:      \" << tr.dfstrv << endl;\n        os << \"ord:  \
    \       \" << tr.ord << endl;\n        os << \"end:         \" << tr.end << endl;\n\
    \        os << \"depth:       \" << tr.depth << endl;\n        os << \"euler_tour:\
    \  \" << tr.euler_tour << endl;\n        os << \"et_fpos:     \" << tr.et_fpos\
    \ << endl;\n        os << \"head_of_comp:\" << tr.head_of_comp << endl;\n    \
    \    return os;\n    }\n#endif /*}}}*/\n}; \n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  - library/cpp/array/segtree/segment_tree.hpp
  - library/cpp/graph/edge.hpp
  isVerificationFile: false
  path: library/cpp/graph/tree.lib/tree_non_recursive.hpp
  requiredBy:
  - library/cpp/include/tree_non_recursive.hpp
  timestamp: '2020-12-21 23:16:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - library/cpp/graph/tree.lib/lca_non_recursive.test.cpp
documentation_of: library/cpp/graph/tree.lib/tree_non_recursive.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/tree.lib/tree_non_recursive.hpp
- /library/library/cpp/graph/tree.lib/tree_non_recursive.hpp.html
title: library/cpp/graph/tree.lib/tree_non_recursive.hpp
---
