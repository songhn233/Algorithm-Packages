class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        if n < 0:
            x, n = 1 / x, - n
        while n:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res
