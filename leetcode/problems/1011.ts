function shipWithinDays(weights: number[], days: number): number {
  const sum = weights.reduce((a, b) => a + b),
    n = weights.length
  let l = 1,
    r = sum
  const check = (x: number) => {
    let count = 1,
      cur = 0
    for (let i = 0; i < n; i++) {
      if (weights[i] > x) {
        return false
      }
      if (cur + weights[i] <= x) {
        cur += weights[i]
      } else {
        count++
        cur = weights[i]
      }
    }
    return count <= days
  }
  while (l < r) {
    const mid = (l + r) >> 1
    if (check(mid)) r = mid
    else l = mid + 1
  }
  return l
}
