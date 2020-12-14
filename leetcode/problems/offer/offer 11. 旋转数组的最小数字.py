class Solution:
    def minArray(self, numbers: List[int]) -> int:
        i, j = 0, len(numbers) - 1
        while i < j:
            mid = (i + j) // 2
            if numbers[mid] > numbers[j]:
                i = mid + 1
            elif numbers[mid] < numbers[j]:
                j = mid
            else:
                return min(numbers[i:j])
        return numbers[i]
