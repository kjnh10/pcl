---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://codeforces.com/contest/1179/problem/C
  bundledCode: "#line 1 \"library/cpp/array/segtree/segment_tree_lazy.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//%snippet.set('segment_tree_lazy')%\n\
    //%snippet.config({'alias':'lazy'})%\n\ntemplate <typename T, typename E>\nstruct\
    \ segment_tree_lazy {  //{{{\n    // T: \u5024\u306E\u578B\n    // E: update\u4F5C\
    \u7528\u7D20\n    using F = function<T(T, T)>;\n    using G = function<T(T, E)>;\n\
    \    using H = function<E(E, E)>;\n    int n, height;\n    F f;   // \u533A\u9593\
    \u306E\u30DE\u30FC\u30B8\n    G g;   // \u66F4\u65B0\u3092\u3069\u306E\u3088\u3046\
    \u306B\u884C\u3046\u304B\n    H h;   // \u8907\u6570\u306E\u66F4\u65B0\u306E\u307E\
    \u3068\u3081\u65B9\n    T ti;  // \u5024\u306E\u5358\u4F4D\u5143\n    E ei;  //\
    \ \u6052\u7B49\u7F6E\u63DB\n    vector<T> dat;\n    vector<E> laz;\n    segment_tree_lazy()\
    \ {}\n    segment_tree_lazy(F f, G g, H h, T ti, E ei)\n        : f(f), g(g),\
    \ h(h), ti(ti), ei(ei) {}\n\n    void init(int n_) { /*{{{*/\n        n = 1;\n\
    \        height = 0;\n        while (n < n_) n <<= 1, height++;\n        dat.assign(2\
    \ * n, ti);\n        laz.assign(2 * n, ei);\n    } /*}}}*/\n\n    void build(const\
    \ vector<T> &v) { /*{{{*/\n        int n_ = v.size();\n        init(n_);\n   \
    \     for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n        for (int i = n\
    \ - 1; i; i--)\n            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n\
    \    } /*}}}*/\n\n    inline T reflect(int k) { /*{{{*/\n        return laz[k]\
    \ == ei ? dat[k] : g(dat[k], laz[k]);\n    } /*}}}*/\n\n    inline void propagate(int\
    \ k) { /*{{{*/\n        if (laz[k] == ei) return;\n        laz[(k << 1) | 0] =\
    \ h(laz[(k << 1) | 0], laz[k]);\n        laz[(k << 1) | 1] = h(laz[(k << 1) |\
    \ 1], laz[k]);\n        dat[k] = reflect(k);\n        laz[k] = ei;\n    } /*}}}*/\n\
    \n    inline void thrust(int k) { /*{{{*/\n        for (int i = height; i; i--)\
    \ propagate(k >> i);\n    } /*}}}*/\n\n    inline void recalc(int k) { /*{{{*/\n\
    \        while (k >>= 1)\n            dat[k] = f(reflect((k << 1) | 0), reflect((k\
    \ << 1) | 1));\n    } /*}}}*/\n\n    void update(int a, int b, E x) { /*{{{*/\n\
    \        if (a >= b) return;\n        thrust(a += n);\n        thrust(b += n -\
    \ 1);\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n       \
    \     if (l & 1) laz[l] = h(laz[l], x), l++;\n            if (r & 1) --r, laz[r]\
    \ = h(laz[r], x);\n        }\n        recalc(a);\n        recalc(b);\n    } /*}}}*/\n\
    \n    void set_val(int a, T x) { /*{{{*/\n        thrust(a += n);\n        dat[a]\
    \ = x;\n        laz[a] = ei;\n        recalc(a);\n    } /*}}}*/\n\n    T query(int\
    \ a, int b) { /*{{{*/\n        if (a >= b) return ti;\n        thrust(a += n);\n\
    \        thrust(b += n - 1);\n        T vl = ti, vr = ti;\n        for (int l\
    \ = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl = f(vl,\
    \ reflect(l++));\n            if (r & 1) vr = f(reflect(--r), vr);\n        }\n\
    \        return f(vl, vr);\n    } /*}}}*/\n\n    template <typename C>\n    int\
    \ find(int st, C &check, T &acc, int k, int l, int r) { /*{{{*/\n        if (l\
    \ + 1 == r) {\n            acc = f(acc, reflect(k));\n            return check(acc)\
    \ ? k - n : -1;\n        }\n        propagate(k);\n        int m = (l + r) >>\
    \ 1;\n        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);\n\
    \        if (st <= l && !check(f(acc, dat[k]))) {\n            acc = f(acc, dat[k]);\n\
    \            return -1;\n        }\n        int vl = find(st, check, acc, (k <<\
    \ 1) | 0, l, m);\n        if (~vl) return vl;\n        return find(st, check,\
    \ acc, (k << 1) | 1, m, r);\n    } /*}}}*/\n\n    template <typename C>\n    int\
    \ find(int st, C &check) { /*{{{*/\n        T acc = ti;\n        return find(st,\
    \ check, acc, 1, 0, n);\n    } /*}}}*/\n};    //}}}\n// Sample:\n// -----------------------------------------------\n\
    // init\n// * \u3053\u306E\u30B3\u30FC\u30C9\u306FRSQ\u306B\u5BFE\u5FDC\u3057\u3066\
    \u3044\u306A\u3044\u306E\u3067RSQ\u3092\u3059\u308B\u5834\u5408\u306F\u5225\u306E\
    \u3082\u306E\u3092\u4F7F\u7528\u3059\u308B\u3088\u3046\u306B\u6CE8\u610F\n// auto\
    \ f=[](int ta,int tb){return max(ta,tb);};  // how to merge\n// auto g=[](int\
    \ t,int e){return t+e;};  // how to update\n// int ti=0,ei=0;\n// segment_tree_lazy<int,\
    \ int> lseg(f,g,g,ti,ei);\n// const int sz = 1<<20;\n// lseg.build(vector<int>(sz,0));\n\
    \n// how to use\n// rep(i, n) lseg.set_val(i, a[i]);\n// lseg.update(l, r, x);\
    \ // [l, r)\n// lseg.query(l, r); // [l, r)\n// -----------------------------------------------\n\
    \n//%snippet.end()%\n\n#ifndef call_from_test\n\nsigned CFR569_C() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(0);\n\n    int n, m;\n    cin >> n >> m;\n    vector<int>\
    \ as(n), bs(m);\n    for (int i = 0; i < n; i++) cin >> as[i];\n    for (int i\
    \ = 0; i < m; i++) cin >> bs[i];\n\n    auto f = [](int ta, int tb) { return max(ta,\
    \ tb); };\n    auto g = [](int t, int e) { return t + e; };\n    int ti = 0, ei\
    \ = 0;\n    segment_tree_lazy<int, int> seg(f, g, g, ti, ei);\n\n    const int\
    \ sz = 1 << 20;\n    seg.build(vector<int>(sz, 0));\n\n    for (int i = 0; i <\
    \ n; i++) seg.update(sz - as[i], sz, +1);\n    for (int i = 0; i < m; i++) seg.update(sz\
    \ - bs[i], sz, -1);\n\n    int q;\n    cin >> q;\n    auto check = [](int d) {\
    \ return d > 0; };\n    for (int i = 0; i < q; i++) {\n        int t, k, v;\n\
    \        cin >> t >> k >> v;\n        k--;\n        if (t == 1) {\n          \
    \  seg.update(sz - as[k], sz, -1);\n            as[k] = v;\n            seg.update(sz\
    \ - as[k], sz, +1);\n        }\n        if (t == 2) {\n            seg.update(sz\
    \ - bs[k], sz, +1);\n            bs[k] = v;\n            seg.update(sz - bs[k],\
    \ sz, -1);\n        }\n        int pos = seg.find(0, check);\n        cout <<\
    \ (pos < 0 ? pos : sz - pos) << \"\\n\";\n    }\n    cout << flush;\n    return\
    \ 0;\n}\n/*\n  verified on 2019/10/28\n  https://codeforces.com/contest/1179/problem/C\n\
    */\n\nsigned main() {\n    CFR569_C();\n    return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n//%snippet.set('segment_tree_lazy')%\n//%snippet.config({'alias':'lazy'})%\n\
    \ntemplate <typename T, typename E>\nstruct segment_tree_lazy {  //{{{\n    //\
    \ T: \u5024\u306E\u578B\n    // E: update\u4F5C\u7528\u7D20\n    using F = function<T(T,\
    \ T)>;\n    using G = function<T(T, E)>;\n    using H = function<E(E, E)>;\n \
    \   int n, height;\n    F f;   // \u533A\u9593\u306E\u30DE\u30FC\u30B8\n    G\
    \ g;   // \u66F4\u65B0\u3092\u3069\u306E\u3088\u3046\u306B\u884C\u3046\u304B\n\
    \    H h;   // \u8907\u6570\u306E\u66F4\u65B0\u306E\u307E\u3068\u3081\u65B9\n\
    \    T ti;  // \u5024\u306E\u5358\u4F4D\u5143\n    E ei;  // \u6052\u7B49\u7F6E\
    \u63DB\n    vector<T> dat;\n    vector<E> laz;\n    segment_tree_lazy() {}\n \
    \   segment_tree_lazy(F f, G g, H h, T ti, E ei)\n        : f(f), g(g), h(h),\
    \ ti(ti), ei(ei) {}\n\n    void init(int n_) { /*{{{*/\n        n = 1;\n     \
    \   height = 0;\n        while (n < n_) n <<= 1, height++;\n        dat.assign(2\
    \ * n, ti);\n        laz.assign(2 * n, ei);\n    } /*}}}*/\n\n    void build(const\
    \ vector<T> &v) { /*{{{*/\n        int n_ = v.size();\n        init(n_);\n   \
    \     for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n        for (int i = n\
    \ - 1; i; i--)\n            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n\
    \    } /*}}}*/\n\n    inline T reflect(int k) { /*{{{*/\n        return laz[k]\
    \ == ei ? dat[k] : g(dat[k], laz[k]);\n    } /*}}}*/\n\n    inline void propagate(int\
    \ k) { /*{{{*/\n        if (laz[k] == ei) return;\n        laz[(k << 1) | 0] =\
    \ h(laz[(k << 1) | 0], laz[k]);\n        laz[(k << 1) | 1] = h(laz[(k << 1) |\
    \ 1], laz[k]);\n        dat[k] = reflect(k);\n        laz[k] = ei;\n    } /*}}}*/\n\
    \n    inline void thrust(int k) { /*{{{*/\n        for (int i = height; i; i--)\
    \ propagate(k >> i);\n    } /*}}}*/\n\n    inline void recalc(int k) { /*{{{*/\n\
    \        while (k >>= 1)\n            dat[k] = f(reflect((k << 1) | 0), reflect((k\
    \ << 1) | 1));\n    } /*}}}*/\n\n    void update(int a, int b, E x) { /*{{{*/\n\
    \        if (a >= b) return;\n        thrust(a += n);\n        thrust(b += n -\
    \ 1);\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n       \
    \     if (l & 1) laz[l] = h(laz[l], x), l++;\n            if (r & 1) --r, laz[r]\
    \ = h(laz[r], x);\n        }\n        recalc(a);\n        recalc(b);\n    } /*}}}*/\n\
    \n    void set_val(int a, T x) { /*{{{*/\n        thrust(a += n);\n        dat[a]\
    \ = x;\n        laz[a] = ei;\n        recalc(a);\n    } /*}}}*/\n\n    T query(int\
    \ a, int b) { /*{{{*/\n        if (a >= b) return ti;\n        thrust(a += n);\n\
    \        thrust(b += n - 1);\n        T vl = ti, vr = ti;\n        for (int l\
    \ = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl = f(vl,\
    \ reflect(l++));\n            if (r & 1) vr = f(reflect(--r), vr);\n        }\n\
    \        return f(vl, vr);\n    } /*}}}*/\n\n    template <typename C>\n    int\
    \ find(int st, C &check, T &acc, int k, int l, int r) { /*{{{*/\n        if (l\
    \ + 1 == r) {\n            acc = f(acc, reflect(k));\n            return check(acc)\
    \ ? k - n : -1;\n        }\n        propagate(k);\n        int m = (l + r) >>\
    \ 1;\n        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);\n\
    \        if (st <= l && !check(f(acc, dat[k]))) {\n            acc = f(acc, dat[k]);\n\
    \            return -1;\n        }\n        int vl = find(st, check, acc, (k <<\
    \ 1) | 0, l, m);\n        if (~vl) return vl;\n        return find(st, check,\
    \ acc, (k << 1) | 1, m, r);\n    } /*}}}*/\n\n    template <typename C>\n    int\
    \ find(int st, C &check) { /*{{{*/\n        T acc = ti;\n        return find(st,\
    \ check, acc, 1, 0, n);\n    } /*}}}*/\n};    //}}}\n// Sample:\n// -----------------------------------------------\n\
    // init\n// * \u3053\u306E\u30B3\u30FC\u30C9\u306FRSQ\u306B\u5BFE\u5FDC\u3057\u3066\
    \u3044\u306A\u3044\u306E\u3067RSQ\u3092\u3059\u308B\u5834\u5408\u306F\u5225\u306E\
    \u3082\u306E\u3092\u4F7F\u7528\u3059\u308B\u3088\u3046\u306B\u6CE8\u610F\n// auto\
    \ f=[](int ta,int tb){return max(ta,tb);};  // how to merge\n// auto g=[](int\
    \ t,int e){return t+e;};  // how to update\n// int ti=0,ei=0;\n// segment_tree_lazy<int,\
    \ int> lseg(f,g,g,ti,ei);\n// const int sz = 1<<20;\n// lseg.build(vector<int>(sz,0));\n\
    \n// how to use\n// rep(i, n) lseg.set_val(i, a[i]);\n// lseg.update(l, r, x);\
    \ // [l, r)\n// lseg.query(l, r); // [l, r)\n// -----------------------------------------------\n\
    \n//%snippet.end()%\n\n#ifndef call_from_test\n\nsigned CFR569_C() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(0);\n\n    int n, m;\n    cin >> n >> m;\n    vector<int>\
    \ as(n), bs(m);\n    for (int i = 0; i < n; i++) cin >> as[i];\n    for (int i\
    \ = 0; i < m; i++) cin >> bs[i];\n\n    auto f = [](int ta, int tb) { return max(ta,\
    \ tb); };\n    auto g = [](int t, int e) { return t + e; };\n    int ti = 0, ei\
    \ = 0;\n    segment_tree_lazy<int, int> seg(f, g, g, ti, ei);\n\n    const int\
    \ sz = 1 << 20;\n    seg.build(vector<int>(sz, 0));\n\n    for (int i = 0; i <\
    \ n; i++) seg.update(sz - as[i], sz, +1);\n    for (int i = 0; i < m; i++) seg.update(sz\
    \ - bs[i], sz, -1);\n\n    int q;\n    cin >> q;\n    auto check = [](int d) {\
    \ return d > 0; };\n    for (int i = 0; i < q; i++) {\n        int t, k, v;\n\
    \        cin >> t >> k >> v;\n        k--;\n        if (t == 1) {\n          \
    \  seg.update(sz - as[k], sz, -1);\n            as[k] = v;\n            seg.update(sz\
    \ - as[k], sz, +1);\n        }\n        if (t == 2) {\n            seg.update(sz\
    \ - bs[k], sz, +1);\n            bs[k] = v;\n            seg.update(sz - bs[k],\
    \ sz, -1);\n        }\n        int pos = seg.find(0, check);\n        cout <<\
    \ (pos < 0 ? pos : sz - pos) << \"\\n\";\n    }\n    cout << flush;\n    return\
    \ 0;\n}\n/*\n  verified on 2019/10/28\n  https://codeforces.com/contest/1179/problem/C\n\
    */\n\nsigned main() {\n    CFR569_C();\n    return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/array/segtree/segment_tree_lazy.cpp
  requiredBy: []
  timestamp: '2020-05-18 01:48:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/segtree/segment_tree_lazy.cpp
layout: document
redirect_from:
- /library/library/cpp/array/segtree/segment_tree_lazy.cpp
- /library/library/cpp/array/segtree/segment_tree_lazy.cpp.html
title: library/cpp/array/segtree/segment_tree_lazy.cpp
---
