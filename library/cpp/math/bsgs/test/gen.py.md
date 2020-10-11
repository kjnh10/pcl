---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from random import randint, choice, sample, choices\nfrom typing import TYPE_CHECKING,\
    \ List, Optional, Type\n\nL = [3, 5, 7, 9]\n# print(randint(1, 100))  # # [1,\
    \ 100]\n# print(choice(L))  # 1\u3064\u9078\u629E\n# print(sample(L, k=2))  #\
    \ \u975E\u5FA9\u5143\u62BD\u51FA\n# print(sample(L, k=len(L)))  # random permutation\n\
    # print(choices(L, k=2))  # \u5FA9\u5143\u62BD\u51FA\n\n\ndef randperm(n: int):\n\
    \    return sample(list(range(1, n+1)), k=n)\n\n\ndef randseq(n: int, l: int,\
    \ r: int, distinct=False):\n    res = []\n    used = set()\n    if (n>r-l+1) and\
    \ distinct:\n        raise Exception(print(\"n>r-l+1 and distinct=True is not\
    \ impossible\"))\n\n    while len(res) < n:\n        v = randint(l, r)\n     \
    \   if distinct and v in used:\n            pass\n        else:\n            res.append(v)\n\
    \            used.add(v)\n    return res\n\n\ndef printtree(n: int):\n    pass\n\
    \n\ndef printgraph(n: int, m: int):\n    pass\n\n\ndef pl(x: List):\n    print('\
    \ '.join(map(str, x)))\n\n\ndef get_sieve_of_eratosthenes(n):\n    if not isinstance(n,\
    \ int):\n        raise TypeError('n is int type.')\n    if n < 2:\n        raise\
    \ ValueError('n is more than 2')\n    prime = [2]\n    limit = int(n**0.5)\n \
    \   data = [i + 1 for i in range(2, n, 2)]\n    while True:\n        p = data[0]\n\
    \        if limit <= p:\n            return prime + data\n        prime.append(p)\n\
    \        data = [e for e in data if e % p != 0]\n\n\na = randint(1, 10000)\nb\
    \ = randint(1, 10000)\np = choice(get_sieve_of_eratosthenes(100000))\nprint(a,\
    \ b, p)\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/math/bsgs/test/gen.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/math/bsgs/test/gen.py
layout: document
redirect_from:
- /library/library/cpp/math/bsgs/test/gen.py
- /library/library/cpp/math/bsgs/test/gen.py.html
title: library/cpp/math/bsgs/test/gen.py
---
