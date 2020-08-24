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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tasks/__init__.py

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2cb1ad4f3eb0ea704c74a73689ad1654">tasks</a>
* <a href="{{ site.github.repository_url }}/blob/master/tasks/__init__.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from invoke import task
from .snippet import Snippets
from pathlib import Path
import re
import os
import subprocess
import click

@task
def modpath(c):
    print("modifying path")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'library/cpp'
    os.chdir(CODE_DIR)

    headers = {}
    print("---------------found headers-------------------------")
    for p in CODE_DIR.rglob("*.hpp"):
        print(p)
        if p.name in headers.keys():
            raise Exception("header dupulication")
        headers[p.name] = p.resolve()

    print("---------------------------------------------------")
    for p in CODE_DIR.rglob("*.[ch]pp"):
        if (p.is_dir()):
            continue
        modified = False
        missing_library = []
        to_write_data = []
        modified_history = []
        with open(p, mode='r') as f:
            print(p)
            for line in f.readlines():
                if (re.match('#include ".*"', line)):  # coment outされてる場合は処理しない
                    first = line.find('"')
                    second = line.find('"', first+1)
                    now_path_str = line[first+1:second]
                    now_path = Path(now_path_str)
                    if (now_path.name not in headers):
                        click.secho(f"not exit: {now_path}", fg='red')
                        missing_library.append(now_path_str)
                    elif (headers[now_path.name] != now_path):
                        # ここには参照は壊れていないがファイルからの相対パスで書いたものも出てくる。
                        # modified_path = headers[now_path.name].relative_to(CODE_DIR)
                        modified_path = Path(os.path.relpath(headers[now_path.name], p.parent))
                        if str(modified_path) != now_path_str:
                            modified_line = re.sub('#include ".*"', f'#include "{modified_path}"', line)
                            to_write_data.append(modified_line)
                            modified = True
                            modified_history.append((line, modified_line))
                        else:
                            to_write_data.append(line)
                    else:
                        click.secho(f"ok: {now_path}", fg='green')
                        to_write_data.append(line)
                else:
                    to_write_data.append(line)

        if missing_library:
            click.secho(f'missing library in {p}', fg='red')
            print(missing_library)
            print("")
        elif modified:
            click.secho(f"changed {p.absolute()}", fg='yellow')
            for change in modified_history:
                print(f"before: {change[0]}".rstrip())
                print(f"after : {change[1]}".rstrip())
            with open(p, mode='w') as f:
                for line in to_write_data:
                    f.write(line)
            print("")

@task
def build(c):
    print("building snippets")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'library'
    neosnip_dir = Path(os.path.dirname(__file__)).parent / 'snippets/'
    vssnip_dir = Path.home() / '.config/Code/User/snippets/'

    print("\nfor cpp--------------")
    _build_snippet(
            code_dir = CODE_DIR / 'cpp',
            extentions = ['cpp', 'hpp'],
            neosnip_file = neosnip_dir / 'cpp/auto.snip',
            vssnip_file = vssnip_dir / 'cpp.code-snippets',
            )

    print("\nfor python--------------")
    _build_snippet(
            code_dir = CODE_DIR / 'python',
            extentions = ['py'],
            neosnip_file = neosnip_dir / 'python/auto.snip',
            vssnip_file = vssnip_dir / 'python.code-snippets',
            )

@task
def format(c):
    print("formatting cpp codes")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'library/cpp'
    for p in CODE_DIR.rglob("*.[ch]pp"):
        if 'snip' in p.name:
            continue  # snippetはformatされると動かなくなるので
        subprocess.run(f"clang-format {p} -i", shell=True)


def _build_snippet(code_dir, extentions, neosnip_file, vssnip_file):
    snippets = Snippets()
    for extension in extentions:
        for f in code_dir.rglob(f'*.{extension}'):
            snippets.extract_snips(f, extension)
    snippets.topological_sort()
    snippets.to_snip_file(neosnip_file, format='neosnippet')
    snippets.to_snip_file(vssnip_file, format='textmate')

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

<a href="../../index.html">Back to top page</a>

