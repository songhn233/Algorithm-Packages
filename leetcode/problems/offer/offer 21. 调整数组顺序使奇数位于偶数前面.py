class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        a, b = [], []
        for i in nums:
            if i % 2:
                a.append(i)
            else:
                b.append(i)
        return a + b
