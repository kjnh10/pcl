from invoke import task
from .snippet import extract_snips
from pathlib import Path
import os

@task
def build(c):
    print("Building!")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'codes/cpp'

    neosnip_file = Path(os.path.dirname(__file__)).parent / 'snippets/cpp/auto.snip'
    # vssnip_file = Path(os.path.dirname(__file__)).parent / 'template/.vscode/auto.code-snippets'
    vssnip_file = Path.home() / '.config/Code/User/snippets/auto.code-snippets'

    if neosnip_file.exists():
        neosnip_file.unlink()

    if vssnip_file.exists():
        vssnip_file.unlink()

    snippets = {}
    for f in CODE_DIR.rglob('*.cpp'):
        extract_snips(f, snippets)

    for name in snippets.keys():
        snippets[name].to_snip_file(neosnip_file, snippets, format='neosnippet')
        snippets[name].to_snip_file(vssnip_file, snippets, format='textmate')


