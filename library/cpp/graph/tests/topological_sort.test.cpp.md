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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/30\"\n#include \"../topological_sort.hpp\"\
    \n\n\nint main() {\n    ll n;cin>>n;\n    ll m;cin>>m;\n\n    Graph<ll> g(n);\n\
    \    rep(i, m){\n        ll a,c,b;cin>>a>>c>>b;\n        a--;b--;\n        g.add_edge(b,\
    \ a, c);\n    }\n    auto tp = get<1>(topological_sort(g));\n\n    vl ans(n-1);\n\
    \    vl cnt(n);\n    cnt[n-1] = 1;\n    each(u, tp){\n        each(edge, g.adj_list[u])\
    \ cnt[edge.to] += cnt[u] * edge.cost;\n        if (g.adj_list[u].empty()) ans[u]\
    \ += cnt[u];\n    }\n    rep(i, n-1) cout << ans[i] << endl;\n    return 0; \n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/graph/tests/topological_sort.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/graph/tests/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/topological_sort.test.cpp
- /verify/library/cpp/graph/tests/topological_sort.test.cpp.html
title: library/cpp/graph/tests/topological_sort.test.cpp
---
