function canPartitionKSubsets(nums: number[], k: number): boolean {
  nums.sort((a, b) => b - a)
  const sum = nums.reduce((a, b) => a + b),
    vis = Array(nums.length).fill(false)
  if (sum % k) {
    return false
  }
  const len = sum / k
  const dfs = (start: number, cur: number, step: number): boolean => {
    if (step >= k) {
      return true
    }
    if (cur > len) {
      return false
    } else if (cur === len) {
      return dfs(0, 0, step + 1)
    }
    for (let i = start; i < nums.length; i++) {
      if (!vis[i]) {
        vis[i] = true
        if (dfs(i + 1, cur + nums[i], step)) {
          return true
        }
        vis[i] = false
        while (i + 1 < nums.length && nums[i] === nums[i + 1]) i++
        if (cur === 0) {
          return false
        }
      }
    }
    return false
  }
  return dfs(0, 0, 0)
}
