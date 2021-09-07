function permute(nums: number[]): number[][] {
  const n = nums.length
  const ans: number[][] = []
  const tmp: number[] = []
  const vis: boolean[] = Array(n).fill(false)
  const dfs = (d: number) => {
    if (d === n) {
      ans.push(tmp.slice())
      return
    }
    for (let i = 0; i < n; i++) {
      if (vis[i]) continue
      vis[i] = true
      tmp.push(nums[i])
      dfs(d + 1)
      vis[i] = false
      tmp.pop()
    }
  }
  dfs(0)
  return ans
}
