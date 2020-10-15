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
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=ja\"\
    \n// \u6A4B\n\n#include \"../graph.hpp\"\n\nsigned main() {\n    int n, m;\n \
    \   cin >> n >> m;\n    Graph g(n);\n    rep(i, m) {\n        int u, v;\n    \
    \    cin >> u >> v;\n        g.add_edge(u, v, 1, i);\n        g.add_edge(v, u,\
    \ 1, i);\n    }\n    g.build_tree(0);\n    dump(g.tr);\n\n    auto res = g.get_bridges();\n\
    \    vector<pair<int, int>> ans;\n    for(auto&&el: res){\n        int s = el.from;\n\
    \        int t = el.to;\n        if (s>t) swap(s, t);\n        ans.pb(mp(s, t));\n\
    \    }\n    sort(all(ans));\n    each(el, ans){\n        cout << el.first << \"\
    \ \" << el.second << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/graph/tests/graph.bridge.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/graph/tests/graph.bridge.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/graph.bridge.test.cpp
- /verify/library/cpp/graph/tests/graph.bridge.test.cpp.html
title: library/cpp/graph/tests/graph.bridge.test.cpp
---
