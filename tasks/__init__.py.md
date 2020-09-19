---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from invoke import task\nfrom .snippet import Snippets\nfrom pathlib import\
    \ Path\nimport re\nimport os\nimport subprocess\nimport click\n\n@task\ndef modpath(c):\n\
    \    print(\"modifying path\")\n\n    CODE_DIR = Path(os.path.dirname(__file__)).parent\
    \ / 'library/cpp'\n    os.chdir(CODE_DIR)\n\n    headers = {}\n    print(\"---------------found\
    \ headers-------------------------\")\n    for p in CODE_DIR.rglob(\"*.hpp\"):\n\
    \        print(p)\n        if p.name in headers.keys():\n            raise Exception(\"\
    header dupulication\")\n        headers[p.name] = p.resolve()\n\n    print(\"\
    ---------------------------------------------------\")\n    for p in CODE_DIR.rglob(\"\
    *.[ch]pp\"):\n        if (p.is_dir()):\n            continue\n        modified\
    \ = False\n        missing_library = []\n        to_write_data = []\n        modified_history\
    \ = []\n        with open(p, mode='r') as f:\n            print(p)\n         \
    \   for line in f.readlines():\n                if (re.match('#include \".*\"\
    ', line)):  # coment out\u3055\u308C\u3066\u308B\u5834\u5408\u306F\u51E6\u7406\
    \u3057\u306A\u3044\n                    first = line.find('\"')\n            \
    \        second = line.find('\"', first+1)\n                    now_path_str =\
    \ line[first+1:second]\n                    now_path = Path(now_path_str)\n  \
    \                  if (now_path.name not in headers):\n                      \
    \  click.secho(f\"not exit: {now_path}\", fg='red')\n                        missing_library.append(now_path_str)\n\
    \                    elif (headers[now_path.name] != now_path):\n            \
    \            # \u3053\u3053\u306B\u306F\u53C2\u7167\u306F\u58CA\u308C\u3066\u3044\
    \u306A\u3044\u304C\u30D5\u30A1\u30A4\u30EB\u304B\u3089\u306E\u76F8\u5BFE\u30D1\
    \u30B9\u3067\u66F8\u3044\u305F\u3082\u306E\u3082\u51FA\u3066\u304F\u308B\u3002\
    \n                        # modified_path = headers[now_path.name].relative_to(CODE_DIR)\n\
    \                        modified_path = Path(os.path.relpath(headers[now_path.name],\
    \ p.parent))\n                        if str(modified_path) != now_path_str:\n\
    \                            modified_line = re.sub('#include \".*\"', f'#include\
    \ \"{modified_path}\"', line)\n                            to_write_data.append(modified_line)\n\
    \                            modified = True\n                            modified_history.append((line,\
    \ modified_line))\n                        else:\n                           \
    \ to_write_data.append(line)\n                    else:\n                    \
    \    click.secho(f\"ok: {now_path}\", fg='green')\n                        to_write_data.append(line)\n\
    \                else:\n                    to_write_data.append(line)\n\n   \
    \     if missing_library:\n            click.secho(f'missing library in {p}',\
    \ fg='red')\n            print(missing_library)\n            print(\"\")\n   \
    \     elif modified:\n            click.secho(f\"changed {p.absolute()}\", fg='yellow')\n\
    \            for change in modified_history:\n                print(f\"before:\
    \ {change[0]}\".rstrip())\n                print(f\"after : {change[1]}\".rstrip())\n\
    \            with open(p, mode='w') as f:\n                for line in to_write_data:\n\
    \                    f.write(line)\n            print(\"\")\n\n@task\ndef build(c):\n\
    \    print(\"building snippets\")\n\n    CODE_DIR = Path(os.path.dirname(__file__)).parent\
    \ / 'library'\n    neosnip_dir = Path(os.path.dirname(__file__)).parent / 'snippets/'\n\
    \    vssnip_dir = Path.home() / '.config/Code/User/snippets/'\n\n    print(\"\\\
    nfor cpp--------------\")\n    _build_snippet(\n            code_dir = CODE_DIR\
    \ / 'cpp',\n            extentions = ['cpp', 'hpp'],\n            neosnip_file\
    \ = neosnip_dir / 'cpp/auto.snip',\n            vssnip_file = vssnip_dir / 'cpp.code-snippets',\n\
    \            )\n\n    print(\"\\nfor python--------------\")\n    _build_snippet(\n\
    \            code_dir = CODE_DIR / 'python',\n            extentions = ['py'],\n\
    \            neosnip_file = neosnip_dir / 'python/auto.snip',\n            vssnip_file\
    \ = vssnip_dir / 'python.code-snippets',\n            )\n\n@task\ndef format(c):\n\
    \    print(\"formatting cpp codes\")\n\n    CODE_DIR = Path(os.path.dirname(__file__)).parent\
    \ / 'library/cpp'\n    for p in CODE_DIR.rglob(\"*.[ch]pp\"):\n        if 'snip'\
    \ in p.name:\n            continue  # snippet\u306Fformat\u3055\u308C\u308B\u3068\
    \u52D5\u304B\u306A\u304F\u306A\u308B\u306E\u3067\n        subprocess.run(f\"clang-format\
    \ {p} -i\", shell=True)\n\n\ndef _build_snippet(code_dir, extentions, neosnip_file,\
    \ vssnip_file):\n    snippets = Snippets()\n    for extension in extentions:\n\
    \        for f in code_dir.rglob(f'*.{extension}'):\n            snippets.extract_snips(f,\
    \ extension)\n    snippets.topological_sort()\n    snippets.to_snip_file(neosnip_file,\
    \ format='neosnippet')\n    snippets.to_snip_file(vssnip_file, format='textmate')\n"
  dependsOn: []
  isVerificationFile: false
  path: tasks/__init__.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tasks/__init__.py
layout: document
redirect_from:
- /library/tasks/__init__.py
- /library/tasks/__init__.py.html
title: tasks/__init__.py
---
