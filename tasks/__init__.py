from invoke import task
from .snippet import extract_snips
from pathlib import Path
import re
import os
import subprocess
import click

@task
def modify(c):
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

@task
def format(c):
    print("formatting cpp codes")

    CODE_DIR = Path(os.path.dirname(__file__)).parent
    for p in CODE_DIR.rglob("*.[ch]pp"):
        if 'snip' in p.name:
            continue  # snippetはformatされると動かなくなるので
        subprocess.run(f"clang-format {p} -i", shell=True)


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
