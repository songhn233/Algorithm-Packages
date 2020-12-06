class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not len(prices):
            return 0
        ans, minx = 0, prices[0]
        for i in prices:
            minx = min(minx, i)
            ans = max(ans, i - minx)
        return ans
