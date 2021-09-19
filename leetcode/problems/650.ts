function minSteps(n: number): number {
  let ans = 0
  for (let i = 2; i * i <= n; i++) {
    while (n % i === 0) {
      n /= i
      ans += i
    }
  }
  if (n > 1) ans += n
  return ans
}
