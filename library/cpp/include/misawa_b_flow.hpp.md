---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/cpp/graph/flow/misawa_b_flow.hpp
    title: library/cpp/graph/flow/misawa_b_flow.hpp
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
    \ ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/graph/flow/misawa_b_flow.hpp\"\
    \n\nenum Objective {/*{{{*/\n    MINIMIZE = 1,\n    MAXIMIZE = -1,\n};/*}}}*/\n\
    enum class Status {/*{{{*/\n    OPTIMAL,\n    INFEASIBLE,\n};/*}}}*/\n\ntemplate\
    \ <class Flow, class Cost, Objective objective = Objective::MINIMIZE>\nclass MinCostFlow\
    \ {\n    using V_id = uint32_t;\n    using E_id = uint32_t;\n\n    class Edge\
    \ {/*{{{*/\n        friend class MinCostFlow;\n\n        V_id src, dst;\n    \
    \    Flow flow, cap;\n        Cost cost;\n        E_id rev;\n\n        public:\n\
    \        Edge() = default;\n\n        Edge(const V_id src, const V_id dst, const\
    \ Flow cap, const Cost cost, const E_id rev)\n            : src(src), dst(dst),\
    \ flow(0), cap(cap), cost(cost), rev(rev) {}\n\n        [[nodiscard]] Flow residual_cap()\
    \ const { return cap - flow; }\n    };/*}}}*/\n\n    public:\n    class EdgePtr\
    \ {/*{{{*/\n        friend class MinCostFlow;\n\n        const MinCostFlow *instance;\n\
    \        V_id v;\n        E_id e;\n\n        EdgePtr(const MinCostFlow * const\
    \ instance, const V_id v, const E_id e)\n            : instance(instance), v(v),\
    \ e(e) {}\n\n        [[nodiscard]] const Edge &edge() const { return instance->g[v][e];\
    \ }\n\n        [[nodiscard]] const Edge &rev() const {\n            const Edge\
    \ &e = edge();\n            return instance->g[e.dst][e.rev];\n        }\n\n \
    \       public:\n        EdgePtr() = default;\n\n        [[nodiscard]] V_id src()\
    \ const { return v; }\n\n        [[nodiscard]] V_id dst() const { return edge().dst;\
    \ }\n\n        [[nodiscard]] Flow flow() const { return edge().flow; }\n\n   \
    \     [[nodiscard]] Flow lower() const { return -rev().cap; }\n\n        [[nodiscard]]\
    \ Flow upper() const { return edge().cap; }\n\n        [[nodiscard]] Cost cost()\
    \ const { return edge().cost; }\n\n        [[nodiscard]] Cost gain() const { return\
    \ -edge().cost; }\n    };/*}}}*/\n\n    private:\n    V_id n;\n    vector<vector<Edge>>\
    \ g;\n    vector<Flow> b;\n\n    public:\n    MinCostFlow() : n(0) {}\n    V_id\
    \ add_vertex() {/*{{{*/\n        ++n;\n        g.resize(n);\n        b.resize(n);\n\
    \        return n-1;\n    }/*}}}*/\n    vector<V_id> add_vertices(const size_t\
    \ size) {/*{{{*/\n        vector<V_id> ret(size);\n        iota(begin(ret), end(ret),\
    \ n);\n        n += size;\n        g.resize(n);\n        b.resize(n);\n      \
    \  return ret;\n    }/*}}}*/\n    EdgePtr add_edge(const V_id src, const V_id\
    \ dst, const Flow lower, const Flow upper, const Cost cost) {/*{{{*/\n       \
    \ const E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();\n   \
    \     assert(lower <= upper);\n        g[src].emplace_back(Edge{src, dst, upper,\
    \ cost * objective, re});\n        g[dst].emplace_back(Edge{dst, src, -lower,\
    \ -cost * objective, e});\n        return EdgePtr{this, src, e};\n    }/*}}}*/\n\
    \    void add_supply(const V_id v, const Flow amount) { b[v] += amount; }\n  \
    \  void add_demand(const V_id v, const Flow amount) { b[v] -= amount; }\n\n  \
    \  private:\n    // Variables used in calculation\n    static Cost constexpr unreachable\
    \ = numeric_limits<Cost>::max();\n    Cost farthest;\n    vector<Cost> potential;\n\
    \    vector<Cost> dist;\n    vector<Edge *> parent; // out-forrest.\n    priority_queue<pair<Cost,\
    \ int>, vector<pair<Cost, int>>, greater<>> pq; // should be empty outside of\
    \ dual()\n    vector<V_id> excess_vs, deficit_vs;\n    Edge &rev(const Edge &e)\
    \ { return g[e.dst][e.rev]; }\n\n    void push(Edge &e, const Flow amount) {/*{{{*/\n\
    \        e.flow += amount;\n        g[e.dst][e.rev].flow -= amount;\n    }/*}}}*/\n\
    \    Cost residual_cost(const V_id src, const V_id dst, const Edge &e) {/*{{{*/\n\
    \        return e.cost + potential[src] - potential[dst];\n    }/*}}}*/\n    bool\
    \ dual() {/*{{{*/\n        dist.assign(n, unreachable);\n        parent.assign(n,\
    \ nullptr);\n        excess_vs.erase(remove_if(begin(excess_vs), end(excess_vs),\n\
    \                    [&](const V_id v) { return b[v] <= 0; }),\n             \
    \   end(excess_vs));\n        deficit_vs.erase(remove_if(begin(deficit_vs),\n\
    \                    end(deficit_vs),\n                    [&](const V_id v) {\
    \ return b[v] >= 0; }),\n                end(deficit_vs));\n        for (const\
    \ auto v : excess_vs) pq.emplace(dist[v] = 0, v);\n        farthest = 0;\n   \
    \     size_t deficit_count = 0;\n        while (!pq.empty()) {\n            const\
    \ auto [d, u] = pq.top();\n            pq.pop();\n            if (dist[u] < d)\
    \ continue;\n            farthest = d;\n            if (b[u] < 0) ++deficit_count;\n\
    \            if (deficit_count >= deficit_vs.size()) break;\n            for (auto\
    \ &e : g[u]) {\n                if (e.residual_cap() <= 0) continue;\n       \
    \         const auto v = e.dst;\n                const auto new_dist = d + residual_cost(u,\
    \ v, e);\n                if (new_dist >= dist[v]) continue;\n               \
    \ pq.emplace(dist[v] = new_dist, v);\n                parent[v] = &e;\n      \
    \      }\n        }\n        pq = decltype(pq)(); // pq.clear() doesn't exist.\n\
    \        for (V_id v = 0; v < n; ++v) {\n            potential[v] += min(dist[v],\
    \ farthest);\n        }\n        return deficit_count > 0;\n    }/*}}}*/\n   \
    \ void primal() {/*{{{*/\n        for (const auto t : deficit_vs) {\n        \
    \    if (dist[t] > farthest) continue;\n            Flow f = -b[t];\n        \
    \    V_id v;\n            for (v = t; parent[v] != nullptr; v = parent[v]->src)\
    \ {\n                f = min(f, parent[v]->residual_cap());\n            }\n \
    \           f = min(f, b[v]);\n            if (f <= 0) continue;\n           \
    \ for (v = t; parent[v] != nullptr;) {\n                auto &e = *parent[v];\n\
    \                push(e, f);\n                int u = parent[v]->src;\n      \
    \          if (e.residual_cap() <= 0) parent[v] = nullptr;\n                v\
    \ = u;\n            }\n            b[t] += f;\n            b[v] -= f;\n      \
    \  }\n    }/*}}}*/\n\n    public:\n    pair<Status, Cost> solve() {/*{{{*/\n \
    \       potential.resize(n);\n        for (auto &es : g) for (auto &e : es) {\n\
    \            const Flow rcap = e.residual_cap();\n            const Cost rcost\
    \ = residual_cost(e.src, e.dst, e);\n            if (rcost < 0 || rcap < 0) {\n\
    \                push(e, rcap);\n                b[e.src] -= rcap;\n         \
    \       b[e.dst] += rcap;\n            }\n        }\n        for (V_id v = 0;\
    \ v < n; ++v) if (b[v] != 0) {\n            (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\n\
    \        }\n\n        while (dual()) primal();\n        Cost value = 0;\n    \
    \    for (const auto &es : g) for (const auto &e : es) {\n            value +=\
    \ e.flow * e.cost;\n        }\n        value /= 2;\n\n        if (excess_vs.empty()\
    \ && deficit_vs.empty()) {\n            return { Status::OPTIMAL, value / objective\
    \ };\n        }\n        else {\n            return { Status::INFEASIBLE, value\
    \ / objective };\n        }\n    }/*}}}*/\n    tuple<Status, Cost, Flow> solve(const\
    \ V_id s, const V_id t) {/*{{{*/\n        assert(s != t);\n        Flow inf_flow\
    \ = abs(b[s]);\n        for (const auto &e : g[s]) inf_flow += max(e.cap, static_cast<Flow>(0));\n\
    \n        add_edge(t, s, 0, inf_flow, 0);\n        const auto [status, circulation_value]\
    \ = solve();\n\n        if (status == Status::INFEASIBLE) {\n            g[s].pop_back();\n\
    \            g[t].pop_back();\n            return { status, circulation_value,\
    \ 0 };\n        }\n        inf_flow = abs(b[s]);\n        for (const auto &e :\
    \ g[s]) inf_flow += e.residual_cap();\n        b[s] += inf_flow;\n        b[t]\
    \ -= inf_flow;\n        const auto [mf_status, mf_value] = solve();\n        b[s]\
    \ -= inf_flow;\n        b[t] += inf_flow;\n        g[s].pop_back();\n        g[t].pop_back();\n\
    \        return { Status::OPTIMAL, mf_value, b[t] };\n    }/*}}}*/\n};\n\ntemplate\
    \ <class Flow, class Cost>\nusing MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;\n\
    #line 2 \"library/cpp/include/misawa_b_flow.hpp\"\n"
  code: '#include "../graph/flow/misawa_b_flow.hpp"'
  dependsOn:
  - library/cpp/graph/flow/misawa_b_flow.hpp
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/misawa_b_flow.hpp
  requiredBy: []
  timestamp: '2020-10-29 04:58:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/misawa_b_flow.hpp
layout: document
redirect_from:
- /library/library/cpp/include/misawa_b_flow.hpp
- /library/library/cpp/include/misawa_b_flow.hpp.html
title: library/cpp/include/misawa_b_flow.hpp
---
