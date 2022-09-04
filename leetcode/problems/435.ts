function eraseOverlapIntervals(intervals: number[][]): number {
  intervals.sort((a, b) => a[1] - b[1])
  let cur = -Infinity,
    ans = 0
  for (const [x, y] of intervals) {
    if (cur <= x) {
      cur = y
      ans++
    }
  }
  return intervals.length - ans
}
