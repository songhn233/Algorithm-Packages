class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue, ans = collections.deque(), []
        for i in range(len(nums)):
            if i >= k:
                if queue[0] < i - k + 1:
                    queue.popleft()
            while len(queue) and nums[i] > nums[queue[-1]]:
                queue.pop()
            queue.append(i)
            if i >= k - 1:
                ans.append(nums[queue[0]])
        return ans
