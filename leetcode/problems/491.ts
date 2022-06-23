function findSubsequences(nums: number[]): number[][] {
  const ans: number[][] = []
  const dfs = (cur: number, tmp: number[]) => {
    if (tmp.length >= 2) {
      ans.push(tmp.slice())
    }
    if (cur >= nums.length) {
      return
    }
    const mp = new Set<number>()
    for (let i = cur; i < nums.length; i++) {
      if (
        (tmp.length === 0 || tmp[tmp.length - 1] <= nums[i]) &&
        !mp.has(nums[i])
      ) {
        tmp.push(nums[i])
        mp.add(nums[i])
        dfs(i + 1, tmp)
        tmp.pop()
      }
    }
  }
  dfs(0, [])
  return ans
}
