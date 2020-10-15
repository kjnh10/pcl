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
  code: "#include \"../header.hpp\"\n#include \"graph.hpp\"\n\n//%snippet.set('bellman_ford')%\n\
    //%snippet.include('Graph')%\n//%snippet.fold()%\n\nauto bellman_ford(const Graph<>&\
    \ g, int start) { // \u8CA0\u9589\u8DEF\u691C\u51FA\n    vector<decltype(g.infcost)>\
    \ dist(g.n, g.infcost);  // \u6700\u77ED\u8DDD\u96E2\n    dist[start] = g.zerocost;\n\
    \    for (int i = 0; i < g.n; i++) {\n        each(edge, g.edges){\n         \
    \   if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.cost)\
    \ {\n                dist[edge.to] = dist[edge.from] + edge.cost;\n          \
    \      if (i == g.n - 1)\n                    return make_pair(true, dist);  //\
    \ n\u56DE\u76EE\u306B\u3082\u66F4\u65B0\u304C\u3042\u308B\u306A\u3089\u8CA0\u306E\
    \u9589\u8DEF\u304C\u5B58\u5728\n            }\n        }\n    }\n    return make_pair(false,\
    \ dist);\n}\n\n//%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/bellman_ford.hpp
- /library/library/cpp/graph/bellman_ford.hpp.html
title: library/cpp/graph/bellman_ford.hpp
---
