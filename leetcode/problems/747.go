func dominantIndex(nums []int) int {
  if len(nums) <= 1 {
    return 0
  }
  a, b, idx := nums[0], nums[1], 0
  if nums[0] < nums[1] {
    a = nums[1]
    b = nums[0]
    idx = 1
  }
  for i, v := range nums[2:] {
    if v > a {
      b = a
      a = v
      idx = i + 2
    } else if v == a {
      b = a
    } else if v > b {
      b = v
    }
  }
  if a >= b * 2 {
    return idx
  }
  return -1
}