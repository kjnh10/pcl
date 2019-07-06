from invoke import task
from .snippet import extract_snips
from pathlib import Path
import os

@task
def build(c):
    print("building snippets")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'codes'
    neosnip_dir = Path(os.path.dirname(__file__)).parent / 'snippets/'
    vssnip_dir = Path.home() / '.config/Code/User/snippets/'

    _build_snippet(
            code_dir = CODE_DIR / 'cpp',
            extention = 'cpp',
            neosnip_file = neosnip_dir / 'cpp/auto.snip',
            vssnip_file = vssnip_dir / 'cpp.code-snippets',
            )
    _build_snippet(
            code_dir = CODE_DIR / 'python',
            extention = 'py',
            neosnip_file = neosnip_dir / 'python/auto.snip',
            vssnip_file = vssnip_dir / 'python.code-snippets',
            )


def _build_snippet(code_dir, extention, neosnip_file, vssnip_file):
    if neosnip_file.exists():
        neosnip_file.unlink()

    if vssnip_file.exists():
        vssnip_file.unlink()

    snippets = {}
    for f in code_dir.rglob(f'*.{extention}'):
        extract_snips(f, snippets)

    for name in snippets.keys():
        snippets[name].to_snip_file(neosnip_file, snippets, format='neosnippet')
        snippets[name].to_snip_file(vssnip_file, snippets, format='textmate')
