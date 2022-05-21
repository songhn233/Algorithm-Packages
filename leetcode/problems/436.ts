function findRightInterval(intervals: number[][]): number[] {
  const arr = intervals.map((v) => v[0]).map((v, idx) => [v, idx])
  arr.sort((x, y) => x[0] - y[0])
  const ans = Array(intervals.length).fill(-1)
  for (let i = 0; i < intervals.length; i++) {
    const v = intervals[i][1]
    let l = 0,
      r = intervals.length - 1
    while (l < r) {
      const mid = (l + r) >> 1
      if (arr[mid][0] >= v) r = mid
      else l = mid + 1
    }
    if (arr[l][0] >= v) {
      ans[i] = arr[l][1]
    }
  }
  return ans
}
