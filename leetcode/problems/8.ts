function myAtoi(s: string): number {
  const n = parseInt(s)
  if (isNaN(n)) {
    return 0
  }
  if (n < Math.pow(-2, 31)) {
    return Math.pow(-2, 31)
  }
  if (n >= Math.pow(2, 31) - 1) {
    return Math.pow(2, 31) - 1
  }
  return n
}
