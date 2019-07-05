# %snippet.set('bit1')%
# Binary Indexd Tree
class BIT():
    def __init__(self, N):
        self.data = [0]*(N+1)  # 1-indexed, 0 not used

    def sum(self, n):
        s = 0
        while n > 0:
            s += self.data[n]
            n -= (n & -n)
        return s

    def add(self, n, x):
        while n <= N:
            self.data[n] += x
            n += (n & -n)
# %snippet.end%


# test
# バブルソートの交換回数
N = 5
A = [3,5,2,1,4]
bit = BIT(N)
ninv = 0
for i in range(N):
    ninv += bit.sum(A[i])
    bit.add(A[i], 1)

ans = N*(N-1)//2 - ninv
assert(ans==6)

print('success')
