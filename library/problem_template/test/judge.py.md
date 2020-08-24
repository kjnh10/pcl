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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: problem_template/test/judge.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76c92c32675513a9b45b3a525f3ad871">problem_template/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/problem_template/test/judge.py">View this file on GitHub</a>
    - Last commit date: 2020-05-20 00:15:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import math
import sys
from pcm.codefile import JudgeResult as jr


def tell(x):
    print(x, flush=True)


def dump(x):
    print(x, ': by judge', file=sys.stderr)


def check_AIE():
    try:
        input()
    except EOFError:
        pass
    else:
        exit(jr.AIE)


def judge_case(x):
    dump(f'start judge for {x=}')
    try:
        num = 22
        while(num):
            num -= 1
            query = list(input().split())
            v = int(query[1])
            if (query[0] == "?"):
                tell(math.gcd(v, x))

            if (query[0] == "!"):
                if (abs(v-x) <= 7 or (v <= 2*x and x <= 2*v)):
                    dump(f"AC: {x=}, {v=}")
                    return 0
                else:
                    dump(f"WA: {x=}, {v=}")
                    sys.exit(jr.WA)
        sys.exit(jr.QLE)
    except Exception as e:
        print(e, file=sys.stderr)
        sys.exit(jr.RE)


def main():  # multi case type
    # input case from a case file
    # case fileの入力をとりきらないとsolver-codeからの出力を入力として受け取れないことに注意。
    Q = int(input())
    x = []
    for i in range(Q):
        x.append(int(input()))

    # judge
    tell(Q)  # TODO: needed only for multi-test-case
    for i in range(Q):
        print('', file=sys.stderr)
        judge_case(x[i])

    # これは何故か動かない。
    # check_AIE()
    sys.exit(jr.AC)


# def main():  # single case type
#     x = int(input())
#     judge_case(x)
#     sys.exit(jr.AC)


if __name__ == "__main__":
    main()

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

<a href="../../../index.html">Back to top page</a>

