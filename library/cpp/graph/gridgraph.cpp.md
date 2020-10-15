---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc151/submissions/12467532
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
  code: "#include \"../header.hpp\"\n#include \"graph.hpp\"\n\nsigned main() {\n \
    \   //%snippet.set('gridgraph')%\n\n    // grid graph\u3092\u901A\u5E38\u306E\u30B0\
    \u30E9\u30D5\u306B\u683C\u7D0D\u3059\u308B\u3002\n    int h, w;\n    cin >> h\
    \ >> w;\n    int n = h * w;  // \u9802\u70B9\u6570\n    vector<vector<ll>> block(h,\
    \ vector<ll>(w));\n    rep(i, h) {\n        string s;\n        cin >> s;\n   \
    \     rep(j, w) { block[i][j] = (s[j] == '#' ? 1 : 0); }\n    }\n\n    Graph g(n);\n\
    \n    auto nid = [&](int i, int j){return (i*w + j);};\n    // int u = nid(i,\
    \ j);\n    auto pos = [&](int u) -> pair<int, int> { return {u/w, u%w}; };\n \
    \   // auto [i,j] = pos(u);\n\n    int dx[] = {1, -1, 0, 0};\n    int dy[] = {0,\
    \ 0, 1, -1};\n\n    // \u4E0B\u3068\u53F3\u306E\u307F. rep(k, 4)\u3092rep(k, 2)\u306B\
    \u5909\u66F4\u3059\u308B\u306E\u3082\u5FD8\u308C\u306A\u3044\u3002\n    // int\
    \ dx[] = {1, 0};\n    // int dy[] = {0, 1};\n    rep(i, h) rep(j, w) {\n     \
    \   if (block[i][j]) continue;  // block\u304B\u3089\u51FA\u308B\u8FBA\u306F\u306A\
    \u3044\n        rep(dir, 4) {\n            int ni = i + dx[dir];\n           \
    \ int nj = j + dy[dir];\n            if (is_in(ni, 0, h) && is_in(nj, 0, w)) {\n\
    \                if (block[ni][nj]) continue;  // block\u306B\u5165\u308B\u8FBA\
    \u306F\u306A\u3044\n                g.add_edge(nid(i, j), nid(ni, nj));\n    \
    \            // \u81EA\u5206\u304B\u3089\u751F\u3048\u308B\u8FBA\u3060\u3051\u3067\
    \u3088\u3044\u3002\u305D\u3046\u3057\u306A\u3044\u3068\u4E8C\u91CD\u8FBA\u306B\
    \u306A\u3063\u3066\u3057\u307E\u3046\u3002\n            }\n        }\n    }\n\
    \    //%snippet.end()%\n\n    // https://atcoder.jp/contests/abc151/submissions/12467532\n\
    \    // (language update\u304C\u7D42\u308F\u308B\u307E\u3067\u306F\u672Averiyf)\n\
    \    ll ans = 0;\n    rep(s, n){\n        auto d = g.dijkstra(s);\n        rep(i,\
    \ sz(d)) if (d[i]<INF) chmax(ans, d[i]);\n    }\n    cout << ans << endl;\n\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/gridgraph.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/gridgraph.cpp
layout: document
redirect_from:
- /library/library/cpp/graph/gridgraph.cpp
- /library/library/cpp/graph/gridgraph.cpp.html
title: library/cpp/graph/gridgraph.cpp
---
