import os
from pathlib import Path
import re
from copy import copy

CODE_DIR = Path(os.path.dirname(__file__)) / 'codes/cpp'
snip_file = Path(os.path.dirname(__file__)) / 'snippets/cpp.snip'
snippets = {}

class Snippet(object):
    def __init__(self):
        self.name = ''
        self.code = []
        self.read_flag = False
        self.dependencies = []
        self.resolving = False


    def set(self, name):
        self.name = name


    def config(self, *dict):
        # TODO: implement
        print(dict)


    def include(self, name):
        self.dependencies.append(name)


    def append(self, line):
        self.code.append(line)


    def end(self):
        # init for next snippet
        self.read_flag = False
        snippets[self.name] = copy(self)
        self.__init__()


    def to_snip_file(self):
        resolve_path = []
        resolve_path = self.__resolve_dependencies(resolve_path)
        print(self.name, resolve_path)
        with snip_file.open(mode='a') as out:
            out.write(f'snippet  {self.name}\n')
            for l in self.code:
                out.write('  ' + l)
            out.write('\n\n')


    def __resolve_dependencies(self, resolve_path):
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
                snippets[name].__resolve_dependencies(resolve_path)
                self.code = snippets[name].code + self.code
                self.dependencies.remove(name)

        self.resolving = False
        return resolve_path


def extract_snips(f: Path) -> list:
    snippet = Snippet()
    with f.open() as f:
        for l in f:
            if re.search("\%snippet.*\%", l):
                if not snippet.read_flag:
                    snippet.read_flag=True

                s = l.find('%')
                e = l.find('%', s+1)
                command = l[s+1:e]
                # print(s, e, command)
                exec(command)
            elif snippet.read_flag:
                snippet.append(l)
            else:
                pass  # ignore non-snippet lines


if __name__=='__main__':
    if snip_file.exists():
        snip_file.unlink()

    for f in CODE_DIR.rglob('*.cpp'):
        extract_snips(f)

    for name in snippets.keys():
        snippets[name].to_snip_file()


