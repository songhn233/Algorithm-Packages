class Solution:
    def replaceSpace(self, s: str) -> str:
        ans = []
        for i in s:
            if i == ' ':
                ans.append('%20')
            else:
                ans.append(i)
        return ''.join(ans)
