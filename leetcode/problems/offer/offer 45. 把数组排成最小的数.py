class Solution:
    def minNumber(self, nums: List[int]) -> str:
        strs = [str(i) for i in nums]
        strs.sort(key=functools.cmp_to_key(
            lambda x, y: int(x + y) - int(y + x)))
        return ''.join(strs)
