class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counter, target = 0, nums[0]
        for i in nums:
            if counter == 0:
                target = i
            if target != i:
                counter -= 1
            else:
                counter += 1
        return target
