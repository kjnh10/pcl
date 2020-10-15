---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc142/tasks/abc142_f
    - https://codeforces.com/contest/1364/problem/D
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
  code: "#include \"graph.hpp\"\n\n//%snippet.set('local_min_cycle_undirected')%\n\
    //%snippet.config({'alias':'cycle'})%\n//%snippet.include('Graph')%\n//%snippet.fold()%\n\
    \n// verified by https://codeforces.com/contest/1364/problem/D\n\ntemplate<class\
    \ T>\nvector<int> local_min_cycle_undirected(Graph<T>& g){\n    // \u7121\u5411\
    \u30B0\u30E9\u30D5\u306B\u3057\u304B\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\
    \u306E\u3067\u6CE8\u610F\n    pair<int, int> loop = mp(-1, -1);  // start, end\n\
    \    vector<int> loop_path;\n    vector<bool> used(g.n);\n    bool loop_found\
    \ = false;\n    auto dfs = [&](const auto& dfs, int u, int pre) -> int {\n   \
    \     used[u] = 1;\n        int max_depth = -1;\n        each(e, g.adj_list[u]){\n\
    \            if (e.to == pre) continue;\n            else if (used[e.to]){  //\
    \ back-track-edge\n                loop_found = true;\n                if (g.tr.depth[e.to]\
    \ > max_depth) {\n                    max_depth = g.tr.depth[e.to];\n        \
    \            loop = mp(e.to, u);\n                }\n            }\n        }\n\
    \        if (loop_found){\n            // generate path\n            loop_path.pb(loop.first);\n\
    \            int cur = loop.second;\n            while(cur != loop.first){\n \
    \               loop_path.pb(cur);\n                cur = g.tr.par[cur];\n   \
    \         }\n            // loop_path.pb(loop.first);\n        }\n\n        //\
    \ if no back-tarck edge exists, the continue to dfs\n        each(e, g.tr.adj_list[u]){\n\
    \            if (e.to == pre) continue;\n            if (!loop_found) dfs(dfs,\
    \ e.to, u);\n        }\n\n        return 0;\n    };\n\n    dfs(dfs, 0, -1);\n\
    \    return loop_path;  // if tree, loop_path = {};\n}\n\n//%snippet.end()%\n\n\
    \n//%snippet.set('local_min_cycle_directed')%\n//%snippet.include('Graph')%\n\
    //%snippet.fold()%\n\n// verified by https://atcoder.jp/contests/abc142/tasks/abc142_f\n\
    // \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6975\u5C0F\u9589\u8DEF\u306E\u898B\u3064\
    \u3051\u65B9\uFF08\u7DDA\u5F62\u2715log\u304F\u3089\u3044\uFF09\n// \u30FBdfs\u3067\
    \u3072\u3068\u3064\u9589\u8DEF\u3092\u307F\u3064\u3051\u308B\uFF08\u3051\u3093\
    \u3061\u3087\u3093\u3055\u3093\u306Edfs\u306E\u8A18\u4E8B\uFF09\n// \u30FB\u5168\
    \u8FBA\u3092\u8D70\u67FB\u3057\u3066\u30B7\u30E7\u30FC\u30C8\u30AB\u30C3\u30C8\
    \u306E\u8FBA\u304C\u3042\u308C\u3070\u4E0D\u8981\u306A\u30CE\u30FC\u30C9\u3092\
    \u524A\u9664\u3057\u3066\u3044\u304F\u3002\u30B5\u30A4\u30AF\u30EB\u306F(index,\
    \ node-num)\u306Eset\u3067\u7BA1\u7406\u3057\u3066\u304A\u304F\u3068\u5404\u30CE\
    \u30FC\u30C9\u306E\u524A\u9664\u306Flog\n\ntemplate<class T>\nvec<int> local_min_cycle_directed(Graph<T>&\
    \ g){\n    int n = g.n;\n    vec<bool> seen(n);\n    vec<bool> finished(n);\n\
    \    vec<int> hist;\n    bool exist_loop = false;\n    int starting_point = -1;\n\
    \    auto dfs = [&](const auto& dfs, int u, int pre) -> void {\n        seen[u]\
    \ = true;\n        hist.push_back(u);\n        each(e, g[u]){\n            if\
    \ (e.to == pre) continue;\n            else if (finished[e.to]) continue;\n  \
    \          else if (seen[e.to]){\n                starting_point = e.to;\n   \
    \             exist_loop = true;\n                return;\n            }\n   \
    \         else{\n                dfs(dfs, e.to, u);\n            }\n         \
    \   if (exist_loop) return;\n        }\n        hist.pop_back();\n        finished[u]\
    \ = true;\n        return;\n    };\n\n    rep(u, n){\n        if (finished[u])\
    \ continue;\n        dfs(dfs, u, -1);\n        if (exist_loop){\n            vec<int>\
    \ loop;\n            r_rep(i, sz(hist)){\n                loop.pb(hist[i]);\n\
    \                if (hist[i] == starting_point) break;\n            }\n      \
    \      reverse(all(loop));\n            int m = sz(loop);\n\n            // find\
    \ short cut\n            map<int, int> pos;\n            rep(i, m) pos[loop[i]]\
    \ = i;\n            vec<int> ans;\n            int next_right = -1;\n        \
    \    int next_left = -1;\n            rep(i, m) {\n                if (next_right\
    \ == -1 || next_right == i){\n                    ans.pb(loop[i]);\n         \
    \           next_right = -1;\n                    each(e, g[loop[i]]){\n     \
    \                   if (e.to != loop[(i+1)%m] && pos.find(e.to) != pos.end())\
    \ {\n                            if (pos[e.to] < i)\n                        \
    \        chmax(next_left, pos[e.to]); // back-edge\n                         \
    \   else\n                                chmax(next_right, pos[e.to]); // to-edge\n\
    \                        }\n                    }\n                    if (next_left\
    \ != -1){\n                        ans.clear();\n                        rep(j,\
    \ next_left, i+1){\n                            if (pos.find(loop[j]) != pos.end())\
    \ ans.pb(loop[j]);\n                        }\n                        return\
    \ ans;\n                    }\n                }\n                else{\n    \
    \                pos.erase(loop[i]);\n                }\n            }\n     \
    \       return ans;\n        }\n    }\n    return {};\n}\n\n//%snippet.end()%\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/graph/local_min_cycle.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/graph/local_min_cycle.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/local_min_cycle.hpp
- /library/library/cpp/graph/local_min_cycle.hpp.html
title: library/cpp/graph/local_min_cycle.hpp
---
