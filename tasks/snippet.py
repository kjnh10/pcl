import os
from pathlib import Path
import re
from copy import copy, deepcopy
import json
from typing import TYPE_CHECKING, List, Optional, Type
from collections import deque, defaultdict
import click


class Snippet(object):
    def __init__(self):
        self.name = ''
        self.option = {}
        self.code = []
        self.dependencies = []
        self.resolving = False

    def set(self, name):
        self.name = name

    def config(self, option: dict):
        # TODO: dot access出来るようにしたい。
        self.option = option

    def include(self, name):
        self.dependencies.append(name)

    def append(self, line):
        self.code.append(line)

    def format_code(self):
        # 最後の空行は1行にする
        while (self.code[-1]=='\n'):
            self.code.pop()
        self.code.append('\n')


class Dag(object):
    def __init__(self):
        self.nodes = []  # idx  -> name
        self.pos = {}    # name -> idx
        self.size = 0    # 頂点数
        self.resolved_paths = None

    def add_node(self, node):
        node.format_code()
        self.nodes.append(deepcopy(node))
        self.pos[node.name] = len(self.nodes) - 1
        self.size += 1
        print(f"{self.pos[node.name]}: {node.name}")

    def topological_sort(self):
        edges = []
        for node in self.nodes:
            for dependency_node in node.dependencies:
                edges.append((self.pos[dependency_node], self.pos[node.name]))

        outs = defaultdict(list)
        ins = defaultdict(list)
        in_nums = defaultdict(int)
        for v1, v2 in edges:
            outs[v1].append(v2)  # outs[v]: vから出ていく辺
            ins[v2].append(v1)
            in_nums[v2] += 1         # ins[v]:  vの入次数

        q = deque(v1 for v1 in range(self.size) if in_nums[v1] == 0)
        sorted_list = []
        ord_in_tpsorted_list = defaultdict(int)
        while q:
            v1 = q.popleft()
            sorted_list.append(v1)
            ord_in_tpsorted_list[v1] = len(sorted_list) - 1
            for v2 in outs[v1]:
                in_nums[v2] -= 1
                if in_nums[v2] == 0:
                    q.append(v2)
        click.secho("order sorted by topological sort", fg='green')
        print(sorted_list)

        paths = {}
        for i in sorted_list:
            paths[i] = set([i])
            for j in ins[i]:
                paths[i] = paths[i] | paths[j]

        for i in sorted_list:
            paths[i] = list(paths[i])
            paths[i].sort(key=lambda x: ord_in_tpsorted_list[x])

        click.secho("resolved_dependencies", fg='green')
        print(paths)
        for i in range(self.size):
            print(str(i)+":", self.nodes[i].name, list(map(lambda x:self.nodes[x].name, paths[i])))

        self.resolved_paths = paths


class Snippets(Dag):
    def __init__(self):
        super().__init__()
        self._names_and_aliases = set()

    def add_node(self, node):
        super().add_node(node)

        def check(name):
            if name in self._names_and_aliases:
                raise Exception(f"{name} declaration dupulicated.")
            self._names_and_aliases.add(name)

        check(node.name)

        if ('alias' in node.option):
            if type(node.option['alias']) is str:
                check(node.option['alias'])
            elif type(node.option['alias']) is list:
                [check(alias) for alias in node.option['alias']]

    def extract_snips(self, f: Path) -> list:
        def get_command_from(line) -> str:
            s = line.find('%')
            e = line.find('%', s+1)
            command = line[s+1:e]
            return command

        snippet = None
        with f.open() as f:
            for l in f:
                if re.search("\%snippet.set.*\%", l):
                    if snippet:
                        self.add_node(snippet)
                    snippet = Snippet()
                    exec(get_command_from(l))
                elif re.search("\%snippet.end.*\%", l):
                    self.add_node(snippet)
                    snippet = None
                elif re.search("\%snippet.*\%", l):
                    exec(get_command_from(l))
                elif snippet:
                    snippet.append(l)
                else:
                    pass  # ignore non-snippet lines
        if snippet:
            self.add_node(snippet)

    def to_snip_file(self, snip_file, format, scope=None):
        if snip_file.exists():
            snip_file.unlink()

        for idx in range(self.size):
            snippet = self.nodes[idx]
            resolve_path = self.resolved_paths[idx]
            code_to_write = []
            for didx in resolve_path:
                code_to_write += self.nodes[didx].code

            with snip_file.open(mode='a') as out:
                if format == 'neosnippet':
                    out.write(f'snippet {snippet.name}\n')
                    if ('alias' in snippet.option):
                        if type(snippet.option['alias']) is str:
                            out.write(f"alias {snippet.option['alias']}\n")
                        elif type(snippet.option['alias']) is list:
                            out.write(f"alias {','.join(snippet.option['alias'])}\n")

                    for l in code_to_write:
                        out.write('  ' + l)
                    out.write('\n\n')
                elif format == 'textmate':
                    res = {}
                    with open(snip_file, mode='r') as f:
                        try:
                            res = json.loads(f.read())
                        except:
                            pass

                    prefix = [snippet.name]
                    if ('alias' in snippet.option):
                        if type(snippet.option['alias']) is str:
                            prefix.append(snippet.option['alias'])
                        elif type(snippet.option['alias']) is list:
                            prefix += snippet.option['alias']

                    res[snippet.name] = {
                            "prefix": prefix,
                            "body": [x.replace("\n", "") for x in code_to_write],
                            "description": "desc",
                            }
                    if scope:
                        res[snippet.name]['scope'] = scope
                    json.dump(res, open(snip_file, mode='w'), indent=2, ensure_ascii=False)
                else:
                    raise Exception(f'to_snip_file for {format} not defined')
