function getSum(a: number, b: number): number {
  while (b) {
    const t = (a & b) << 1
    a = a ^ b
    b = t
  }
  return a
}
