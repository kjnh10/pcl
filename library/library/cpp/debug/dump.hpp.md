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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: library/cpp/debug/dump.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#dbefae66adc6b6e178b4020d7ee0c756">library/cpp/debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/debug/dump.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:36:04+09:00




## Depends on

* :warning: <a href="prettyprint.hpp.html">library/cpp/debug/prettyprint.hpp</a>
* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// http://www.creativ.xyz/dump-cpp-652
using namespace std;
#include <bits/stdc++.h>

#include "../header.hpp"

#define DUMPOUT cerr  // where to dump. cout or cerr

#define cerrendl cerr << endl

namespace dump_macro {
stack<vector<string>> varnames;
stack<int> varidx;
}  // namespace dump_macro

#define dump(...)                                                            \
    {                                                                        \
        dump_macro::varnames.push([](string s) -> vector<string> {           \
            int n = s.size();                                                \
            vector<string> res;                                              \
            string tmp = "";                                                 \
            int parlevel = 0;                                                \
            for (int i = 0; i < n; i++) {                                    \
                if (s[i] == '(') parlevel++;                                 \
                if (s[i] == ')') parlevel--;                                 \
                if (s[i] == ' ') continue;                                   \
                if (s[i] == ',' && parlevel == 0) {                          \
                    res.push_back(tmp);                                      \
                    tmp = "";                                                \
                } else {                                                     \
                    tmp += s[i];                                             \
                }                                                            \
            }                                                                \
            res.push_back(tmp);                                              \
            return res;                                                      \
        }(#__VA_ARGS__));                                                    \
        dump_macro::varidx.push(0);                                          \
        dump_func(__VA_ARGS__);                                              \
        DUMPOUT << "in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl; \
        dump_macro::varnames.pop();                                          \
        dump_macro::varidx.pop();                                            \
    }

#define dump_1d(x, n)                                                     \
    {                                                                     \
        DUMPOUT << "  " << #x << "[" << #n << "]"                         \
                << ":=> {";                                               \
        rep(i, n) { DUMPOUT << x[i] << (((i) == (n - 1)) ? "}" : ", "); } \
        DUMPOUT << " in [" << __LINE__ << "]" << endl;                    \
    }

#define dump_2d(x, n, m)                                      \
    {                                                         \
        DUMPOUT << "  " << #x << "[" << #n << "]"             \
                << "[" << #m << "]"                           \
                << ":=> \n";                                  \
        rep(i, n) rep(j, m) {                                 \
            DUMPOUT << ((j == 0) ? "     |" : " ") << x[i][j] \
                    << (((j) == (m - 1)) ? "|\n" : " ");      \
        }                                                     \
        DUMPOUT << "  in [" << __LINE__ << "]" << endl;       \
    }

void dump_func() {}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << dump_macro::varnames.top()[dump_macro::varidx.top()] << ":"
            << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    } else {
        DUMPOUT << ", ";
    }
    ++dump_macro::varidx.top();
    dump_func(std::move(tail)...);
}

#include "prettyprint.hpp"

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

<a href="../../../../index.html">Back to top page</a>

