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
<script type="text/javascript" src="../../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/string/kmp/codes/solve.py

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#c4edc97866360646965a77b5500cc883">library/cpp/string/kmp/codes</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/string/kmp/codes/solve.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys  # {{{
import os
import time
import re
from pydoc import help
import string
import math
from operator import itemgetter
from collections import Counter
from collections import deque
from collections import defaultdict as dd
import fractions
from heapq import heappop, heappush, heapify
import array
from bisect import bisect_left, bisect_right, insort_left, insort_right
from copy import deepcopy as dcopy
import itertools
# }}}

# pre-defined{{{
sys.setrecursionlimit(10**7)
INF = 10**20
GOSA = 1.0 / 10**10
MOD = 10**9+7
ALPHABETS = [chr(i) for i in range(ord('a'), ord('z')+1)]  # can also use string module
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def DP(N, M, first): return [[first] * M for n in range(N)]
def DP3(N, M, L, first): return [[[first] * L for n in range(M)] for _ in range(N)]
from inspect import currentframe
# }}}

def solve():
    return 0

if __name__ == "__main__":# {{{
    solve()

# vim: set foldmethod=marker: }}}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

