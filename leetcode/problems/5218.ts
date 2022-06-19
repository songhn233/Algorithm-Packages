function minimumNumbers(num: number, k: number): number {
  if (num === 0) {
    return 0
  }
  for (let i = 1; i <= num && num - i * k >= 0; i++) {
    const t = num - i * k
    if (t % 10 === 0) {
      return i
    }
  }
  return -1
}
