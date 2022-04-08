function isHappy(n: number): boolean {
  const next = (n: number) =>
    String(n)
      .split('')
      .map(Number)
      .map((v) => v * v)
      .reduce((a, b) => a + b)
  let a = next(n),
    b = n
  while (a !== 1 && a !== b) {
    a = next(next(a))
    b = next(b)
  }
  return a === 1
}
