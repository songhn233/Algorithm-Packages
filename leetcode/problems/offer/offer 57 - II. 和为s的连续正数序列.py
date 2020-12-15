class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans, sum, pre, i = [], 0, 1, 1
        while pre <= target // 2:
            if sum + i < target:
                sum += i
                i += 1
            elif sum + i > target:
                sum -= pre
                pre += 1
            else:
                temp = list(range(pre, i + 1))
                ans.append(temp)
                sum -= pre
                pre += 1
        return ans
