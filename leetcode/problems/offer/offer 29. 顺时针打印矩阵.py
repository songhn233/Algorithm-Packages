class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        if not matrix:
            return ans
        l, r, t, b = 0, len(matrix[0]) - 1, 0, len(matrix) - 1
        while True:
            for i in range(l, r + 1):
                ans.append(matrix[t][i])
            t += 1
            if t > b:
                break
            for i in range(t, b + 1):
                ans.append(matrix[i][r])
            r -= 1
            if r < l:
                break
            for i in range(r, l - 1, - 1):
                ans.append(matrix[b][i])
            b -= 1
            if b < t:
                break
            for i in range(b, t - 1, - 1):
                ans.append(matrix[i][l])
            l += 1
            if l > r:
                break
        return ans
