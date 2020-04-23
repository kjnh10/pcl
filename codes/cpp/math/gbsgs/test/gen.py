from random import randint, choice, sample, choices
from typing import TYPE_CHECKING, List, Optional, Type

L = [3, 5, 7, 9]
# print(randint(1, 100))  # # [1, 100]
# print(choice(L))  # 1つ選択
# print(sample(L, k=2))  # 非復元抽出
# print(sample(L, k=len(L)))  # random permutation
# print(choices(L, k=2))  # 復元抽出


def randperm(n: int):
    return sample(list(range(1, n+1)), k=n)


def randseq(n: int, l: int, r: int, distinct=False):
    res = []
    used = set()
    if (n>r-l+1) and distinct:
        raise Exception(print("n>r-l+1 and distinct=True is not impossible"))

    while len(res) < n:
        v = randint(l, r)
        if distinct and v in used:
            pass
        else:
            res.append(v)
            used.add(v)
    return res


def printtree(n: int):
    pass


def printgraph(n: int, m: int):
    pass


def pl(x: List):
    print(' '.join(map(str, x)))


def get_sieve_of_eratosthenes(n):
    if not isinstance(n, int):
        raise TypeError('n is int type.')
    if n < 2:
        raise ValueError('n is more than 2')
    prime = [2]
    limit = int(n**0.5)
    data = [i + 1 for i in range(2, n, 2)]
    while True:
        p = data[0]
        if limit <= p:
            return prime + data
        prime.append(p)
        data = [e for e in data if e % p != 0]


p = randint(1, 10000)
a = randint(1, 10000)
b = randint(1, p-1)
# p = choice(get_sieve_of_eratosthenes(100000))
print(a, b, p)
