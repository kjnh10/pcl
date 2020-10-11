---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#Btree, SegTree\nfrom math import ceil,log2\n\nclass Btree(object):\n   \
    \ def __init__(self, N):  # N:\u8981\u7D20\u6570\n        self.depth = ceil(log2(N))\
    \ + 1\n        self.number_of_nodes = (1 << self.depth) - 1\n        self.ls =\
    \ 2**(self.depth-1)-1  # leaf start\n        self.le = 2**(self.depth  )-1  #\
    \ leaf end + 1\n        self.leafs = range(self.ls, self.le)\n        self.data\
    \ = [0] * (self.number_of_nodes)  # \u6DF1\u3055depth\u306E\u4E8C\u5206\u6728\n\
    \n        # \u533A\u9593\u306E\u521D\u671F\u5316\n        self.ranges = [(0,0)]\
    \ * ((1 << self.depth) - 1)  # [l, r)\n        self.__set_range(0, 0, N)\n\n \
    \   def parent(self, v): return ceil((v-2)/2)\n    def chl(self, v): return 2*v\
    \ + 1\n    def chr(self, v): return 2*v + 2\n    def isleaf(self, v):\n      \
    \  if 2**(self.depth-1)-1 <= v:\n            return True\n        else:\n    \
    \        return False\n\n    def __set_range(self, v, l, r):\n        self.ranges[v]=\
    \ (l, r)\n        m = ceil((l+r)/2)\n        left = self.chl(v)\n        right\
    \ = self.chr(v)\n\n        self.ranges[left]= (l, m)\n        if not self.isleaf(left):\n\
    \            self.__set_range(left, l, m)\n\n        self.ranges[right]= (m, r)\n\
    \        if not self.isleaf(right):\n            self.__set_range(right, m, r)\n\
    \nclass SegTree(Btree):\n    def __init__(self, A):  # A:\u6570\u5217\n      \
    \  N = len(A)\n        super().__init__(N)\n\n        # \u8449\u306E\u521D\u671F\
    \u5316\n        for n in range(N):\n            self.data[self.ls + n] = A[n]\n\
    \n        self.__rec_calc(0)\n\n        self.worthless = float('inf')  #\u3053\
    \u308C\u3092\u5909\u66F4\u3059\u308B\u3002\n\n    def __op(self,a,b):\n      \
    \  \"\"\"\n        \u3053\u308C\u3092\u5909\u66F4\u3059\u308B\u3002\n        \"\
    \"\"\n        return min(a,b) #RMQ\n\n    def __rec_calc(self, v):\n        \"\
    \"\"\n        root\u304B\u3089\u518D\u5E30\u7684\u306B\u30CE\u30FC\u30C9\u306E\
    \u5024\u3092\u8A08\u7B97\u3057\u3066\u3044\u304F\u95A2\u6570\u3002\n        \"\
    \"\"\n        if self.isleaf(v):\n            return self.data[v]\n        else:\n\
    \            a = self.__rec_calc(self.chl(v))\n            b = self.__rec_calc(self.chr(v))\n\
    \            self.data[v] = self.__op(a,b)\n            return self.data[v]\n\n\
    \    def change(self, k, x):\n        \"\"\"\n        A\u306Ek\u756A\u76EE\u306E\
    \u5024(0-indexed)\u3092x\u306B\u5909\u66F4\n        \"\"\"\n        k += self.ls\
    \  # node\u5185\u306E\u5BFE\u5FDC\u3059\u308B\u8449\u306E\u756A\u53F7\u306B\u5909\
    \u63DB\n        self.data[k] = x\n        while k > 0:\n            k = (k-1)//2\
    \  # parent\n            self.data[k] = self.__op(self.data[2*k + 1], self.data[2*k\
    \ + 2])\n\n    def query(self, a, b, k=0):\n        \"\"\"\n        [a, b)\u306E\
    \u533A\u9593\u306E\u5024\u3092\u7BC0\u70B9k\u306B\u5BFE\u3057\u3066\u6C42\u3081\
    \u308B\u3002\u547C\u3073\u51FA\u3059\u3068\u304D\u306Fquery(a,b)\n        \"\"\
    \"\n        l,r = self.ranges[k]\n\n        # [a, b)\u3068[l, r)\u304C\u4EA4\u5DEE\
    \u3057\u306A\u3051\u308C\u3070, worthless\u3092\u8FD4\u3059\u3002\n        if\
    \ (r <= a or b <= l):\n            return self.worthless\n\n        # [a, b)\u304C\
    [l, r)\u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\u308C\u3070\u3053\u306E\
    \u7BC0\u70B9\u306E\u5024\u3092\u8FD4\u3059\u3002\n        if (a <= l and r <=\
    \ b):\n            return self.data[k]\n\n        # \u305D\u3046\u3067\u306A\u3051\
    \u308C\u30702\u3064\u306E\u5B50\u306E\u6700\u5C0F\u5024\n        left = self.query(a,\
    \ b, 2*k+1)\n        right = self.query(a, b, 2*k+2)\n        return self.__op(left,\
    \ right)\n\n# test\nif __name__ == '__main__':\n    bt = Btree(16)\n    print('depth',\
    \ bt.depth)\n    print(bt.ranges[0])\n    print(bt.ranges[5])\n\n    st = SegTree([5,3,7,9,6,4,1,2])\n\
    \    print(st.data[5])\n    print(st.query(3, 6))\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/btree.py
  requiredBy: []
  timestamp: '2020-04-25 20:06:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/python/btree.py
layout: document
redirect_from:
- /library/library/python/btree.py
- /library/library/python/btree.py.html
title: library/python/btree.py
---
