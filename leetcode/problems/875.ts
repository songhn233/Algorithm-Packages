function minEatingSpeed(piles: number[], h: number): number {
  const maxn = piles.reduce((a, b) => (a > b ? a : b))
  let l = 1,
    r = maxn
  const calc = (x: number) => {
    return piles.reduce((pre, v) => pre + Math.ceil(v / x), 0)
  }
  while (l < r) {
    const mid = (l + r) >> 1
    if (calc(mid) <= h) r = mid
    else l = mid + 1
  }
  return l
}
