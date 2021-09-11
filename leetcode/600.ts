function findIntegers(n: number): number {
  const num = n.toString(2),
    len = num.length
  const f = Array(len + 1)
    .fill(0)
    .map((_) => [0, 0])
  f[1][0] = f[1][1] = 1
  for (let i = 2; i <= len; i++) {
    f[i][0] = f[i - 1][0] + f[i - 1][1]
    f[i][1] = f[i - 1][0]
  }
  let ans = 0,
    pre = '0'
  for (let i = 0; i < len; i++) {
    if (num[i] === '1') {
      ans += f[len - i][0]
      if (pre === '1') {
        return ans
      }
    }
    pre = num[i]
  }
  return ans + 1
}
