const MOD = 1e9 + 7

function numPrimeArrangements(n: number): number {
  const isPrime = (x: number) => {
    if (x <= 1) {
      return false
    }
    for (let t = 2; t * t <= x; ++t) {
      if (x % t === 0) {
        return false
      }
    }
    return true
  }
  let ans = 1
  const factor = (x: number) => {
    for (let i = 2; i <= x; i++) {
      ans = (ans * i) % MOD
    }
  }
  let cnt = 0
  for (let i = 1; i <= n; i++) {
    if (isPrime(i)) {
      cnt++
    }
  }
  factor(cnt)
  factor(n - cnt)
  return ans
}
