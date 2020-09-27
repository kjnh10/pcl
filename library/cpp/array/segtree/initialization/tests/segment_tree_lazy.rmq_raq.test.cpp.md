---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: initialization/segment_tree_lazy.rmq_raq.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja\"\
    \n#include \"initialization/segment_tree_lazy.rmq_raq.hpp\"\n\nint main(){\n \
    \   ll n,q;cin>>n>>q;\n    auto lseg = make_lseg_rmq_raq();\n    const int sz\
    \ = n;\n    lseg.build(vector<X>(sz, 0));\n    rep(i, q){\n        int ty;cin>>ty;\n\
    \        if (ty == 0){\n            ll s,t,x;cin>>s>>t>>x;\n            lseg.update(s,\
    \ t+1, x);\n        }\n        if (ty == 1){\n            ll s,t;cin>>s>>t;\n\
    \            cout << lseg.query(s, t+1) << endl;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rmq_raq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rmq_raq.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rmq_raq.test.cpp
- /verify/library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rmq_raq.test.cpp.html
title: library/cpp/array/segtree/initialization/tests/segment_tree_lazy.rmq_raq.test.cpp
---
