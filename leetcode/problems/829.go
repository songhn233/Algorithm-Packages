func consecutiveNumbersSum(n int) int {
  n *= 2
  ans := 0
  for i := 1; i * i < n; i ++ {
    if n % i != 0 {
      continue
    }
    if (n / i - i + 1) & 1 == 0 {
      ans ++
    }
  }
  return ans
}