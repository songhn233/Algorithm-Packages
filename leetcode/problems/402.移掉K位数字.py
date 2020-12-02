class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        length = len(num) - k
        for i in num:
            while k and len(stack) and stack[-1] > i:
                stack.pop()
                k -= 1
            stack.append(i)
        if ''.join(stack[:length]).lstrip('0'):
            return ''.join(stack[:length]).lstrip('0')
        else:
            return '0'
