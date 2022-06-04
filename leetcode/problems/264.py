class Solution:
    def nthUglyNumber(self, n: int) -> int:
        f, a, b, c = [1]*n , 0, 0, 0
        for i in range(1, n):
            f[i] = min(f[a] * 2, f[b] * 3, f[c] * 5)
            if f[i] == f[a] * 2: a += 1
            if f[i] == f[b] * 3: b += 1
            if f[i] == f[c] * 5: c += 1
        return f[-1]
