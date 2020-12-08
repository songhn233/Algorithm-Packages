class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        n = len(a)
        ldot, rdot, ans = [1]*n, [1]*n, [1]*n
        pre, nex = 1, 1
        for i in range(0, len(a), 1):
            pre *= a[i]
            ldot[i] = pre
        for i in range(len(a) - 1, -1, -1):
            nex *= a[i]
            rdot[i] = nex
        for i in range(0, len(a), 1):
            if i == 0:
                ans[0] = (rdot[1])
            elif i == len(a) - 1:
                ans[len(a) - 1] = ldot[len(a) - 2]
            else:
                ans[i] = ldot[i - 1]*rdot[i + 1]
        return ans
