---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: codes/cpp/segtree/lazy/range_update_min.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#fd7327930a755f2af79454333bd36f77">codes/cpp/segtree/lazy</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/segtree/lazy/range_update_min.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-16 23:52:39+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

struct LazySegmentTree {/*{{{*/
  private:
    int n;
    vector<int> node, lazy;
    vector<bool> lazyFlag;

  public:
    LazySegmentTree(vector<int> v) {/*{{{*/
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, INF);
        lazyFlag.resize(2*n-1, false);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }/*}}}*/

    void lazyEvaluate(int k, int l, int r) {/*{{{*/
        if(lazyFlag[k]) {
            node[k] = lazy[k];
            if(r - l > 1) {
                lazy[k*2+1] = lazy[k*2+2] = lazy[k];
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }/*}}}*/

    void update(int a, int b, int x, int k=0, int l=0, int r=-1) {/*{{{*/
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }/*}}}*/

    int find(int a, int b, int k=0, int l=0, int r=-1) {/*{{{*/
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }/*}}}*/
};/*}}}*/

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree seg( vector<int>(N, INF) );
    for(int i=0; i<Q; i++) {
        int query; cin >> query;
        if(query == 0) {
            int s, t, x; cin >> s >> t >> x;
            seg.update(s, t+1, x);
        }
        else {
            int s, t; cin >> s >> t;
            cout << seg.find(s, t+1) << endl;
        }
    }
    return 0;
}

// (参考) http://tsutaj.hatenablog.com/entry/2017/03/30/224339

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/segtree/lazy/range_update_min.cpp"
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

struct LazySegmentTree {/*{{{*/
  private:
    int n;
    vector<int> node, lazy;
    vector<bool> lazyFlag;

  public:
    LazySegmentTree(vector<int> v) {/*{{{*/
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, INF);
        lazyFlag.resize(2*n-1, false);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }/*}}}*/

    void lazyEvaluate(int k, int l, int r) {/*{{{*/
        if(lazyFlag[k]) {
            node[k] = lazy[k];
            if(r - l > 1) {
                lazy[k*2+1] = lazy[k*2+2] = lazy[k];
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }/*}}}*/

    void update(int a, int b, int x, int k=0, int l=0, int r=-1) {/*{{{*/
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }/*}}}*/

    int find(int a, int b, int k=0, int l=0, int r=-1) {/*{{{*/
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }/*}}}*/
};/*}}}*/

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree seg( vector<int>(N, INF) );
    for(int i=0; i<Q; i++) {
        int query; cin >> query;
        if(query == 0) {
            int s, t, x; cin >> s >> t >> x;
            seg.update(s, t+1, x);
        }
        else {
            int s, t; cin >> s >> t;
            cout << seg.find(s, t+1) << endl;
        }
    }
    return 0;
}

// (参考) http://tsutaj.hatenablog.com/entry/2017/03/30/224339

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

