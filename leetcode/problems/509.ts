function fib(n: number): number {
  if (n <= 1) return n
  const f = [0, 1]
  for (let i = 2; i <= n; i++) {
    ;[f[0], f[1]] = [f[1], f[0] + f[1]]
  }
  return f[1]
}
