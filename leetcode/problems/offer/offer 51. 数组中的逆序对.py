class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        ans = 0
        temp = [0] * len(nums)

        def merge(left, right, temp):
            ans = 0
            if left >= right:
                return 0
            mid = (left + right) // 2
            ans += merge(left, mid, temp)
            ans += merge(mid + 1, right, temp)
            p, q, t = left, mid + 1, left
            while p <= mid and q <= right:
                if nums[p] <= nums[q]:
                    temp[t] = nums[p]
                    p += 1
                    t += 1
                else:
                    temp[t] = nums[q]
                    ans += mid - p + 1
                    q += 1
                    t += 1
            while p <= mid:
                temp[t] = nums[p]
                t += 1
                p += 1
            while q <= right:
                temp[t] = nums[q]
                t += 1
                q += 1
            nums[left:right + 1] = temp[left:right+1]
            return ans
        return merge(0, len(nums) - 1, temp)
