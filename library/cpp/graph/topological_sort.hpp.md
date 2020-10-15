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
  code: "#include \"../header.hpp\"\n#include \"graph.hpp\"\n\n//%snippet.set('topological_sort')%\n\
    //%snippet.include('Graph')%\n//%snippet.config({'alias':'tps'})%\n//%snippet.fold()%\n\
    \nusing Pos = int;\ntuple<bool, vector<Pos>, int> topological_sort(const Graph<>&\
    \ g) {\n    vector<Pos> res;  // sort\u5F8C\u306E\u7D50\u679C\u3092\u683C\u7D0D\
    \n    vector<int> h(g.n);  // \u9802\u70B9\u3054\u3068\u306E\u5165\u6B21\u6570\
    \n    stack<Pos> st;    // \u5165\u6B21\u6570\u304C0\u306B\u306A\u3063\u3066\u3044\
    \u308B\u9802\u70B9\u306E\u96C6\u5408\n    int max_len = 0;   // \u6700\u9577\u7D4C\
    \u8DEF\u306E\u9577\u3055\n\n    // \u5165\u6B21\u6570\u3092\u8A08\u7B97\u3059\u308B\
    \u3002\n    rep(u, g.n) {\n        for (const auto& edge : g[u]) {\n         \
    \   h[edge.to]++;\n        }\n    }\n\n    // \u6700\u521D\u306B\u5165\u6B21\u6570\
    0\u306B\u306A\u3063\u3066\u3044\u308B\u9802\u70B9\u3092\u96C6\u3081\u308B\u3002\
    \n    rep(u, g.n) {\n        if (h[u] == 0) {\n            st.push(u);\n     \
    \       res.push_back(u);\n        }\n    }\n\n    // \u5165\u6B21\u65700\u306E\
    \u9802\u70B9\u3092res\u306B\u8FFD\u52A0\u3057\u305D\u3053\u304B\u3089\u51FA\u3066\
    \u884C\u304F\u8FBA\u306F\u524A\u9664\u3057\u3066\u3044\u304F\u3002O(g.n+E)\n \
    \   while (!st.empty()) {\n        stack<Pos> nex_st;\n        while (!st.empty())\
    \ {\n            Pos u = st.top(); st.pop();\n            for (const auto& edge\
    \ : g[u]) {\n                h[edge.to]--;\n                if (h[edge.to] ==\
    \ 0) {\n                    res.push_back(edge.to);\n                    nex_st.push(edge.to);\n\
    \                }\n            }\n        }\n        max_len++;\n        st =\
    \ nex_st;\n    }\n    \n    bool is_valid = (sz(res)==g.n ? true : false);\n \
    \   return {is_valid, res, max_len};  // res.size()<g.n\u306A\u3089\u9589\u8DEF\
    \u304C\u3042\u308ADAG\u3067\u306F\u306A\u3044\u3002\u9589\u8DEF\u5185\u306E\u9802\
    \u70B9\u306Fst\u306B\u5165\u308A\u5F97\u306A\u3044\u306E\u3067\u3002\n}\n//%snippet.end()%\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/topological_sort.hpp
- /library/library/cpp/graph/topological_sort.hpp.html
title: library/cpp/graph/topological_sort.hpp
---
