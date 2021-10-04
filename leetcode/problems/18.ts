function fourSum(nums: number[], target: number): number[][] {
  nums.sort((a, b) => a - b)
  const ans = []
  const n = nums.length
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      let x = j + 1,
        y = n - 1
      const sum = nums[i] + nums[j]
      while (x < y) {
        if (x < y && nums[x] + nums[y] < target - sum) x++
        if (x < y && nums[x] + nums[y] > target - sum) y--
        if (x < y && nums[x] + nums[y] === target - sum) {
          ans.push([i, j, x, y].map((t) => nums[t]))
          while (nums[x] === nums[x + 1]) x++
          while (nums[y] === nums[y - 1]) y--
          x++, y--
        }
      }
      while (nums[j] === nums[j + 1]) j++
    }
    while (nums[i] === nums[i + 1]) i++
  }
  return ans
}
