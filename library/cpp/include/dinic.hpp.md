---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/flow/dinic.hpp
    title: library/cpp/graph/flow/dinic.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n// varibable settings\n\
    template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;\n\n#define\
    \ _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define\
    \ repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
    \ repi, _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i, 0, n)\n#define rrepi(i,\
    \ a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n#define r_rep(...) _overload3(__VA_ARGS__,\
    \ rrepi, _rrep, )(__VA_ARGS__)\n#define each(i, a) for (auto &&i : a)\n#define\
    \ all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n#define pb(a)\
    \ push_back(a)\n#define mp(a, b) make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n\
    #define ub upper_bound\n#define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A),\
    \ x) - A.begin())\n#define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate\
    \ <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a)\
    \ = (b); }\ntemplate <class T, class U> inline void chmin(T &a, const U &b) {\
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto make_table(X\
    \ x, T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y,\
    \ z, zs...); return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T\
    \ cdiv(T a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x,\
    \ a, b) ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing pll\
    \ = pair<ll, ll>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>,\
    \ greater<T>>;\nvoid check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp;\
    \ assert(cin.eof() == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define\
    \ dump(...) ;\n#define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl\
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/graph/flow/dinic.hpp\"\
    \n\n//%snippet.set('dinic')%\n//%snippet.config({'alias':'flow'})%\n//%snippet.fold()%\n\
    \n// Dinic: https://tubo28.me/compprog/algorithm/dinic/\nusing Capacity = int;\n\
    struct Edge {\n    int src, dst;\n    Capacity cap;\n    Edge(int src_, int dst_,\
    \ Capacity cap_) : src(src_), dst(dst_), cap(cap_) {}\n};\n\nusing Edges = vector<Edge>;\n\
    using Graph = vector<Edges>;\ntemplate <typename Flow = unsigned int>\nstruct\
    \ dinic {\n    int n, s, t;\n    vector<int> level, prog, que;\n    vector<vector<Flow>>\
    \ cap, flow;\n    vector<vector<int>> g;\n    Flow inf;\n    dinic(const Graph\
    \ &graph)/*{{{*/\n        : n(graph.size()),\n          cap(n, vector<Flow>(n)),\n\
    \          flow(n, vector<Flow>(n)),\n          g(n, vector<int>()),\n       \
    \   inf(numeric_limits<Flow>::max() / 8) {\n        for (int i = 0; i < n; i++)\
    \ {\n            for (auto &e : graph[i]) {\n                int u = e.src, v\
    \ = e.dst;\n                Flow c = e.cap;\n                cap[u][v] += c;\n\
    \                cap[v][u] += c;\n                flow[v][u] += c;\n         \
    \       g[u].push_back(v);\n                g[v].push_back(u);\n            }\n\
    \        }\n    }/*}}}*/\n    Flow solve(int s_, int t_) {/*{{{*/\n        this->t\
    \ = t_, this->s = s_;\n        que.resize(n + 1);\n        Flow res = 0;\n   \
    \     while (levelize()) {\n            prog.assign(n, 0);\n            res +=\
    \ augment(s, inf);\n        }\n        return res;\n    }/*}}}*/\n\nprivate:\n\
    \    inline Flow residue(int u, int v) { return cap[u][v] - flow[u][v]; }\n  \
    \  bool levelize() {/*{{{*/\n        int l = 0, r = 0;\n        level.assign(n,\
    \ -1);\n        level[s] = 0;\n        que[r++] = s;\n        while (l != r) {\n\
    \            int v = que[l++];\n            if (v == t) break;\n            for\
    \ (const int &d : g[v])\n                if (level[d] == -1 && residue(v, d) !=\
    \ 0) {\n                    level[d] = level[v] + 1;\n                    que[r++]\
    \ = d;\n                }\n        }\n        return level[t] != -1;\n    }/*}}}*/\n\
    \    Flow augment(int v, Flow lim) {/*{{{*/\n        Flow res = 0;\n        if\
    \ (v == t) return lim;\n        for (int &i = prog[v]; i < (int)g[v].size(); i++)\
    \ {\n            const int &d = g[v][i];\n            if (residue(v, d) == 0 ||\
    \ level[v] >= level[d]) continue;\n            const Flow aug = augment(d, std::min(lim,\
    \ residue(v, d)));\n            flow[v][d] += aug;\n            flow[d][v] -=\
    \ aug;\n            res += aug;\n            lim -= aug;\n            if (lim\
    \ == 0) break;\n        }\n        return res;\n    }/*}}}*/\n};\n// Graph g(n);\n\
    // auto connect = [&](int x, int y, auto cost){\n//     g[x].emplace_back(x, y,\
    \ cost);\n// };\n\n// int u,v;cin>>u>>v;\n// connect(u, v, 1);\n\n// auto f =\
    \ dinic(g).solve(S, T);\n\n//%snippet.end()%\n#line 2 \"library/cpp/include/dinic.hpp\"\
    \n"
  code: '#include "../graph/flow/dinic.hpp"'
  dependsOn:
  - library/cpp/graph/flow/dinic.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/dinic.hpp
  requiredBy: []
  timestamp: '2020-11-15 09:51:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/dinic.hpp
layout: document
redirect_from:
- /library/library/cpp/include/dinic.hpp
- /library/library/cpp/include/dinic.hpp.html
title: library/cpp/include/dinic.hpp
---
