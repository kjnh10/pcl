# ---- memo -----------------
# 巡回セールスマン問題
# ---------------------------

def tsp(d):
    N = len(d)  # node num
    dp = [[float('inf') for j in range(N)] for i in range(2**N)]

    V = (1<<N)-1
    dp[V][0] = 0

    for S in range(V-1, -1, -1):
    # S(i) <= S(j) => i <= jが言えるのでこの順番でOK。ループの順序が正しい自信がなければメモ化再帰で行えば良い。
        for now in range(N):
            for new in range(N):
                if (S >> new) & 1 != 0:
                    continue
                dp[S][now] = min(dp[S][now], dp[S + (1 << new)][new] + d[now][new])

    return dp[0][0]


if __name__ == '__main__':
    inf = float('inf')
    data = [ [inf, 3, inf, 4, inf],
             [inf, inf, 5, inf, inf],
             [4, inf, inf, 5, inf],
             [inf, inf, inf, inf, 3],
             [7, 6, inf, inf, inf]
           ]
    print(tsp(data))

