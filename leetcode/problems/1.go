func twoSum(nums []int, target int) []int {
  m := map[int]int{}
  for idx, num := range nums {
    if v, ok := m[target - num]; ok {
      return []int{v, idx}
    }
    m[num] = idx
  }
  return nil
}