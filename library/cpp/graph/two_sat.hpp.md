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
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: union_find.hpp:\
    \ line -1: no such header\n"
  code: "#include \"strongly_connected_components.hpp\"\n#include \"topological_sort.hpp\"\
    \n\n//%snippet.set('two_sat')%\n//%snippet.include('scc')%\n//%snippet.include('topological_sort')%\n\
    //%snippet.fold()%\n\nstruct two_sat{\n    using Pos = int;\n    using Size =\
    \ int;\n    Size orig_n;\n    Graph<bool> g;\n    vector<int> assigned;\n\n  \
    \  two_sat(Size _orig_n): orig_n(_orig_n){\n        g = Graph<bool>(orig_n * 2);\
    \  // \u9802\u70B9\u500D\u52A0\n    };\n\n    Pos toid(Pos u, bool is_u) {\n \
    \       return u * 2 + is_u;\n    }\n\n    void add_condition(Pos u, bool is_u,\
    \ Pos v, bool is_v) {\n        // add condition (u == is_u or v == is_v)\n   \
    \     g.add_edge(toid(u, is_u^1), toid(v, is_v));\n        g.add_edge(toid(v,\
    \ is_v^1), toid(u, is_u));\n    }\n\n    bool build(){\n        // if successed\
    \ to assigne valiables, return true, else return false\u3002\n        StronglyConnectedComponents\
    \ scc(g);\n        auto ts = get<1>(topological_sort(scc.dag));\n        vector<Size>\
    \ ord(sz(ts));\n        rep(i, sz(ts)) ord[ts[i]] = i;\n\n        // check valid\n\
    \        rep(u, orig_n){\n            if (scc.comp[toid(u, 0)] == scc.comp[toid(u,\
    \ 1)]) {\n                return false;\n            }\n        }\n\n        assigned\
    \ = vector<int>(orig_n, -1);\n        rep(u, orig_n){\n            assigned[u]\
    \ = (ord[scc.comp[toid(u, 0)]] < ord[scc.comp[toid(u, 1)]] ? 1 : 0);\n       \
    \ }\n        return true;\n    }\n};\n// how to use\n// two_sat ts(n); // n\u5909\
    \u6570\n// ts.add_condition(x, 1, y, 0);  // represents (x==1 or y==0)\n// ......\n\
    // ......\n// auto valid = ts.build();\n// if (valid) dump(ts.assigned);\n\n//%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/two_sat.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/two_sat.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/two_sat.hpp
- /library/library/cpp/graph/two_sat.hpp.html
title: library/cpp/graph/two_sat.hpp
---
