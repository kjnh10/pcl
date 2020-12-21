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
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nfrom pathlib import Path\nimport re\nfrom copy import copy, deepcopy\n\
    import json\nfrom typing import TYPE_CHECKING, List, Optional, Type\nfrom collections\
    \ import deque, defaultdict\nimport click\n\ncomment_string  = {'cpp': '//', 'hpp':\
    \ '//', 'py': '#'}\n\nclass Snippet(object):\n    def __init__(self, extension):\n\
    \        self.extension = extension\n        self.name = ''\n        self.option\
    \ = {}\n        self.code = []\n        self.dependencies = []\n        self.fold_flag\
    \ = False\n\n    def set(self, name):\n        self.name = name\n\n    def config(self,\
    \ option: dict):\n        # TODO: dot access\u51FA\u6765\u308B\u3088\u3046\u306B\
    \u3057\u305F\u3044\u3002\n        self.option = option\n\n    def include(self,\
    \ name):\n        self.dependencies.append(name)\n\n    def append_line(self,\
    \ line):\n        self.code.append(line)\n\n    def fold(self):\n        self.fold_flag\
    \ = True\n\n    def format_code(self):\n        # \u6700\u5F8C\u306E\u7A7A\u884C\
    \u306F1\u884C\u306B\u3059\u308B\n        while (self.code[-1]=='\\n'):\n     \
    \       self.code.pop()\n\n        if self.fold_flag:\n            self.code.insert(0,\
    \ f\"{comment_string[self.extension]} snippet:{self.name}\" + ' {{{\\n')\n   \
    \         self.append_line(f\"{comment_string[self.extension]} snippet:{self.name}\"\
    \ + ' }}}\\n')\n\n\nclass Dag(object):\n    def __init__(self):\n        self.nodes\
    \ = []  # idx  -> name\n        self.pos = {}    # name -> idx\n        self.size\
    \ = 0    # \u9802\u70B9\u6570\n        self.resolved_paths = None\n\n    def add_node(self,\
    \ node):\n        node.format_code()\n        self.nodes.append(deepcopy(node))\n\
    \        self.pos[node.name] = len(self.nodes) - 1\n        self.size += 1\n \
    \       print(f\"{self.pos[node.name]}: {node.name}\")\n\n    def topological_sort(self):\n\
    \        edges = []\n        for node in self.nodes:\n            for dependency_node\
    \ in node.dependencies:\n                edges.append((self.pos[dependency_node],\
    \ self.pos[node.name]))\n\n        outs = defaultdict(list)\n        ins = defaultdict(list)\n\
    \        in_nums = defaultdict(int)\n        for v1, v2 in edges:\n          \
    \  outs[v1].append(v2)  # outs[v]: v\u304B\u3089\u51FA\u3066\u3044\u304F\u8FBA\
    \n            ins[v2].append(v1)\n            in_nums[v2] += 1         # ins[v]:\
    \  v\u306E\u5165\u6B21\u6570\n\n        q = deque(v1 for v1 in range(self.size)\
    \ if in_nums[v1] == 0)\n        sorted_list = []\n        ord_in_tpsorted_list\
    \ = defaultdict(int)\n        while q:\n            v1 = q.popleft()\n       \
    \     sorted_list.append(v1)\n            ord_in_tpsorted_list[v1] = len(sorted_list)\
    \ - 1\n            for v2 in outs[v1]:\n                in_nums[v2] -= 1\n   \
    \             if in_nums[v2] == 0:\n                    q.append(v2)\n       \
    \ click.secho(\"order sorted by topological sort\", fg='green')\n        print(sorted_list)\n\
    \n        paths = {}\n        for i in sorted_list:\n            paths[i] = set([i])\n\
    \            for j in ins[i]:\n                paths[i] = paths[i] | paths[j]\n\
    \n        for i in sorted_list:\n            paths[i] = list(paths[i])\n     \
    \       paths[i].sort(key=lambda x: ord_in_tpsorted_list[x])\n\n        click.secho(\"\
    resolved_dependencies\", fg='green')\n        print(paths)\n        for i in range(self.size):\n\
    \            print(str(i)+\":\", self.nodes[i].name, list(map(lambda x:self.nodes[x].name,\
    \ paths[i])))\n\n        self.resolved_paths = paths\n\n\nclass Snippets(Dag):\n\
    \    def __init__(self):\n        super().__init__()\n        self._names_and_aliases\
    \ = set()\n\n    def add_node(self, node):\n        super().add_node(node)\n\n\
    \        def check(name):\n            if name in self._names_and_aliases:\n \
    \               print(name)\n                raise Exception(f\"{name} declaration\
    \ dupulicated.\")\n            self._names_and_aliases.add(name)\n\n        check(node.name)\n\
    \n        if ('alias' in node.option):\n            if type(node.option['alias'])\
    \ is str:\n                check(node.option['alias'])\n            elif type(node.option['alias'])\
    \ is list:\n                [check(alias) for alias in node.option['alias']]\n\
    \n    def extract_snips(self, f: Path, extension: str) -> list:\n        def get_command_from(line)\
    \ -> str:\n            s = line.find('%')\f\n            e = line.find('%', s+1)\n\
    \            command = line[s+1:e]\n            return command\n\n        snippet\
    \ = None\n        with f.open() as f:\n            for line in f:\n          \
    \      if re.search(\"\\%snippet.set.*\\%\", line):\n                    if snippet:\n\
    \                        self.add_node(snippet)\n                    snippet =\
    \ Snippet(extension)\n                    exec(get_command_from(line))\n     \
    \           elif re.search(\"\\%snippet.end.*\\%\", line):\n                 \
    \   self.add_node(snippet)\n                    snippet = None\n             \
    \   elif re.search(\"\\%snippet.*\\%\", line):\n                    exec(get_command_from(line))\n\
    \                elif snippet:\n                    if (snippet.code or line.strip()):\n\
    \                        snippet.append_line(line)\n                else:\n  \
    \                  pass  # ignore non-snippet lines\n        if snippet:\n   \
    \         self.add_node(snippet)\n\n    def to_snip_file(self, snip_file, format,\
    \ scope=None):\n        if snip_file.exists():\n            snip_file.unlink()\n\
    \n        for idx in range(self.size):\n            snippet = self.nodes[idx]\n\
    \            resolve_path = self.resolved_paths[idx]\n            code_to_write\
    \ = []\n            for didx in resolve_path:\n                code_to_write +=\
    \ self.nodes[didx].code\n                code_to_write += [\"\\n\"]  # snippet\u306E\
    snippet\u306E\u9593\u306F\u898B\u3084\u3059\u304F\u7A7A\u767D\u884C\u3092\u3044\
    \u308C\u308B\u3002\n            # \u6700\u5F8C\u306E\u6539\u884C\u306F\u3044\u3089\
    \u306A\u3044\u3002vscode\u3067\uFF11\u884Csnippet\u3068\u304B\u306B\u6539\u884C\
    \u304C\u5165\u3063\u3066\u3057\u307E\u3046\u306E\u3067\n            code_to_write.pop()\n\
    \n            with snip_file.open(mode='a') as out:\n                if format\
    \ == 'neosnippet':\n                    out.write(f'snippet {snippet.name}\\n')\n\
    \                    if ('alias' in snippet.option):\n                       \
    \ if type(snippet.option['alias']) is str:\n                            out.write(f\"\
    alias {snippet.option['alias']}\\n\")\n                        elif type(snippet.option['alias'])\
    \ is list:\n                            out.write(f\"alias {','.join(snippet.option['alias'])}\\\
    n\")\n\n                    for l in code_to_write:\n                        out.write('\
    \  ' + l)\n                    out.write('\\n\\n')\n                elif format\
    \ == 'textmate':\n                    res = {}\n                    with open(snip_file,\
    \ mode='r') as f:\n                        try:\n                            res\
    \ = json.loads(f.read())\n                        except:\n                  \
    \          pass\n\n                    prefix = [snippet.name]\n             \
    \       if ('alias' in snippet.option):\n                        if type(snippet.option['alias'])\
    \ is str:\n                            prefix.append(snippet.option['alias'])\n\
    \                        elif type(snippet.option['alias']) is list:\n       \
    \                     prefix += snippet.option['alias']\n\n                  \
    \  res[snippet.name] = {\n                            \"prefix\": prefix,\n  \
    \                          \"body\": [x.replace(\"\\n\", \"\") for x in code_to_write],\n\
    \                            \"description\": \"desc\",\n                    \
    \        }\n                    if scope:\n                        res[snippet.name]['scope']\
    \ = scope\n                    json.dump(res, open(snip_file, mode='w'), indent=2,\
    \ ensure_ascii=False)\n                else:\n                    raise Exception(f'to_snip_file\
    \ for {format} not defined')\n"
  dependsOn: []
  isVerificationFile: false
  path: tasks/snippet.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tasks/snippet.py
layout: document
redirect_from:
- /library/tasks/snippet.py
- /library/tasks/snippet.py.html
title: tasks/snippet.py
---
