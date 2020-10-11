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
  code: "import math\nimport sys\nfrom pcm.codefile import JudgeResult as jr\n\n\n\
    def tell(x):\n    print(x, flush=True)\n\n\ndef dump(x):\n    print(x, ': by judge',\
    \ file=sys.stderr)\n\n\ndef check_AIE():\n    try:\n        input()\n    except\
    \ EOFError:\n        pass\n    else:\n        exit(jr.AIE)\n\n\ndef judge_case(x):\n\
    \    dump(f'start judge for {x=}')\n    try:\n        num = 22\n        while(num):\n\
    \            num -= 1\n            query = list(input().split())\n           \
    \ v = int(query[1])\n            if (query[0] == \"?\"):\n                tell(math.gcd(v,\
    \ x))\n\n            if (query[0] == \"!\"):\n                if (abs(v-x) <=\
    \ 7 or (v <= 2*x and x <= 2*v)):\n                    dump(f\"AC: {x=}, {v=}\"\
    )\n                    return 0\n                else:\n                    dump(f\"\
    WA: {x=}, {v=}\")\n                    sys.exit(jr.WA)\n        sys.exit(jr.QLE)\n\
    \    except Exception as e:\n        print(e, file=sys.stderr)\n        sys.exit(jr.RE)\n\
    \n\ndef main():  # multi case type\n    # input case from a case file\n    # case\
    \ file\u306E\u5165\u529B\u3092\u3068\u308A\u304D\u3089\u306A\u3044\u3068solver-code\u304B\
    \u3089\u306E\u51FA\u529B\u3092\u5165\u529B\u3068\u3057\u3066\u53D7\u3051\u53D6\
    \u308C\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\u3002\n    Q = int(input())\n\
    \    x = []\n    for i in range(Q):\n        x.append(int(input()))\n\n    # judge\n\
    \    tell(Q)  # TODO: needed only for multi-test-case\n    for i in range(Q):\n\
    \        print('', file=sys.stderr)\n        judge_case(x[i])\n\n    # \u3053\u308C\
    \u306F\u4F55\u6545\u304B\u52D5\u304B\u306A\u3044\u3002\n    # check_AIE()\n  \
    \  sys.exit(jr.AC)\n\n\n# def main():  # single case type\n#     x = int(input())\n\
    #     judge_case(x)\n#     sys.exit(jr.AC)\n\n\nif __name__ == \"__main__\":\n\
    \    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: problem_template/test/judge.py
  requiredBy: []
  timestamp: '2020-05-20 00:15:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: problem_template/test/judge.py
layout: document
redirect_from:
- /library/problem_template/test/judge.py
- /library/problem_template/test/judge.py.html
title: problem_template/test/judge.py
---
