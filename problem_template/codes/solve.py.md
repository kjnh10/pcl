---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python\n# -*- coding: utf-8 -*-\n\nimport sys  # {{{\nimport\
    \ os\nimport time\nimport re\nfrom pydoc import help\nimport string\nimport math\n\
    from operator import itemgetter\nfrom collections import Counter\nfrom collections\
    \ import deque\nfrom collections import defaultdict as dd\nimport fractions\n\
    from heapq import heappop, heappush, heapify\nimport array\nfrom bisect import\
    \ bisect_left, bisect_right, insort_left, insort_right\nfrom copy import deepcopy\
    \ as dcopy\nimport itertools\n# }}}\n\n# pre-defined{{{\nsys.setrecursionlimit(10**7)\n\
    INF = 10**20\nGOSA = 1.0 / 10**10\nMOD = 10**9+7\nALPHABETS = [chr(i) for i in\
    \ range(ord('a'), ord('z')+1)]  # can also use string module\ndef LI(): return\
    \ [int(x) for x in sys.stdin.readline().split()]\ndef LI_(): return [int(x)-1\
    \ for x in sys.stdin.readline().split()]\ndef LF(): return [float(x) for x in\
    \ sys.stdin.readline().split()]\ndef LS(): return sys.stdin.readline().split()\n\
    def I(): return int(sys.stdin.readline())\ndef F(): return float(sys.stdin.readline())\n\
    def DP(N, M, first): return [[first] * M for n in range(N)]\ndef DP3(N, M, L,\
    \ first): return [[[first] * L for n in range(M)] for _ in range(N)]\nfrom inspect\
    \ import currentframe\n# }}}\n\ndef solve():\n    return 0\n\nif __name__ == \"\
    __main__\":# {{{\n    solve()\n\n# vim: set foldmethod=marker: }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: problem_template/codes/solve.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: problem_template/codes/solve.py
layout: document
redirect_from:
- /library/problem_template/codes/solve.py
- /library/problem_template/codes/solve.py.html
title: problem_template/codes/solve.py
---
