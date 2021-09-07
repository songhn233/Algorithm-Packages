function climbStairs(n: number): number {
  const a = Array(n + 1).fill(0)
  const fib = (n: number) => {
    if (a[n]) return a[n]
    if (n === 0 || n === 1) a[n] = 1
    else if (n == 2) a[n] = 2
    else a[n] = fib(n - 1) + fib(n - 2)
    return a[n]
  }
  fib(n)
  return a[n]
}
