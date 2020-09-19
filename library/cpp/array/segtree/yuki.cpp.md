---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"library/cpp/array/segtree/yuki.cpp\"\n#include <bits/stdc++.h>\n\
    #define rep(i, a, b) for (ll i = ll(a); i < ll(b); i++)\n#define rer(i, a, b)\
    \ for (ll i = ll(a) - 1; i >= ll(b); i--)\n#define sz(v) (int)(v).size()\n#define\
    \ pb push_back\n#define sc second\n#define fr first\n#define sor(v) sort(v.begin(),\
    \ v.end())\n#define rev(s) reverse(s.begin(), s.end())\n#define lb(vec, a) lower_bound(vec.begin(),\
    \ vec.end(), a)\n#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)\n#define\
    \ uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())\nusing namespace\
    \ std;\ntypedef long long int ll;\ntypedef pair<int, int> P;\n\nconst ll MOD =\
    \ 1000000007;\nconst int MAX_N = 1 << 17;  // n\u306E2\u500D\u304F\u3089\u3044\
    \nconst ll INF = (1LL << 31) - 1;\n// RSQ&RAQ\n/*\nstruct LazySegmentTree{\n \
    \   ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:n\u3092\uFF12\u3079\u304D\
    \u306B\u3057\u305F\u3082\u306E\n\n    //\u521D\u671F\u5316\n    void init(int\
    \ n_){\n        //\u8981\u7D20\u6570\u30922\u3079\u304D\u306B\n        SIZE=1;\n\
    \        while(SIZE<n_) SIZE*=2;\n\n        //\u5168\u3066\u306E\u5024\u3092I_MAX\u306B\
    \n        rep(i,0,2*SIZE-1) node[i]=0;\n    }\n\n    //k\u756A\u76EE\u306E\u30CE\
    \u30FC\u30C9\u306B\u3064\u3044\u3066\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\
    \n    void eval(int k, int l, int r){\n        // \u9045\u5EF6\u914D\u5217\u304C\
    \u7A7A\u3067\u306A\u3044\u5834\u5408\u3001\u81EA\u30CE\u30FC\u30C9\u53CA\u3073\
    \u5B50\u30CE\u30FC\u30C9\u3078\u306E\u5024\u306E\u4F1D\u64AD\u304C\u8D77\u3053\
    \u308B\n        if(lazy[k]!=0){\n            node[k]+=lazy[k];\n            //\
    \ \u6700\u4E0B\u6BB5\u304B\u3069\u3046\u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\
    \u3057\u3088\u3046\n            if(r-l>1){\n                lazy[2*k+1]+=lazy[k]/2;\n\
    \                lazy[2*k+2]+=lazy[k]/2;\n            }\n            // \u4F1D\
    \u64AD\u304C\u7D42\u308F\u3063\u305F\u306E\u3067\u3001\u81EA\u30CE\u30FC\u30C9\
    \u306E\u9045\u5EF6\u914D\u5217\u3092\u7A7A\u306B\u3059\u308B\n            lazy[k]\
    \ = 0;\n        }\n    }\n\n    void add(int a, int b, ll x, int k=0, int l=0,\
    \ int r=-1){\n        if(r<0) r=SIZE;\n        eval(k,l,r);\n        if(b <= l\
    \ || r <= a) return;\n        if(a <= l && r <= b) {\n            lazy[k] += (r\
    \ - l) * x;\n            eval(k, l, r);\n        }\n        else{\n          \
    \  add(a, b, x, 2*k+1, l, (l+r)/2);\n            add(a, b, x, 2*k+2, (l+r)/2,\
    \ r);\n            node[k]=node[2*k+1]+node[2*k+2];\n        }\n    }\n\n    ll\
    \ getsum(int a, int b, int k=0, int l=0, int r=-1){\n        if(r<0) r=SIZE;\n\
    \        if(b <= l || r <= a) return 0;\n        eval(k,l,r);\n        if(a <=\
    \ l && r <= b) return node[k];\n        ll vl=getsum(a, b, 2*k+1, l, (l+r)/2);\n\
    \        ll vr=getsum(a, b, 2*k+2, (l+r)/2, r);\n        return vl+vr;\n    }\n\
    };\n*/\n\n// RMQ&RUQ\n/*\nstruct LazySegmentTree{\n    ll node[2*MAX_N-1], lazy[2*MAX_N-1],\
    \ SIZE; //SIZE:n\u3092\uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\n    bool\
    \ lazyflag[2*MAX_N-1];\n\n    //\u521D\u671F\u5316\n    void init(int n_){\n \
    \       //\u8981\u7D20\u6570\u30922\u3079\u304D\u306B\n        SIZE=1;\n     \
    \   while(SIZE<n_) SIZE*=2;\n\n        //\u5168\u3066\u306E\u5024\u3092I_MAX\u306B\
    \n        rep(i,0,2*SIZE-1) node[i]=INF;\n    }\n\n    //k\u756A\u76EE\u306E\u30CE\
    \u30FC\u30C9\u306B\u3064\u3044\u3066\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\
    \n    void eval(int k, int l, int r){\n        // \u9045\u5EF6\u914D\u5217\u304C\
    \u7A7A\u3067\u306A\u3044\u5834\u5408\u3001\u81EA\u30CE\u30FC\u30C9\u53CA\u3073\
    \u5B50\u30CE\u30FC\u30C9\u3078\u306E\u5024\u306E\u4F1D\u64AD\u304C\u8D77\u3053\
    \u308B\n        if(lazyflag[k]){\n            node[k]=lazy[k];\n            //\
    \ \u6700\u4E0B\u6BB5\u304B\u3069\u3046\u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\
    \u3057\u3088\u3046\n            if(r-l>1){\n                lazy[k*2+1] = lazy[k*2+2]\
    \ = lazy[k];\n                lazyflag[k*2+1] = lazyflag[k*2+2] = true;\n    \
    \        }\n            lazyflag[k] = false;\n        }\n    }\n\n    void update(int\
    \ a, int b, ll x, int k=0, int l=0, int r=-1){\n        if(r<0) r=SIZE;\n    \
    \    eval(k,l,r);\n        if(b <= l || r <= a) return;\n        if(a <= l &&\
    \ r <= b) {\n            lazy[k] = x;\n            lazyflag[k]=true;\n       \
    \     eval(k, l, r);\n        }\n        else{\n            update(a, b, x, 2*k+1,\
    \ l, (l+r)/2);\n            update(a, b, x, 2*k+2, (l+r)/2, r);\n            node[k]=min(node[2*k+1],\
    \ node[2*k+2]);\n        }\n    }\n\n    ll getmin(int a, int b, int k=0, int\
    \ l=0, int r=-1){\n        if(r<0) r=SIZE;\n        eval(k,l,r);\n        if(b\
    \ <= l || r <= a) return INF;\n        if(a <= l && r <= b) return node[k];\n\
    \        ll vl=getmin(a, b, 2*k+1, l, (l+r)/2);\n        ll vr=getmin(a, b, 2*k+2,\
    \ (l+r)/2, r);\n        return min(vl, vr);\n    }\n};*/\n\n// RMQ&RAQ\n/*\nstruct\
    \ LazySegmentTree{\n    ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:n\u3092\
    \uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\n    bool lazyflag[2*MAX_N-1];\n\
    \    //\u521D\u671F\u5316\n    void init(int n_){\n        //\u8981\u7D20\u6570\
    \u30922\u3079\u304D\u306B\n        SIZE=1;\n        while(SIZE<n_) SIZE*=2;\n\n\
    \        //\u5168\u3066\u306E\u5024\u3092I_MAX\u306B\n        rep(i,0,2*SIZE-1)\
    \ node[i]=0;\n    }\n\n    //k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306B\u3064\
    \u3044\u3066\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\n    void eval(int k, int\
    \ l, int r){\n        // \u9045\u5EF6\u914D\u5217\u304C\u7A7A\u3067\u306A\u3044\
    \u5834\u5408\u3001\u81EA\u30CE\u30FC\u30C9\u53CA\u3073\u5B50\u30CE\u30FC\u30C9\
    \u3078\u306E\u5024\u306E\u4F1D\u64AD\u304C\u8D77\u3053\u308B\n        if(lazyflag[k]){\n\
    \            node[k]+=lazy[k];\n            // \u6700\u4E0B\u6BB5\u304B\u3069\u3046\
    \u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\u3057\u3088\u3046\n            if(r-l>1){\n\
    \                lazy[k*2+1] += lazy[k];\n                lazy[k*2+2] += lazy[k];\n\
    \                lazyflag[k*2+1] = lazyflag[k*2+2] = true;\n            }\n  \
    \          lazyflag[k] = false;\n            lazy[k]=0;\n        }\n    }\n\n\
    \    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){\n        if(r<0)\
    \ r=SIZE;\n        eval(k,l,r);\n        if(b <= l || r <= a) return;\n      \
    \  if(a <= l && r <= b) {\n            lazy[k] += x;\n            lazyflag[k]=true;\n\
    \            eval(k, l, r);\n        }\n        else{\n            add(a, b, x,\
    \ 2*k+1, l, (l+r)/2);\n            add(a, b, x, 2*k+2, (l+r)/2, r);\n        \
    \    node[k]=min(node[2*k+1], node[2*k+2]);\n        }\n    }\n\n    ll getmin(int\
    \ a, int b, int k=0, int l=0, int r=-1){\n        if(r<0) r=SIZE;\n        eval(k,l,r);\n\
    \        if(b <= l || r <= a) return INF;\n        if(a <= l && r <= b) return\
    \ node[k];\n        ll vl=getmin(a, b, 2*k+1, l, (l+r)/2);\n        ll vr=getmin(a,\
    \ b, 2*k+2, (l+r)/2, r);\n        return min(vl, vr);\n    }\n};*/\n\n// RSQ&RUQ\n\
    struct LazySegmentTree {\n    ll node[2 * MAX_N - 1], lazy[2 * MAX_N - 1],\n \
    \       SIZE;  // SIZE:n\u3092\uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\
    \n    bool lazyflag[2 * MAX_N - 1];\n\n    //\u521D\u671F\u5316\n    void init(int\
    \ n_) {\n        //\u8981\u7D20\u6570\u30922\u3079\u304D\u306B\n        SIZE =\
    \ 1;\n        while (SIZE < n_) SIZE *= 2;\n\n        //\u5168\u3066\u306E\u5024\
    \u3092I_MAX\u306B\n        rep(i, 0, 2 * SIZE - 1) node[i] = 0;\n    }\n\n   \
    \ // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306B\u3064\u3044\u3066\u9045\u5EF6\
    \u8A55\u4FA1\u3092\u884C\u3046\n    void eval(int k, int l, int r) {\n       \
    \ // \u9045\u5EF6\u914D\u5217\u304C\u7A7A\u3067\u306A\u3044\u5834\u5408\u3001\u81EA\
    \u30CE\u30FC\u30C9\u53CA\u3073\u5B50\u30CE\u30FC\u30C9\u3078\u306E\u5024\u306E\
    \u4F1D\u64AD\u304C\u8D77\u3053\u308B\n        if (lazyflag[k]) {\n           \
    \ node[k] = (r - l) * lazy[k];\n            // \u6700\u4E0B\u6BB5\u304B\u3069\u3046\
    \u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\u3057\u3088\u3046\n            if (r\
    \ - l > 1) {\n                lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];\n \
    \               lazyflag[k * 2 + 1] = lazyflag[k * 2 + 2] = true;\n          \
    \  }\n            lazyflag[k] = false;\n        }\n    }\n\n    void update(int\
    \ a, int b, ll x, int k = 0, int l = 0, int r = -1) {\n        if (r < 0) r =\
    \ SIZE;\n        eval(k, l, r);\n        if (b <= l || r <= a) return;\n     \
    \   if (a <= l && r <= b) {\n            lazy[k] = x;\n            lazyflag[k]\
    \ = true;\n            eval(k, l, r);\n        } else {\n            update(a,\
    \ b, x, 2 * k + 1, l, (l + r) / 2);\n            update(a, b, x, 2 * k + 2, (l\
    \ + r) / 2, r);\n            node[k] = node[2 * k + 1] + node[2 * k + 2];\n  \
    \      }\n    }\n\n    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1)\
    \ {\n        if (r < 0) r = SIZE;\n        eval(k, l, r);\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return node[k];\n      \
    \  ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);\n        ll vr = getsum(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return vl + vr;\n    }\n};\n\nLazySegmentTree\
    \ S;\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    ll\
    \ n, q;\n    cin >> n >> q;\n    S.init(n);\n    rep(i, 0, q) {\n        int b;\n\
    \        cin >> b;\n        if (b) {\n            int s, t;\n            cin >>\
    \ s >> t;\n            cout << S.getsum(s, t + 1) << \"\\n\";\n        } else\
    \ {\n            int s, t;\n            cin >> s >> t;\n            ll x;\n  \
    \          cin >> x;\n            S.update(s, t + 1, x);\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i, a, b) for (ll i = ll(a); i < ll(b);\
    \ i++)\n#define rer(i, a, b) for (ll i = ll(a) - 1; i >= ll(b); i--)\n#define\
    \ sz(v) (int)(v).size()\n#define pb push_back\n#define sc second\n#define fr first\n\
    #define sor(v) sort(v.begin(), v.end())\n#define rev(s) reverse(s.begin(), s.end())\n\
    #define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)\n#define ub(vec, a)\
    \ upper_bound(vec.begin(), vec.end(), a)\n#define uniq(vec) vec.erase(unique(vec.begin(),\
    \ vec.end()), vec.end())\nusing namespace std;\ntypedef long long int ll;\ntypedef\
    \ pair<int, int> P;\n\nconst ll MOD = 1000000007;\nconst int MAX_N = 1 << 17;\
    \  // n\u306E2\u500D\u304F\u3089\u3044\nconst ll INF = (1LL << 31) - 1;\n// RSQ&RAQ\n\
    /*\nstruct LazySegmentTree{\n    ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:n\u3092\
    \uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\n\n    //\u521D\u671F\u5316\n\
    \    void init(int n_){\n        //\u8981\u7D20\u6570\u30922\u3079\u304D\u306B\
    \n        SIZE=1;\n        while(SIZE<n_) SIZE*=2;\n\n        //\u5168\u3066\u306E\
    \u5024\u3092I_MAX\u306B\n        rep(i,0,2*SIZE-1) node[i]=0;\n    }\n\n    //k\u756A\
    \u76EE\u306E\u30CE\u30FC\u30C9\u306B\u3064\u3044\u3066\u9045\u5EF6\u8A55\u4FA1\
    \u3092\u884C\u3046\n    void eval(int k, int l, int r){\n        // \u9045\u5EF6\
    \u914D\u5217\u304C\u7A7A\u3067\u306A\u3044\u5834\u5408\u3001\u81EA\u30CE\u30FC\
    \u30C9\u53CA\u3073\u5B50\u30CE\u30FC\u30C9\u3078\u306E\u5024\u306E\u4F1D\u64AD\
    \u304C\u8D77\u3053\u308B\n        if(lazy[k]!=0){\n            node[k]+=lazy[k];\n\
    \            // \u6700\u4E0B\u6BB5\u304B\u3069\u3046\u304B\u306E\u30C1\u30A7\u30C3\
    \u30AF\u3092\u3057\u3088\u3046\n            if(r-l>1){\n                lazy[2*k+1]+=lazy[k]/2;\n\
    \                lazy[2*k+2]+=lazy[k]/2;\n            }\n            // \u4F1D\
    \u64AD\u304C\u7D42\u308F\u3063\u305F\u306E\u3067\u3001\u81EA\u30CE\u30FC\u30C9\
    \u306E\u9045\u5EF6\u914D\u5217\u3092\u7A7A\u306B\u3059\u308B\n            lazy[k]\
    \ = 0;\n        }\n    }\n\n    void add(int a, int b, ll x, int k=0, int l=0,\
    \ int r=-1){\n        if(r<0) r=SIZE;\n        eval(k,l,r);\n        if(b <= l\
    \ || r <= a) return;\n        if(a <= l && r <= b) {\n            lazy[k] += (r\
    \ - l) * x;\n            eval(k, l, r);\n        }\n        else{\n          \
    \  add(a, b, x, 2*k+1, l, (l+r)/2);\n            add(a, b, x, 2*k+2, (l+r)/2,\
    \ r);\n            node[k]=node[2*k+1]+node[2*k+2];\n        }\n    }\n\n    ll\
    \ getsum(int a, int b, int k=0, int l=0, int r=-1){\n        if(r<0) r=SIZE;\n\
    \        if(b <= l || r <= a) return 0;\n        eval(k,l,r);\n        if(a <=\
    \ l && r <= b) return node[k];\n        ll vl=getsum(a, b, 2*k+1, l, (l+r)/2);\n\
    \        ll vr=getsum(a, b, 2*k+2, (l+r)/2, r);\n        return vl+vr;\n    }\n\
    };\n*/\n\n// RMQ&RUQ\n/*\nstruct LazySegmentTree{\n    ll node[2*MAX_N-1], lazy[2*MAX_N-1],\
    \ SIZE; //SIZE:n\u3092\uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\n    bool\
    \ lazyflag[2*MAX_N-1];\n\n    //\u521D\u671F\u5316\n    void init(int n_){\n \
    \       //\u8981\u7D20\u6570\u30922\u3079\u304D\u306B\n        SIZE=1;\n     \
    \   while(SIZE<n_) SIZE*=2;\n\n        //\u5168\u3066\u306E\u5024\u3092I_MAX\u306B\
    \n        rep(i,0,2*SIZE-1) node[i]=INF;\n    }\n\n    //k\u756A\u76EE\u306E\u30CE\
    \u30FC\u30C9\u306B\u3064\u3044\u3066\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\
    \n    void eval(int k, int l, int r){\n        // \u9045\u5EF6\u914D\u5217\u304C\
    \u7A7A\u3067\u306A\u3044\u5834\u5408\u3001\u81EA\u30CE\u30FC\u30C9\u53CA\u3073\
    \u5B50\u30CE\u30FC\u30C9\u3078\u306E\u5024\u306E\u4F1D\u64AD\u304C\u8D77\u3053\
    \u308B\n        if(lazyflag[k]){\n            node[k]=lazy[k];\n            //\
    \ \u6700\u4E0B\u6BB5\u304B\u3069\u3046\u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\
    \u3057\u3088\u3046\n            if(r-l>1){\n                lazy[k*2+1] = lazy[k*2+2]\
    \ = lazy[k];\n                lazyflag[k*2+1] = lazyflag[k*2+2] = true;\n    \
    \        }\n            lazyflag[k] = false;\n        }\n    }\n\n    void update(int\
    \ a, int b, ll x, int k=0, int l=0, int r=-1){\n        if(r<0) r=SIZE;\n    \
    \    eval(k,l,r);\n        if(b <= l || r <= a) return;\n        if(a <= l &&\
    \ r <= b) {\n            lazy[k] = x;\n            lazyflag[k]=true;\n       \
    \     eval(k, l, r);\n        }\n        else{\n            update(a, b, x, 2*k+1,\
    \ l, (l+r)/2);\n            update(a, b, x, 2*k+2, (l+r)/2, r);\n            node[k]=min(node[2*k+1],\
    \ node[2*k+2]);\n        }\n    }\n\n    ll getmin(int a, int b, int k=0, int\
    \ l=0, int r=-1){\n        if(r<0) r=SIZE;\n        eval(k,l,r);\n        if(b\
    \ <= l || r <= a) return INF;\n        if(a <= l && r <= b) return node[k];\n\
    \        ll vl=getmin(a, b, 2*k+1, l, (l+r)/2);\n        ll vr=getmin(a, b, 2*k+2,\
    \ (l+r)/2, r);\n        return min(vl, vr);\n    }\n};*/\n\n// RMQ&RAQ\n/*\nstruct\
    \ LazySegmentTree{\n    ll node[2*MAX_N-1], lazy[2*MAX_N-1], SIZE; //SIZE:n\u3092\
    \uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\n    bool lazyflag[2*MAX_N-1];\n\
    \    //\u521D\u671F\u5316\n    void init(int n_){\n        //\u8981\u7D20\u6570\
    \u30922\u3079\u304D\u306B\n        SIZE=1;\n        while(SIZE<n_) SIZE*=2;\n\n\
    \        //\u5168\u3066\u306E\u5024\u3092I_MAX\u306B\n        rep(i,0,2*SIZE-1)\
    \ node[i]=0;\n    }\n\n    //k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306B\u3064\
    \u3044\u3066\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\n    void eval(int k, int\
    \ l, int r){\n        // \u9045\u5EF6\u914D\u5217\u304C\u7A7A\u3067\u306A\u3044\
    \u5834\u5408\u3001\u81EA\u30CE\u30FC\u30C9\u53CA\u3073\u5B50\u30CE\u30FC\u30C9\
    \u3078\u306E\u5024\u306E\u4F1D\u64AD\u304C\u8D77\u3053\u308B\n        if(lazyflag[k]){\n\
    \            node[k]+=lazy[k];\n            // \u6700\u4E0B\u6BB5\u304B\u3069\u3046\
    \u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\u3057\u3088\u3046\n            if(r-l>1){\n\
    \                lazy[k*2+1] += lazy[k];\n                lazy[k*2+2] += lazy[k];\n\
    \                lazyflag[k*2+1] = lazyflag[k*2+2] = true;\n            }\n  \
    \          lazyflag[k] = false;\n            lazy[k]=0;\n        }\n    }\n\n\
    \    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){\n        if(r<0)\
    \ r=SIZE;\n        eval(k,l,r);\n        if(b <= l || r <= a) return;\n      \
    \  if(a <= l && r <= b) {\n            lazy[k] += x;\n            lazyflag[k]=true;\n\
    \            eval(k, l, r);\n        }\n        else{\n            add(a, b, x,\
    \ 2*k+1, l, (l+r)/2);\n            add(a, b, x, 2*k+2, (l+r)/2, r);\n        \
    \    node[k]=min(node[2*k+1], node[2*k+2]);\n        }\n    }\n\n    ll getmin(int\
    \ a, int b, int k=0, int l=0, int r=-1){\n        if(r<0) r=SIZE;\n        eval(k,l,r);\n\
    \        if(b <= l || r <= a) return INF;\n        if(a <= l && r <= b) return\
    \ node[k];\n        ll vl=getmin(a, b, 2*k+1, l, (l+r)/2);\n        ll vr=getmin(a,\
    \ b, 2*k+2, (l+r)/2, r);\n        return min(vl, vr);\n    }\n};*/\n\n// RSQ&RUQ\n\
    struct LazySegmentTree {\n    ll node[2 * MAX_N - 1], lazy[2 * MAX_N - 1],\n \
    \       SIZE;  // SIZE:n\u3092\uFF12\u3079\u304D\u306B\u3057\u305F\u3082\u306E\
    \n    bool lazyflag[2 * MAX_N - 1];\n\n    //\u521D\u671F\u5316\n    void init(int\
    \ n_) {\n        //\u8981\u7D20\u6570\u30922\u3079\u304D\u306B\n        SIZE =\
    \ 1;\n        while (SIZE < n_) SIZE *= 2;\n\n        //\u5168\u3066\u306E\u5024\
    \u3092I_MAX\u306B\n        rep(i, 0, 2 * SIZE - 1) node[i] = 0;\n    }\n\n   \
    \ // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306B\u3064\u3044\u3066\u9045\u5EF6\
    \u8A55\u4FA1\u3092\u884C\u3046\n    void eval(int k, int l, int r) {\n       \
    \ // \u9045\u5EF6\u914D\u5217\u304C\u7A7A\u3067\u306A\u3044\u5834\u5408\u3001\u81EA\
    \u30CE\u30FC\u30C9\u53CA\u3073\u5B50\u30CE\u30FC\u30C9\u3078\u306E\u5024\u306E\
    \u4F1D\u64AD\u304C\u8D77\u3053\u308B\n        if (lazyflag[k]) {\n           \
    \ node[k] = (r - l) * lazy[k];\n            // \u6700\u4E0B\u6BB5\u304B\u3069\u3046\
    \u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3092\u3057\u3088\u3046\n            if (r\
    \ - l > 1) {\n                lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];\n \
    \               lazyflag[k * 2 + 1] = lazyflag[k * 2 + 2] = true;\n          \
    \  }\n            lazyflag[k] = false;\n        }\n    }\n\n    void update(int\
    \ a, int b, ll x, int k = 0, int l = 0, int r = -1) {\n        if (r < 0) r =\
    \ SIZE;\n        eval(k, l, r);\n        if (b <= l || r <= a) return;\n     \
    \   if (a <= l && r <= b) {\n            lazy[k] = x;\n            lazyflag[k]\
    \ = true;\n            eval(k, l, r);\n        } else {\n            update(a,\
    \ b, x, 2 * k + 1, l, (l + r) / 2);\n            update(a, b, x, 2 * k + 2, (l\
    \ + r) / 2, r);\n            node[k] = node[2 * k + 1] + node[2 * k + 2];\n  \
    \      }\n    }\n\n    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1)\
    \ {\n        if (r < 0) r = SIZE;\n        eval(k, l, r);\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return node[k];\n      \
    \  ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);\n        ll vr = getsum(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return vl + vr;\n    }\n};\n\nLazySegmentTree\
    \ S;\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    ll\
    \ n, q;\n    cin >> n >> q;\n    S.init(n);\n    rep(i, 0, q) {\n        int b;\n\
    \        cin >> b;\n        if (b) {\n            int s, t;\n            cin >>\
    \ s >> t;\n            cout << S.getsum(s, t + 1) << \"\\n\";\n        } else\
    \ {\n            int s, t;\n            cin >> s >> t;\n            ll x;\n  \
    \          cin >> x;\n            S.update(s, t + 1, x);\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/array/segtree/yuki.cpp
  requiredBy: []
  timestamp: '2020-04-26 09:08:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/array/segtree/yuki.cpp
layout: document
redirect_from:
- /library/library/cpp/array/segtree/yuki.cpp
- /library/library/cpp/array/segtree/yuki.cpp.html
title: library/cpp/array/segtree/yuki.cpp
---
