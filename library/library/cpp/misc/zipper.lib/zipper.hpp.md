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


# :heavy_check_mark: library/cpp/misc/zipper.lib/zipper.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#04045c664907c0ef027b886794febe26">library/cpp/misc/zipper.lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/misc/zipper.lib/zipper.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00




## Depends on

* :heavy_check_mark: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/library/cpp/misc/zipper.lib/zipper.test.cpp.html">library/cpp/misc/zipper.lib/zipper.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../../header.hpp"

//%snippet.set('zip')%

struct zipper {                             /*{{{*/
    unordered_map<long long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3]
    vector<long long> _unzipper;            // [2, 3, 5, 10]
    bool _is_build = false;

    zipper(long long inf_value = INF) { /*{{{*/
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
    }                                                        /*}}}*/
    zipper(vector<long long> a, long long inf_value = INF) { /*{{{*/
        int n = sz(a);
        _unzipper = vector<long long>(n);
        rep(i, n) { _unzipper[i] = a[i]; }
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
        build();
    }                              /*}}}*/
    void add_value(long long lv) { /*{{{*/
        _unzipper.push_back(lv);
        _is_build = false;
    }              /*}}}*/
    void build() { /*{{{*/
        uni(_unzipper);
        zip_map.clear();
        rep(i, sz(_unzipper)) { zip_map[_unzipper[i]] = i; }
        _is_build = true;
    }                              /*}}}*/
    int get_zipped(long long lv) { /*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }                                               /*}}}*/
    vector<int> get_zipped(vector<long long> lvs) { /*{{{*/
        if (!_is_build) assert(false);
        int n = sz(lvs);
        vector<int> res(n);
        rep(i, n) res[i] = zip_map[lvs[i]];
        return res;
    }                              /*}}}*/
    int operator()(long long lv) { /*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }                         /*}}}*/
    long long unzip(int sv) { /*{{{*/
        if (!_is_build) assert(false);
        return _unzipper[sv];
    }                              /*}}}*/
#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const zipper& zp) {
        os << endl;
        os << "_is_build: " << zp._is_build << endl;
        os << "zip_map:   " << zp.zip_map << endl;
        return os;
    }
#endif /*}}}*/
};     /*}}}*/
// How to use {{{
// construct
// auto z = zipper(x); // x: vector<long long>;
// auto z = zipper(x, 30*INF);

// auto z = zipper();
// auto z = zipper();
// z.add_value(3);
// z.add_value(5);
// z.add_value(10);
// z.add_value(100000000);
// z.build();

// other method
// z(x[i]); -> zipped x[i]
// z.unzip(z(x[i])) -> x[i];
// z.get_zipped(x) -> zipped x
// }}}

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: library/cpp/header.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

