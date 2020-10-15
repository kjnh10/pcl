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
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp\"\
    \n#include \"../strongly_connected_components.hpp\"\n\nsigned main() {\n    int\
    \ n, m;\n    cin >> n >> m;\n    Graph g(n);\n    rep(i, m) {\n        int from,\
    \ to;\n        cin >> from >> to;\n        g.add_edge(from, to);\n    }\n    StronglyConnectedComponents\
    \ scc(g);\n    dump(scc.comp);\n    rep(i, sz(scc.dag.adj_list)){\n        dump(scc.dag.adj_list[i]);\n\
    \    }\n    dump(scc._order);\n\n    // 01_small_01.in\n    // scc.comp:[0, 0,\
    \ 2, 1, 0, 0, 4, 3, 3, 3, 3, 4, 4, 4] in [15:main]\n    // scc.dag.adj_list[i]:[(0,2),\
    \ (0,1), (0,4), (0,4)] in [17:main]\n    // scc.dag.adj_list[i]:[(1,3), (1,3)]\
    \ in [17:main]\n    // scc.dag.adj_list[i]:[(2,3)] in [17:main]\n    // scc.dag.adj_list[i]:[]\
    \ in [17:main]\n    // scc.dag.adj_list[i]:[] in [17:main]\n    // scc._order:[0,\
    \ 3, 2, 7, 8, 9, 10, 1, 5, 11, 12, 13, 6, 4] in [19:main]\n\n    int q;\n    cin\
    \ >> q;\n    rep(_, q) {\n        int x, y;\n        cin >> x >> y;\n        if\
    \ (scc[x] == scc[y]) {\n            cout << 1 << endl;\n        } else {\n   \
    \         cout << 0 << endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/graph/tests/scc.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/graph/tests/scc.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/scc.test.cpp
- /verify/library/cpp/graph/tests/scc.test.cpp.html
title: library/cpp/graph/tests/scc.test.cpp
---
