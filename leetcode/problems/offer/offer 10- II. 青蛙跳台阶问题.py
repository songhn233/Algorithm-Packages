class Solution:
    def numWays(self, n: int) -> int:
        f = [0] * 105
        mod = 1e9+7
        f[1] = 1
        for i in range(2, n + 2):
            f[i] = (f[i - 1] + f[i - 2]) % mod
        return int(f[n + 1])
