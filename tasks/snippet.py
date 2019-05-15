import os
from pathlib import Path
import re
from copy import copy, deepcopy


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


    def save_to(self, snippets):
        # init for next snippet
        self.format_code()
        snippets[self.name] = deepcopy(self)


    def to_snip_file(self, snip_file, snippets):
        resolve_path = []
        resolve_path = self.__resolve_dependencies(resolve_path, snippets)
        print(self.name, resolve_path)
        with snip_file.open(mode='a') as out:
            out.write(f'snippet {self.name}\n')
            if ('alias' in self.option):
                out.write(f"alias {self.option['alias']}\n")

            for l in self.code:
                out.write('  ' + l)
            out.write('\n\n')


    def format_code(self):
        # 最後の空行は1行にする
        while (self.code[-1]=='\n'):
            self.code.pop()
        self.code.append('\n')


    def __resolve_dependencies(self, resolve_path, snippets):
        if self.resolving==True:
            raise Exception(
                    f"""
                    there is loop reference below.
                    {resolve_path}
                    """
                    )

        self.resolving = True
        resolve_path.append(self.name)

        if (len(self.dependencies)==0):
            pass
        else:
            for name in self.dependencies:
                snippets[name].__resolve_dependencies(resolve_path, snippets)
                self.code = snippets[name].code + self.code
                self.dependencies.remove(name)

        self.resolving = False
        return resolve_path


def extract_snips(f: Path, snippets: dict) -> list:
    def get_command_from(line) -> str:
        s = line.find('%')
        e = line.find('%', s+1)
        command = line[s+1:e]
        print(s, e, command)
        return command

    with f.open() as f:
        for l in f:
            if re.search("\%snippet.set.*\%", l):
                if 'snippet' in locals():
                    snippet.save_to(snippets)
                snippet = Snippet()
                exec(get_command_from(l))
            elif re.search("\%snippet.end.*\%", l):
                snippet.save_to(snippets)
                del snippet
            elif re.search("\%snippet.*\%", l):
                exec(get_command_from(l))
            elif 'snippet' in locals():
                snippet.append(l)
            else:
                pass  # ignore non-snippet lines

    if 'snippet' in locals():
        snippet.save_to(snippets)


