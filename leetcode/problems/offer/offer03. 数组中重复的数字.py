class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        dict = set()
        for i in nums:
            if i in dict:
                return i
            else:
                dict.add(i)
