---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "#line 1 \"library/cpp/graph/flow/acl_micost_application.cpp\"\n//%snippet.set('mincostflow')%\n\
    //%snippet.config({'alias':'mcf'})%\n//%snippet.fold()%\n\n#include <atcoder/mincostflow>\n\
    using namespace atcoder;\n\nmcf_graph<ll, ll> g(2*n + 4);\n// auto debug = [&](){\n\
    //     auto edges = (g.edges());\n//     for (auto& e : edges){ dump(e.from, e.to,\
    \ e.cap, e.flow, e.cost); }\n// };\nll s0 = 2*n;     // super source\nll s1 =\
    \ 2*n+1;   // original source\nll t1 = 2*n+2;   // original target\nll t0 = 2*n+3;\
    \   // super target\n\nll total_cost = 0;\nll surplus_at_super_source = 0;\nauto\
    \ add_negative_edge = [&](ll u, ll v, ll cap, ll cost){\n    assert(cost <= 0);\n\
    \    g.add_edge(s0, v, cap, 0);\n    g.add_edge(u, t0, cap, 0);\n    g.add_edge(v,\
    \ u, cap, -cost);\n    total_cost += cost;\n    surplus_at_super_source += cap;\n\
    };\n\n// add edge\ng.add_edge(t1, s1, INF, 0);\nrep(x, n) g.add_edge(s1, x, k,\
    \ 0);\nrep(x, n, 2*n) g.add_edge(x, t1, k, 0);\nrep(i, n)rep(j, n) add_negative_edge(i,\
    \ n+j, 1, -a[i][j]);\n\nauto res = g.flow(s0, t0, surplus_at_super_source);\n\
    cout << -(total_cost + res.second) << endl;\n\n// \u5FA9\u5143\nauto edges = (g.edges());\n\
    vec<string> ans(n, string(n, '.'));\nfor (auto& e : edges){\n    if (e.flow ==\
    \ 0 && e.cost > 0){\n        ans[e.to][e.from-n] = 'X';\n    }\n}\nrep(i, n) cout\
    \ << ans[i] << endl;\n\n//%snippet.end()%\n"
  code: "//%snippet.set('mincostflow')%\n//%snippet.config({'alias':'mcf'})%\n//%snippet.fold()%\n\
    \n#include <atcoder/mincostflow>\nusing namespace atcoder;\n\nmcf_graph<ll, ll>\
    \ g(2*n + 4);\n// auto debug = [&](){\n//     auto edges = (g.edges());\n//  \
    \   for (auto& e : edges){ dump(e.from, e.to, e.cap, e.flow, e.cost); }\n// };\n\
    ll s0 = 2*n;     // super source\nll s1 = 2*n+1;   // original source\nll t1 =\
    \ 2*n+2;   // original target\nll t0 = 2*n+3;   // super target\n\nll total_cost\
    \ = 0;\nll surplus_at_super_source = 0;\nauto add_negative_edge = [&](ll u, ll\
    \ v, ll cap, ll cost){\n    assert(cost <= 0);\n    g.add_edge(s0, v, cap, 0);\n\
    \    g.add_edge(u, t0, cap, 0);\n    g.add_edge(v, u, cap, -cost);\n    total_cost\
    \ += cost;\n    surplus_at_super_source += cap;\n};\n\n// add edge\ng.add_edge(t1,\
    \ s1, INF, 0);\nrep(x, n) g.add_edge(s1, x, k, 0);\nrep(x, n, 2*n) g.add_edge(x,\
    \ t1, k, 0);\nrep(i, n)rep(j, n) add_negative_edge(i, n+j, 1, -a[i][j]);\n\nauto\
    \ res = g.flow(s0, t0, surplus_at_super_source);\ncout << -(total_cost + res.second)\
    \ << endl;\n\n// \u5FA9\u5143\nauto edges = (g.edges());\nvec<string> ans(n, string(n,\
    \ '.'));\nfor (auto& e : edges){\n    if (e.flow == 0 && e.cost > 0){\n      \
    \  ans[e.to][e.from-n] = 'X';\n    }\n}\nrep(i, n) cout << ans[i] << endl;\n\n\
    //%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/flow/acl_micost_application.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/flow/acl_micost_application.cpp
layout: document
redirect_from:
- /library/library/cpp/graph/flow/acl_micost_application.cpp
- /library/library/cpp/graph/flow/acl_micost_application.cpp.html
title: library/cpp/graph/flow/acl_micost_application.cpp
---
