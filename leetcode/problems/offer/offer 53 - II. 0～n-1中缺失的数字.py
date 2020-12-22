class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        sum = n * (n + 1) // 2
        for i in nums:
            sum -= i
        return sum
