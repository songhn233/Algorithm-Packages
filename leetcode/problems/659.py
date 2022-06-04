class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        counter = collections.Counter(nums)
        map = collections.Counter()
        for item in nums:
            if not counter[item]:
                continue
            if map.get(item - 1, 0) > 0:
                map[item - 1] -= 1
                map[item] += 1
                counter[item] -= 1
            elif counter.get(item + 1, 0) > 0 and counter.get(item + 2, 0) > 0:
                counter[item] -= 1
                counter[item + 1] -= 1
                counter[item + 2] -= 1
                map[item + 2] += 1
            else:
                return False
        return True
