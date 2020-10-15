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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: union_find.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/274\"\n#include \"../two_sat.hpp\"\
    \n\nint main() {\n    int n,m;cin>>n>>m;\n    vector<int> l(n), r(n);\n    rep(i,\
    \ n){\n        cin>>l[i]>>r[i];\n    }\n\n    two_sat ts(n);\n\n    rep(i, n){\n\
    \        rep(j, i+1, n){\n            if (r[j] < l[i] || r[i] < l[j]) {\n    \
    \        }\n            else{\n                ts.add_condition(i, 0, j, 0);\n\
    \                ts.add_condition(i, 1, j, 1);\n            }\n\n            if\
    \ (r[j] < m-1-r[i] || m-1-l[i] < l[j]) {\n            }\n            else{\n \
    \               ts.add_condition(i, 0, j, 1);\n                ts.add_condition(i,\
    \ 1, j, 0);\n            }\n        }\n    }\n    auto valid = ts.build();\n \
    \   cout << (valid ? \"YES\" : \"NO\") << endl;\n\n    return 0; \n}\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/graph/tests/two_sat.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/graph/tests/two_sat.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/two_sat.test.cpp
- /verify/library/cpp/graph/tests/two_sat.test.cpp.html
title: library/cpp/graph/tests/two_sat.test.cpp
---
