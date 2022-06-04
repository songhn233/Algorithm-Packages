func maxRotateFunction(nums []int) int {
  arr, ans, n, res := make([]int, len(nums) * 2), 0, len(nums), 0
  copy(arr[:len(nums)], nums)
  copy(arr[len(nums):], nums)
  
  sum := make([]int, len(nums) * 2)
  for i, v := range arr {
    if i == 0 {
      sum[i] = v
    } else {
      sum[i] = sum[i - 1] + v
    }
    if i < n {
      ans += i * v
    }
  }
  res = ans
  for i := 1; i < n; i ++ {
    ans += (n - 1) * arr[i + n - 1]
    ans -= sum[i + n - 2] - sum[i - 1]
    if res < ans {
      res = ans
    }
  }
  return res
}