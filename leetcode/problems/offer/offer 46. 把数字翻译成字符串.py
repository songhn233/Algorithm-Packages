class Solution:
    def translateNum(self, num: int) -> int:
        strs = str(num)
        f = [0] * len(strs)
        for i in range(len(strs)):
            if i == 0:
                f[i] = 1
                continue
            f[i] += f[i-1]
            if strs[i - 1] + strs[i] >= "10" and strs[i - 1] + strs[i] <= "25":
                if i == 1:
                    f[i] += 1
                else:
                    f[i] += f[i - 2]
        return f[len(strs) - 1]
