function findPoisonedDuration(timeSeries: number[], duration: number): number {
  let ex = 0,
    ans = 0
  for (let v of timeSeries) {
    if (v >= ex) {
      ans += duration
    } else {
      ans += v + duration - ex
    }
    ex = v + duration
  }
  return ans
}
