function splitArray(nums: number[], m: number): number {
  const sum = nums.reduce((a, b) => a + b),
    maxn = nums.reduce((a, b) => (a > b ? a : b))
  let l = maxn,
    r = sum
  const check = (x: number) => {
    let count = 1,
      cur = 0
    for (let v of nums) {
      if (v > x) {
        return false
      }
      if (cur + v <= x) {
        cur += v
      } else {
        cur = v
        count++
      }
    }
    return count <= m
  }
  while (l < r) {
    const mid = (l + r) >> 1
    if (check(mid)) r = mid
    else l = mid + 1
  }
  return l
}
