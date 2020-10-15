---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: union_find.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp\"\
    \n#include \"../bellman_ford.hpp\"\n\nsigned main() {\n    int n, m, s;\n    cin\
    \ >> n >> m >> s;\n\n    Graph g(n);\n\n    for (int i = 0; i < m; i++) {\n  \
    \      int from, to, cost;\n        cin >> from >> to >> cost;\n        g.add_edge(from,\
    \ to, cost);\n    }\n\n    auto [negative_cycle, d] = bellman_ford(g, s);\n  \
    \  if (negative_cycle){\n        cout << \"NEGATIVE CYCLE\" << endl;\n    }\n\
    \    else{\n        rep(u, n){\n            cout << (d[u]==INF ? \"INF\" : to_string(d[u]))\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/graph/tests/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/graph/tests/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/bellman_ford.test.cpp
- /verify/library/cpp/graph/tests/bellman_ford.test.cpp.html
title: library/cpp/graph/tests/bellman_ford.test.cpp
---
