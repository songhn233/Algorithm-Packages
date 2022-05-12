function minDeletionSize(strs: string[]): number {
  const n = strs[0].length,
    m = strs.length
  let ans = 0
  for (let i = 0; i < n; i++) {
    for (let j = 1; j < m; j++) {
      if (strs[j - 1][i] > strs[j][i]) {
        ++ans
        break
      }
    }
  }
  return ans
}
