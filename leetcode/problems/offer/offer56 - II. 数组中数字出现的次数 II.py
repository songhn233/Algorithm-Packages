class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        c = [0] * 32
        for i in nums:
            for j in range(0, 32):
                if i >> j & 1:
                    c[j] += 1
        res = 0
        for i in range(31, -1, -1):
            c[i] %= 3
            res <<= 1
            res |= c[i]
        return res
