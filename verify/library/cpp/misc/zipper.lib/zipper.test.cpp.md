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


# :heavy_check_mark: library/cpp/misc/zipper.lib/zipper.test.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#04045c664907c0ef027b886794febe26">library/cpp/misc/zipper.lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/misc/zipper.lib/zipper.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:35:47+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../../library/library/cpp/header.hpp.html">library/cpp/header.hpp</a>
* :heavy_check_mark: <a href="../../../../../library/library/cpp/misc/zipper.lib/zipper.hpp.html">library/cpp/misc/zipper.lib/zipper.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "zipper.hpp"

signed main() {
    vector<int> x({3, 10, 5, (int)1e12});
    auto z1 = zipper(x);  // x: vector<long long>;
    dump(z1);
    auto z2 = zipper(x, INF + 5);
    dump(z2);

    auto z3 = zipper();
    z3.add_value(3);
    z3.add_value(5);
    z3.add_value(10);
    z3.add_value((int)1e12);
    z3.build();
    dump(z3);

    dump(z1(5));
    assert(z1(5) == 2);
    assert(z1.unzip(4) == (int)1e12);
    dump(z1.get_zipped(x));
    assert(z1.get_zipped(x) == vector<int>({1, 3, 2, 4}));

    cout << "Hello World" << endl;
    return 0;
}

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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: library/cpp/header.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

