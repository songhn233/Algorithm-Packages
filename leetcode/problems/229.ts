function majorityElement(nums: number[]): number[] {
  let c1 = 0,
    c2 = 0,
    e1 = 0,
    e2 = 0
  for (let v of nums) {
    if (c1 > 0 && v === e1) {
      c1++
    } else if (c2 > 0 && v === e2) {
      c2++
    } else if (c1 === 0) {
      c1++
      e1 = v
    } else if (c2 === 0) {
      c2++
      e2 = v
    } else {
      c1--
      c2--
    }
  }
  let ans = [],
    t1 = 0,
    t2 = 0
  for (let v of nums) {
    if (c1 > 0 && v === e1) t1++
    if (c2 > 0 && v === e2) t2++
  }
  if (c1 > 0 && t1 > Math.floor(nums.length / 3)) ans.push(e1)
  if (c2 > 0 && t2 > Math.floor(nums.length / 3)) ans.push(e2)
  return ans
}
