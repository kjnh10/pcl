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
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: union_find.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C\"\
    \n\n#include \"../../header.hpp\"\n#include \"../graph.hpp\"\n\nsigned main()\
    \ {\n    int n;\n    cin >> n;\n    Graph g(n);\n    rep(i, n) {\n        int\
    \ u;\n        cin >> u;\n        int k;\n        cin >> k;\n        rep(j, k)\
    \ {\n            int to, cost;\n            cin >> to >> cost;\n            g.add_edge(u,\
    \ to, cost, i);\n        }\n    }\n    auto d = g.dijkstra(0);\n    rep(i, n)\
    \ { cout << i << \" \" << d[i] << endl; }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/graph/tests/graph.dijkstra.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/graph/tests/graph.dijkstra.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/graph.dijkstra.test.cpp
- /verify/library/cpp/graph/tests/graph.dijkstra.test.cpp.html
title: library/cpp/graph/tests/graph.dijkstra.test.cpp
---
