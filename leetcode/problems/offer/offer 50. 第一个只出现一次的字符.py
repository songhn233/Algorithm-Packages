class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = {}
        for i in s:
            dic[i] = not i in dic
        for i in s:
            if dic[i] == 1:
                return i
        return " "
