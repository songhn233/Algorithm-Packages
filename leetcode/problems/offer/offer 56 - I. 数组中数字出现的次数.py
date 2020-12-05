class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        res = 0
        for i in nums:
            res ^= i
        temp = 1
        while not temp & res:
            temp <<= 1
        a, b = 0, 0
        for i in nums:
            if temp & i:
                a ^= i
            else:
                b ^= i
        return [a, b]
