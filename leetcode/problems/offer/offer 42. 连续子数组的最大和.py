class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, temp = nums[0], 0
        for i in nums:
            temp += i
            ans = max(ans, temp)
            if temp < 0:
                temp = 0
        return ans
