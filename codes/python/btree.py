#Btree, SegTree
from math import ceil,log2

class Btree(object):
    def __init__(self, N):  # N:要素数
        self.depth = ceil(log2(N)) + 1
        self.number_of_nodes = (1 << self.depth) - 1
        self.ls = 2**(self.depth-1)-1  # leaf start
        self.le = 2**(self.depth  )-1  # leaf end + 1
        self.leafs = range(self.ls, self.le)
        self.data = [0] * (self.number_of_nodes)  # 深さdepthの二分木

        # 区間の初期化
        self.ranges = [(0,0)] * ((1 << self.depth) - 1)  # [l, r)
        self.__set_range(0, 0, N)

    def parent(self, v): return ceil((v-2)/2)
    def chl(self, v): return 2*v + 1
    def chr(self, v): return 2*v + 2
    def isleaf(self, v):
        if 2**(self.depth-1)-1 <= v:
            return True
        else:
            return False

    def __set_range(self, v, l, r):
        self.ranges[v]= (l, r)
        m = ceil((l+r)/2)
        left = self.chl(v)
        right = self.chr(v)

        self.ranges[left]= (l, m)
        if not self.isleaf(left):
            self.__set_range(left, l, m)

        self.ranges[right]= (m, r)
        if not self.isleaf(right):
            self.__set_range(right, m, r)

class SegTree(Btree):
    def __init__(self, A):  # A:数列
        N = len(A)
        super().__init__(N)

        # 葉の初期化
        for n in range(N):
            self.data[self.ls + n] = A[n]

        self.__rec_calc(0)

        self.worthless = float('inf')  #これを変更する。

    def __op(self,a,b):
        """
        これを変更する。
        """
        return min(a,b) #RMQ

    def __rec_calc(self, v):
        """
        rootから再帰的にノードの値を計算していく関数。
        """
        if self.isleaf(v):
            return self.data[v]
        else:
            a = self.__rec_calc(self.chl(v))
            b = self.__rec_calc(self.chr(v))
            self.data[v] = self.__op(a,b)
            return self.data[v]

    def change(self, k, x):
        """
        Aのk番目の値(0-indexed)をxに変更
        """
        k += self.ls  # node内の対応する葉の番号に変換
        self.data[k] = x
        while k > 0:
            k = (k-1)//2  # parent
            self.data[k] = self.__op(self.data[2*k + 1], self.data[2*k + 2])

    def query(self, a, b, k=0):
        """
        [a, b)の区間の値を節点kに対して求める。呼び出すときはquery(a,b)
        """
        l,r = self.ranges[k]

        # [a, b)と[l, r)が交差しなければ, worthlessを返す。
        if (r <= a or b <= l):
            return self.worthless

        # [a, b)が[l, r)を完全に含んでいればこの節点の値を返す。
        if (a <= l and r <= b):
            return self.data[k]

        # そうでなければ2つの子の最小値
        left = self.query(a, b, 2*k+1)
        right = self.query(a, b, 2*k+2)
        return self.__op(left, right)

# test
if __name__ == '__main__':
    bt = Btree(16)
    print('depth', bt.depth)
    print(bt.ranges[0])
    print(bt.ranges[5])

    st = SegTree([5,3,7,9,6,4,1,2])
    print(st.data[5])
    print(st.query(3, 6))

