---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/misc/dfs.cpp\"\n\n\n//%snippet.set('dfs')%\n\
    \nstack<int> st;\nvector<int> used(n);\n\nst.push(0);\nwhile (!st.empty()) {\n\
    \    auto u = st.top(); st.pop();\n    if (used[u]) continue; used[u] = 1;\n\n\
    \    each(v, g[u]) {\n        if (used[v]) continue;\n        // if (d[u]+cost>=d[v])\
    \ continue;\n        // d[v] = d[u]+cost;\n        st.push(v);\n    }\n}\n\n//%snippet.end()%\n\
    \n//%snippet.set('bfs')%\n\nqueue<int> q;\nvector<int> used(n);\n\nq.push(0);\n\
    while (!q.empty()) {\n    auto u = q.front(); q.pop();\n    if (used[u]) continue;\n\
    \    used[u] = 1;\n\n    each(v, g[u]) {\n        // process\n        q.push(v);\n\
    \    }\n}\n\n//%snippet.end()%\n\n//%snippet.set('01bfs')%\n\ndeque<int> dq;\n\
    vector<int> used(n);\n\ndq.push_back(0);\nwhile (!dq.empty()) {\n    auto u =\
    \ dq.front(); dq.pop_front();\n    if (used[u]) continue;\n    used[u] = 1;\n\n\
    \    each(v, g[u]) {\n        // process\n        q.push_back(v);\n    }\n}\n\n\
    //%snippet.end()%\n"
  code: "\n\n//%snippet.set('dfs')%\n\nstack<int> st;\nvector<int> used(n);\n\nst.push(0);\n\
    while (!st.empty()) {\n    auto u = st.top(); st.pop();\n    if (used[u]) continue;\
    \ used[u] = 1;\n\n    each(v, g[u]) {\n        if (used[v]) continue;\n      \
    \  // if (d[u]+cost>=d[v]) continue;\n        // d[v] = d[u]+cost;\n        st.push(v);\n\
    \    }\n}\n\n//%snippet.end()%\n\n//%snippet.set('bfs')%\n\nqueue<int> q;\nvector<int>\
    \ used(n);\n\nq.push(0);\nwhile (!q.empty()) {\n    auto u = q.front(); q.pop();\n\
    \    if (used[u]) continue;\n    used[u] = 1;\n\n    each(v, g[u]) {\n       \
    \ // process\n        q.push(v);\n    }\n}\n\n//%snippet.end()%\n\n//%snippet.set('01bfs')%\n\
    \ndeque<int> dq;\nvector<int> used(n);\n\ndq.push_back(0);\nwhile (!dq.empty())\
    \ {\n    auto u = dq.front(); dq.pop_front();\n    if (used[u]) continue;\n  \
    \  used[u] = 1;\n\n    each(v, g[u]) {\n        // process\n        q.push_back(v);\n\
    \    }\n}\n\n//%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/misc/dfs.cpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/misc/dfs.cpp
layout: document
redirect_from:
- /library/library/cpp/misc/dfs.cpp
- /library/library/cpp/misc/dfs.cpp.html
title: library/cpp/misc/dfs.cpp
---
