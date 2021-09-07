function threeSum(nums: number[]): number[][] {
  const arr = nums.sort((a, b) => a - b),
    n = arr.length
  const ans: number[][] = []
  for (let i = 0; i < n; i++) {
    if (i > 0 && arr[i] === arr[i - 1]) continue
    let j = i + 1,
      k = n - 1
    while (j < k) {
      while (j > i + 1 && arr[j] === arr[j - 1]) j++
      if (j >= k) break
      if (arr[j] + arr[k] < -arr[i]) j++
      else if (arr[j] + arr[k] > -arr[i]) k--
      else {
        ans.push([arr[i], arr[j], arr[k]])
        j++, k--
      }
    }
  }
  return ans
}
