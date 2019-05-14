from invoke import task
from .snippet import extract_snips
from pathlib import Path
import os

@task
def build(c):
    print("Building!")

    CODE_DIR = Path(os.path.dirname(__file__)).parent / 'codes/cpp'
    snip_file = Path(os.path.dirname(__file__)).parent / 'snippets/cpp/auto.snip'

    snippets = {}
    if snip_file.exists():
        snip_file.unlink()

    for f in CODE_DIR.rglob('*.cpp'):
        extract_snips(f, snippets)

    for name in snippets.keys():
        snippets[name].to_snip_file(snip_file, snippets)

