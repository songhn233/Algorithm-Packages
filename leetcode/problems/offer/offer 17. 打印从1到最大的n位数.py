class Solution:
    def printNumbers(self, n: int) -> List[int]:
        ans = []
        for i in range(1, int(math.pow(10, n))):
            ans.append(i)
        return ans
