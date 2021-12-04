function findNthDigit(n: number): number {
  let len = 1
  while (n > len * 9 * Math.pow(10, len - 1)) {
    n -= len * 9 * Math.pow(10, len - 1)
    ++len
  }
  let s = Math.pow(10, len - 1) + Math.floor(n / len) - 1
  return n % len
    ? Math.floor((s + 1) / Math.pow(10, len - n + Math.floor(n / len) * len)) %
        10
    : s % 10
}
