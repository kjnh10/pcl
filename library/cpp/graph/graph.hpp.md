---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: union_find.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../header.hpp\"\n#include \"edge.hpp\"\n#include\
    \ \"tree.lib/tree.hpp\"\n#include \"union_find.hpp\"\n\n//%snippet.set('Graph')%\n\
    //%snippet.include('union_find')%\n//%snippet.include('tree')%\n//%snippet.fold()%\n\
    \ntemplate<class Cost=ll>\nstruct Graph {\n    using Pos = int;  // int\u4EE5\u5916\
    \u306B\u306F\u5BFE\u5FDC\u3057\u306A\u3044\u3002\n\n    int n;  // \u9802\u70B9\
    \u6570\n    vector<vector<Edge<Cost>>> adj_list;\n    auto operator[](Pos pos)\
    \ const { return adj_list[pos]; }\n    vector<Edge<Cost>> edges;\n    tree<Cost>\
    \ tr;\n    Pos root;\n    vector<int> _used_in_dfs;\n    vector<int> lowlink;\n\
    \    Cost zerocost;\n    Cost infcost;\n\n    Graph() {}\n    Graph(int _n) :\
    \ n(_n), adj_list(_n), tr(n), _used_in_dfs(n), zerocost(0LL), infcost(INF) { }\n\
    \    Graph(int _n, Cost zc, Cost ic) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n),\
    \ zerocost(zc), infcost(ic) { }\n\n    void add_edge(Pos from, Pos to, Cost cost,\
    \ int idx=-1) {/*{{{*/\n        adj_list[from].emplace_back(from, to, cost, idx);\n\
    \        edges.emplace_back(from, to, cost, idx);\n    }\n    void add_edge(Pos\
    \ from, Pos to) {  // for ll\n        adj_list[from].emplace_back(from, to, 1,\
    \ -1);\n        edges.emplace_back(from, to, 1, -1);\n    }/*}}}*/\n\n    void\
    \ build_tree(Pos _root) {/*{{{*/\n        root = _root;\n        _dfs_tree(root);\n\
    \        tr.build(root);\n        _make_lowlink();\n    }/*}}}*/\n\n    vector<int>\
    \ make_bipartite() {/*{{{*/\n        union_find buf(2 * n);\n        rep(u, n)\
    \ {\n            each(e, adj_list[u]) {\n                buf.merge(u, e.to + n);\n\
    \                buf.merge(e.to, u + n);\n            }\n        }\n\n       \
    \ vector<int> res(n, -1);\n        rep(u, n) {\n            if (buf.same(u, u\
    \ + n)) return res;\n        }\n        rep(u, n) {\n            if (buf.same(0,\
    \ u)) res[u] = 0;\n            else res[u] = 1;\n        }\n        return res;\n\
    \    }/*}}}*/\n\n    void _dfs_tree(Pos u) {/*{{{*/\n        _used_in_dfs[u] =\
    \ 1;\n        each(e, adj_list[u]) {\n            if (_used_in_dfs[e.to]) continue;\n\
    \            tr.add_edge(u, e.to, e.cost);\n            _dfs_tree(e.to);\n   \
    \     }\n    }/*}}}*/\n\n    void _make_lowlink() {/*{{{*/\n        lowlink =\
    \ vector<Pos>(n, numeric_limits<Pos>().max());\n        r_rep(i, n) {\n      \
    \      Pos u = tr.dfstrv[i];\n            chmin(lowlink[u], tr.ord[u]);\n\n  \
    \          each(e, adj_list[u]) {\n                if (e.to == tr.par[u])\n  \
    \                  continue;\n                else if (tr.ord[e.to] < tr.ord[u])\
    \ {\n                    chmin(lowlink[u], tr.ord[e.to]);\n                } else\
    \ {\n                    chmin(lowlink[u], lowlink[e.to]);\n                }\n\
    \            }\n        }\n    }/*}}}*/\n\n    vector<Pos> get_articulation_points()\
    \ {/*{{{*/\n        if (sz(lowlink) == 0) throw(\"make_lowlik() beforehand\");\n\
    \n        vector<Pos> res;\n        if (sz(tr.children[root]) > 1) {\n       \
    \     res.push_back(root);\n        }\n        rep(u, 0, n) {\n            if\
    \ (u == root) continue;\n            bool is_kan = false;\n            each(v,\
    \ tr.children[u]) {\n                if (tr.ord[u] <= lowlink[v]) {\n        \
    \            is_kan = true;\n                }\n            }\n            if\
    \ (is_kan) res.push_back(u);\n        }\n        return res;\n    }/*}}}*/\n\n\
    \    vector<Edge<Cost>> get_bridges() {/*{{{*/\n        if (sz(lowlink) == 0)\
    \ throw(\"make_lowlik() beforehand\");\n        vector<Edge<Cost>> res;\n    \
    \    each(edge, edges){\n            if (tr.ord[edge.from] < lowlink[edge.to])\
    \ res.push_back(edge);\n        }\n        return res;\n    }/*}}}*/\n\n    vector<Edge<Cost>>\
    \ kruskal_tree() {/*{{{*/\n        // \u4F7F\u7528\u3055\u308C\u308B\u8FBA\u306E\
    vector\u3092\u8FD4\u3059\n        vector<Edge<Cost>> res(n - 1);\n        sort(all(edges),\
    \ [&](auto l, auto r) { return l.cost < r.cost; });\n        union_find uf(n);\n\
    \n        Cost total_cost = zerocost;\n        int idx = 0;\n        each(e, edges)\
    \ {\n            if (uf.same(e.from, e.to)) continue;\n            uf.merge(e.from,\
    \ e.to);\n            total_cost = total_cost + e.cost;\n            res[idx]\
    \ = e;\n            idx++;\n        }\n        assert(idx == n - 1);\n\n     \
    \   return res;\n    }/*}}}*/\n\n    vector<Cost> dijkstra(vector<Pos> starts)\
    \ {  // \u591A\u70B9\u30B9\u30BF\u30FC\u30C8{{{\n        vector<Cost> dist(n,\
    \ infcost);           // \u6700\u77ED\u8DDD\u96E2\n        PQ<pair<Cost, Pos>>\
    \ pq;\n        each(start, starts) {\n            dist[start] = zerocost;\n  \
    \          pq.push(make_pair(zerocost, start));\n        }\n        while (!pq.empty())\
    \ {\n            auto cp = pq.top();\n            pq.pop();\n            auto\
    \ [cost, u] = cp;\n            for (const auto& edge : adj_list[u]) {\n      \
    \          Cost new_cost = cost + edge.cost;  // TODO: \u554F\u984C\u306B\u3088\
    \u3063\u3066\u306F\u3053\u3053\u304C\u5909\u66F4\u306E\u5FC5\u8981\u3042\u308A\
    \n                if (new_cost < dist[edge.to]) {\n                    dist[edge.to]\
    \ = new_cost;\n                    pq.push(make_pair(new_cost, edge.to));\n  \
    \              }\n            }\n        }\n        return dist;\n    };/*}}}*/\n\
    \n    vector<Cost> dijkstra(Pos start) {  // 1\u70B9\u30B9\u30BF\u30FC\u30C8{{{\n\
    \        vector<Pos> starts = {start};\n        return dijkstra(starts);\n   \
    \ };/*}}}*/\n};\n\n//%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/graph.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/graph.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/graph.hpp
- /library/library/cpp/graph/graph.hpp.html
title: library/cpp/graph/graph.hpp
---
