function majorityElement(nums: number[]): number {
  let count = 0,
    ele = 0
  for (let v of nums) {
    if (count > 0 && v === ele) {
      count++
    } else if (count === 0) {
      ele = v
      count++
    } else {
      count--
    }
  }
  return ele
}
