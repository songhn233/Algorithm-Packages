const findKthNumber = (m: number, n: number, k: number) => {
  let l = 1,
    r = m * n
  const check = (x: number) =>
    Array(n)
      .fill(0)
      .map((_, i) => i + 1)
      .reduce((pre, v) => pre + (v * m <= x ? m : Math.floor(x / v)), 0) >= k
  while (l < r) {
    const mid = (l + r) >> 1
    if (check(mid)) r = mid
    else l = mid + 1
  }
  return l
}
