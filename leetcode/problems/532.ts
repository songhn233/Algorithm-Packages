function findPairs(nums: number[], k: number): number {
  if (k < 0) k = -k
  if (k === 0) {
    let ans = 0
    const mp = new Map()
    for (let i = 0; i < nums.length; i++) {
      mp.set(nums[i], mp.has(nums[i]) ? mp.get(nums[i]) + 1 : 1)
      if (mp.get(nums[i]) === 2) {
        ans++
      }
    }
    return ans
  }
  const arr = [...new Set(nums)],
    n = arr.length
  arr.sort((a, b) => a - b)
  let ans = 0
  for (let i = 0; i < n; i++) {
    const v = arr[i]
    const target = v + k
    let l = i + 1,
      r = n - 1
    while (l < r) {
      const mid = (l + r) >> 1
      if (arr[mid] >= target) r = mid
      else l = mid + 1
    }
    if (arr[l] === target) {
      ++ans
    }
  }
  return ans
}
