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
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: union_find.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../header.hpp\"\n#include \"graph.hpp\"\n\n//%snippet.set('scc')%\n\
    //%snippet.config({'alias':'StronglyConnectedComponents'})%\n//%snippet.include('Graph')%\n\
    //%snippet.fold()%\n\ntemplate<class T = ll>\nstruct StronglyConnectedComponents\
    \ {\n    const Graph<T> &g;  //{{{\n    vector<int> comp;  // comp[i]: i\u304C\
    \u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u304C\u4F55\u756A\u76EE\u306E\
    \u6210\u5206\u304B\n    Graph<> dag;  // \u7E2E\u7D04\u3055\u308C\u305FDAG graph.\
    \ size\u3092\u3068\u308C\u3070\u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\
    \u304C\u5206\u304B\u308B\u3002\n    Graph<> _rg;  // reversed graph\n    vector<int>\
    \ _order;  // order[i]: \u5E30\u308A\u304C\u3051\u9806\n    vector<int> _used;\n\
    \n    StronglyConnectedComponents(Graph<T> &_g)\n        : g(_g), comp(_g.n, -1),\
    \ _rg(_g.n), _used(_g.n) {\n        for (int i = 0; i < g.n; i++) {\n        \
    \    for (auto e : g[i]) {\n                _rg.add_edge(e.to, e.from);\n    \
    \        }\n        }\n        _build();\n    }\n\n    int operator[](int k) {\
    \ return comp[k]; }\n\n    void _build() {\n        for (int i = 0; i < g.n; i++)\
    \ _dfs(i);\n        reverse(begin(_order), end(_order));\n        int cnt = 0;\n\
    \        for (int u : _order)\n            if (comp[u] == -1) _rdfs(u, cnt), cnt++;\n\
    \n        dag = Graph(cnt);\n        for (int u = 0; u < g.n; u++) {\n       \
    \     for (auto &e : g[u]) {\n                if (comp[u] == comp[e.to]) continue;\n\
    \                dag.add_edge(comp[u], comp[e.to]);\n            }\n        }\n\
    \    }\n\n    void _dfs(int idx) {\n        if (_used[idx]) return;\n        _used[idx]\
    \ = true;\n        for (auto &e : g[idx]) _dfs(e.to);\n        _order.push_back(idx);\n\
    \    }\n\n    void _rdfs(int idx, int cnt) {\n        if (comp[idx] != -1) return;\n\
    \        comp[idx] = cnt;\n        for (auto e : _rg[idx]) _rdfs(e.to, cnt);\n\
    \    }  //}}}\n};\n// how to use\n// StronglyConnectedComponents scc(g); // g:\
    \ Graph\n// dump(scc.comp, scc.dag.adj_list);\n\n//%snippet.end()%\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/strongly_connected_components.hpp
- /library/library/cpp/graph/strongly_connected_components.hpp.html
title: library/cpp/graph/strongly_connected_components.hpp
---
