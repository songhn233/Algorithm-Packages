class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = -1, -1
        for i in range(len(nums)):
            if nums[i] == target:
                if l == -1:
                    l = r = i
                else:
                    r = i
            elif l != - 1:
                return r - l + 1
        if l == -1:
            return 0
        return r - l + 1
