from invoke import task
from .snippet import extract_snips
from pathlib import Path
import re
import os
import click

@task
def modify(c):
    print("modifying path")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'codes/cpp'
    os.chdir(CODE_DIR)

    headers = {}
    for p in CODE_DIR.rglob("*.hpp"):
        print(p)
        if p.name in headers.keys():
            raise Exception("header dupulication")
        headers[p.name] = p.resolve()

    for p in CODE_DIR.rglob("*"):
        if (p.is_dir()):
            continue
        modified = False
        missing_library = []
        modified_lines = []
        with open(p, mode='r') as f:
            for line in f.readlines():
                if (re.search('#include ".*"', line)):
                    first = line.find('"')
                    second = line.find('"', first+1)
                    now_path_str = line[first+1:second]
                    now_path = Path(now_path_str)
                    if (now_path.name not in headers):
                        click.secho(f"not exit: {now_path}", fg='red')
                        missing_library.append(now_path_str)
                    elif (headers[now_path.name] != now_path):
                        # ここには参照は壊れていないがファイルからの相対パスで書いたものも出てくる。
                        modified_path = headers[now_path.name].relative_to(CODE_DIR)
                        if str(modified_path) != now_path_str:
                            click.secho(f"path changed: {now_path}", fg='yellow')
                            modified_line = re.sub('#include ".*"', f'#include "{modified_path}"', line)
                            modified_lines.append(modified_line)
                            modified = True
                        else:
                            modified_lines.append(line)
                    else:
                        click.secho(f"ok: {now_path}", fg='green')
                        modified_lines.append(line)
                else:
                    modified_lines.append(line)

        if missing_library:
            click.secho("{p} has missing library", fg='red')
            print(missing_library)
        elif modified:
            print(f"changed {p.absolute()}")
            with open(p, mode='w') as f:
                for line in modified_lines:
                    f.write(line)

@task
def build(c):
    print("building snippets")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'codes'
    neosnip_dir = Path(os.path.dirname(__file__)).parent / 'snippets/'
    vssnip_dir = Path.home() / '.config/Code/User/snippets/'

    _build_snippet(
            code_dir = CODE_DIR / 'cpp',
            extentions = ['cpp', 'hpp'],
            neosnip_file = neosnip_dir / 'cpp/auto.snip',
            vssnip_file = vssnip_dir / 'cpp.code-snippets',
            )
    _build_snippet(
            code_dir = CODE_DIR / 'python',
            extentions = ['py'],
            neosnip_file = neosnip_dir / 'python/auto.snip',
            vssnip_file = vssnip_dir / 'python.code-snippets',
            )


def _build_snippet(code_dir, extentions, neosnip_file, vssnip_file):
    if neosnip_file.exists():
        neosnip_file.unlink()

    if vssnip_file.exists():
        vssnip_file.unlink()

    snippets = {}
    for extention in extentions:
        for f in code_dir.rglob(f'*.{extention}'):
            extract_snips(f, snippets)

    for name in snippets.keys():
        snippets[name].to_snip_file(neosnip_file, snippets, format='neosnippet')
        snippets[name].to_snip_file(vssnip_file, snippets, format='textmate')


